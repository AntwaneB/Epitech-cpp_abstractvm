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
#include "IOperand.hpp"

class Parser {
public:
	static void	parse(std::vector<std::string>);
private:
	Parser();
	virtual ~Parser();
	std::stack<IOperand*>			_operands;
};

#endif	/* PARSER_HPP */

