/*
 * File:   Parser.cpp
 * Author: buchse_a
 *
 * Created on February 9, 2015, 12:19 PM
 */

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include "Parser.hpp"
#include "Operand.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

bool	Parser::inStr(char const c, std::string const & str)
{
	for (size_t i = 0; i < str.size(); i++)
		if (str[i] == c)
			return (true);
	return (false);
}

std::vector<std::string>		Parser::strtovec(std::string const & str, std::string const & delim)
{
	std::vector<std::string>	res;

	std::string	tmp = "";
	size_t		len = str.size();
	for (size_t i = 0; i < len; i++)
	{
		if (Parser::inStr(str[i], delim))
		{
			if (!tmp.empty())
			res.push_back(tmp);
			tmp.clear();
		}
		else
			tmp += str[i];
		if (str[i] == ';')
			break;
	}
	if (!tmp.empty())
		res.push_back(tmp);

	return (res);
}

void	Parser::parse(std::vector<std::string> const & content)
{
	std::map<std::string, void (Parser::*)(std::vector<std::string> const &)>	operations;

	operations.insert(std::map<std::string, void (Parser::*)(std::vector<std::string> const &)>::value_type("push", &Parser::push));
	operations.insert(std::map<std::string, void (Parser::*)(std::vector<std::string> const &)>::value_type("pop", &Parser::pop));
	operations.insert(std::map<std::string, void (Parser::*)(std::vector<std::string> const &)>::value_type("dump", &Parser::dump));
	operations.insert(std::map<std::string, void (Parser::*)(std::vector<std::string> const &)>::value_type("assert", &Parser::assert));
	operations.insert(std::map<std::string, void (Parser::*)(std::vector<std::string> const &)>::value_type("add", &Parser::add));
	operations.insert(std::map<std::string, void (Parser::*)(std::vector<std::string> const &)>::value_type("sub", &Parser::sub));
	operations.insert(std::map<std::string, void (Parser::*)(std::vector<std::string> const &)>::value_type("mul", &Parser::mul));
	operations.insert(std::map<std::string, void (Parser::*)(std::vector<std::string> const &)>::value_type("div", &Parser::div));
	operations.insert(std::map<std::string, void (Parser::*)(std::vector<std::string> const &)>::value_type("mod", &Parser::pop));
	operations.insert(std::map<std::string, void (Parser::*)(std::vector<std::string> const &)>::value_type("print", &Parser::print));
	operations.insert(std::map<std::string, void (Parser::*)(std::vector<std::string> const &)>::value_type("exit", &Parser::exit));

	size_t	len = content.size();
	for (size_t i = 0; i < len; i++)
	{
		if (!content[i].empty())
		{
			std::vector<std::string>	parts = Parser::strtovec(content[i], " ();");
			if (!parts.empty() && operations.find(parts[0]) != operations.end())
				(this->*(operations.find(parts[0])->second))(parts);
			else if (!parts.empty() && operations.find(parts[0]) == operations.end())
				throw ParserException("Invalid operations");
		}
	}
	_operands.clear();
	throw ParserException("Force exiting programm, missing exit instruction");
}

void	Parser::push(std::vector<std::string> const & s)
{
	if (s[1] == "int8")
		_operands.push_front(Parser::createOperand(Int8, s[2]));
	else if (s[1] == "int16")
		_operands.push_front(Parser::createOperand(Int16, s[2]));
	else if (s[1] == "int32")
		_operands.push_front(Parser::createOperand(Int32, s[2]));
	else if (s[1] == "float")
		_operands.push_front(Parser::createOperand(Float, s[2]));
	else if (s[1] == "double")
		_operands.push_front(Parser::createOperand(Double, s[2]));
	else
		throw ParserException("Pushing invalid type");
}

void	Parser::pop(std::vector<std::string> const & s)
{
	(void)s;
	if (_operands.empty())
		throw StackException("Trying to remove an element from an empty stack");
	_operands.pop_front();
}

void	Parser::dump(std::vector<std::string> const & s)
{
	(void)s;
	if (_operands.empty())
		throw StackException("Trying to dump elements from an empty stack");
	for (std::list<IOperand*>::const_iterator it = Parser::_operands.begin(); it != Parser::_operands.end(); ++it)
	{
    	std::cout << (*it)->toString() << std::endl;
	}
}

void	Parser::assert(std::vector<std::string> const & s)
{
	(void)s;
	if (_operands.empty())
		throw StackException("Trying to assert an element from an empty stack");
	if (s.back() != _operands.front()->toString())
		throw ParserException("The value at the top of the stack is not equal to the one passed as parameter");
}

