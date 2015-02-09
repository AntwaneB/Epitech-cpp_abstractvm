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
#include <iostream>
#include <string>
#include "TypeException.hpp"
#include "IOperand.hpp"

template<typename T>
class Operand : public IOperand
{
public:
	Operand(T value);
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
	std::string		_raw;
	T					_val;
	eOperandType	_type;
};

template <typename T>
Operand<T>::Operand(T value)
	: _val(value)
{
}

template <typename T>
Operand<T>::~Operand()
{
}

template <typename T>
std::string const & Operand<T>::toString()
{
	std::stringstream ss;
	ss << _val;
	_raw = ss.str();
	return (_raw);
}

template <typename T>
int Operand<T>::getPrecision()
{
	return (_type);
}

template <typename T>
eOperandType Operand<T>::getType()
{
	return (_type);
}

template <typename T>
IOperand*	Operand<T>::operator+(const IOperand & rhs)
{
	(void)rhs;
	return (NULL);
}

template <typename T>
IOperand*	Operand<T>::operator-(const IOperand & rhs)
{
	(void)rhs;
	return (NULL);

}

template <typename T>
IOperand*	Operand<T>::operator*(const IOperand & rhs)
{
	(void)rhs;
	return (NULL);

}

template <typename T>
IOperand*	Operand<T>::operator/(const IOperand & rhs)
{
	(void)rhs;
	return (NULL);

}

template <typename T>
IOperand*	Operand<T>::operator%(const IOperand & rhs)
{
	(void)rhs;
	return (NULL);

}

template <typename T>
IOperand*		Operand<T>::createOperand(const std::string & value)
{
	IOperand*	(Operand::*creators[5])(const std::string &);

	creators[Int8] = &Operand::createInt8;
	creators[Int16] = &Operand::createInt16;
	creators[Int32] = &Operand::createInt32;
	creators[Float] = &Operand::createFloat;
	creators[Double] = &Operand::createDouble;

	/* Getting values */
	long					vI;
	double				vD;
	std::stringstream	ss;
	ss = value;
	ss >> vI;
	ss >> vD;

	if (vD == vI && vI >= SHRT_MIN && vI <= SHRT_MAX)
		return (this->*creators[Int8](value));
	else if (vD == vI && vI >= INT_MIN && vI <= INT_MAX)
		return (this->*creators[Int16](value));
	else if (vD == vI && vI >= LONG_MIN && vI <= LONG_MAX)
		return (this->*creators[Int32](value));
	else if (vD != vI && value.size() - value.find(".") + 1 <= 6)
		return (this->*creators[Float](value));
	else if (vD != vI && value.size() - value.find(".") + 1 > 6)
		return (this->*creators[Double](value));
	else
		throw TypeException("Invalid type");
	return (NULL);
}

template <typename T>
IOperand*	Operand<T>::createInt8(const std::string & value)
{
	(void)value;
	return (NULL);
}

template <typename T>
IOperand*	Operand<T>::createInt16(const std::string & value)
{
	(void)value;
	return (NULL);

}

template <typename T>
IOperand*	Operand<T>::createInt32(const std::string & value)
{
	(void)value;
	return (NULL);

}

template <typename T>
IOperand*	Operand<T>::createFloat(const std::string & value)
{
	(void)value;
	return (NULL);

}

template <typename T>
IOperand*	Operand<T>::createDouble(const std::string & value)
{
	(void)value;
	return (NULL);

}


#endif	/* OPERAND_HPP */

