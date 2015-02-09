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
Operand<T>::Operand(eOperandType type, T value)
	: _type(type), _val(value)
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
			return (new Operand<double>(v + _val));
		else if (type == Float)
			return (new Operand<float>(v + _val));
		else if (type == Int32 || (type < Int32 && (v + _val > INT_MAX || v + _val < INT_MIN)))
			return (new Operand<long>(v + _val));
		else if (type == Int16 || (type < Int16 && (v + _val > SHRT_MAX || v + _val < SHRT_MIN)))
			return (new Operand<int>(v + _val));
		else if (type == Int8)
			return (new Operand<short>(v + _val));
		else
			throw TypeException("Invalid operand type");
	}
	else
	{
		long v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (type == Double)
			return (new Operand<double>(v + _val));
		else if (type == Float)
			return (new Operand<float>(v + _val));
		else if (type == Int32 || (type < Int32 && (v + _val > INT_MAX || v + _val < INT_MIN)))
			return (new Operand<long>(v + _val));
		else if (type == Int16 || (type < Int16 && (v + _val > SHRT_MAX || v + _val < SHRT_MIN)))
			return (new Operand<int>(v + _val));
		else if (type == Int8)
			return (new Operand<short>(v + _val));
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
			return (new Operand<double>(v - _val));
		else if (type == Float)
			return (new Operand<float>(v - _val));
		else if (type == Int32 || (type < Int32 && (v - _val > INT_MAX || v - _val < INT_MIN)))
			return (new Operand<long>(v - _val));
		else if (type == Int16 || (type < Int16 && (v - _val > SHRT_MAX || v - _val < SHRT_MIN)))
			return (new Operand<int>(v - _val));
		else if (type == Int8)
			return (new Operand<short>(v - _val));
		else
			throw TypeException("Invalid operand type");
	}
	else
	{
		long v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (type == Double)
			return (new Operand<double>(v - _val));
		else if (type == Float)
			return (new Operand<float>(v - _val));
		else if (type == Int32 || (type < Int32 && (v - _val > INT_MAX || v - _val < INT_MIN)))
			return (new Operand<long>(v - _val));
		else if (type == Int16 || (type < Int16 && (v - _val > SHRT_MAX || v - _val < SHRT_MIN)))
			return (new Operand<int>(v - _val));
		else if (type == Int8)
			return (new Operand<short>(v - _val));
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
			return (new Operand<double>(v * _val));
		else if (type == Float)
			return (new Operand<float>(v * _val));
		else if (type == Int32 || (type < Int32 && (v * _val > INT_MAX || v * _val < INT_MIN)))
			return (new Operand<long>(v * _val));
		else if (type == Int16 || (type < Int16 && (v * _val > SHRT_MAX || v * _val < SHRT_MIN)))
			return (new Operand<int>(v * _val));
		else if (type == Int8)
			return (new Operand<short>(v * _val));
		else
			throw TypeException("Invalid operand type");
	}
	else
	{
		long v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (type == Double)
			return (new Operand<double>(v * _val));
		else if (type == Float)
			return (new Operand<float>(v * _val));
		else if (type == Int32 || (type < Int32 && (v * _val > INT_MAX || v * _val < INT_MIN)))
			return (new Operand<long>(v * _val));
		else if (type == Int16 || (type < Int16 && (v * _val > SHRT_MAX || v * _val < SHRT_MIN)))
			return (new Operand<int>(v * _val));
		else if (type == Int8)
			return (new Operand<short>(v * _val));
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
			return (new Operand<double>(v / _val));
		else if (type == Float)
			return (new Operand<float>(v / _val));
		else if (type == Int32 || (type < Int32 && (v / _val > INT_MAX || v / _val < INT_MIN)))
			return (new Operand<long>(v / _val));
		else if (type == Int16 || (type < Int16 && (v / _val > SHRT_MAX || v / _val < SHRT_MIN)))
			return (new Operand<int>(v / _val));
		else if (type == Int8)
			return (new Operand<short>(v / _val));
		else
			throw TypeException("Invalid operand type");
	}
	else
	{
		long v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (type == Double)
			return (new Operand<double>(v / _val));
		else if (type == Float)
			return (new Operand<float>(v / _val));
		else if (type == Int32 || (type < Int32 && (v / _val > INT_MAX || v / _val < INT_MIN)))
			return (new Operand<long>(v / _val));
		else if (type == Int16 || (type < Int16 && (v / _val > SHRT_MAX || v / _val < SHRT_MIN)))
			return (new Operand<int>(v / _val));
		else if (type == Int8)
			return (new Operand<short>(v / _val));
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
		double v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (type == Double)
			return (new Operand<double>(v % _val));
		else if (type == Float)
			return (new Operand<float>(v % _val));
		else if (type == Int32 || (type < Int32 && (v % _val > INT_MAX || v % _val < INT_MIN)))
			return (new Operand<long>(v % _val));
		else if (type == Int16 || (type < Int16 && (v % _val > SHRT_MAX || v % _val < SHRT_MIN)))
			return (new Operand<int>(v % _val));
		else if (type == Int8)
			return (new Operand<short>(v % _val));
		else
			throw TypeException("Invalid operand type");
	}
	else
	{
		long v;
		std::stringstream	ss;
		ss << rhs.toString();
		ss >> v;

		if (type == Double)
			return (new Operand<double>(v % _val));
		else if (type == Float)
			return (new Operand<float>(v % _val));
		else if (type == Int32 || (type < Int32 && (v % _val > INT_MAX || v % _val < INT_MIN)))
			return (new Operand<long>(v % _val));
		else if (type == Int16 || (type < Int16 && (v % _val > SHRT_MAX || v % _val < SHRT_MIN)))
			return (new Operand<int>(v % _val));
		else if (type == Int8)
			return (new Operand<short>(v % _val));
		else
			throw TypeException("Invalid operand type");
	}

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

	long					vI;
	double				vD;
	std::stringstream	ss;
	ss << value;
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
	short					v;
	std::stringstream	ss;
	ss << value;
	ss >> v;

	return (new Operand<short>(Int8, v));
}

template <typename T>
IOperand*	Operand<T>::createInt16(const std::string & value)
{
	int					v;
	std::stringstream	ss;
	ss << value;
	ss >> v;

	return (new Operand<int>(Int16, v));
}

template <typename T>
IOperand*	Operand<T>::createInt32(const std::string & value)
{
	long					v;
	std::stringstream	ss;
	ss << value;
	ss >> v;

	return (new Operand<long>(Int32, v));
}

template <typename T>
IOperand*	Operand<T>::createFloat(const std::string & value)
{
	float					v;
	std::stringstream	ss;
	ss << value;
	ss >> v;

	return (new Operand<float>(Float, v));
}

template <typename T>
IOperand*	Operand<T>::createDouble(const std::string & value)
{
	double				v;
	std::stringstream	ss;
	ss << value;
	ss >> v;

	return (new Operand<double>(Double, v));
}


#endif	/* OPERAND_HPP */

