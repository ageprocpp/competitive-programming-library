#pragma once
#include "../other/template.hpp"
#include "../algebraic/StaticModInt.hpp"
template <unsigned int mod, unsigned int base>
class RollingHash {
	using M = StaticModInt<mod>;
	std::string s;
	int n;
	std::vector<M> has, power;

  public:
	RollingHash() {}
	RollingHash(const std::string& s) { init(s); }
	void init(const std::string& s) {
		n = s.size();
		has.resize(n);
		power.resize(n);
		this->s = s;
		rep(i, n) {
			has[i] = s[i];
			if (i) {
				has[i] += has[i - 1] * base;
				power[i] = power[i - 1] * base;
			} else
				power[i] = 1;
		}
	}
	operator M() const { return has.back(); }
	M substr(int l, size_t sz) const {
		return has[l + sz - 1] - power[sz] * (!l ? M(0) : has[l - 1]);
	}
	M operator+(const std::string& t) const {
		RollingHash tmp(t);
		if (n == 0)
			return tmp;
		else
			return has.back() * mypow(M(base), t.size()) + tmp;
	}
	RollingHash& operator+=(const std::string& t) {
		if (n == 0) {
			*this = RollingHash(t, base);
		} else {
			s += t;
			has.resize(n + t.size());
			power.resize(n + t.size());
			for (int i = n; i < n + t.size(); i++) {
				has[i] = t[i - n];
				has[i] += has[i - 1] * base;
				power[i] = power[i - 1] * base;
			}
			n += t.size();
		}
		return *this;
	}
};