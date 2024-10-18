#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, int to_sign, int to_exec) : _name(name), _signed(false), _toSign(to_sign), _toExec(to_exec)
{
	if (to_sign < 1 || to_exec < 1)
		throw GradeTooHighException();
	else if (to_sign > 150 || to_exec > 150)
		throw GradeTooLowException();
}

const std::string& Form::getName() const
{
	return (_name);
}

bool Form::isSigned() const
{
    return (_signed);
}

int Form::toSign() const
{
    return (_toSign);
}

int Form::toExec() const
{
    return (_toExec);
}

void Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= _toSign)
        _signed = true;
    else
      throw GradeTooLowException();  
}

std::ostream & operator << (std::ostream &out, const Form& f)
{
    out << f.getName() << ", signed: " << f.isSigned() << ", required grade to => sign: " << f.toSign() << ", execute: " << f.toExec() << ".";
	return (out);
}
