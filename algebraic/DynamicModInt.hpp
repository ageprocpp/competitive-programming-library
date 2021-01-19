#pragma once
#include "../other/template.hpp"
class DynamicModInt : DynamicModInt__Base {
	static uint modulo;

	int value;
	static constexpr void setMod(uint mod) { modulo = mod; }
	constexpr DynamicModInt() : value(0) {}
	template <class T>
	constexpr DynamicModInt(T value = 0) : value(value) {
		this->value =
			(value < 0 ? -(-value % modulo) + modulo : lint(value)) % modulo;
	}

	inline constexpr DynamicModInt inv() const {
		return mypow(*this, modulo - 2);
	}
	inline constexpr operator int() const { return value; }
	inline constexpr DynamicModInt& operator+=(const DynamicModInt& x) {
		value = value + x.value;
		if (value >= modulo) value -= modulo;
		return *this;
	}
	inline constexpr DynamicModInt& operator++() {
		if (value == modulo - 1)
			value = 0;
		else
			value++;
		return *this;
	}
	inline constexpr DynamicModInt operator++(int) {
		DynamicModInt res = *this;
		++*this;
		return res;
	}
	inline constexpr DynamicModInt operator-() const {
		return DynamicModInt(0) -= *this;
	}
	inline constexpr DynamicModInt& operator-=(const DynamicModInt& x) {
		value -= x.value;
		if (value < 0) value += modulo;
		return *this;
	}
	inline constexpr DynamicModInt& operator--() {
		if (value == 0)
			value = modulo - 1;
		else
			value--;
		return *this;
	}
	inline constexpr DynamicModInt operator--(int) {
		DynamicModInt res = *this;
		--*this;
		return res;
	}
	inline constexpr DynamicModInt& operator*=(const DynamicModInt& x) {
		value = (lint)value * x.value % modulo;
		return *this;
	}
	inline constexpr DynamicModInt& operator/=(const DynamicModInt& rhs) {
		return *this *= rhs.inv();
	}
	template <class T>
	constexpr DynamicModInt operator+(const T& rhs) const {
		return DynamicModInt(*this) += rhs;
	}
	template <class T>
	constexpr DynamicModInt& operator+=(const T& rhs) {
		return operator+=(DynamicModInt(rhs));
	}
	template <class T>
	constexpr DynamicModInt operator-(const T& rhs) const {
		return DynamicModInt(*this) -= rhs;
	}
	template <class T>
	constexpr DynamicModInt& operator-=(const T& rhs) {
		return operator-=(DynamicModInt(rhs));
	}
	template <class T>
	constexpr DynamicModInt operator*(const T& rhs) const {
		return DynamicModInt(*this) *= rhs;
	}
	template <class T>
	constexpr DynamicModInt& operator*=(const T& rhs) {
		return operator*=(DynamicModInt(rhs));
	}
	template <class T>
	constexpr DynamicModInt operator/(const T& rhs) const {
		return DynamicModInt(*this) /= rhs;
	}
	template <class T>
	constexpr DynamicModInt& operator/=(const T& rhs) {
		return operator/=(DynamicModInt(rhs));
	}
};