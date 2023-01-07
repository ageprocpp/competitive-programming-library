#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef __clang__
#ifdef ONLINE_JUDGE
#ifdef _WIN64
#pragma GCC target("avx2")
#else
#pragma GCC target("avx512f")
#endif
#elif defined EVAL
#else
#pragma GCC target("avx2")
#endif
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif
#include <string.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <chrono>
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
using IP = std::pair<int, int>;
using LP = std::pair<lint, lint>;

constexpr int INF = INT_MAX / 2;
constexpr lint LINF = LLONG_MAX / 2;
constexpr double eps = DBL_EPSILON * 10;
constexpr double PI = 3.141592653589793238462643383279;

template <class T>
class prique : public std::priority_queue<T, std::vector<T>, std::greater<T>> {};
int popcount(uint x) {
#if __cplusplus >= 202002L
	return std::popcount(x);
#else
#ifndef __clang__
	return __builtin_popcount(x);
#endif
#endif
	x = (x & 0x55555555) + (x >> 1 & 0x55555555);
	x = (x & 0x33333333) + (x >> 2 & 0x33333333);
	x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);
	x = (x & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);
	return (x & 0x0000ffff) + (x >> 16 & 0x0000ffff);
}
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
	return std::vector<decltype(make_vec<T>(args...))>(n, make_vec<T>(std::forward<Args>(args)...));
}
template <class T, class U>
std::istream& operator>>(std::istream& ist, std::pair<T, U>& x) {
	return ist >> x.first >> x.second;
}
template <class T, class U>
std::ostream& operator<<(std::ostream& ost, const std::pair<T, U>& x) {
	return ost << x.first << " " << x.second;
}
template <class Container,
		  std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t> = nullptr>
auto operator>>(std::istream& ist, Container& cont)
	-> decltype(typename Container::iterator(), std::cin)& {
	Container tmp;
	while (true) {
		typename Container::value_type t;
		ist >> t;
		tmp.emplace_back(t);
		if (getchar() == '\n') break;
	}
	cont = Container(std::move(tmp));
	return ist;
}
template <class Container,
		  std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t> = nullptr>
auto operator<<(std::ostream& ost, const Container& cont)
	-> decltype(typename Container::iterator(), std::cout)& {
	for (auto it = cont.begin(); it != cont.end(); it++) {
		if (it != cont.begin()) ost << ' ';
		ost << *it;
	}
	return ost;
}
template <class Container>
auto sum(const Container& cont) -> decltype(typename Container::iterator(), 0LL) {
	lint res = 0;
	for (auto it = cont.begin(); it != cont.end(); it++) res += *it;
	return res;
}
template <class T, class U>
constexpr inline bool chmax(T& lhs, const U& rhs) noexcept {
	if (lhs < rhs) {
		lhs = rhs;
		return true;
	}
	return false;
}
template <class T, class U>
constexpr inline bool chmin(T& lhs, const U& rhs) noexcept {
	if (lhs > rhs) {
		lhs = rhs;
		return true;
	}
	return false;
}
constexpr inline lint gcd(lint a, lint b) noexcept {
	while (b) {
		lint c = a;
		a = b;
		b = c % b;
	}
	return a;
}
inline lint lcm(lint a, lint b) noexcept { return a / gcd(a, b) * b; }
constexpr bool isprime(lint n) noexcept {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}
template <class T>
constexpr T mypow(T a, lint b) noexcept {
	T res(1);
	while (true) {
		if (b & 1) res *= a;
		b >>= 1;
		if (!b) break;
		a *= a;
	}
	return res;
}
constexpr lint modpow(lint a, lint b, lint m) noexcept {
	a %= m;
	lint res(1);
	while (b) {
		if (b & 1) res *= a, res %= m;
		a *= a, a %= m, b >>= 1;
	}
	return res;
}
LP extGcd(lint a, lint b) noexcept {
	if (b == 0) return {1, 0};
	LP s = extGcd(b, a % b);
	std::swap(s.first, s.second);
	s.second -= a / b * s.first;
	return s;
}
LP ChineseRem(const lint& b1, const lint& m1, const lint& b2, const lint& m2) noexcept {
	auto p = extGcd(m1, m2);
	lint g = gcd(m1, m2), l = m1 / g * m2;
	lint tmp = (b2 - b1) / g * p.first % (m2 / g);
	lint r = (b1 + m1 * tmp + l) % l;
	return {r, l};
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
template <class T, std::enable_if_t<std::is_convertible<int, T>::value, std::nullptr_t> = nullptr>
void compress(std::vector<T>& vec) {
	auto tmp = vec;
	std::sort(all(tmp));
	tmp.erase(std::unique(all(tmp)), tmp.end());
	for (T& i : vec) i = std::lower_bound(all(tmp), i) - tmp.begin();
}
template <class T>
void compress(T* l, T* r) {
	std::vector<T> tmp(l, r);
	std::sort(all(tmp));
	tmp.erase(std::unique(all(tmp)), tmp.end());
	for (auto i = l; i < r; i++) {
		*i = std::lower_bound(all(tmp), *i) - tmp.begin();
	}
}
template <class InputIter>
void compress(InputIter l, InputIter r) {
	std::vector<typename InputIter::value_type> tmp(l, r);
	std::sort(all(tmp));
	tmp.erase(std::unique(all(tmp)), tmp.end());
	for (auto i = l; i < r; i++) {
		*i = std::lower_bound(all(tmp), *i) - tmp.begin();
	}
}
template <class InputIter,
		  std::enable_if_t<std::is_same<typename InputIter::value_type, std::pair<IP, int>>::value,
						   std::nullptr_t> = nullptr>
void mo_sort(InputIter l, InputIter r, int N) {
	const int M = std::max(1.0, std::sqrt(lint(N) * N / std::distance(l, r)));
	std::sort(l, r, [M](const auto& lhs, const auto& rhs) {
		if (lhs.first.first / M < rhs.first.first / M) return true;
		if (lhs.first.first / M == rhs.first.first / M) return lhs.first.second < rhs.first.second;
		return false;
	});
	int before = -1, cnt = 0;
	bool f = false;
	for (InputIter i = l; i != r; i++) {
		if (before != i->first.first / M) {
			if (f) std::reverse(i - cnt, i);
			f ^= true, before = i->first.first / M, cnt = 1;
		} else
			cnt++;
	}
	if (f) std::reverse(r - cnt, r);
}
template <class T>
std::vector<T> xor_bases(const std::vector<T>& vec) {
	std::vector<T> res;
	for (T i : vec) {
		for (T j : res) {
			chmin(i, i ^ j);
		}
		if (i) res.emplace_back(i);
	}
	return res;
}