/*
 * File:   Operand.hpp
 * Author: buchse_a
 *
 * Created on February 9, 2015, 12:05 PM
 */

#ifndef OPERAND_HPP
#define	OPERAND_HPP

#include <string>
#include "IOperand.hpp"

template<typename T>
class Operand : public IOperand
{
public:
	Operand();
	virtual ~Operand();

	virtual std::string const & toString();

	virtual int getPrecision();
	virtual eOperandType getType();

	virtual IOperand*	operator+(const IOperand & rhs);
	virtual IOperand*	operator-(const IOperand & rhs);
	virtual IOperand*	operator*(const IOperand & rhs);
	virtual IOperand*	operator/(const IOperand & rhs);
	virtual IOperand*	operator%(const IOperand & rhs);

	IOperand*	createOperand(const std::string & value);

private:
	IOperand*	createInt8(const std::string & value);
	IOperand*	createInt16(const std::string & value);
	IOperand*	createInt32(const std::string & value);
	IOperand*	createFloat(const std::string & value);
	IOperand*	createDouble(const std::string & value);

private:
	T					_val;
	eOperandType	_type;
};

#endif	/* OPERAND_HPP */

