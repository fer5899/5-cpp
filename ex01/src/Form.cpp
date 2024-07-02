#include "Form.hpp"

template <typename T>
  std::string numberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

Form::Form(std::string const &name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	_isSigned = false;
}

Form::~Form()
{
}


Form	&Form::operator=(const Form &copy)
{
	if (this != &copy)
	{
		_isSigned = copy.getIsSigned();
	}
	return *this;
}


Form::Form(const Form &copy) : _name(copy.getName()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade())
{
	*this = copy;
}

void	Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const std::string	&Form::getName() const
{
	return _name;
}

bool	Form::getIsSigned() const
{
	return _isSigned;
}

int	Form::getSignGrade() const
{
	return _signGrade;
}

int	Form::getExecuteGrade() const
{
	return _executeGrade;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName() << std::string(", form sign grade ") << numberToString(form.getSignGrade()) << std::string(", form execute grade ") << numberToString(form.getExecuteGrade()) << std::string(", form is signed ") << (form.getIsSigned() ? "true" : "false");
	return out;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}

