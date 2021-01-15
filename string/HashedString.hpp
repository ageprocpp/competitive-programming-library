#pragma once
#include "../other/template.hpp"
#include "RollingHash.hpp"
class HashedString {
	using M = StaticModInt<1000000007>;
	RollingHash<1000000007, 1007> rh1;
	RollingHash<1000000007, 10007> rh2;

  public:
	HashedString() {}
	HashedString(const std::string& s) { init(s); }
	void init(const std::string& s) {
		rh1.init(s);
		rh2.init(s);
	}
	bool operator==(const HashedString& rhs) const {
		return (M)rh1 == (M)rhs.rh1 && (M)rh2 == (M)rhs.rh2;
	}
	operator std::pair<M, M>() const { return {rh1, rh2}; }
	std::pair<M, M> substr(int l, size_t sz) const {
		return {rh1.substr(l, sz), rh2.substr(l, sz)};
	}
	std::pair<M, M> operator+(const std::string t) const {
		return {rh1 + t, rh2 + t};
	}
};

/**
 * @title Hash library for strings
 */