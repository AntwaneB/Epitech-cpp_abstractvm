/*
 ** App.hpp
 **
 ** Made by Antoine Buchser
 ** Login   <buchse_a@epitech.eu>
 **
 ** Started on February 6, 2015, 10:53 AM Antoine Buchser
 ** Updated on February 6, 2015, 10:53 AM Antoine Buchser
 */

#ifndef APP_HPP
#define	APP_HPP

#include <string>

class App
{
public:
	App(int, char**);
	~App();

	int	run(void) const;

private:
	int		_ac;
	char**	_av;
};

#endif /* !APP_HPP */
