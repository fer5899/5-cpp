#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    // Test form creation with Intern
	std::cout << "\n--- Test form creation with Intern ---\n" << std::endl;
	Intern intern;
	AForm *form1 = intern.makeForm("shrubbery creation", "home");
	AForm *form2 = intern.makeForm("robotomy request", "home");
	AForm *form3 = intern.makeForm("presidential pardon", "home");
	AForm *form4 = intern.makeForm("nonexistent form", "home");

	// Test form signing
	std::cout << "\n--- Test form signing ---\n" << std::endl;
	Bureaucrat bureaucrat1("bureaucrat1", 1);

	try {
		bureaucrat1.signForm(*form1);
		bureaucrat1.signForm(*form2);
		bureaucrat1.signForm(*form3);
		
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << *form1 << std::endl;
	std::cout << *form2 << std::endl;
	std::cout << *form3 << std::endl;

	// Test form execution
	std::cout << "\n--- Test form execution ---\n" << std::endl;
	Bureaucrat bureaucrat2("bureaucrat2", 1);

	try {
		bureaucrat2.executeForm(*form1);
		bureaucrat2.executeForm(*form2);
		bureaucrat2.executeForm(*form3);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	delete form1;
	delete form2;
	delete form3;
	delete form4;


    return 0;
}