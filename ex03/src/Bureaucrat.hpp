
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <sstream>
# include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(std::string const &name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);

		const std::string &getName() const;
		int	getGrade() const;

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm &form);
		void	executeForm(AForm const &form);


	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);



#endif
