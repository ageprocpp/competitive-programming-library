#pragma once
#include "../other/template.hpp"
#include "DynamicModInt.hpp"
template <uint modulo>
class StaticModInt {
	lint value;

  public:
	static constexpr uint mod_value = modulo;
	StaticModInt() : value(0) {}
	template <typename T>
	StaticModInt(T value = 0) : value(value) {
		this->value =
			(value < 0 ? -(-value % modulo) + modulo : value) % modulo;
	}
	inline StaticModInt inv() const { return mypow(*this, modulo - 2); }
	inline operator int() const { return value; }
	inline StaticModInt& operator+=(const StaticModInt& x) {
		value += x.value;
		if (value >= modulo) value -= modulo;
		return *this;
	}
	inline StaticModInt& operator++() {
		if (value == modulo - 1)
			value = 0;
		else
			value++;
		return *this;
	}
	inline StaticModInt operator++(int) {
		StaticModInt res = *this;
		++*this;
		return res;
	}
	inline StaticModInt operator-() const { return StaticModInt(0) -= *this; }
	inline StaticModInt& operator-=(const StaticModInt& x) {
		value -= x.value;
		if (value < 0) value += modulo;
		return *this;
	}
	inline StaticModInt& operator--() {
		if (value == 0)
			value = modulo - 1;
		else
			value--;
		return *this;
	}
	inline StaticModInt operator--(int) {
		StaticModInt res = *this;
		--*this;
		return res;
	}
	inline StaticModInt& operator*=(const StaticModInt& x) {
		value = value * x.value % modulo;
		return *this;
	}
	inline StaticModInt& operator/=(const StaticModInt& rhs) {
		return *this *= rhs.inv();
	}
	template <typename T>
	StaticModInt operator+(const T& rhs) const {
		return StaticModInt(*this) += rhs;
	}
	template <typename T>
	StaticModInt& operator+=(const T& rhs) {
		return operator+=(StaticModInt(rhs));
	}
	template <typename T>
	StaticModInt operator-(const T& rhs) const {
		return StaticModInt(*this) -= rhs;
	}
	template <typename T>
	StaticModInt& operator-=(const T& rhs) {
		return operator-=(StaticModInt(rhs));
	}
	template <typename T>
	StaticModInt operator*(const T& rhs) const {
		return StaticModInt(*this) *= rhs;
	}
	template <typename T>
	StaticModInt& operator*=(const T& rhs) {
		return operator*=(StaticModInt(rhs));
	}
	template <typename T>
	StaticModInt operator/(const T& rhs) const {
		return StaticModInt(*this) /= rhs;
	}
	template <typename T>
	StaticModInt& operator/=(const T& rhs) {
		return operator/=(StaticModInt(rhs));
	}
};
template <uint modulo>
std::istream& operator>>(std::istream& ist, StaticModInt<modulo>& x) {
	lint a;
	ist >> a;
	x = a;
	return ist;
}