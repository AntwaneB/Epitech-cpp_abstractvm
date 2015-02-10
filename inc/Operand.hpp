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
#include "Exception.hpp"
#include "IOperand.hpp"

template<typename T>
class Operand : public IOperand
{
public:
	Operand(eOperandType type, T value);
	virtual ~Operand();

	virtual std::string const &	toString() const;

	virtual int				getPrecision() const;
	virtual eOperandType	getType() const;
	T							getValue();

	virtual IOperand*	operator+(const IOperand & rhs) const;
	virtual IOperand*	operator-(const IOperand & rhs) const;
	virtual IOperand*	operator*(const IOperand & rhs) const;
	virtual IOperand*	operator/(const IOperand & rhs) const;
	virtual IOperand*	operator%(const IOperand & rhs) const;

private:
	std::string		_raw;
	T					_val;
	eOperandType	_type;
};

template <typename T>
Operand<T>::Operand(eOperandType type, T value)
	:  _val(value), _type(type)
{
	std::stringstream ss;
	ss << _val;
	_raw = ss.str();
}

template <typename T>
Operand<T>::~Operand()
{
}

template <typename T>
std::string const & Operand<T>::toString() const
{
	return (_raw);
}

template <typename T>
int Operand<T>::getPrecision() const
{
	return (_type);
}

template <typename T>
eOperandType Operand<T>::getType() const
{
	return (_type);
}

template <typename T>
IOperand*	Operand<T>::operator+(const IOperand & rhs) const
{
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	if (type == Double || type == Float)
	{
		double v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (type == Double)
			return (new Operand<double>(Double, v + _val));
		else if (type == Float)
			return (new Operand<float>(Float, v + _val));
	}
	else
	{
		long v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (type == Int32 || (type < Int32 && (v + _val > INT_MAX || v + _val < INT_MIN)))
			return (new Operand<long>(Int32, v + _val));
		else if (type == Int16 || (type < Int16 && (v + _val > SHRT_MAX || v + _val < SHRT_MIN)))
			return (new Operand<int>(Int16, v + _val));
		else if (type == Int8)
			return (new Operand<short>(Int8, v + _val));
		else
			throw TypeException("Invalid operand type");
	}

	return (NULL);
}

template <typename T>
IOperand*	Operand<T>::operator-(const IOperand & rhs) const
{
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	if (type == Double || type == Float)
	{
		double v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (type == Double)
			return (new Operand<double>(Double, v - _val));
		else if (type == Float)
			return (new Operand<float>(Float, v - _val));
	}
	else
	{
		long v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (type == Int32 || (type < Int32 && (v - _val > INT_MAX || v - _val < INT_MIN)))
			return (new Operand<long>(Int32, v - _val));
		else if (type == Int16 || (type < Int16 && (v - _val > SHRT_MAX || v - _val < SHRT_MIN)))
			return (new Operand<int>(Int16, v - _val));
		else if (type == Int8)
			return (new Operand<short>(Int8, v - _val));
		else
			throw TypeException("Invalid operand type");
	}

	return (NULL);
}

template <typename T>
IOperand*	Operand<T>::operator*(const IOperand & rhs) const
{
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	if (type == Double || type == Float)
	{
		double v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (type == Double)
			return (new Operand<double>(Double, v * _val));
		else if (type == Float)
			return (new Operand<float>(Float, v * _val));
	}
	else
	{
		long v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (type == Int32 || (type < Int32 && (v * _val > INT_MAX || v * _val < INT_MIN)))
			return (new Operand<long>(Int32, v * _val));
		else if (type == Int16 || (type < Int16 && (v * _val > SHRT_MAX || v * _val < SHRT_MIN)))
			return (new Operand<int>(Int16, v * _val));
		else if (type == Int8)
			return (new Operand<short>(Int8, v * _val));
		else
			throw TypeException("Invalid operand type");
	}

	return (NULL);
}

template <typename T>
IOperand*	Operand<T>::operator/(const IOperand & rhs) const
{
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	if (type == Double || type == Float)
	{
		double v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (type == Double)
			return (new Operand<double>(Double, v / _val));
		else if (type == Float)
			return (new Operand<float>(Float, v / _val));
	}
	else
	{
		long v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (v == 0)
			throw TypeException("Division by zero");
		if (type == Int32)
			return (new Operand<long>(Int32, v / _val));
		else if (type == Int16)
			return (new Operand<int>(Int16, v / _val));
		else if (type == Int8)
			return (new Operand<short>(Int8, v / _val));
		else
			throw TypeException("Invalid operand type");
	}

	return (NULL);
}

template <typename T>
IOperand*	Operand<T>::operator%(const IOperand & rhs) const
{
	eOperandType	type = rhs.getType() > _type ? rhs.getType() : _type;

	if (type == Double || type == Float)
	{
		throw TypeException("Modulo on floating point numbers");
	}
	else
	{
		long v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (v == 0)
			throw TypeException("Modulo by zero");
		if (type == Int32)
			return (new Operand<long>(Int32, static_cast<long>(v) % static_cast<long>(_val)));
		else if (type == Int16)
			return (new Operand<int>(Int16, static_cast<int>(v) % static_cast<int>(_val)));
		else if (type == Int8)
			return (new Operand<short>(Int8, static_cast<int>(v) % static_cast<short>(_val)));
		else
			throw TypeException("Invalid operand type");
	}

	return (NULL);
}

#endif	/* OPERAND_HPP */

