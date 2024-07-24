#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy.getTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
	}
	return *this;
}

void	ShrubberyCreationForm::action() const
{
	std::ofstream	file;
	std::string		filename = _target + "_shrubbery";

	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return ;
	}
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << std::endl;
	file.close();
}

const char *ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const std::string	&ShrubberyCreationForm::getTarget() const
{
	return _target;
}


