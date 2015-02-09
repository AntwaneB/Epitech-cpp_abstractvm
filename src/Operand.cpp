/*
 * File:   Operand.cpp
 * Author: buchse_a
 *
 * Created on February 9, 2015, 12:05 PM
 */

#include <climits>
#include <sstream>
#include "Operand.hpp"

Operand::Operand()
{
}

Operand::~Operand()
{
}

std::string const & Operand::toString()
{
	stringstream ss;
	ss << _val;
	return (ss.str());
}

int Operand::getPrecision()
{
	return (_type);
}

eOperandType Operand::getType()
{
	return (_type);
}

IOperand*	Operand::operator+(const IOperand & rhs)
{

}

IOperand*	Operand::operator-(const IOperand & rhs)
{

}

IOperand*	Operand::operator*(const IOperand & rhs)
{

}

IOperand*	Operand::operator/(const IOperand & rhs)
{

}

IOperand*	Operand::operator%(const IOperand & rhs)
{

}

IOperand*		Operand::createOperand(const std::string & value)
{
	IOperand*	(Operand::*creators[5])(const std::string &);

	creators[Int8] = &Operand::createInt8;
	creators[Int16] = &Operand::createInt16;
	creators[Int32] = &Operand::createInt32;
	creators[Float] = &Operand::createFloat;
	creators[Double] = &Operand::createDouble;

	/* Getting values */
	long				vI;
	double			vD;
	stringstream	ss;
	ss = value;
	ss >> vI;
	ss >> vD;

	if (vD == vI && vI >= SHRT_MIN && vI <= SHRT_MAX)
		return (this->createInt8(value));
	else if (vD == vI && vI >= INT_MIN && vI <= INT_MAX)
		return (this->createInt16(value));
	else if (vD == vI && vI >= LONG_MIN && vI <= LONG_MAX)
		return (this->createInt32(value));
	else if (vD != vI && vD >= FLT_MIN && vD <= FLT_MAX)
		return (this->createFloat(value));
	else if (vD != vI && vD >= DBL_MIN && vD <= DBL_MAX)
		return (this->createDouble(value));
	else
		throw TypeException("Invalid type");
}

IOperand*	Operand::createInt8(const std::string & value)
{

}

IOperand*	Operand::createInt16(const std::string & value)
{

}

IOperand*	Operand::createInt32(const std::string & value)
{

}

IOperand*	Operand::createFloat(const std::string & value)
{

}

IOperand*	Operand::createDouble(const std::string & value)
{

}
