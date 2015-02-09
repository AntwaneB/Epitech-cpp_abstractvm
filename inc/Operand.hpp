/*
 * File:   Operand.hpp
 * Author: buchse_a
 *
 * Created on February 9, 2015, 12:05 PM
 */

#ifndef OPERAND_HPP
#define	OPERAND_HPP

#include <climits>
#include <sstream>
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

template <typename T>
Operand::Operand()
{
}

template <typename T>
Operand::~Operand()
{
}

template <typename T>
std::string const & Operand::toString()
{
	stringstream ss;
	ss << _val;
	return (ss.str());
}

template <typename T>
int Operand::getPrecision()
{
	return (_type);
}

template <typename T>
eOperandType Operand::getType()
{
	return (_type);
}

template <typename T>
IOperand*	Operand::operator+(const IOperand & rhs)
{

}

template <typename T>
IOperand*	Operand::operator-(const IOperand & rhs)
{

}

template <typename T>
IOperand*	Operand::operator*(const IOperand & rhs)
{

}

template <typename T>
IOperand*	Operand::operator/(const IOperand & rhs)
{

}

template <typename T>
IOperand*	Operand::operator%(const IOperand & rhs)
{

}

template <typename T>
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

template <typename T>
IOperand*	Operand::createInt8(const std::string & value)
{

}

template <typename T>
IOperand*	Operand::createInt16(const std::string & value)
{

}

template <typename T>
IOperand*	Operand::createInt32(const std::string & value)
{

}

template <typename T>
IOperand*	Operand::createFloat(const std::string & value)
{

}

template <typename T>
IOperand*	Operand::createDouble(const std::string & value)
{

}


#endif	/* OPERAND_HPP */

