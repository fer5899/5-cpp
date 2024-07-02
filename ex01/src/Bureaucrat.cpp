#include "Bureaucrat.hpp"
#include "Form.hpp"

template <typename T>
  std::string numberToString ( T Number )
  {
     std::ostringstream ss;
     ss << Number;
     return ss.str();
  }

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}


std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << std::string(", bureaucrat grade ") << numberToString(bureaucrat.getGrade());
	return out;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
	{
		_grade = copy.getGrade();
	}
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string &Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned())
	{
		std::cout << _name << " cannot sign " << form.getName() << " because the form is already signed" << std::endl;
		return ;
	}
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

