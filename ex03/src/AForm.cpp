#include "AForm.hpp"

template <typename T>
  std::string numberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

AForm::AForm(std::string const &name, int signGrade, int executeGrade) : _name(name), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	_isSigned = false;
}

AForm::~AForm()
{
}


AForm	&AForm::operator=(const AForm &copy)
{
	if (this != &copy)
	{
		_isSigned = copy.getIsSigned();
	}
	return *this;
}


AForm::AForm(const AForm &copy) : _name(copy.getName()), _signGrade(copy.getSignGrade()), _executeGrade(copy.getExecuteGrade())
{
	*this = copy;
}

void	AForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

const std::string	&AForm::getName() const
{
	return _name;
}

bool	AForm::getIsSigned() const
{
	return _isSigned;
}

int	AForm::getSignGrade() const
{
	return _signGrade;
}

int	AForm::getExecuteGrade() const
{
	return _executeGrade;
}

std::ostream &operator<<(std::ostream &out, const AForm &AForm)
{
	out << AForm.getName() << std::string(", AForm sign grade ") << numberToString(AForm.getSignGrade()) << std::string(", AForm execute grade ") << numberToString(AForm.getExecuteGrade()) << std::string(", AForm is signed ") << (AForm.getIsSigned() ? "true" : "false");
	return out;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}

const char* AForm::UnsignedFormException::what() const throw()
{
	return "Form to be executed is not signed";
}

void	AForm::checkExecutionGrade(Bureaucrat bureaucrat) const
{
	if (bureaucrat.getGrade() > _executeGrade)
		throw AForm::GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw AForm::UnsignedFormException();
	checkExecutionGrade(executor);
	action();
}

