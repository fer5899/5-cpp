#include "Form.hpp"
#include <iostream>

int main()
{
	// Test the creation of a Form
	std::cout << "Test the creation of a Form -----" << std::endl;
	Form f1("Form 1", 1, 1);
	std::cout << f1 << std::endl;
	std::cout << std::endl;

	// Test the creation of a Form with a grade too high
	std::cout << "Test the creation of a Form with a grade too high -----" << std::endl;
	try
	{
		Form f2("Form 2", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test the creation of a Form with a grade too low
	std::cout << "Test the creation of a Form with a grade too low -----" << std::endl;
	try
	{
		Form f3("Form 3", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test the copy of a Form
	std::cout << "Test the copy constructor of a Form -----" << std::endl;
	Form f1bis(f1);
	std::cout << f1bis << std::endl;
	std::cout << std::endl;

	// Test the assignation of a Form
	std::cout << "Test the assignation of a Form -----" << std::endl;
	Form f1ter("Form 1 ter", 5, 5);
	std::cout << f1ter << std::endl;
	f1ter = f1;
	std::cout << f1ter << std::endl;
	std::cout << std::endl;

	// Test getters
	std::cout << "Test getters -----" << std::endl;
	std::cout << f1.getName() << std::endl;
	std::cout << f1.getIsSigned() << std::endl;
	std::cout << f1.getSignGrade() << std::endl;
	std::cout << f1.getExecuteGrade() << std::endl;
	std::cout << std::endl;

	// Test the signature of a Form with a grade too low
	std::cout << "Test the signature of a Form with a grade too low -----" << std::endl;
	Bureaucrat b1("Bureaucrat 1", 150);
	std::cout << b1 << std::endl;
	std::cout << f1 << std::endl;
	b1.signForm(f1);
	std::cout << f1 << std::endl;
	std::cout << std::endl;

	// Test the signature of a Form
	std::cout << "Test the signature of a Form -----" << std::endl;
	Bureaucrat b2("Bureaucrat 2", 1);
	std::cout << b2 << std::endl;
	std::cout << f1 << std::endl;
	b2.signForm(f1);
	std::cout << f1 << std::endl;
	std::cout << std::endl;

	// Test the signature of a Form already signed
	std::cout << "Test the signature of a Form already signed -----" << std::endl;
	Bureaucrat b3("Bureaucrat 3", 1);
	std::cout << b3 << std::endl;
	std::cout << f1 << std::endl;
	b3.signForm(f1);
	std::cout << f1 << std::endl;
	std::cout << std::endl;






	return 0;
}


