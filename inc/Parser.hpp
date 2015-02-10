/*
 * File:   Parser.hpp
 * Author: buchse_a
 *
 * Created on February 9, 2015, 12:19 PM
 */

#ifndef PARSER_HPP
#define	PARSER_HPP

#include <vector>
#include <stack>
#include <string>
#include "IOperand.hpp"

class Parser
{
public:
	Parser();
	~Parser();
	static void	parse(std::vector<std::string> const &);

	void	push(std::string const &);
	void	pop(std::string const &);
	void	dump(std::string const &);
	void	assert(std::string const &);
	void	add(std::string const &);
	void	sub(std::string const &);
	void	mul(std::string const &);
	void	div(std::string const &);
	void	mod(std::string const &);
	void	print(std::string const &);
	void	exit(std::string const &);

	static std::vector<std::string>	strtovec(std::string const &, std::string const &);
	static bool								inStr(char const c, std::string const & str);

private:
	std::stack<IOperand*>	_operands;
};

#endif	/* PARSER_HPP */

