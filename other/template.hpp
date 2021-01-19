#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifdef ONLINE_JUDGE
#pragma GCC target("avx512f")
#else
#pragma GCC target("avx2")
#endif
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <string.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define REP(i, n) for (int i = 1; i <= int(n); i++)
#define all(V) V.begin(), V.end()

using i128 = __int128_t;
using u128 = __uint128_t;
using uint = unsigned int;
using lint = long long;
using ulint = unsigned long long;
using P = std::pair<int, int>;
using LP = std::pair<lint, lint>;

constexpr int INF = INT_MAX / 2;
constexpr lint LINF = LLONG_MAX / 2;
constexpr double eps = DBL_EPSILON;
constexpr double PI = 3.141592653589793238462643383279;

template <class T>
class prique : public std::priority_queue<T, std::vector<T>, std::greater<T>> {
};
template <class F>
inline constexpr decltype(auto) lambda_fix(F&& f) {
	return [f = std::forward<F>(f)](auto&&... args) {
		return f(f, std::forward<decltype(args)>(args)...);
	};
}
template <class T>
constexpr std::vector<T> make_vec(size_t n) {
	return std::vector<T>(n);
}
template <class T, class... Args>
constexpr auto make_vec(size_t n, Args&&... args) {
	return std::vector<decltype(make_vec<T>(args...))>(
		n, make_vec<T>(std::forward<Args>(args)...));
}
template <class T, class U>
constexpr inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return true;
	}
	return false;
}
template <class T, class U>
constexpr inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return true;
	}
	return false;
}
constexpr inline lint gcd(lint a, lint b) {
	while (b) {
		lint c = a;
		a = b;
		b = c % b;
	}
	return a;
}
inline lint lcm(lint a, lint b) { return a / gcd(a, b) * b; }
constexpr bool isprime(lint n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
template <class T>
constexpr T mypow(T a, lint b) {
	T res(1);
	while (true) {
		if (b & 1) res *= a;
		b >>= 1;
		if (!b) break;
		a *= a;
	}
	return res;
}
constexpr lint modpow(lint a, lint b, lint m) {
	a %= m;
	lint res(1);
	while (b) {
		if (b & 1) {
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		b >>= 1;
	}
	return res;
}
template <class T>
constexpr void printArray(const std::vector<T>& vec, char split = ' ') {
	rep(i, vec.size()) {
		std::cout << vec[i];
		std::cout << (i == (int)vec.size() - 1 ? '\n' : split);
	}
}
template <class T>
constexpr void printArray(T l, T r, char split = ' ') {
	T rprev = std::prev(r);
	for (T i = l; i != r; i++) {
		std::cout << *i;
		std::cout << (i == rprev ? '\n' : split);
	}
}
LP extGcd(lint a, lint b) {
	if (b == 0) return {1, 0};
	LP s = extGcd(b, a % b);
	std::swap(s.first, s.second);
	s.second -= a / b * s.first;
	return s;
}
LP ChineseRem(const lint& b1, const lint& m1, const lint& b2, const lint& m2) {
	lint p = extGcd(m1, m2).first;
	lint tmp = (b2 - b1) * p % m2;
	lint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);
	return {r, m1 * m2};
}
int LCS(const std::string& a, const std::string& b) {
	auto dp = make_vec<int>(a.size() + 1, b.size() + 1);
	rep(i, a.size()) {
		rep(j, b.size()) {
			chmax(dp[i + 1][j], dp[i][j]);
			chmax(dp[i][j + 1], dp[i][j]);
			if (a[i] == b[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);
		}
		chmax(dp[i + 1][b.size()], dp[i][b.size()]);
	}
	rep(j, b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);
	return dp[a.size()][b.size()];
}