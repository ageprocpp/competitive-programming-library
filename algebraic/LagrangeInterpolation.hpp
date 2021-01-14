#pragma once
#include "../other/template.hpp"
#include "DynamicModInt.hpp"
DynamicModInt arithmetic_lagrange_interpolation(
	const DynamicModInt& a, const DynamicModInt& d,
	const std::vector<DynamicModInt>& y, const DynamicModInt& t) {
	const int n = y.size() - 1;
	DynamicModInt res = 0, ft = 1;
	rep(i, n + 1) ft *= t - (a + d * i);
	DynamicModInt f = 1;
	REP(i, n) f *= -d * i;
	res += y[0] / f * ft / (t - a);
	rep(i, n) {
		f *= i + 1;
		f /= i - n;
		res += y[i + 1] / f * ft / (t - (a + d * (i + 1)));
	}
	return res;
}

/**
 * Lagrange Interpolation
 */