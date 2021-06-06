#pragma once
#include "../other/template.hpp"
#include "NumberTheoreticTransform.hpp"
#include "StaticModInt.hpp"
template <typename T>
class Polynomial {
	std::vector<T> vec;

  public:
	Polynomial() : vec() {}
	Polynomial(const std::vector<T>& v) : vec(v) {}
	Polynomial operator*(const Polynomial& p) {
		Polynomial res(std::vector<T>(vec.size() + p.vec.size() - 1));
		rep(i, vec.size()) {
			rep(j, p.vec.size()) res.vec[i + j] += vec[i] * p.vec[j];
		}
		return res;
	}
	Polynomial& operator*=(const Polynomial& p) {
		auto res = NumberTheoreticTransform::convolution_plain(vec, p.vec);
		std::vector<T> nvec(vec.size() + p.vec.size() - 1);
		rep(i, vec.size()) {
			rep(j, p.vec.size()) nvec[i + j] = vec[i] * p.vec[j];
		}
		vec = std::move(nvec);
		return *this;
	}
};