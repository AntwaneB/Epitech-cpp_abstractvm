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
			/*
			std::cout << "'" << content[i] << "' line :" << std::endl;
			for (size_t j = 0; j < parts.size(); j++)
				std::cout << j << ". " << parts[j] << std::endl;
			std::cout << std::endl;
			*/
			if (operations.find(parts[0]) != operations.end())
				(this->*(operations.find(parts[0])->second))(parts);
			else
				throw ParserException("Invalid operations");
		}
	}
	_operands.clear();
	throw ParserException("Exiting programm, missing exit instruction");
}

void	Parser::push(std::vector<std::string> const & s)
{
	(void)s;
}

void	Parser::pop(std::vector<std::string> const & s)
{
	(void)s;
	if (_operands.empty())
		throw StackException("Trying to remove an element from a empty stack");
	_operands.pop_front();
}

void	Parser::dump(std::vector<std::string> const & s)
{
	(void)s;
	for (std::list<std::string>::iterator it = Parser::_operands.begin(); it != Parser::_operands.end(); ++it)
	{
    	std::cout << (*it) << std::endl;
	}
}

void	Parser::assert(std::vector<std::string> const & s)
{
	(void)s;
	if (_operands.empty())
		throw StackException("Trying to assert an element from a empty stack");
	if (s.back() != _operands.front())
		throw ParserException("The value at the top of the stack is not equal to the one passed
as parameter");
}

void	Parser::add(std::vector<std::string> const & s)
{
	(void)s;
	if (_operands.empty())
		throw StackException("Trying to add elements from a empty stack");
	if (_operands.size() < 2)
		throw StackException("Trying to add two elements from a stack of one element");
	std::list<IOperand*>::iterator it0 = std::next(_operands.begin(), 0);
	std::list<IOperand*>::iterator it1 = std::next(_operands.begin(), 1);
	_operands.erase(0);
	_operands.erase(1);
	_operands.push_front(it0 + it1);
}

void	Parser::sub(std::vector<std::string> const & s)
{
	(void)s;

}

void	Parser::mul(std::vector<std::string> const & s)
{
	(void)s;

}

void	Parser::div(std::vector<std::string> const & s)
{
	(void)s;

}

void	Parser::mod(std::vector<std::string> const & s)
{
	(void)s;

}

void	Parser::print(std::vector<std::string> const & s)
{
	(void)s;

}

void	Parser::exit(std::vector<std::string> const & s)
{
	(void)s;
	_operands.clear();
	throw ExitException("Exiting program normally");
}
