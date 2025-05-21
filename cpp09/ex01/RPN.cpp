#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &src) : _stack(src._stack) {}
RPN &RPN::operator=(const RPN &src) {
  if (this != &src)
    _stack = src._stack;
  return *this;
}

int stringToInt(const std::string &str) {
  std::istringstream iss(str);
  int num;
  iss >> num;
  return num;
}

bool isValidDigit(const std::string &str) {
  if (str.empty())
    return false;
  for (size_t i = 0; i < str.length(); i++) {
    if (str[i] == '+' && i == 0 && str.length() > 1)
      continue;
    if (!isdigit(str[i]))
      return false;
  }
  return true;
}

int RPN::calculate(const std::string &expression) {
  std::istringstream iss(expression);
  std::string token;
  while (iss >> token) {
    if (isValidDigit(token))
      _stack.push(stringToInt(token));
    else if (isOperator(token))
      performOperation(token);
    else
      throw std::runtime_error("Error: Invalid token");
  }
  if (_stack.size() != 1)
    throw std::runtime_error("Error: Invalid expression");
  return _stack.top();
}

void RPN::performOperation(const std::string &operation) {
  if (_stack.size() < 2)
    throw std::runtime_error("Error: Not enough operands");
  int b = _stack.top();
  _stack.pop();
  int a = _stack.top();
  _stack.pop();
  _stack.push(applyOperation(a, b, operation));
}

bool RPN::isOperator(const std::string &token) {
  return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::applyOperation(int a, int b, const std::string &operation) {
  if (operation == "+")
    return a + b;
  else if (operation == "-")
    return a - b;
  else if (operation == "*")
    return a * b;
  else if (operation == "/") {
    if (b == 0)
      throw std::runtime_error("Error: Division by zero");
    return a / b;
  }
  throw std::runtime_error("Error: Invalid operator");
}
