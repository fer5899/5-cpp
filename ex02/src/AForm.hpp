
#ifndef AForm_HPP
# define AForm_HPP

# include <string>
# include <sstream>

# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_executeGrade;

		void				checkExecutionGrade(Bureaucrat bureaucrat) const;

	protected:
		AForm(std::string const &name, int signGrade, int executeGrade);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		~AForm();


	public:
		void				beSigned(Bureaucrat bureaucrat);
		void				execute(Bureaucrat const &executor) const;
		
		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getSignGrade() const;
		int					getExecuteGrade() const;

		virtual void		action() const = 0;


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

	class UnsignedFormException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);


#endif
