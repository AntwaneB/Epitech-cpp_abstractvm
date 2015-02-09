/* 
 * File:   Parser.hpp
 * Author: buchse_a
 *
 * Created on February 9, 2015, 12:19 PM
 */

#ifndef PARSER_HPP
#define	PARSER_HPP

class Parser {
public:
	Parser();
	Parser(const Parser& orig);
	virtual ~Parser();
private:
	std::vector<std::string>	_content;
};

#endif	/* PARSER_HPP */

