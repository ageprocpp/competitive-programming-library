---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/FormalPowerSeries.hpp
    title: math/FormalPowerSeries.hpp
  - icon: ':x:'
    path: math/NumberTheoreticTransform.hpp
    title: NumberTheoreticTransform
  - icon: ':x:'
    path: math/StaticModInt.hpp
    title: StaticModInt
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':x:'
    path: other/type_traits.hpp
    title: other/type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/exp_of_formal_power_series
  bundledCode: "#line 1 \"test/yosupo/exp_of_formal_power_series.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series\"\n#line\
    \ 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n\
    #pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#endif\n\
    #include <string.h>\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cfloat>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <complex>\n#include <ctime>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i, n) for (int i = 0; i < int(n); i++)\n#define REP(i,\
    \ n) for (int i = 1; i <= int(n); i++)\n#define all(V) V.begin(), V.end()\n\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\nusing uint = unsigned int;\n\
    using lint = long long;\nusing ulint = unsigned long long;\nusing IP = std::pair<int,\
    \ int>;\nusing LP = std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\n\
    constexpr lint LINF = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON * 10;\n\
    constexpr double PI = 3.141592653589793238462643383279;\n\ntemplate <class T>\n\
    class prique : public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {};\nint popcount(uint x) {\n#if __cplusplus >= 202002L\n\treturn std::popcount(x);\n\
    #else\n#ifndef __clang__\n\treturn __builtin_popcount(x);\n#endif\n#endif\n\t\
    x = (x & 0x55555555) + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333) + (x >>\
    \ 2 & 0x33333333);\n\tx = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\tx = (x\
    \ & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x >> 16\
    \ & 0x0000ffff);\n}\ntemplate <class F>\ninline constexpr decltype(auto) lambda_fix(F&&\
    \ f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\t\
    return std::vector<T>(n);\n}\ntemplate <class T, class... Args>\nconstexpr auto\
    \ make_vec(size_t n, Args&&... args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(n,\
    \ make_vec<T>(std::forward<Args>(args)...));\n}\ntemplate <class T, class U, class\
    \ Stream>\nStream& operator>>(Stream& ist, std::pair<T, U>& x) {\n\treturn ist\
    \ >> x.first >> x.second;\n}\ntemplate <class T, class U, class Stream>\nStream&\
    \ operator<<(Stream& ost, const std::pair<T, U>& x) {\n\treturn ost << x.first\
    \ << \" \" << x.second;\n}\ntemplate <class Container,\n\t\t  std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value, std::nullptr_t> = nullptr>\nauto operator>>(std::istream&\
    \ ist, Container& cont)\n\t-> decltype(typename Container::iterator(), std::cin)&\
    \ {\n\tContainer tmp;\n\twhile (true) {\n\t\ttypename Container::value_type t;\n\
    \t\tist >> t;\n\t\ttmp.emplace_back(t);\n\t\tif (getchar() == '\\n') break;\n\t\
    }\n\tcont = Container(std::move(tmp));\n\treturn ist;\n}\ntemplate <class Container,\
    \ class Stream,\n\t\t  std::enable_if_t<!std::is_same<Container, std::string>::value,\
    \ std::nullptr_t> = nullptr>\nauto operator<<(Stream& ost, const Container& cont)\n\
    \t-> decltype(typename Container::iterator(), ost)& {\n\tfor (auto it = cont.begin();\
    \ it != cont.end(); it++) {\n\t\tif (it != cont.begin()) ost << ' ';\n\t\tost\
    \ << *it;\n\t}\n\treturn ost;\n}\ntemplate <class Container>\nauto sum(const Container&\
    \ cont) -> decltype(typename Container::iterator(), 0LL) {\n\tlint res = 0;\n\t\
    for (auto it = cont.begin(); it != cont.end(); it++) res += *it;\n\treturn res;\n\
    }\ntemplate <class T, class U>\nconstexpr inline bool chmax(T& lhs, const U& rhs)\
    \ noexcept {\n\tif (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn\
    \ false;\n}\ntemplate <class T, class U>\nconstexpr inline bool chmin(T& lhs,\
    \ const U& rhs) noexcept {\n\tif (lhs > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\
    \t}\n\treturn false;\n}\nconstexpr inline lint gcd(lint a, lint b) noexcept {\n\
    \twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\tb = c % b;\n\t}\n\treturn a;\n\
    }\ninline lint lcm(lint a, lint b) noexcept { return a / gcd(a, b) * b; }\nconstexpr\
    \ bool isprime(lint n) noexcept {\n\tif (n == 1) return false;\n\tfor (int i =\
    \ 2; i * i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn true;\n\
    }\ntemplate <class T>\nconstexpr T mypow(T a, lint b) noexcept {\n\tT res(1);\n\
    \twhile (true) {\n\t\tif (b & 1) res *= a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\
    \t\ta *= a;\n\t}\n\treturn res;\n}\nconstexpr lint modpow(lint a, lint b, lint\
    \ m) noexcept {\n\ta %= m;\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) res\
    \ *= a, res %= m;\n\t\ta *= a, a %= m, b >>= 1;\n\t}\n\treturn res;\n}\nLP extGcd(lint\
    \ a, lint b) noexcept {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b, a %\
    \ b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b * s.first;\n\treturn\
    \ s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const lint& b2, const lint&\
    \ m2) noexcept {\n\tauto p = extGcd(m1, m2);\n\tlint g = gcd(m1, m2), l = m1 /\
    \ g * m2;\n\tlint tmp = (b2 - b1) / g * p.first % (m2 / g);\n\tlint r = (b1 +\
    \ m1 * tmp + l) % l;\n\treturn {r, l};\n}\nint LCS(const std::string& a, const\
    \ std::string& b) {\n\tauto dp = make_vec<int>(a.size() + 1, b.size() + 1);\n\t\
    rep(i, a.size()) {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j], dp[i][j]);\n\
    \t\t\tchmax(dp[i][j + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i + 1][j\
    \ + 1], dp[i][j] + 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\
    \t}\n\trep(j, b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn\
    \ dp[a.size()][b.size()];\n}\ntemplate <class T, std::enable_if_t<std::is_convertible<int,\
    \ T>::value, std::nullptr_t> = nullptr>\nvoid compress(std::vector<T>& vec) {\n\
    \tauto tmp = vec;\n\tstd::sort(all(tmp));\n\ttmp.erase(std::unique(all(tmp)),\
    \ tmp.end());\n\tfor (T& i : vec) i = std::lower_bound(all(tmp), i) - tmp.begin();\n\
    }\ntemplate <class T>\nvoid compress(T* l, T* r) {\n\tstd::vector<T> tmp(l, r);\n\
    \tstd::sort(all(tmp));\n\ttmp.erase(std::unique(all(tmp)), tmp.end());\n\tfor\
    \ (auto i = l; i < r; i++) {\n\t\t*i = std::lower_bound(all(tmp), *i) - tmp.begin();\n\
    \t}\n}\ntemplate <class InputIter>\nvoid compress(InputIter l, InputIter r) {\n\
    \tstd::vector<typename InputIter::value_type> tmp(l, r);\n\tstd::sort(all(tmp));\n\
    \ttmp.erase(std::unique(all(tmp)), tmp.end());\n\tfor (auto i = l; i < r; i++)\
    \ {\n\t\t*i = std::lower_bound(all(tmp), *i) - tmp.begin();\n\t}\n}\ntemplate\
    \ <class InputIter,\n\t\t  std::enable_if_t<std::is_same<typename InputIter::value_type,\
    \ std::pair<IP, int>>::value,\n\t\t\t\t\t\t   std::nullptr_t> = nullptr>\nvoid\
    \ mo_sort(InputIter l, InputIter r, int N) {\n\tconst int M = std::max(1.0, std::sqrt(lint(N)\
    \ * N / std::distance(l, r)));\n\tstd::sort(l, r, [M](const auto& lhs, const auto&\
    \ rhs) {\n\t\tif (lhs.first.first / M < rhs.first.first / M) return true;\n\t\t\
    if (lhs.first.first / M == rhs.first.first / M) return lhs.first.second < rhs.first.second;\n\
    \t\treturn false;\n\t});\n\tint before = -1, cnt = 0;\n\tbool f = false;\n\tfor\
    \ (InputIter i = l; i != r; i++) {\n\t\tif (before != i->first.first / M) {\n\t\
    \t\tif (f) std::reverse(i - cnt, i);\n\t\t\tf ^= true, before = i->first.first\
    \ / M, cnt = 1;\n\t\t} else\n\t\t\tcnt++;\n\t}\n\tif (f) std::reverse(r - cnt,\
    \ r);\n}\ntemplate <class T>\nstd::vector<T> xor_bases(const std::vector<T>& vec)\
    \ {\n\tstd::vector<T> res;\n\tfor (T i : vec) {\n\t\tfor (T j : res) {\n\t\t\t\
    chmin(i, i ^ j);\n\t\t}\n\t\tif (i) res.emplace_back(i);\n\t}\n\treturn res;\n\
    }\n#line 3 \"other/type_traits.hpp\"\n\nclass ModInt__Base {};\nclass StaticModInt__Base\
    \ : ModInt__Base {};\nclass DynamicModInt__Base : ModInt__Base {};\n\ntemplate\
    \ <class T>\nclass is_ModInt : public std::is_base_of<ModInt__Base, T> {};\ntemplate\
    \ <class T>\nconstexpr bool is_ModInt_v = is_ModInt<T>::value;\n\ntemplate <class\
    \ T>\nclass is_StaticModInt : public std::is_base_of<StaticModInt__Base, T> {};\n\
    template <class T>\nconstexpr bool is_StaticModInt_v = is_StaticModInt<T>::value;\n\
    \ntemplate <class T>\nclass is_DynamicModInt : public std::is_base_of<DynamicModInt__Base,\
    \ T> {};\ntemplate <class T>\nconstexpr bool is_DynamicModInt_v = is_DynamicModInt<T>::value;\n\
    #line 4 \"math/StaticModInt.hpp\"\ntemplate <int modulo>\nclass StaticModInt :\
    \ StaticModInt__Base {\n\tuint value;\n\tstatic constexpr int inv1000000007[]\
    \ = {0,\t\t   1,\t\t  500000004, 333333336,\n\t\t\t\t\t\t\t\t\t\t\t250000002,\
    \ 400000003, 166666668, 142857144,\n\t\t\t\t\t\t\t\t\t\t\t125000001, 111111112,\
    \ 700000005},\n\t\t\t\t\t\t inv998244353[] = {0,\t\t  1,\t\t 499122177, 332748118,\n\
    \t\t\t\t\t\t\t\t\t\t   748683265, 598946612, 166374059, 855638017,\n\t\t\t\t\t\
    \t\t\t\t\t   873463809, 443664157, 299473306};\n\n  public:\n\tstatic constexpr\
    \ int mod_value = modulo;\n\n\tconstexpr StaticModInt() : value(0) {}\n\ttemplate\
    \ <class T, std::enable_if_t<!std::is_convertible<T, StaticModInt>::value,\n\t\
    \t\t\t\t\t\t\t\t\tstd::nullptr_t> = nullptr>\n\tconstexpr StaticModInt(T value\
    \ = 0) : value(value % modulo) {\n\t\tif (this->value < 0) this->value += modulo;\n\
    \t}\n\tinline constexpr StaticModInt inv() const {\n\t\tif constexpr (modulo ==\
    \ 1000000007) {\n\t\t\tif (*this <= 10) return inv1000000007[*this];\n\t\t} else\
    \ if constexpr (modulo == 998244353) {\n\t\t\tif (*this <= 10) return inv998244353[*this];\n\
    \t\t}\n\t\treturn mypow(*this, modulo - 2);\n\t}\n\tinline constexpr StaticModInt\
    \ pow(lint k) const { return mypow(*this, k); }\n\tinline constexpr operator int()\
    \ const { return value; }\n\tinline constexpr StaticModInt& operator+=(const StaticModInt&\
    \ x) {\n\t\tvalue = value + x.value;\n\t\tif (value >= modulo) value -= modulo;\n\
    \t\treturn *this;\n\t}\n\tinline constexpr StaticModInt& operator++() {\n\t\t\
    if (value == modulo - 1)\n\t\t\tvalue = 0;\n\t\telse\n\t\t\tvalue++;\n\t\treturn\
    \ *this;\n\t}\n\tinline constexpr StaticModInt operator++(int) {\n\t\tStaticModInt\
    \ res = *this;\n\t\t++*this;\n\t\treturn res;\n\t}\n\tinline constexpr StaticModInt\
    \ operator-() const { return StaticModInt(0) -= *this; }\n\tinline constexpr StaticModInt&\
    \ operator-=(const StaticModInt& x) {\n\t\tif (value < x.value) value += modulo;\n\
    \t\tvalue -= x.value;\n\t\treturn *this;\n\t}\n\tinline constexpr StaticModInt&\
    \ operator--() {\n\t\tif (value == 0)\n\t\t\tvalue = modulo - 1;\n\t\telse\n\t\
    \t\tvalue--;\n\t\treturn *this;\n\t}\n\tinline constexpr StaticModInt operator--(int)\
    \ {\n\t\tStaticModInt res = *this;\n\t\t--*this;\n\t\treturn res;\n\t}\n\tinline\
    \ constexpr StaticModInt& operator*=(const StaticModInt& x) {\n\t\tvalue = (ulint)value\
    \ * x.value % modulo;\n\t\treturn *this;\n\t}\n\tinline constexpr StaticModInt&\
    \ operator/=(const StaticModInt& rhs) {\n\t\treturn *this *= rhs.inv();\n\t}\n\
    \ttemplate <class T>\n\tconstexpr StaticModInt operator+(const T& rhs) const {\n\
    \t\treturn StaticModInt(*this) += rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ StaticModInt& operator+=(const T& rhs) {\n\t\treturn operator+=(StaticModInt(rhs));\n\
    \t}\n\ttemplate <class T>\n\tconstexpr StaticModInt operator-(const T& rhs) const\
    \ {\n\t\treturn StaticModInt(*this) -= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ StaticModInt& operator-=(const T& rhs) {\n\t\treturn operator-=(StaticModInt(rhs));\n\
    \t}\n\ttemplate <class T>\n\tconstexpr StaticModInt operator*(const T& rhs) const\
    \ {\n\t\treturn StaticModInt(*this) *= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ StaticModInt& operator*=(const T& rhs) {\n\t\treturn operator*=(StaticModInt(rhs));\n\
    \t}\n\ttemplate <class T>\n\tconstexpr StaticModInt operator/(const T& rhs) const\
    \ {\n\t\treturn StaticModInt(*this) /= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ StaticModInt& operator/=(const T& rhs) {\n\t\treturn operator/=(StaticModInt(rhs));\n\
    \t}\n\tconstexpr static StaticModInt primitive_root() {\n\t\tif constexpr (modulo\
    \ == 1012924417) return 5;\n\t\tif constexpr (modulo == 924844033) return 5;\n\
    \t\tif constexpr (modulo == 998244353) return 3;\n\t\tif constexpr (modulo ==\
    \ 1224736769) return 3;\n\t\tif constexpr (modulo == 167772161) return 3;\n\t\t\
    if constexpr (modulo == 469762049) return 3;\n\t\tif constexpr (modulo == 1107296257)\
    \ return 10;\n\n\t\tint p = 0;\n\t\tstd::mt19937 mt(0);\n\t\tstd::uniform_int_distribution<>\
    \ uid(1, modulo - 1);\n\t\tif (p) return p;\n\n\t\t// use naive factorize due\
    \ to file size limit\n\t\tstd::vector<int> vec;\n\t\tint tmp = modulo - 1;\n\t\
    \tfor (int i = 2; i * i <= tmp; i++) {\n\t\t\tif (tmp % i == 0) {\n\t\t\t\tvec.emplace_back(i);\n\
    \t\t\t\tdo {\n\t\t\t\t\ttmp /= i;\n\t\t\t\t} while (tmp % i == 0);\n\t\t\t}\n\t\
    \t}\n\t\tif (tmp != 1) vec.emplace_back(tmp);\n\n\t\twhile (true) {\n\t\t\tp =\
    \ uid(mt);\n\t\t\tbool f = true;\n\t\t\tfor (const auto& i : vec) {\n\t\t\t\t\
    if (mypow(StaticModInt(p), (modulo - 1) / i) == 1) {\n\t\t\t\t\tf = false;\n\t\
    \t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (f) return p;\n\t\t}\n\t}\n};\ntemplate\
    \ <int modulo, class Stream>\nStream& operator>>(Stream& ist, StaticModInt<modulo>&\
    \ x) {\n\tlint a;\n\tist >> a;\n\tx = a;\n\treturn ist;\n}\ntemplate <int modulo,\
    \ class Stream>\nStream& operator<<(Stream& ost, const StaticModInt<modulo>& x)\
    \ {\n\tost << int(x);\n\treturn ost;\n}\n\n#if __cplusplus < 201703L\ntemplate\
    \ <int modulo>\nconstexpr int StaticModInt<modulo>::inv1000000007[];\ntemplate\
    \ <int modulo>\nconstexpr int StaticModInt<modulo>::inv998244353[];\n#endif\n\n\
    /**\n * @title StaticModInt\n */\n#line 4 \"math/NumberTheoreticTransform.hpp\"\
    \n// 1012924417, 5, 2^21\n// 924844033, 5, 2^21\n// 998244353, 3, 2^23\n// 1224736769,\
    \ 3, 2^24\n// 167772161, 3, 2^25\n// 1107296257, 10, 2^25\n// 469762049, 3, 2^26\n\
    class NumberTheoreticTransform {\n\tstatic int constexpr friendly_limit(int p)\
    \ { return __builtin_ffs(p - 1) - 1; }\n\n  public:\n\ttemplate <int modulo>\n\
    \tstatic void ntt(std::vector<StaticModInt<modulo>>& a, bool inverse,\n\t\t\t\t\
    \tint size = -1) {  // size should be one of powers of two\n\t\tif (size == -1)\
    \ size = a.size();\n\t\tif (size == 1) return;\n\t\ta.resize(size);\n\t\tconst\
    \ StaticModInt<modulo> root = StaticModInt<modulo>::primitive_root().pow(\n\t\t\
    \tinverse ? modulo - 1 - (modulo - 1) / size : (modulo - 1) / size);\n\n\t\tstd::vector<StaticModInt<modulo>>\
    \ b(size);\n\t\tStaticModInt<modulo> r_p = root;\n\t\tfor (int i = size >> 1,\
    \ w = 1; w < size; i >>= 1, w <<= 1) {\n\t\t\tStaticModInt<modulo> r_pp = 1;\n\
    \t\t\tfor (int j = 0; j < i; j++, r_pp *= r_p) {\n\t\t\t\tfor (int k = 0; k <\
    \ w; k++) {\n\t\t\t\t\tb[k + ((w * j) << 1)] = a[k + w * j] + a[k + w * j + (size\
    \ >> 1)];\n\t\t\t\t\tb[k + ((w * j) << 1) + w] = r_pp * (a[k + w * j] - a[k +\
    \ w * j + (size >> 1)]);\n\t\t\t\t}\n\t\t\t}\n\t\t\tstd::swap(a, b);\n\t\t\tr_p\
    \ *= r_p;\n\t\t}\n\t}\n\n  private:\n\ttemplate <class T, int modulo>\n\tstatic\
    \ std::vector<StaticModInt<modulo>> internal_convolution(const std::vector<T>&\
    \ f_,\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  const std::vector<T>& g_) {\n\t\tstd::vector<StaticModInt<modulo>>\
    \ f(f_.size()), g(g_.size());\n\t\trep(i, f_.size()) f[i] = f_[i];\n\t\trep(i,\
    \ g_.size()) g[i] = g_[i];\n\t\treturn internal_convolution(std::move(f), std::move(g));\n\
    \t}\n\ttemplate <int modulo>\n\tstatic std::vector<StaticModInt<modulo>> internal_convolution(\n\
    \t\tconst std::vector<StaticModInt<modulo>>& f, const std::vector<StaticModInt<modulo>>&\
    \ g) {\n\t\tauto f_ = f, g_ = g;\n\t\treturn internal_convolution(std::move(f_),\
    \ std::move(g_));\n\t}\n\ttemplate <int modulo>\n\tstatic std::vector<StaticModInt<modulo>>\
    \ internal_convolution(\n\t\tconst std::vector<StaticModInt<modulo>>& f, std::vector<StaticModInt<modulo>>&&\
    \ g) {\n\t\tauto f_ = f;\n\t\treturn internal_convolution(std::move(f_), std::move(g));\n\
    \t}\n\ttemplate <int modulo>\n\tstatic std::vector<StaticModInt<modulo>> internal_convolution(\n\
    \t\tstd::vector<StaticModInt<modulo>>& f, const std::vector<StaticModInt<modulo>>&&\
    \ g) {\n\t\tauto g_ = g;\n\t\treturn internal_convolution(std::move(f), std::move(g_));\n\
    \t}\n\ttemplate <int modulo>\n\tstatic std::vector<StaticModInt<modulo>> internal_convolution(\n\
    \t\tstd::vector<StaticModInt<modulo>>&& f, std::vector<StaticModInt<modulo>>&&\
    \ g) {\n\t\tsize_t target_size = f.size() + g.size() - 1, sz = 1;\n\t\twhile (sz\
    \ < target_size) sz <<= 1;\n\t\tf.resize(sz), g.resize(sz);\n\t\tntt(f, false),\
    \ ntt(g, false);\n\t\trep(i, f.size()) f[i] *= g[i];\n\t\tntt(f, true);\n\t\t\
    StaticModInt<modulo> inv = StaticModInt<modulo>(sz).inv();\n\t\trep(i, f.size())\
    \ f[i] *= inv;\n\t\tf.resize(target_size);\n\t\treturn std::move(f);\n\t}\n\n\
    \  public:\n\ttemplate <int modulo>\n\tstatic std::vector<StaticModInt<modulo>>\
    \ convolution(\n\t\tconst std::vector<StaticModInt<modulo>>& f, const std::vector<StaticModInt<modulo>>&\
    \ g) {\n\t\tif (1 << friendly_limit(modulo) >= f.size() + g.size() - 1) {\n\t\t\
    \tauto f_ = f, g_ = g;\n\t\t\treturn internal_convolution<modulo>(std::move(f_),\
    \ std::move(g_));\n\t\t} else if (1 << friendly_limit(modulo) + 2 >= f.size()\
    \ + g.size() - 1) {\n\t\t\tint sz = 1 << friendly_limit(modulo) - 1;\n\t\t\tstd::vector<std::vector<StaticModInt<modulo>>>\
    \ f_, g_;\n\t\t\tfor (int i = 0; i * sz < f.size(); i++)\n\t\t\t\tf_.emplace_back(f.begin()\
    \ + i * sz,\n\t\t\t\t\t\t\t\tf.begin() + std::min((int)f.size(), (i + 1) * sz));\n\
    \t\t\tfor (int i = 0; i * sz < g.size(); i++)\n\t\t\t\tg_.emplace_back(g.begin()\
    \ + i * sz,\n\t\t\t\t\t\t\t\tg.begin() + std::min((int)g.size(), (i + 1) * sz));\n\
    \t\t\tstd::vector<StaticModInt<modulo>> res(f.size() + g.size() - 1);\n\t\t\t\
    rep(i, f_.size()) {\n\t\t\t\trep(j, g_.size()) {\n\t\t\t\t\tauto tmp =\n\t\t\t\
    \t\t\tinternal_convolution<modulo>(j == g_.size() - 1 ? std::move(f_[i]) : f_[i],\n\
    \t\t\t\t\t\t\t\t\t\t\t\t\t i == f_.size() - 1 ? std::move(g_[j]) : g_[j]);\n\t\
    \t\t\t\trep(k, tmp.size()) res[(i + j) * sz + k] += tmp[k];\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\treturn res;\n\t\t}\n\t\tconstexpr int base1 = 167772161, base2 = 1107296257,\
    \ base3 = 469762049;\n\t\tauto re1 = internal_convolution<StaticModInt<modulo>,\
    \ base1>(f, g);\n\t\tauto re2 = internal_convolution<StaticModInt<modulo>, base2>(f,\
    \ g);\n\t\tauto re3 = internal_convolution<StaticModInt<modulo>, base3>(f, g);\n\
    \t\tstd::vector<StaticModInt<modulo>> res(re1.size());\n\t\tconstexpr int r12\
    \ = StaticModInt<base2>(base1).inv();\n\t\tconstexpr int r13 = StaticModInt<base3>(base1).inv();\n\
    \t\tconstexpr int r23 = StaticModInt<base3>(base2).inv();\n\t\trep(i, re1.size())\
    \ {\n\t\t\tre2[i] = StaticModInt<base2>(re2[i] - re1[i]) * r12;\n\t\t\tre3[i]\
    \ = (StaticModInt<base3>(re3[i] - re1[i]) * r13 - re2[i]) * r23;\n\t\t\tres[i]\
    \ = StaticModInt<modulo>(re1[i]) + StaticModInt<modulo>(re2[i]) * base1 +\n\t\t\
    \t\t\t StaticModInt<modulo>(re3[i]) * base1 * base2;\n\t\t}\n\t\treturn res;\n\
    \t}\n\ttemplate <int modulo, class T>\n\tstatic std::vector<StaticModInt<modulo>>\
    \ convolution(const std::vector<T>& f,\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t const std::vector<T>&\
    \ g) {\n\t\tstd::vector<StaticModInt<modulo>> f_(f.size()), g_(g.size());\n\t\t\
    rep(i, f.size()) f_[i] = f[i];\n\t\trep(i, g.size()) g_[i] = g[i];\n\t\treturn\
    \ convolution(f_, g_);\n\t}\n\ttemplate <class T>\n\tstatic std::vector<lint>\
    \ convolution_plain(const std::vector<T>& f, const std::vector<T>& g) {\n\t\t\
    const int mod1 = 998244353, mod2 = 1224736769;\n\t\tstd::vector<StaticModInt<mod1>>\
    \ mul1 = internal_convolution<T, mod1>(f, g);\n\t\tstd::vector<StaticModInt<mod2>>\
    \ mul2 = internal_convolution<T, mod2>(f, g);\n\t\tstd::vector<lint> res(mul1.size());\n\
    \t\trep(i, mul1.size()) res[i] = ChineseRem(mul1[i], mod1, mul2[i], mod2).first;\n\
    \t\treturn res;\n\t}\n};\n\n/**\n * @title NumberTheoreticTransform\n */\n#line\
    \ 4 \"math/FormalPowerSeries.hpp\"\n\ntemplate <class T, std::enable_if_t<is_ModInt_v<T>,\
    \ std::nullptr_t> = nullptr>\nclass FormalPowerSeries : public std::vector<T>\
    \ {\n  private:\n\tusing NTT = NumberTheoreticTransform;\n\tusing FPS = FormalPowerSeries<T>;\n\
    \tusing std::vector<T>::vector;\n\n  public:\n\tFormalPowerSeries(const std::vector<T>&\
    \ vec) : std::vector<T>(vec) {}\n\n\tFPS operator-() const {\n\t\tFPS res(*this);\n\
    \t\tfor (T& i : res) i = -i;\n\t\treturn res;\n\t}\n\n\ttemplate <class U>\n\t\
    FPS& operator+=(const U& v) {\n\t\tif (this->empty())\n\t\t\tthis->emplace_back(v);\n\
    \t\telse\n\t\t\t(*this)[0] += v;\n\t\treturn *this;\n\t}\n\ttemplate <class U>\n\
    \tFPS operator+(const U& v) const {\n\t\tFPS res(*this);\n\t\treturn res += v;\n\
    \t}\n\tFPS operator+=(const FPS& f) {\n\t\tthis->resize(std::max(this->size(),\
    \ f.size()));\n\t\trep(i, this->size())(*this)[i] += f[i];\n\t\treturn *this;\n\
    \t}\n\tFPS operator+(const FPS& f) const {\n\t\tFPS res(*this);\n\t\treturn res\
    \ += f;\n\t}\n\n\ttemplate <class U>\n\tFPS& operator-=(const U& v) {\n\t\tif\
    \ (this->empty())\n\t\t\tthis->emplace_back(-v);\n\t\telse\n\t\t\t(*this)[0] -=\
    \ v;\n\t\treturn *this;\n\t}\n\ttemplate <class U>\n\tFPS operator-(const U& v)\
    \ const {\n\t\tFPS res(*this);\n\t\treturn res -= v;\n\t}\n\tFPS operator-=(const\
    \ FPS& f) {\n\t\tthis->resize(std::max(this->size(), f.size()));\n\t\trep(i, std::min(this->size(),\
    \ f.size()))(*this)[i] -= f[i];\n\t\treturn *this;\n\t}\n\tFPS operator-(const\
    \ FPS& f) const {\n\t\tFPS res(*this);\n\t\treturn res -= f;\n\t}\n\n\ttemplate\
    \ <class U>\n\tFPS& operator*=(const U& v) {\n\t\tfor (T& i : *this) i *= v;\n\
    \t\treturn *this;\n\t}\n\ttemplate <class U>\n\tFPS operator*(const U& v) const\
    \ {\n\t\tFPS res(*this);\n\t\treturn res *= v;\n\t}\n\tFPS operator*=(const FPS&\
    \ f) {\n\t\t*this = NTT::convolution(*this, f);\n\t\treturn *this;\n\t}\n\tFPS\
    \ operator*(const FPS& f) const { return NTT::convolution(*this, f); }\n\n\ttemplate\
    \ <class U>\n\tFPS& operator/=(const U& v) {\n\t\treturn *this *= T(v).inv();\n\
    \t}\n\ttemplate <class U>\n\tFPS operator/(const U& v) const {\n\t\treturn *this\
    \ * T(v).inv();\n\t}\n\tFPS operator/=(const FPS& f) {\n\t\t*this = *this * f.inv();\n\
    \t\treturn *this;\n\t}\n\tFPS operator/(const FPS& f) const { return *this * f.inv();\
    \ }\n\n\tvoid differentiate() {\n\t\tthis->erase(this->begin());\n\t\tREP(i, this->size())(*this)[i\
    \ - 1] *= i;\n\t}\n\t[[nodiscard]] FPS differential() {\n\t\tFPS res = *this;\n\
    \t\tres.differentiate();\n\t\treturn res;\n\t}\n\n\tvoid integrate() {\n\t\tthis->insert(this->begin(),\
    \ 0);\n\t\tREP(i, this->size() - 1)(*this)[i] /= i;\n\t}\n\t[[nodiscard]] FPS\
    \ integral() {\n\t\tFPS res = *this;\n\t\tres.integrate();\n\t\treturn res;\n\t\
    }\n\n\tvoid invert() { invert(this->size()); }\n\tvoid invert(size_t len) { *this\
    \ = FPS(len); }\n\t[[nodiscard]] FPS inv() const { return inv(this->size()); }\n\
    \t[[nodiscard]] FPS inv(size_t len) const {\n\t\tFPS res;\n\t\tsize_t n = 1;\n\
    \t\tres.emplace_back((*this)[0].inv());\n\t\twhile (n < len) {\n\t\t\tn <<= 1;\n\
    \t\t\tFPS f(n), g(n);\n\t\t\trep(i, std::min(this->size(), n)) f[i] = (*this)[i];\n\
    \t\t\trep(i, res.size()) g[i] = res[i];\n\t\t\tNTT::ntt(f, false, n);\n\t\t\t\
    NTT::ntt(g, false, n);\n\t\t\trep(i, n) f[i] *= g[i];\n\t\t\tNTT::ntt(f, true,\
    \ n);\n\t\t\tT inv = T(n).inv();\n\t\t\trep(i, n >> 1) f[i] = 0, f[i + (n >> 1)]\
    \ *= inv;\n\t\t\tNTT::ntt(f, false, n);\n\t\t\trep(i, n) f[i] *= g[i];\n\t\t\t\
    NTT::ntt(f, true, n);\n\t\t\trep(i, n >> 1) f[i + (n >> 1)] *= -inv;\n\t\t\tres.insert(res.end(),\
    \ f.begin() + (n >> 1), f.begin() + n);\n\t\t}\n\t\tres.resize(len);\n\t\treturn\
    \ std::move(res);\n\t}\n\n\t[[nodiscard]] FPS log() { return log(this->size());\
    \ }\n\t[[nodiscard]] FPS log(size_t len) {\n\t\tFPS differentiated = differential();\n\
    \t\tFPS tmp = differentiated / *this;\n\t\ttmp.resize(len - 1);\n\t\treturn tmp.integral();\n\
    \t}\n\n\t[[nodiscard]] FPS exp() { return exp(this->size()); }\n\t[[nodiscard]]\
    \ FPS exp(size_t len) {\n\t\tFPS res(1, 1);\n\t\tsize_t n = 1;\n\t\twhile (n <\
    \ len) {\n\t\t\tn <<= 1;\n\t\t\tauto tmp = *this + 1;\n\t\t\ttmp -= res.log(n);\n\
    \t\t\tres *= tmp;\n\t\t\tres.resize(std::min(len, 2 * n));\n\t\t}\n\t\treturn\
    \ res;\n\t}\n\n\t[[nodiscard]] FPS pow(lint k) { return pow(k, this->size());\
    \ }\n\t[[nodiscard]] FPS pow(lint k, size_t len) {\n\t\trep(i, len) {\n\t\t\t\
    if (i && (len < k || len < k * i)) break;\n\t\t\tif ((*this)[i]) {\n\t\t\t\tFPS\
    \ res = FPS(this->begin() + i, this->end()) / (*this)[i];\n\t\t\t\tres = (res.log()\
    \ * k).exp();\n\t\t\t\tres.resize(len);\n\t\t\t\tT c = (*this)[i].pow(k);\n\t\t\
    \t\tfor (int j = len - 1; j >= 0; j--) {\n\t\t\t\t\tif (i && (j < k || j < k *\
    \ i))\n\t\t\t\t\t\tres[j] = 0;\n\t\t\t\t\telse\n\t\t\t\t\t\tres[j] = res[j - i\
    \ * k] * c;\n\t\t\t\t}\n\t\t\t\treturn res;\n\t\t\t}\n\t\t}\n\t\tFPS res(len);\n\
    \t\tif (!k) res[0] = 1;\n\t\treturn res;\n\t}\n};\n#line 5 \"test/yosupo/exp_of_formal_power_series.test.cpp\"\
    \n\nusing ModInt = StaticModInt<998244353>;\nusing FPS = FormalPowerSeries<ModInt>;\n\
    int main() {\n\tint N;\n\tFPS vec;\n\tstd::cin >> N >> vec;\n\tstd::cout << vec.exp()\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_formal_power_series\"\
    \n#include \"../../other/template.hpp\"\n#include \"../../math/StaticModInt.hpp\"\
    \n#include \"../../math/FormalPowerSeries.hpp\"\n\nusing ModInt = StaticModInt<998244353>;\n\
    using FPS = FormalPowerSeries<ModInt>;\nint main() {\n\tint N;\n\tFPS vec;\n\t\
    std::cin >> N >> vec;\n\tstd::cout << vec.exp() << std::endl;\n}"
  dependsOn:
  - other/template.hpp
  - math/StaticModInt.hpp
  - other/type_traits.hpp
  - math/FormalPowerSeries.hpp
  - math/NumberTheoreticTransform.hpp
  isVerificationFile: true
  path: test/yosupo/exp_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2023-06-16 19:42:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/exp_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/exp_of_formal_power_series.test.cpp
- /verify/test/yosupo/exp_of_formal_power_series.test.cpp.html
title: test/yosupo/exp_of_formal_power_series.test.cpp
---
