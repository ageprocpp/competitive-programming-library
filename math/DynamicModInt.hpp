#pragma once
#include "../other/template.hpp"
#include "../other/type_traits.hpp"
class DynamicModInt : DynamicModInt__Base {
	static uint modulo;
	int value;

  public:
	static void setMod(uint mod) { modulo = mod; }
	constexpr DynamicModInt() : value(0) {}
	template <class T>
	DynamicModInt(T value = 0) : value(value) {
		this->value =
			(value < 0 ? -(-value % modulo) + modulo : lint(value)) % modulo;
	}

	inline DynamicModInt inv() const { return mypow(*this, modulo - 2); }
	inline constexpr operator int() const { return value; }
	inline DynamicModInt& operator+=(const DynamicModInt& x) {
		value = value + x.value;
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
		++*this;
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
		value = (lint)value * x.value % modulo;
		return *this;
	}
	inline DynamicModInt& operator/=(const DynamicModInt& rhs) {
		return *this *= rhs.inv();
	}
	template <class T>
	DynamicModInt operator+(const T& rhs) const {
		return DynamicModInt(*this) += rhs;
	}
	template <class T>
	DynamicModInt& operator+=(const T& rhs) {
		return operator+=(DynamicModInt(rhs));
	}
	template <class T>
	DynamicModInt operator-(const T& rhs) const {
		return DynamicModInt(*this) -= rhs;
	}
	template <class T>
	DynamicModInt& operator-=(const T& rhs) {
		return operator-=(DynamicModInt(rhs));
	}
	template <class T>
	DynamicModInt operator*(const T& rhs) const {
		return DynamicModInt(*this) *= rhs;
	}
	template <class T>
	DynamicModInt& operator*=(const T& rhs) {
		return operator*=(DynamicModInt(rhs));
	}
	template <class T>
	DynamicModInt operator/(const T& rhs) const {
		return DynamicModInt(*this) /= rhs;
	}
	template <class T>
	DynamicModInt& operator/=(const T& rhs) {
		return operator/=(DynamicModInt(rhs));
	}
	static int primitive_root() {
		int p = 0;
		static std::random_device rd;
		static std::mt19937 mt(rd());
		std::uniform_int_distribution<> uid(1, modulo - 1);

		// use naive factorize due to file size limit
		std::vector<int> vec;
		int tmp = modulo - 1;
		for (int i = 2; i * i <= tmp; i++) {
			if (tmp % i == 0) {
				vec.emplace_back(i);
				do {
					tmp /= i;
				} while (tmp % i == 0);
			}
		}
		if (tmp != 1) vec.emplace_back(tmp);

		vec.erase(std::unique(all(vec)), vec.end());
		while (true) {
			p = uid(mt);
			bool f = true;
			for (const auto& i : vec) {
				if (mypow(DynamicModInt(p), (modulo - 1) / i) == 1) {
					f = false;
					break;
				}
			}
			if (f) return p;
		}
	}
};
uint DynamicModInt::modulo = 1000000007;

/**
 * @title DynamicModInt
 */