/*
 * File:   IOperand.hpp
 * Author: buchse_a
 *
 * Created on February 9, 2015, 11:35 AM
 */

#ifndef IOPERAND_HPP
#define	IOPERAND_HPP

#include <string>

enum eOperandType
{
	Int8,
	Int16,
	Int32,
	Float,
	Double
};

class IOperand
{
public:
	virtual std::string const & toString() const = 0;

	virtual int getPrecision() const = 0;
	virtual eOperandType getType() const = 0;

	virtual IOperand* operator+(const IOperand &rhs) const = 0;
	virtual IOperand* operator-(const IOperand &rhs) const = 0;
	virtual IOperand* operator*(const IOperand &rhs) const = 0;
	virtual IOperand* operator/(const IOperand &rhs) const = 0;
	virtual IOperand* operator%(const IOperand &rhs) const = 0;

	virtual ~IOperand() {}
};

#endif	/* IOPERAND_HPP */
