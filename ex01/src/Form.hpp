
#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <sstream>

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

	public:
		Form(std::string const &name, int signGrade, int executeGrade);
		~Form();
		Form(const Form &copy);
		Form &operator=(const Form &copy);

		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		void				beSigned(Bureaucrat bureaucrat);


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

std::ostream &operator<<(std::ostream &out, const Form &form);


#endif
