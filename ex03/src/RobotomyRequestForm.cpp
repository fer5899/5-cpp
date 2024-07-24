#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy.getTarget())
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
	}
	return *this;
}

void	RobotomyRequestForm::action() const
{
	std::cout << "* drilling noises *" << std::endl;

	srand(time(0));

	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << _target << "'s robotomy failed" << std::endl;
}

const char* RobotomyRequestForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* RobotomyRequestForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const std::string	&RobotomyRequestForm::getTarget() const
{
	return _target;
}




