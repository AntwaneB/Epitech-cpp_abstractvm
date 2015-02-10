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
#include <string.h>
#include "Parser.hpp"
#include "Operand.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

void	Parser::parse(std::vector<std::string> const & v)
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

	for(std::vector<std::string>::const_iterator i = v.begin(); i != v.end(); ++i)
	{
		char*	str = strdup(*i->c_str());
		std::vector<std::string>	parts;
		for (char* tok = strtok(str, " ()"); tok != NULL; tok = strtok(NULL, " ()"))
			parts.insert(std::string(tok));
		for (size_t j = 0; j < parts.size(); j++)
			std::cout << "==> " << parts[i] << std::endl;
		std::cout << *i << std::endl;
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
