#pragma once
#include "../other/template.hpp"
class DynamicModInt {
	lint value;

  public:
	static uint modulo;
	DynamicModInt() : value(0) {}
	template <typename T>
	DynamicModInt(T value = 0) : value(value) {
		if (value < 0) value = -(lint)(-value % modulo) + modulo;
		this->value = value % modulo;
	}
	static inline void setMod(const uint& mod) { modulo = mod; }
	inline DynamicModInt inv() const { return mypow(*this, modulo - 2); }
	inline operator int() const { return value; }
	inline DynamicModInt& operator+=(const DynamicModInt& x) {
		value += x.value;
		if (value >= modulo) value -= modulo;
		return *this;
	}
	inline DynamicModInt& operator++() {
		if (value == modulo - 1)
			value = 0;
		else
			value++;
		return *this;
	}
	inline DynamicModInt operator++(int) {
		DynamicModInt res = *this;
		--*this;
		return res;
	}
	inline DynamicModInt operator-() const { return DynamicModInt(0) -= *this; }
	inline DynamicModInt& operator-=(const DynamicModInt& x) {
		value -= x.value;
		if (value < 0) value += modulo;
		return *this;
	}
	inline DynamicModInt& operator--() {
		if (value == 0)
			value = modulo - 1;
		else
			value--;
		return *this;
	}
	inline DynamicModInt operator--(int) {
		DynamicModInt res = *this;
		--*this;
		return res;
	}
	inline DynamicModInt& operator*=(const DynamicModInt& x) {
		value = value * x.value % modulo;
		return *this;
	}
	inline DynamicModInt& operator/=(const DynamicModInt& rhs) {
		return *this *= rhs.inv();
	}
	template <typename T>
	DynamicModInt operator+(const T& rhs) const {
		return DynamicModInt(*this) += rhs;
	}
	template <typename T>
	DynamicModInt& operator+=(const T& rhs) {
		return operator+=(DynamicModInt(rhs));
	}
	template <typename T>
	DynamicModInt operator-(const T& rhs) const {
		return DynamicModInt(*this) -= rhs;
	}
	template <typename T>
	DynamicModInt& operator-=(const T& rhs) {
		return operator-=(DynamicModInt(rhs));
	}
	template <typename T>
	DynamicModInt operator*(const T& rhs) const {
		return DynamicModInt(*this) *= rhs;
	}
	template <typename T>
	DynamicModInt& operator*=(const T& rhs) {
		return operator*=(DynamicModInt(rhs));
	}
	template <typename T>
	DynamicModInt operator/(const T& rhs) const {
		return DynamicModInt(*this) /= rhs;
	}
	template <typename T>
	DynamicModInt& operator/=(const T& rhs) {
		return operator/=(DynamicModInt(rhs));
	}
};
uint DynamicModInt::modulo = 1000000007;
std::istream& operator>>(std::istream& ist, DynamicModInt& x) {
	lint a;
	ist >> a;
	x = a;
	return ist;
}