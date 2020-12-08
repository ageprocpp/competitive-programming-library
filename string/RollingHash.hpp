#include "../algebraic/StaticModInt.hpp"
#include "../other/template.hpp"
template <unsigned int mod>
class RollingHash {
	using M = StaticModInt<mod>;
	std::string s;
	int n, base;
	std::vector<M> has, power;

  public:
	RollingHash(const std::string& s, int b) {
		init(s, b);
	}
	void init(const std::string& s, int b) {
		n = s.size();
		has.resize(n);
		power.resize(n);
		base = b;
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
	operator M() const {
		return has.back();
	}
	operator int() const {
		return has.back();
	}
	M query(int a, int b) const {
		return has[b - 1] - power[b - a] * (!a ? M(0) : has[a - 1]);
	}
	M operator+(const std::string& t) const {
		RollingHash tmp(t, base);
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