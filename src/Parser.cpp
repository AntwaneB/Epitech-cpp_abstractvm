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
	std::map<std::string, void (Parser::*)(std::string const &)>	operations;

	operations.insert(std::map<std::string, void (Parser::*)(std::string const &)>::value_type("push", &Parser::push));
	operations.insert(std::map<std::string, void (Parser::*)(std::string const &)>::value_type("pop", &Parser::pop));
	operations.insert(std::map<std::string, void (Parser::*)(std::string const &)>::value_type("dump", &Parser::dump));
	operations.insert(std::map<std::string, void (Parser::*)(std::string const &)>::value_type("assert", &Parser::assert));
	operations.insert(std::map<std::string, void (Parser::*)(std::string const &)>::value_type("add", &Parser::add));
	operations.insert(std::map<std::string, void (Parser::*)(std::string const &)>::value_type("sub", &Parser::sub));
	operations.insert(std::map<std::string, void (Parser::*)(std::string const &)>::value_type("mul", &Parser::mul));
	operations.insert(std::map<std::string, void (Parser::*)(std::string const &)>::value_type("div", &Parser::div));
	operations.insert(std::map<std::string, void (Parser::*)(std::string const &)>::value_type("mod", &Parser::pop));
	operations.insert(std::map<std::string, void (Parser::*)(std::string const &)>::value_type("print", &Parser::print));
	operations.insert(std::map<std::string, void (Parser::*)(std::string const &)>::value_type("exit", &Parser::exit));

	size_t	len = content.size();
	for (size_t i = 0; i < len; i++)
	{
		if (!content[i].empty())
		{
			std::vector<std::string>	parts = Parser::strtovec(content[i], " ();");
			std::cout << "'" << content[i] << "' line :" << std::endl;
			for (size_t j = 0; j < parts.size(); j++)
				std::cout << j << ". " << parts[j] << std::endl;
			std::cout << std::endl;
		}
	}
}

void	Parser::push(std::string const & s)
{
	(void)s;
}

void	Parser::pop(std::string const & s)
{
	(void)s;

}

void	Parser::dump(std::string const & s)
{
	(void)s;

}

void	Parser::assert(std::string const & s)
{
	(void)s;

}

void	Parser::add(std::string const & s)
{
	(void)s;

}

void	Parser::sub(std::string const & s)
{
	(void)s;

}

void	Parser::mul(std::string const & s)
{
	(void)s;

}

void	Parser::div(std::string const & s)
{
	(void)s;

}

void	Parser::mod(std::string const & s)
{
	(void)s;

}

void	Parser::print(std::string const & s)
{
	(void)s;

}

void	Parser::exit(std::string const & s)
{
	(void)s;

}
