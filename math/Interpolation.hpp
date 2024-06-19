#pragma once
#include "../basic/template.hpp"
template <class T>
T arithmetic_interpolation(const T& a, const T& d, const std::vector<T>& y, const T& t) {
	const int n = y.size() - 1;
	T res = 0, ft = 1;
	rep(i, n + 1) ft *= t - (a + d * i);
	T f = 1;
	REP(i, n) f *= -d * i;
	res += y[0] * ft / (t - a) / f;
	rep(i, n) {
		f *= i + 1;
		f /= i - n;
		res += y[i + 1] * ft / (t - (a + d * (i + 1))) / f;
	}
	return res;
}