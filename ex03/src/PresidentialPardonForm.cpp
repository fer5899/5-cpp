#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy.getTarget())
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
	}
	return *this;
}

void	PresidentialPardonForm::action() const
{
	std::cout << PresidentialPardonForm::getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const char* PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const std::string	&PresidentialPardonForm::getTarget() const
{
	return _target;
}





