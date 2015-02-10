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

class Exception : public std::exception
{
public:
	Exception(std::string const & s)
		: _message(s)
	{

	}

	virtual ~Exception() throw() {}

	virtual const char*	what() const throw()
	{
		return (_message.c_str());
	}

protected:
	std::string	_message;
};

class TypeException : public Exception
{
public:
	TypeException(std::string const & s) : Exception(s) {}

	virtual ~TypeException() throw() {}
};

class ParserException : public Exception
{
public:
	ParserException(std::string const & s) : Exception(s) {}

	virtual ~ParserException() throw() {}
};

class StackException : public Exception
{
public:
	StackException(std::string const & s) : Exception(s) {}

	virtual ~StackException() throw() {}
};

class ExitException : public Exception
{
public:
	ExitException(std::string const & s) : Exception(s) {}

	virtual ~ExitException() throw() {}
};

#endif	/* TYPEEXCEPTION_HPP */