void	Parser::add(std::vector<std::string> const & s)
{
	(void)s;
	if (_operands.empty())
		throw StackException("Trying to add elements from an empty stack");
	if (_operands.size() < 2)
		throw StackException("Trying to add two elements from a stack of one element");
	std::list<IOperand*>::iterator it0 = std::next(_operands.begin(), 0);
	std::list<IOperand*>::iterator it1 = std::next(_operands.begin(), 1);
	_operands.erase(it0);
	_operands.erase(it1);
	_operands.push_front(*(*it0) + *(*it1));
}

void	Parser::sub(std::vector<std::string> const & s)
{
	(void)s;
	if (_operands.empty())
		throw StackException("Trying to sub elements from an empty stack");
	if (_operands.size() < 2)
		throw StackException("Trying to sub two elements from a stack of one element");
	std::list<IOperand*>::iterator it0 = std::next(_operands.begin(), 0);
	std::list<IOperand*>::iterator it1 = std::next(_operands.begin(), 1);
	_operands.erase(it0);
	_operands.erase(it1);
	_operands.push_front(*(*it0) - *(*it1));
}

void	Parser::mul(std::vector<std::string> const & s)
{
	(void)s;
		if (_operands.empty())
		throw StackException("Trying to mul elements from an empty stack");
	if (_operands.size() < 2)
		throw StackException("Trying to mul two elements from a stack of one element");
	std::list<IOperand*>::iterator it0 = std::next(_operands.begin(), 0);
	std::list<IOperand*>::iterator it1 = std::next(_operands.begin(), 1);
	_operands.erase(it0);
	_operands.erase(it1);
	_operands.push_front(*(*it0) * *(*it1));
}

void	Parser::div(std::vector<std::string> const & s)
{
	(void)s;
	if (_operands.empty())
		throw StackException("Trying to div elements from an empty stack");
	if (_operands.size() < 2)
		throw StackException("Trying to div two elements from a stack of one element");
	std::list<IOperand*>::iterator it0 = std::next(_operands.begin(), 0);
	std::list<IOperand*>::iterator it1 = std::next(_operands.begin(), 1);
	_operands.erase(it0);
	_operands.erase(it1);
	_operands.push_front(*(*it0) / *(*it1));
}

void	Parser::mod(std::vector<std::string> const & s)
{
	(void)s;
	if (_operands.empty())
		throw StackException("Trying to mod elements from an empty stack");
	if (_operands.size() < 2)
		throw StackException("Trying to mod two elements from a stack of one element");
	std::list<IOperand*>::iterator it0 = std::next(_operands.begin(), 0);
	std::list<IOperand*>::iterator it1 = std::next(_operands.begin(), 1);
	_operands.erase(it0);
	_operands.erase(it1);
	_operands.push_front(*(*it0) % *(*it1));
}

void	Parser::print(std::vector<std::string> const & s)
{
	(void)s;
	if (_operands.empty())
		throw StackException("Trying to print element from an empty stack");
	if (_operands.front()->getType() != Int8)
		throw TypeException("Invalid type for print operation");
	char c;
	std::stringstream ss;
	ss << _operands.front()->toString();
	ss >> c;
	std::cout << c << std::endl;
}

void	Parser::exit(std::vector<std::string> const & s)
{
	(void)s;
	_operands.clear();
	throw ExitException("Exiting program normally");
}

IOperand*		Parser::createOperand(eOperandType type, const std::string & value) const
{
	IOperand*	(Parser::*creators[5])(const std::string &) const;

	creators[Int8]		= &Parser::createInt8;
	creators[Int16]	= &Parser::createInt16;
	creators[Int32]	= &Parser::createInt32;
	creators[Float]	= &Parser::createFloat;
	creators[Double]	= &Parser::createDouble;

	int					vI;
	double				vD;
	std::stringstream	ss;
	ss << value;
	ss >> vI;
	ss >> vD;

	if (type > Double)
		throw TypeException("Invalid type");
	return ((this->*creators[type])(value));
	return (NULL);
}

IOperand*	Parser::createInt8(const std::string & value) const
{
	short					v;
	std::stringstream	ss;
	ss << value;
	ss >> v;

	return (new Operand<char>(Int8, v));
}

IOperand*	Parser::createInt16(const std::string & value) const
{
	int					v;
	std::stringstream	ss;
	ss << value;
	ss >> v;

	return (new Operand<short>(Int16, v));
}

IOperand*	Parser::createInt32(const std::string & value) const
{
	long					v;
	std::stringstream	ss;
	ss << value;
	ss >> v;

	return (new Operand<int>(Int32, v));
}

IOperand*	Parser::createFloat(const std::string & value) const
{
	float					v;
	std::stringstream	ss;
	ss << value;
	ss >> v;

	return (new Operand<float>(Float, v));
}

IOperand*	Parser::createDouble(const std::string & value) const
{
	double				v;
	std::stringstream	ss;
	ss << value;
	ss >> v;

	return (new Operand<double>(Double, v));
}
