#include "../other/template.hpp"
#include "../algebraic/ModInt.hpp"
class RollingHash {
	std::string s;
	int n,base;
	std::vector<ModInt> has, power;
public:
	RollingHash(std::string s, int b) : n(s.size()), base(b) { init(s, b); }
	void init(std::string s, int b) {
		n = s.size();
		has.resize(n);
		power.resize(n);
		base = ModInt(b);
		this->s = s;
		rep(i, n) {
			has[i] = ModInt(s[i]);
			if (i) {
				has[i] += has[i - 1]*base;
				power[i] = power[i - 1] * base;
			}
			else power[i] = 1;
		}
	}
	operator int() const {
		return has.back();
	}
	ModInt query(int a, int b)const{
		return has[b - 1] - power[b - a] * (!a ? ModInt(0) : has[a - 1]);
	}
	RollingHash& operator+=(std::string t) {
		s += t;
		has.resize(n + t.size());
		power.resize(n + t.size());
		for (int i = n; i < n + t.size(); i++) {
			has[i] = ModInt(t[i] * base);
			has[i] += has[i - 1]*base;
			power[i] = power[i - 1] * base;
		}
		n += t.size();
		return *this;
	}
};