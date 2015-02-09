/*
 * File:   TypeException.hpp
 * Author: buchse_a
 *
 * Created on February 9, 2015, 1:12 PM
 */

#ifndef TYPEEXCEPTION_HPP
#define	TYPEEXCEPTION_HPP

#include <string>
#include <exception>

class TypeException : public std::exception
{
public:
	TypeException(std::string const & s)
		: _message(s)
	{

	}

	virtual ~TypeException() throw() {}

	virtual const char*	what() const throw()
	{
		return (_message.c_str());
	}

private:
	std::string	_message;
};

#endif	/* TYPEEXCEPTION_HPP */

