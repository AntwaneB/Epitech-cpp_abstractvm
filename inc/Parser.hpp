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

	void	push(std::vector<std::string> const &);
	void	pop(std::vector<std::string> const &);
	void	dump(std::vector<std::string> const &);
	void	assert(std::vector<std::string> const &);
	void	add(std::vector<std::string> const &);
	void	sub(std::vector<std::string> const &);
	void	mul(std::vector<std::string> const &);
	void	div(std::vector<std::string> const &);
	void	mod(std::vector<std::string> const &);
	void	print(std::vector<std::string> const &);
	void	exit(std::vector<std::string> const &);

	static std::vector<std::string>	strtovec(std::string const &, std::string const &);
	static bool								inStr(char const c, std::string const & str);

private:
	std::stack<IOperand*>	_operands;
};

#endif	/* PARSER_HPP */

