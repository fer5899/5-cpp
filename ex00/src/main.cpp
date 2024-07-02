#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	// Test the creation of a Bureaucrat
	std::cout << "Test the creation of a Bureaucrat -----" << std::endl;
	Bureaucrat b1("Bureaucrat 1", 1);
	std::cout << b1 << std::endl;
	std::cout << std::endl;

	// Test the creation of a Bureaucrat with a grade too high
	std::cout << "Test the creation of a Bureaucrat with a grade too high -----" << std::endl;
	try
	{
		Bureaucrat b2("Bureaucrat 2", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test the creation of a Bureaucrat with a grade too low
	std::cout << "Test the creation of a Bureaucrat with a grade too low -----" << std::endl;
	try
	{
		Bureaucrat b3("Bureaucrat 3", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test the copy of a Bureaucrat
	std::cout << "Test the copy constructor of a Bureaucrat -----" << std::endl;
	Bureaucrat b1bis(b1);
	std::cout << b1bis << std::endl;
	std::cout << std::endl;

	// Test the assignation of a Bureaucrat
	std::cout << "Test the assignation of a Bureaucrat -----" << std::endl;
	Bureaucrat b1ter("Bureaucrat 1 ter", 5);
	std::cout << b1ter << std::endl;
	b1ter = b1;
	std::cout << b1ter << std::endl;
	std::cout << std::endl;

	// Test getters
	// std::cout << "Test getters -----" << std::endl;
	std::cout << b1.getName() << std::endl;
	std::cout << b1.getGrade() << std::endl;
	std::cout << std::endl;

	// Test the incrementation of a Bureaucrat
	std::cout << "Test the incrementation of a Bureaucrat -----" << std::endl;
	Bureaucrat b4("Bureaucrat 4", 150);
	std::cout << b4 << std::endl;
	b4.incrementGrade();
	std::cout << b4 << std::endl;
	std::cout << std::endl;

	// Test the incrementation of a Bureaucrat with a grade too high
	std::cout << "Test the incrementation of a Bureaucrat with a grade too high -----" << std::endl;
	try
	{
		b4.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	// Test the decrementation of a Bureaucrat
	std::cout << "Test the decrementation of a Bureaucrat -----" << std::endl;
	Bureaucrat b5("Bureaucrat 5", 1);
	std::cout << b5 << std::endl;
	b5.decrementGrade();
	std::cout << b5 << std::endl;
	std::cout << std::endl;

	// Test the decrementation of a Bureaucrat with a grade too low
	std::cout << "Test the decrementation of a Bureaucrat with a grade too low -----" << std::endl;
	try
	{
		b5.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}


