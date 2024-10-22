#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _toSign(1), _toExec(1) {}

AForm::AForm(const std::string name, int to_sign, int to_exec) : _name(name), _signed(false), _toSign(to_sign), _toExec(to_exec)
{
	if (to_sign < 1 || to_exec < 1)
		throw GradeTooHighException();
	else if (to_sign > 150 || to_exec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _toSign(other._toSign), _toExec(other._toExec) {}

AForm &AForm::operator=(const AForm &other)
{
    _signed = other._signed;
    return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
	return (_name);
}

bool AForm::isSigned() const
{
    return (_signed);
}

int AForm::toSign() const
{
    return (_toSign);
}

int AForm::toExec() const
{
    return (_toExec);
}

void AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() <= _toSign)
        _signed = true;
    else
      throw GradeTooLowException();  
}

std::ostream & operator << (std::ostream &out, const AForm& f)
{
    out << f.getName() << ", signed: " << f.isSigned() << ", required grade to => sign: " << f.toSign() << ", execute: " << f.toExec() << ".";
	return (out);
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > toExec())
        throw GradeTooLowException();
}
