#pragma once


#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);
        int calculate(const std::string &expression);

    private:
        std::stack<int> _stack;
        void performOperation(const std::string &operation);
        bool isOperator(const std::string &token);
        int applyOperation(int a, int b, const std::string &operation);
};
