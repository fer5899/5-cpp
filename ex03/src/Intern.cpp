#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return *this;
}

AForm *makeShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *makeRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *makePresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

/*----------------------------PUBLIC-FUNCTIONS----------------------------*/

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
    typedef AForm *(*funcPtr)(std::string target);
    std::string NameArray[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    funcPtr funcArray[3] = {&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm};
    for (int i = 0; i < 3; i++)
    {
        if (formName == NameArray[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (funcArray[i])(target);
        }
    }
    std::cout << "Intern can't create " << formName << " because it doesn't exist" << std::endl;
    return NULL;
}



