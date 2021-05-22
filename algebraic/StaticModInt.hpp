#pragma once
#include "../other/template.hpp"
#include "../other/type_traits.hpp"
template <uint modulo>
class StaticModInt : StaticModInt__Base {
	std::conditional_t<(modulo > INT_MAX >> 1), lint, int> value;
	static constexpr int inv1000000007[] = {0,		   1,		  500000004,
											333333336, 250000002, 400000003,
											166666668, 142857144, 125000001,
											111111112, 700000005},
						 inv998244353[] = {0,		  1,		 499122177,
										   332748118, 748683265, 598946612,
										   166374059, 855638017, 873463809,
										   443664157, 299473306};

  public:
	static constexpr uint mod_value = modulo;

	constexpr StaticModInt() : value(0) {}
	template <class T,
			  std::enable_if_t<!std::is_convertible<T, StaticModInt>::value,
							   std::nullptr_t> = nullptr>
	constexpr StaticModInt(T value = 0) : value(value) {
		this->value %= modulo;
		if (this->value < 0) this->value += modulo;
	}
	inline constexpr StaticModInt inv() const {
		if constexpr (modulo == 1000000007) {
			if (*this <= 10) return inv1000000007[*this];
		} else if constexpr (modulo == 998244353) {
			if (*this <= 10) return inv998244353[*this];
		}
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
		value = (ulint)value * x.value % modulo;
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
	static int primitive_root() {
		static int p = 0;
		static std::random_device rd;
		static std::mt19937 mt(rd());
		static std::uniform_int_distribution<> uid(1, modulo - 1);
		if (p) return 0;

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

		while (true) {
			p = uid(mt);
			bool f = true;
			for (const auto& i : vec) {
				if (mypow(StaticModInt(p), (modulo - 1) / i) == 1) {
					f = false;
					break;
				}
			}
			if (f) return p;
		}
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