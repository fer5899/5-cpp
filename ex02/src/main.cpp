#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {

        // Form creation
        ShrubberyCreationForm shrubberyForm("home");
        RobotomyRequestForm robotomyForm("employee");
        PresidentialPardonForm pardonForm("criminal");


        // Bureaucrat creation
        Bureaucrat highRanker("HighRanker", 1);
        Bureaucrat midRanker("MidRanker", 70);
        Bureaucrat lowRanker("LowRanker", 150);

		std::cout << "\n-- Unsigned Execution Tests --\n";
		highRanker.executeForm(shrubberyForm); // Expected to fail
		highRanker.executeForm(robotomyForm); // Expected to fail
		highRanker.executeForm(pardonForm); // Expected to fail

        // Signing forms
		std::cout << "\n-- Low Ranker Signing Tests --\n";
		lowRanker.signForm(shrubberyForm); // Expected to fail
		lowRanker.signForm(robotomyForm); // Expected to fail
		lowRanker.signForm(pardonForm); // Expected to fail

		std::cout << "\n-- Mid Ranker Signing Tests --\n";
		midRanker.signForm(shrubberyForm);
		midRanker.signForm(robotomyForm);
		midRanker.signForm(pardonForm);

		std::cout << "\n-- High Ranker Signing Tests --\n";
        highRanker.signForm(shrubberyForm);
        highRanker.signForm(robotomyForm);
        highRanker.signForm(pardonForm);

        // Executing forms
        std::cout << "\n-- High Ranker Execution Tests --\n";
        highRanker.executeForm(shrubberyForm);
        highRanker.executeForm(robotomyForm);
		highRanker.executeForm(pardonForm);

		std::cout << "\n-- Mid Ranker Execution Tests --\n";
		midRanker.executeForm(shrubberyForm);
		midRanker.executeForm(robotomyForm); // Expected to fail
		midRanker.executeForm(pardonForm); // Expected to fail

		std::cout << "\n-- Low Ranker Execution Tests --\n";
		lowRanker.executeForm(shrubberyForm); // Expected to fail
		lowRanker.executeForm(robotomyForm); // Expected to fail
		lowRanker.executeForm(pardonForm); // Expected to fail

    } catch (std::exception& e) {
        std::cout << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}