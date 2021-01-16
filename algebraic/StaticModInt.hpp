#pragma once
#include "../other/template.hpp"
template <uint modulo>
class StaticModInt {
	std::conditional_t<(modulo > INT_MAX >> 1), lint, int> value;

  public:
	static constexpr uint mod_value = modulo;
	constexpr StaticModInt() : value(0) {}
	template <class T, std::enable_if_t<!std::is_convertible_v<T, StaticModInt>,
										std::nullptr_t> = nullptr>
	constexpr StaticModInt(T value = 0) : value(value) {
		this->value =
			(value < 0 ? -(-value % modulo) + modulo : lint(value)) % modulo;
	}
	inline constexpr StaticModInt inv() const {
		return mypow(*this, modulo - 2);
	}
	inline constexpr operator int() const { return value; }
	inline constexpr StaticModInt& operator+=(const StaticModInt& x) {
		value = value + x.value;
		if (value >= modulo) value -= modulo;
		return *this;
	}
	inline constexpr StaticModInt& operator++() {
		if (value == modulo - 1)
			value = 0;
		else
			value++;
		return *this;
	}
	inline constexpr StaticModInt operator++(int) {
		StaticModInt res = *this;
		++*this;
		return res;
	}
	inline constexpr StaticModInt operator-() const {
		return StaticModInt(0) -= *this;
	}
	inline constexpr StaticModInt& operator-=(const StaticModInt& x) {
		value -= x.value;
		if (value < 0) value += modulo;
		return *this;
	}
	inline constexpr StaticModInt& operator--() {
		if (value == 0)
			value = modulo - 1;
		else
			value--;
		return *this;
	}
	inline constexpr StaticModInt operator--(int) {
		StaticModInt res = *this;
		--*this;
		return res;
	}
	inline constexpr StaticModInt& operator*=(const StaticModInt& x) {
		value = (lint)value * x.value % modulo;
		return *this;
	}
	inline constexpr StaticModInt& operator/=(const StaticModInt& rhs) {
		return *this *= rhs.inv();
	}
	template <class T>
	constexpr StaticModInt operator+(const T& rhs) const {
		return StaticModInt(*this) += rhs;
	}
	template <class T>
	constexpr StaticModInt& operator+=(const T& rhs) {
		return operator+=(StaticModInt(rhs));
	}
	template <class T>
	constexpr StaticModInt operator-(const T& rhs) const {
		return StaticModInt(*this) -= rhs;
	}
	template <class T>
	constexpr StaticModInt& operator-=(const T& rhs) {
		return operator-=(StaticModInt(rhs));
	}
	template <class T>
	constexpr StaticModInt operator*(const T& rhs) const {
		return StaticModInt(*this) *= rhs;
	}
	template <class T>
	constexpr StaticModInt& operator*=(const T& rhs) {
		return operator*=(StaticModInt(rhs));
	}
	template <class T>
	constexpr StaticModInt operator/(const T& rhs) const {
		return StaticModInt(*this) /= rhs;
	}
	template <class T>
	constexpr StaticModInt& operator/=(const T& rhs) {
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

/**
 * @title StaticModInt
 */