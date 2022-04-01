---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/FormalPowerSeries.hpp
    title: math/FormalPowerSeries.hpp
  - icon: ':heavy_check_mark:'
    path: math/NumberTheoreticTransform.hpp
    title: NumberTheoreticTransform
  - icon: ':heavy_check_mark:'
    path: math/StaticModInt.hpp
    title: StaticModInt
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: other/type_traits.hpp
    title: other/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/exp_of_formal_power_series
  bundledCode: "#line 1 \"test/yosupo/exp_of_formal_power_series.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series\"\n#line\
    \ 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n\
    #ifdef ONLINE_JUDGE\n#ifdef _WIN64\n#pragma GCC target(\"avx2\")\n#else\n#pragma\
    \ GCC target(\"avx512f\")\n#endif\n#elif defined EVAL\n#else\n#pragma GCC target(\"\
    avx2\")\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n#endif\n#include <string.h>\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <ctime>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <vector>\n\n#define rep(i, n) for (int i = 0; i < (n); i++)\n#define\
    \ REP(i, n) for (int i = 1; i <= (n); i++)\n#define all(V) V.begin(), V.end()\n\
    \nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing uint = unsigned int;\n\
    using lint = long long;\nusing ulint = unsigned long long;\nusing IP = std::pair<int,\
    \ int>;\nusing LP = std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\n\
    constexpr lint LINF = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON * 10;\n\
    constexpr double PI = 3.141592653589793238462643383279;\n\ntemplate <class T>\n\
    class prique : public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {\n};\nint popcount(uint x) {\n#if __cplusplus >= 202002L\n\treturn std::popcount(x);\n\
    #else\n#ifndef __clang__\n\treturn __builtin_popcount(x);\n#endif\n#endif\n\t\
    x = (x & 0x55555555) + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333) + (x >>\
    \ 2 & 0x33333333);\n\tx = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\tx = (x\
    \ & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x >> 16\
    \ & 0x0000ffff);\n}\ntemplate <class F>\ninline constexpr decltype(auto) lambda_fix(F&&\
    \ f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\t\
    return std::vector<T>(n);\n}\ntemplate <class T, class... Args>\nconstexpr auto\
    \ make_vec(size_t n, Args&&... args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\
    \t\tn, make_vec<T>(std::forward<Args>(args)...));\n}\ntemplate <class T, class\
    \ U>\nstd::istream& operator>>(std::istream& ist, std::pair<T, U>& x) {\n\treturn\
    \ ist >> x.first >> x.second;\n}\ntemplate <class T, class U>\nstd::ostream& operator<<(std::ostream&\
    \ ost, const std::pair<T, U>& x) {\n\treturn ost << x.first << \" \" << x.second;\n\
    }\ntemplate <class Container,\n#if __cplusplus >= 201703L\n\t\t  std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>,\n#else\n\t\t  std::enable_if_t<!std::is_same<Container, std::string>::value,\n\
    #endif\n\t\t\t\t\t\t   std::nullptr_t> = nullptr>\nauto operator>>(std::istream&\
    \ ist, Container& cont)\n\t-> decltype(typename Container::iterator(), std::cin)&\
    \ {\n\tstd::vector<typename Container::value_type> tmp;\n\twhile (true) {\n\t\t\
    typename Container::value_type t;\n\t\tist >> t;\n\t\ttmp.emplace_back(t);\n\t\
    \tif (getchar() == '\\n') break;\n\t}\n\tcont = Container(std::move(tmp));\n\t\
    return ist;\n}\ntemplate <class Container,\n#if __cplusplus >= 201703L\n\t\t \
    \ std::enable_if_t<!std::is_same_v<Container, std::string>,\n#else\n\t\t  std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value,\n#endif\n\t\t\t\t\t\t   std::nullptr_t> = nullptr>\nauto\
    \ operator<<(std::ostream& ost, const Container& cont)\n\t-> decltype(typename\
    \ Container::iterator(), std::cout)& {\n\tfor (auto it = cont.begin(); it != cont.end();\
    \ it++) {\n\t\tif (it != cont.begin()) ost << ' ';\n\t\tost << *it;\n\t}\n\treturn\
    \ ost;\n}\ntemplate <class Container>\nauto sum(const Container& cont)\n\t-> decltype(typename\
    \ Container::iterator(), 0LL) {\n\tlint res = 0;\n\tfor (auto it = cont.begin();\
    \ it != cont.end(); it++) res += *it;\n\treturn res;\n}\ntemplate <class T, class\
    \ U>\nconstexpr inline bool chmax(T& lhs, const U& rhs) noexcept {\n\tif (lhs\
    \ < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate\
    \ <class T, class U>\nconstexpr inline bool chmin(T& lhs, const U& rhs) noexcept\
    \ {\n\tif (lhs > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\nconstexpr inline lint gcd(lint a, lint b) noexcept {\n\twhile (b) {\n\t\tlint\
    \ c = a;\n\t\ta = b;\n\t\tb = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint\
    \ a, lint b) noexcept { return a / gcd(a, b) * b; }\nconstexpr bool isprime(lint\
    \ n) noexcept {\n\tif (n == 1) return false;\n\tfor (int i = 2; i * i <= n; i++)\
    \ {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn true;\n}\ntemplate <class\
    \ T>\nconstexpr T mypow(T a, lint b) noexcept {\n\tT res(1);\n\twhile (true) {\n\
    \t\tif (b & 1) res *= a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\t\ta *= a;\n\t}\n\
    \treturn res;\n}\nconstexpr lint modpow(lint a, lint b, lint m) noexcept {\n\t\
    a %= m;\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) res *= a, res %= m;\n\t\
    \ta *= a, a %= m, b >>= 1;\n\t}\n\treturn res;\n}\nconstexpr i128 modpow(i128\
    \ a, i128 b, i128 m) noexcept {\n\ta %= m;\n\ti128 res(1);\n\twhile (b) {\n\t\t\
    if (b & 1) res *= a, res %= m;\n\t\ta *= a, a %= m, b >>= 1;\n\t}\n\treturn res;\n\
    }\nLP extGcd(lint a, lint b) noexcept {\n\tif (b == 0) return {1, 0};\n\tLP s\
    \ = extGcd(b, a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b *\
    \ s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const\
    \ lint& b2,\n\t\t\t  const lint& m2) noexcept {\n\tauto p = extGcd(m1, m2);\n\t\
    lint g = gcd(m1, m2), l = m1 / g * m2;\n\tlint tmp = (b2 - b1) / g * p.first %\
    \ (m2 / g);\n\tlint r = (b1 + m1 * tmp + l) % l;\n\treturn {r, l};\n}\nint LCS(const\
    \ std::string& a, const std::string& b) {\n\tauto dp = make_vec<int>(a.size()\
    \ + 1, b.size() + 1);\n\trep(i, a.size()) {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i\
    \ + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j + 1], dp[i][j]);\n\t\t\tif (a[i] ==\
    \ b[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()],\
    \ dp[i][b.size()]);\n\t}\n\trep(j, b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\
    \treturn dp[a.size()][b.size()];\n}\ntemplate <class T, std::enable_if_t<std::is_convertible<int,\
    \ T>::value,\n\t\t\t\t\t\t\t\t\tstd::nullptr_t> = nullptr>\nvoid compress(std::vector<T>&\
    \ vec) {\n\tauto tmp = vec;\n\tstd::sort(all(tmp));\n\ttmp.erase(std::unique(all(tmp)),\
    \ tmp.end());\n\tfor (T& i : vec) i = std::lower_bound(all(tmp), i) - tmp.begin();\n\
    }\ntemplate <class T>\nvoid compress(T* l, T* r) {\n\tstd::vector<T> tmp(l, r);\n\
    \tstd::sort(all(tmp));\n\ttmp.erase(std::unique(all(tmp)), tmp.end());\n\tfor\
    \ (auto i = l; i < r; i++) {\n\t\t*i = std::lower_bound(all(tmp), *i) - tmp.begin();\n\
    \t}\n}\ntemplate <class InputIter>\nvoid compress(InputIter l, InputIter r) {\n\
    \tstd::vector<typename InputIter::value_type> tmp(l, r);\n\tstd::sort(all(tmp));\n\
    \ttmp.erase(std::unique(all(tmp)), tmp.end());\n\tfor (auto i = l; i < r; i++)\
    \ {\n\t\t*i = std::lower_bound(all(tmp), *i) - tmp.begin();\n\t}\n}\n#line 3 \"\
    other/type_traits.hpp\"\n\nclass ModInt__Base {};\nclass StaticModInt__Base :\
    \ ModInt__Base {};\nclass DynamicModInt__Base : ModInt__Base {};\n\ntemplate <class\
    \ T>\nclass is_ModInt : public std::is_base_of<ModInt__Base, T> {};\ntemplate\
    \ <class T>\nconstexpr bool is_ModInt_v = is_ModInt<T>::value;\n\ntemplate <class\
    \ T>\nclass is_StaticModInt : public std::is_base_of<StaticModInt__Base, T> {};\n\
    template <class T>\nconstexpr bool is_StaticModInt_v = is_StaticModInt<T>::value;\n\
    \ntemplate <class T>\nclass is_DynamicModInt : public std::is_base_of<DynamicModInt__Base,\
    \ T> {};\ntemplate <class T>\nconstexpr bool is_DynamicModInt_v = is_DynamicModInt<T>::value;\n\
    #line 4 \"math/StaticModInt.hpp\"\ntemplate <int modulo>\nclass StaticModInt :\
    \ StaticModInt__Base {\n\tstd::conditional_t<(modulo > (INT_MAX >> 1)), lint,\
    \ int> value;\n\tstatic constexpr int inv1000000007[] = {0,\t\t   1,\t\t  500000004,\n\
    \t\t\t\t\t\t\t\t\t\t\t333333336, 250000002, 400000003,\n\t\t\t\t\t\t\t\t\t\t\t\
    166666668, 142857144, 125000001,\n\t\t\t\t\t\t\t\t\t\t\t111111112, 700000005},\n\
    \t\t\t\t\t\t inv998244353[] = {0,\t\t  1,\t\t 499122177,\n\t\t\t\t\t\t\t\t\t\t\
    \   332748118, 748683265, 598946612,\n\t\t\t\t\t\t\t\t\t\t   166374059, 855638017,\
    \ 873463809,\n\t\t\t\t\t\t\t\t\t\t   443664157, 299473306};\n\n  public:\n\tstatic\
    \ constexpr int mod_value = modulo;\n\n\tconstexpr StaticModInt() : value(0) {}\n\
    \ttemplate <class T,\n\t\t\t  std::enable_if_t<!std::is_convertible<T, StaticModInt>::value,\n\
    \t\t\t\t\t\t\t   std::nullptr_t> = nullptr>\n\tconstexpr StaticModInt(T value\
    \ = 0) : value(value % int(modulo)) {\n\t\tif (this->value < 0) this->value +=\
    \ modulo;\n\t}\n\tinline constexpr StaticModInt inv() const {\n#if __cplusplus\
    \ >= 201703L\n\t\tif constexpr (modulo == 1000000007) {\n\t\t\tif (*this <= 10)\
    \ return inv1000000007[*this];\n\t\t} else if constexpr (modulo == 998244353)\
    \ {\n\t\t\tif (*this <= 10) return inv998244353[*this];\n\t\t}\n#else\n\t\tif\
    \ (modulo == 1000000007) {\n\t\t\tif (*this <= 10) return inv1000000007[*this];\n\
    \t\t} else if (modulo == 998244353) {\n\t\t\tif (*this <= 10) return inv998244353[*this];\n\
    \t\t}\n#endif\n\t\treturn mypow(*this, modulo - 2);\n\t}\n\tinline constexpr operator\
    \ int() const { return value; }\n\tinline constexpr StaticModInt& operator+=(const\
    \ StaticModInt& x) {\n\t\tvalue = value + x.value;\n\t\tif (value >= modulo) value\
    \ -= modulo;\n\t\treturn *this;\n\t}\n\tinline constexpr StaticModInt& operator++()\
    \ {\n\t\tif (value == modulo - 1)\n\t\t\tvalue = 0;\n\t\telse\n\t\t\tvalue++;\n\
    \t\treturn *this;\n\t}\n\tinline constexpr StaticModInt operator++(int) {\n\t\t\
    StaticModInt res = *this;\n\t\t++*this;\n\t\treturn res;\n\t}\n\tinline constexpr\
    \ StaticModInt operator-() const {\n\t\treturn StaticModInt(0) -= *this;\n\t}\n\
    \tinline constexpr StaticModInt& operator-=(const StaticModInt& x) {\n\t\tif (value\
    \ < x.value) value += modulo;\n\t\tvalue -= x.value;\n\t\treturn *this;\n\t}\n\
    \tinline constexpr StaticModInt& operator--() {\n\t\tif (value == 0)\n\t\t\tvalue\
    \ = modulo - 1;\n\t\telse\n\t\t\tvalue--;\n\t\treturn *this;\n\t}\n\tinline constexpr\
    \ StaticModInt operator--(int) {\n\t\tStaticModInt res = *this;\n\t\t--*this;\n\
    \t\treturn res;\n\t}\n\tinline constexpr StaticModInt& operator*=(const StaticModInt&\
    \ x) {\n\t\tvalue = (ulint)value * x.value % modulo;\n\t\treturn *this;\n\t}\n\
    \tinline constexpr StaticModInt& operator/=(const StaticModInt& rhs) {\n\t\treturn\
    \ *this *= rhs.inv();\n\t}\n\ttemplate <class T>\n\tconstexpr StaticModInt operator+(const\
    \ T& rhs) const {\n\t\treturn StaticModInt(*this) += rhs;\n\t}\n\ttemplate <class\
    \ T>\n\tconstexpr StaticModInt& operator+=(const T& rhs) {\n\t\treturn operator+=(StaticModInt(rhs));\n\
    \t}\n\ttemplate <class T>\n\tconstexpr StaticModInt operator-(const T& rhs) const\
    \ {\n\t\treturn StaticModInt(*this) -= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ StaticModInt& operator-=(const T& rhs) {\n\t\treturn operator-=(StaticModInt(rhs));\n\
    \t}\n\ttemplate <class T>\n\tconstexpr StaticModInt operator*(const T& rhs) const\
    \ {\n\t\treturn StaticModInt(*this) *= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ StaticModInt& operator*=(const T& rhs) {\n\t\treturn operator*=(StaticModInt(rhs));\n\
    \t}\n\ttemplate <class T>\n\tconstexpr StaticModInt operator/(const T& rhs) const\
    \ {\n\t\treturn StaticModInt(*this) /= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ StaticModInt& operator/=(const T& rhs) {\n\t\treturn operator/=(StaticModInt(rhs));\n\
    \t}\n\tstatic int primitive_root() {\n\t\tstatic int p = 0;\n\t\tstatic std::random_device\
    \ rd;\n\t\tstatic std::mt19937 mt(rd());\n\t\tstatic std::uniform_int_distribution<>\
    \ uid(1, modulo - 1);\n\t\tif (p) return 0;\n\n\t\t// use naive factorize due\
    \ to file size limit\n\t\tstd::vector<int> vec;\n\t\tint tmp = modulo - 1;\n\t\
    \tfor (int i = 2; i * i <= tmp; i++) {\n\t\t\tif (tmp % i == 0) {\n\t\t\t\tvec.emplace_back(i);\n\
    \t\t\t\tdo {\n\t\t\t\t\ttmp /= i;\n\t\t\t\t} while (tmp % i == 0);\n\t\t\t}\n\t\
    \t}\n\t\tif (tmp != 1) vec.emplace_back(tmp);\n\n\t\twhile (true) {\n\t\t\tp =\
    \ uid(mt);\n\t\t\tbool f = true;\n\t\t\tfor (const auto& i : vec) {\n\t\t\t\t\
    if (mypow(StaticModInt(p), (modulo - 1) / i) == 1) {\n\t\t\t\t\tf = false;\n\t\
    \t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (f) return p;\n\t\t}\n\t}\n};\ntemplate\
    \ <int modulo>\nstd::istream& operator>>(std::istream& ist, StaticModInt<modulo>&\
    \ x) {\n\tlint a;\n\tist >> a;\n\tx = a;\n\treturn ist;\n}\n\n#if __cplusplus\
    \ < 201703L\ntemplate <int modulo>\nconstexpr int StaticModInt<modulo>::inv1000000007[];\n\
    template <int modulo>\nconstexpr int StaticModInt<modulo>::inv998244353[];\n#endif\n\
    \n/**\n * @title StaticModInt\n */\n#line 4 \"math/NumberTheoreticTransform.hpp\"\
    \n// 1012924417, 5, 2^21\n// 924844033, 5, 2^21\n// 998244353, 3, 2^23\n// 1224736769,\
    \ 3, 2^24\n// 167772161, 3, 2^25\n// 469762049, 3, 2^26\nclass NumberTheoreticTransform\
    \ {\n\tstatic constexpr int bases[] = {1012924417, 924844033, 998244353,\n\t\t\
    \t\t\t\t\t\t\t1224736769, 167772161, 469762049};\n\tstatic constexpr int roots[]\
    \ = {5, 5, 3, 3, 3, 3};\n\n  private:\n\ttemplate <int modulo>\n\tstatic void\
    \ ntt(std::vector<StaticModInt<modulo>>& a,\n\t\t\t\t\tStaticModInt<modulo> root)\
    \ {\n\t\tint sz = a.size();\n\t\tif (sz == 1) return;\n\t\tif (inverse)\n\t\t\t\
    root = mypow(root, modulo - 1 - (modulo - 1) / sz);\n\t\telse\n\t\t\troot = mypow(root,\
    \ (modulo - 1) / sz);\n\t\tstd::vector<StaticModInt<modulo>> b(sz), roots((sz\
    \ >> 1) + 1, 1);\n\t\trep(i, sz >> 1) roots[i + 1] = roots[i] * root;\n\t\tfor\
    \ (int i = sz >> 1, w = 1; w < sz; i >>= 1, w <<= 1) {\n\t\t\tfor (int j = 0;\
    \ j < i; j++) {\n\t\t\t\tfor (int k = 0; k < w; k++) {\n\t\t\t\t\tb[k + ((w *\
    \ j) << 1)] =\n\t\t\t\t\t\ta[k + w * j] + a[k + w * j + (sz >> 1)];\n\t\t\t\t\t\
    b[k + ((w * j) << 1) + w] =\n\t\t\t\t\t\troots[w * j] *\n\t\t\t\t\t\t(a[k + w\
    \ * j] - a[k + w * j + (sz >> 1)]);\n\t\t\t\t}\n\t\t\t}\n\t\t\tstd::swap(a, b);\n\
    \t\t}\n\t}\n\ttemplate <class T, int modulo>\n\tstatic std::vector<StaticModInt<modulo>>\
    \ internal_convolution(\n\t\tconst std::vector<T>& f_, const std::vector<T>& g_,\n\
    \t\tStaticModInt<modulo> root) {\n\t\tstd::vector<StaticModInt<modulo>> f(f_.size()),\
    \ g(g_.size());\n\t\trep(j, f_.size()) f[j] = f_[j];\n\t\trep(j, g_.size()) g[j]\
    \ = g_[j];\n\t\treturn internal_convolution(f, g, root);\n\t}\n\ttemplate <int\
    \ modulo>\n\tstatic std::vector<StaticModInt<modulo>> internal_convolution(\n\t\
    \tstd::vector<StaticModInt<modulo>> f,\n\t\tstd::vector<StaticModInt<modulo>>\
    \ g, StaticModInt<modulo> root) {\n\t\tsize_t target_size = f.size() + g.size()\
    \ - 1, sz = 1;\n\t\twhile (sz < f.size() + g.size()) sz <<= 1;\n\t\tf.resize(sz),\
    \ g.resize(sz);\n\n\t\tinverse = false;\n\t\tntt(f, root), ntt(g, root);\n\t\t\
    rep(i, f.size()) f[i] *= g[i];\n\t\tinverse = true;\n\t\tntt(f, root);\n\t\tStaticModInt<modulo>\
    \ inv = StaticModInt<modulo>(f.size()).inv();\n\t\trep(i, f.size()) f[i] *= inv;\n\
    \t\tf.resize(target_size);\n\t\treturn f;\n\t}\n\n  public:\n\tstatic bool inverse;\n\
    \n\ttemplate <int modulo, class T>\n\tstatic std::vector<StaticModInt<modulo>>\
    \ convolution(\n\t\tconst std::vector<T>& f, const std::vector<T>& g) {\n#if __cplusplus\
    \ >= 201703L\n\t\tif constexpr\n#else\n\t\tif\n#endif\n\t\t\t(modulo == bases[0]\
    \ || modulo == bases[1] || modulo == bases[2] ||\n\t\t\t modulo == bases[3] ||\
    \ modulo == bases[4] || modulo == bases[5]) {\n\t\t\tstd::vector<StaticModInt<modulo>>\
    \ f_(f.size()), g_(g.size());\n\t\t\trep(i, f.size()) f_[i] = f[i];\n\t\t\trep(i,\
    \ g.size()) g_[i] = g[i];\n#if __cplusplus >= 201703L\n\t\t\tif constexpr (modulo\
    \ == bases[0]) {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_,\
    \ g_, StaticModInt<modulo>(roots[0]));\n\t\t\t} else if constexpr (modulo == bases[1])\
    \ {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[1]));\n\
    \t\t\t} else if constexpr (modulo == bases[2]) {\n\t\t\t\treturn internal_convolution<modulo>(\n\
    \t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[2]));\n\t\t\t} else if constexpr\
    \ (modulo == bases[3]) {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\
    \t\tf_, g_, StaticModInt<modulo>(roots[3]));\n\t\t\t} else if constexpr (modulo\
    \ == bases[4]) {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_,\
    \ g_, StaticModInt<modulo>(roots[4]));\n\t\t\t} else {\n\t\t\t\treturn internal_convolution<modulo>(\n\
    \t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[5]));\n\t\t\t}\n#else\n\n\t\t\tif\
    \ (modulo == bases[0]) {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\
    \t\tf_, g_, StaticModInt<modulo>(roots[0]));\n\t\t\t} else if (modulo == bases[1])\
    \ {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[1]));\n\
    \t\t\t} else if (modulo == bases[2]) {\n\t\t\t\treturn internal_convolution<modulo>(\n\
    \t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[2]));\n\t\t\t} else if (modulo ==\
    \ bases[3]) {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_, g_,\
    \ StaticModInt<modulo>(roots[3]));\n\t\t\t} else if (modulo == bases[4]) {\n\t\
    \t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[4]));\n\
    \t\t\t} else {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_, g_,\
    \ StaticModInt<modulo>(roots[5]));\n\t\t\t}\n#endif\n\t\t}\n\t\tconstexpr int\
    \ base1 = 998244353, base2 = 1224736769, base3 = 469762049;\n\t\tauto re1 = internal_convolution<T,\
    \ base1>(f, g, 3);\n\t\tauto re2 = internal_convolution<T, base2>(f, g, 3);\n\t\
    \tauto re3 = internal_convolution<T, base3>(f, g, 3);\n\t\tstd::vector<StaticModInt<modulo>>\
    \ res(re1.size());\n\t\tconstexpr int r12 = StaticModInt<base2>(base1).inv();\n\
    \t\tconstexpr int r13 = StaticModInt<base3>(base1).inv();\n\t\tconstexpr int r23\
    \ = StaticModInt<base3>(base2).inv();\n\t\trep(i, re1.size()) {\n\t\t\tre2[i]\
    \ = StaticModInt<base2>(re2[i] - re1[i]) * r12;\n\t\t\tre3[i] =\n\t\t\t\t(StaticModInt<base3>(re3[i]\
    \ - re1[i]) * r13 - re2[i]) * r23;\n\t\t\tres[i] = (StaticModInt<modulo>(re1[i])\
    \ +\n\t\t\t\t\t  StaticModInt<modulo>(re2[i]) * base1 +\n\t\t\t\t\t  StaticModInt<modulo>(re3[i])\
    \ * base1 * base2);\n\t\t}\n\t\treturn res;\n\t}\n\ttemplate <int modulo>\n\t\
    static std::vector<StaticModInt<modulo>> convolution(\n\t\tstd::vector<StaticModInt<modulo>>\
    \ f,\n\t\tstd::vector<StaticModInt<modulo>> g) {\n#if __cplusplus >= 201703L\n\
    \t\tif constexpr\n#else\n\t\tif\n#endif\n\t\t\t(modulo == bases[0] || modulo ==\
    \ bases[1] || modulo == bases[2] ||\n\t\t\t modulo == bases[3] || modulo == bases[4]\
    \ || modulo == bases[5]) {\n\t\t\tstd::vector<StaticModInt<modulo>> f_(f.size()),\
    \ g_(g.size());\n\t\t\trep(i, f.size()) f_[i] = f[i];\n\t\t\trep(i, g.size())\
    \ g_[i] = g[i];\n#if __cplusplus >= 201703L\n\t\t\tif constexpr (modulo == bases[0])\
    \ {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[0]));\n\
    \t\t\t} else if constexpr (modulo == bases[1]) {\n\t\t\t\treturn internal_convolution<modulo>(\n\
    \t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[1]));\n\t\t\t} else if constexpr\
    \ (modulo == bases[2]) {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\
    \t\tf_, g_, StaticModInt<modulo>(roots[2]));\n\t\t\t} else if constexpr (modulo\
    \ == bases[3]) {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_,\
    \ g_, StaticModInt<modulo>(roots[3]));\n\t\t\t} else if constexpr (modulo == bases[4])\
    \ {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[4]));\n\
    \t\t\t} else {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_, g_,\
    \ StaticModInt<modulo>(roots[5]));\n\t\t\t}\n#else\n\n\t\t\tif (modulo == bases[0])\
    \ {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[0]));\n\
    \t\t\t} else if (modulo == bases[1]) {\n\t\t\t\treturn internal_convolution<modulo>(\n\
    \t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[1]));\n\t\t\t} else if (modulo ==\
    \ bases[2]) {\n\t\t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_, g_,\
    \ StaticModInt<modulo>(roots[2]));\n\t\t\t} else if (modulo == bases[3]) {\n\t\
    \t\t\treturn internal_convolution<modulo>(\n\t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[3]));\n\
    \t\t\t} else if (modulo == bases[4]) {\n\t\t\t\treturn internal_convolution<modulo>(\n\
    \t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[4]));\n\t\t\t} else {\n\t\t\t\treturn\
    \ internal_convolution<modulo>(\n\t\t\t\t\tf_, g_, StaticModInt<modulo>(roots[5]));\n\
    \t\t\t}\n#endif\n\t\t}\n\t\tconstexpr int base1 = 998244353, base2 = 1224736769,\
    \ base3 = 469762049;\n\t\tauto re1 = internal_convolution<StaticModInt<modulo>,\
    \ base1>(\n\t\t\tf, g, StaticModInt<base1>(3));\n\t\tauto re2 = internal_convolution<StaticModInt<modulo>,\
    \ base2>(\n\t\t\tf, g, StaticModInt<base2>(3));\n\t\tauto re3 = internal_convolution<StaticModInt<modulo>,\
    \ base3>(\n\t\t\tf, g, StaticModInt<base3>(3));\n\t\tstd::vector<StaticModInt<modulo>>\
    \ res(re1.size());\n\t\tconstexpr int r12 = StaticModInt<base2>(base1).inv();\n\
    \t\tconstexpr int r13 = StaticModInt<base3>(base1).inv();\n\t\tconstexpr int r23\
    \ = StaticModInt<base3>(base2).inv();\n\t\trep(i, re1.size()) {\n\t\t\tre2[i]\
    \ = StaticModInt<base2>(re2[i] - re1[i]) * r12;\n\t\t\tre3[i] =\n\t\t\t\t(StaticModInt<base3>(re3[i]\
    \ - re1[i]) * r13 - re2[i]) * r23;\n\t\t\tres[i] = (StaticModInt<modulo>(re1[i])\
    \ +\n\t\t\t\t\t  StaticModInt<modulo>(re2[i]) * base1 +\n\t\t\t\t\t  StaticModInt<modulo>(re3[i])\
    \ * base1 * base2);\n\t\t}\n\t\treturn res;\n\t}\n\ttemplate <class T>\n\tstatic\
    \ std::vector<lint> convolution_plain(std::vector<T> f,\n\t\t\t\t\t\t\t\t\t\t\t\
    \   std::vector<T> g) {\n\t\tconst int mod1 = 998244353, mod2 = 1224736769;\n\t\
    \tstd::vector<StaticModInt<mod1>> mul1 =\n\t\t\tinternal_convolution<T, mod1>(f,\
    \ g, StaticModInt<mod1>(3));\n\t\tstd::vector<StaticModInt<mod2>> mul2 =\n\t\t\
    \tinternal_convolution<T, mod2>(f, g, StaticModInt<mod2>(3));\n\t\tstd::vector<lint>\
    \ res(mul1.size());\n\t\trep(i, mul1.size()) res[i] =\n\t\t\tChineseRem(mul1[i],\
    \ mod1, mul2[i], mod2).first;\n\t\treturn res;\n\t}\n};\nbool NumberTheoreticTransform::inverse\
    \ = false;\n\n/**\n * @title NumberTheoreticTransform\n */\n#line 4 \"math/FormalPowerSeries.hpp\"\
    \n\ntemplate <class T, std::enable_if_t<is_ModInt_v<T>, std::nullptr_t> = nullptr>\n\
    class FormalPowerSeries {\n  private:\n\tstd::vector<T> vec;\n\n\tusing NTT =\
    \ NumberTheoreticTransform;\n\tusing FPS = FormalPowerSeries<T>;\n\n  public:\n\
    \ttemplate <class... Args>\n\tFormalPowerSeries(Args&&... args) : vec(std::forward<Args>(args)...)\
    \ {}\n\n\toperator std::vector<T>() { return vec; }\n\toperator std::vector<T>()\
    \ const { return vec; }\n\tsize_t size() const noexcept { return vec.size(); }\n\
    \n\tFPS operator-() const {\n\t\tFPS res(*this);\n\t\tfor (T& i : res.vec) i =\
    \ -i;\n\t\treturn res;\n\t}\n\n\ttemplate <class U>\n\tFPS& operator+=(const U&\
    \ v) {\n\t\tif (vec.empty())\n\t\t\tvec.emplace_back(v);\n\t\telse\n\t\t\tvec[0]\
    \ += v;\n\t\treturn *this;\n\t}\n\ttemplate <class U>\n\tFPS operator+(const U&\
    \ v) const {\n\t\tFPS res(*this);\n\t\treturn res += v;\n\t}\n\tFPS operator+=(const\
    \ FPS& f) {\n\t\tvec.resize(std::max(size(), f.size()));\n\t\trep(i, vec.size())\
    \ vec[i] += f.vec[i];\n\t\treturn *this;\n\t}\n\tFPS operator+(const FPS& f) const\
    \ {\n\t\tFPS res(*this);\n\t\treturn res += f;\n\t}\n\n\ttemplate <class U>\n\t\
    FPS& operator-=(const U& v) {\n\t\tif (vec.empty())\n\t\t\tvec.emplace_bcak(-v);\n\
    \t\telse\n\t\t\tvec[0] -= v;\n\t\treturn *this;\n\t}\n\ttemplate <class U>\n\t\
    FPS operator-(const U& v) const {\n\t\tFPS res(*this);\n\t\treturn res -= v;\n\
    \t}\n\tFPS operator-=(const FPS& f) {\n\t\tvec.resize(std::max(size(), f.size()));\n\
    \t\trep(i, std::min(size(), f.size())) vec[i] -= f.vec[i];\n\t\treturn *this;\n\
    \t}\n\tFPS operator-(const FPS& f) const {\n\t\tFPS res(*this);\n\t\treturn res\
    \ -= f;\n\t}\n\n\ttemplate <class U>\n\tFPS& operator*=(const U& v) {\n\t\tfor\
    \ (const T& i : vec) i *= v;\n\t\treturn *this;\n\t}\n\ttemplate <class U>\n\t\
    FPS operator*(const U& v) {\n\t\tFPS res(*this);\n\t\treturn res *= v;\n\t}\n\t\
    FPS operator*=(const FPS& f) {\n\t\tvec = NTT::convolution(vec, f.vec);\n\t\t\
    return *this;\n\t}\n\tFPS operator*(const FPS& f) {\n\t\tFPS res(*this);\n\t\t\
    return res *= f;\n\t}\n\n\ttemplate <class U>\n\tFPS& operator/=(const U& v) {\n\
    \t\tfor (const T& i : vec) i /= v;\n\t\treturn *this;\n\t}\n\ttemplate <class\
    \ U>\n\tFPS operator/(const U& v) {\n\t\tFPS res(*this);\n\t\treturn res /= v;\n\
    \t}\n\tFPS operator/=(const FPS& f) {\n\t\tvec = NTT::convolution(vec, f.inverse().vec);\n\
    \t\treturn *this;\n\t}\n\tFPS operator/(const FPS& f) {\n\t\tFPS res(*this);\n\
    \t\treturn res /= f;\n\t}\n\n\ttemplate <class U>\n\n\t[[nodiscard]] size_t size()\
    \ const {\n\t\treturn vec.size();\n\t}\n\tvoid resize(size_t n) { vec.resize(n);\
    \ }\n\n\tvoid differentiate() {\n\t\tvec.erase(vec.begin());\n\t\tREP(i, vec.size())\
    \ vec[i - 1] *= i;\n\t}\n\t[[nodiscard]] FPS differential() {\n\t\tFPS res = *this;\n\
    \t\tres.differentiate();\n\t\treturn res;\n\t}\n\n\tvoid integrate() {\n\t\tvec.insert(vec.begin(),\
    \ 0);\n\t\tREP(i, vec.size() - 1) vec[i] /= i;\n\t}\n\t[[nodiscard]] FPS integral()\
    \ {\n\t\tFPS res = *this;\n\t\tres.integrate();\n\t\treturn res;\n\t}\n\n\tvoid\
    \ invert() { invert(vec.size()); }\n\tvoid invert(size_t len) { *this = FPS(len);\
    \ }\n\t[[nodiscard]] FPS inverse() const { return inverse(vec.size()); }\n\t[[nodiscard]]\
    \ FPS inverse(size_t len) const {\n\t\tstd::vector<T> res;\n\t\tsize_t n = 1;\n\
    \t\tres.emplace_back(T(1) / vec[0]);\n\t\tstd::vector<T> vec_shortened = {vec[0]};\n\
    \t\tvec_shortened.reserve(len);\n\t\twhile (n < len) {\n\t\t\tn <<= 1;\n\t\t\t\
    vec_shortened.insert(vec_shortened.end(),\n\t\t\t\t\t\t\t\t vec.begin() + vec_shortened.size(),\n\
    \t\t\t\t\t\t\t\t vec.begin() + std::min(vec.size(), n));\n\t\t\tauto tmp = NTT::convolution(res,\
    \ vec_shortened);\n\t\t\ttmp.resize(std::min(n, len));\n\t\t\tfor (T& i : tmp)\
    \ i = -i;\n\t\t\ttmp[0] += 2;\n\t\t\tres = NTT::convolution(res, tmp);\n\t\t\t\
    res.resize(std::min(n, len));\n\t\t}\n\t\treturn FPS(std::move(res));\n\t}\n\n\
    \t[[nodiscard]] FPS log() { return log(size()); }\n\t[[nodiscard]] FPS log(size_t\
    \ len) {\n\t\tFPS differentiated = differential();\n\t\tFPS tmp = differentiated\
    \ / *this;\n\t\ttmp.resize(len - 1);\n\t\treturn tmp.integral();\n\t}\n\n\t[[nodiscard]]\
    \ FPS exp() { return exp(size()); }\n\t[[nodiscard]] FPS exp(size_t len) {\n\t\
    \tFPS res(1, 1);\n\t\tsize_t n = 1;\n\t\twhile (n < len) {\n\t\t\tn <<= 1;\n\t\
    \t\tauto tmp = *this + 1;\n\t\t\ttmp -= res.log(n);\n\t\t\tres *= tmp;\n\t\t\t\
    res.resize(std::min(len, 2 * n));\n\t\t}\n\t\treturn res;\n\t}\n\n\ttemplate <class\
    \ U>\n\tfriend std::ostream& operator<<(std::ostream&, const FormalPowerSeries<U>&);\n\
    };\n\ntemplate <class T>\nstd::ostream& operator<<(std::ostream& ost, const FormalPowerSeries<T>&\
    \ fps) {\n\tost << fps.vec;\n\treturn ost;\n}\n#line 5 \"test/yosupo/exp_of_formal_power_series.test.cpp\"\
    \n\nusing ModInt = StaticModInt<998244353>;\nusing FPS = FormalPowerSeries<ModInt>;\n\
    int main() {\n\tint N;\n\tstd::vector<ModInt> vec;\n\tstd::cin >> N >> vec;\n\t\
    std::cout << FPS(std::move(vec)).exp() << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series\"\
    \n#include \"../../other/template.hpp\"\n#include \"../../math/StaticModInt.hpp\"\
    \n#include \"../../math/FormalPowerSeries.hpp\"\n\nusing ModInt = StaticModInt<998244353>;\n\
    using FPS = FormalPowerSeries<ModInt>;\nint main() {\n\tint N;\n\tstd::vector<ModInt>\
    \ vec;\n\tstd::cin >> N >> vec;\n\tstd::cout << FPS(std::move(vec)).exp() << std::endl;\n\
    }"
  dependsOn:
  - other/template.hpp
  - math/StaticModInt.hpp
  - other/type_traits.hpp
  - math/FormalPowerSeries.hpp
  - math/NumberTheoreticTransform.hpp
  isVerificationFile: true
  path: test/yosupo/exp_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2022-04-01 21:43:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/exp_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/exp_of_formal_power_series.test.cpp
- /verify/test/yosupo/exp_of_formal_power_series.test.cpp.html
title: test/yosupo/exp_of_formal_power_series.test.cpp
---
