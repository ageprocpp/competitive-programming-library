---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/SegTree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: math/StaticModInt.hpp
    title: StaticModInt
  - icon: ':question:'
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo/point_set_range_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n#line\
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
    #include <vector>\n\n#define rep(i, n) for (int i = 0; i < int(n); i++)\n#define\
    \ REP(i, n) for (int i = 1; i <= int(n); i++)\n#define all(V) V.begin(), V.end()\n\
    \nusing i128 = __int128_t;\nusing u128 = __uint128_t;\nusing uint = unsigned int;\n\
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
    \ make_vec<T>(std::forward<Args>(args)...));\n}\ntemplate <class T, class U>\n\
    std::istream& operator>>(std::istream& ist, std::pair<T, U>& x) {\n\treturn ist\
    \ >> x.first >> x.second;\n}\ntemplate <class T, class U>\nstd::ostream& operator<<(std::ostream&\
    \ ost, const std::pair<T, U>& x) {\n\treturn ost << x.first << \" \" << x.second;\n\
    }\ntemplate <class Container,\n\t\t  std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value, std::nullptr_t> = nullptr>\nauto operator>>(std::istream&\
    \ ist, Container& cont)\n\t-> decltype(typename Container::iterator(), std::cin)&\
    \ {\n\tContainer tmp;\n\twhile (true) {\n\t\ttypename Container::value_type t;\n\
    \t\tist >> t;\n\t\ttmp.emplace_back(t);\n\t\tif (getchar() == '\\n') break;\n\t\
    }\n\tcont = Container(std::move(tmp));\n\treturn ist;\n}\ntemplate <class Container,\n\
    \t\t  std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t>\
    \ = nullptr>\nauto operator<<(std::ostream& ost, const Container& cont)\n\t->\
    \ decltype(typename Container::iterator(), std::cout)& {\n\tfor (auto it = cont.begin();\
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
    \n/**\n * @title StaticModInt\n */\n#line 3 \"data-structure/SegTree.hpp\"\ntemplate\
    \ <class T, T (*nodef)(const T&, const T&)>\nclass SegTree {\n  protected:\n\t\
    unsigned int n = 1, m = 1, rank = 0;\n\tstd::vector<T> node;\n\tT ident;\n\n \
    \ public:\n\tSegTree(T e_) : ident(e_) {}\n\tSegTree(unsigned int m_, T e_) :\
    \ m(m_), ident(e_) {\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t\
    }\n\t\tnode.resize(2 * n, ident);\n\t}\n\tSegTree(unsigned int m_, T init, T e_)\
    \ : m(m_), ident(e_) {\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t\
    }\n\t\tnode.resize(2 * n, ident);\n\t\tfor (unsigned int i = n; i < 2 * n; i++)\
    \ node[i] = init;\n\t\tfor (unsigned int i = n - 1; i > 0; i--) node[i] = nodef(node[i\
    \ << 1], node[i << 1 | 1]);\n\t}\n\ttemplate <class U>\n\tSegTree(const std::vector<U>&\
    \ initvec, T e_) : ident(e_) {\n\t\tm = initvec.size();\n\t\twhile (n < m) {\n\
    \t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2 * n, ident);\n\t\tfor (unsigned\
    \ int i = n; i < 2 * n; i++) {\n\t\t\tif (i - n < m) node[i] = initvec[i - n];\n\
    \t\t}\n\t\tfor (unsigned int i = n - 1; i > 0; i--) node[i] = nodef(node[i <<\
    \ 1], node[i << 1 | 1]);\n\t}\n\tvoid update(int i, T x) {\n\t\ti += n;\n\t\t\
    node[i] = x;\n\t\twhile (i != 1) {\n\t\t\ti >>= 1;\n\t\t\tnode[i] = nodef(node[2\
    \ * i], node[2 * i + 1]);\n\t\t}\n\t}\n\tT query(int l, int r) const {\n\t\tl\
    \ += n;\n\t\tr += n;\n\t\tT ls = ident, rs = ident;\n\t\twhile (l < r) {\n\t\t\
    \tif (l & 1) ls = nodef(ls, node[l++]);\n\t\t\tif (r & 1) rs = nodef(node[--r],\
    \ rs);\n\t\t\tl >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t\treturn nodef(ls, rs);\n\t}\n\
    \tconst T& operator[](const int& i) const { return node[n + i]; }\n\tT query_all()\
    \ const { return node[1]; }\n\tvoid fill(T x) {\n\t\tfor (unsigned int i = n;\
    \ i < 2 * n; i++) node[i] = x;\n\t\tfor (unsigned int i = n - 1; i > 0; i--) node[i]\
    \ = nodef(node[i << 1], node[i << 1 | 1]);\n\t}\n\n  private:\n\ttemplate <class\
    \ F>\n\tint max_right(int st, F& check, T& acc, int k, int l, int r) const {\n\
    \t\tif (l + 1 == r) {\n\t\t\tacc = nodef(acc, node[k]);\n\t\t\treturn check(acc)\
    \ ? m : k - n;\n\t\t}\n\t\tint mid = (l + r) >> 1;\n\t\tif (mid <= st) return\
    \ max_right(st, check, acc, (k << 1) | 1, mid, r);\n\t\tif (st <= l && check(nodef(acc,\
    \ node[k]))) {\n\t\t\tacc = nodef(acc, node[k]);\n\t\t\treturn m;\n\t\t}\n\t\t\
    int vl = max_right(st, check, acc, k << 1, l, mid);\n\t\tif (vl != m) return vl;\n\
    \t\treturn max_right(st, check, acc, (k << 1) | 1, mid, r);\n\t}\n\n\ttemplate\
    \ <class F>\n\tint min_left(int st, F& check, T& acc, int k, int l, int r) const\
    \ {\n\t\tif (l + 1 == r) {\n\t\t\tacc = nodef(node[k], acc);\n\t\t\treturn check(acc)\
    \ ? 0 : k - n + 1;\n\t\t}\n\t\tint mid = (l + r) >> 1;\n\t\tif (st <= mid) return\
    \ min_left(st, check, acc, k << 1, l, mid);\n\t\tif (r <= st && check(nodef(node[k],\
    \ acc))) {\n\t\t\tacc = nodef(node[k], acc);\n\t\t\treturn 0;\n\t\t}\n\t\tint\
    \ vr = min_left(st, check, acc, (k << 1) | 1, mid, r);\n\t\tif (vr != 0) return\
    \ vr;\n\t\treturn min_left(st, check, acc, k << 1, l, mid);\n\t}\n\n  public:\n\
    \ttemplate <class F>\n\tint max_right(int st, F check) const {\n\t\tT acc = ident;\n\
    \t\treturn max_right(st, check, acc, 1, 0, n);\n\t}\n\ttemplate <bool (*check)(const\
    \ T&)>\n\tint max_right(int st) const {\n\t\tT acc = ident;\n\t\treturn max_right(st,\
    \ check, acc, 1, 0, n);\n\t}\n\n\ttemplate <class F>\n\tint min_left(int st, F\
    \ check) const {\n\t\tT acc = ident;\n\t\treturn min_left(st, check, acc, 1, 0,\
    \ n);\n\t}\n\ttemplate <bool (*check)(const T&)>\n\tint min_left(int st) const\
    \ {\n\t\tT acc = ident;\n\t\treturn min_left(st, check, acc, 1, 0, n);\n\t}\n\
    };\nnamespace {\n\ttemplate <typename T>\n\tT RSQ_nodef(const T& lhs, const T&\
    \ rhs) {\n\t\treturn lhs + rhs;\n\t}\n\ttemplate <typename T>\n\tT RMiQ_nodef(const\
    \ T& lhs, const T& rhs) {\n\t\treturn std::min(lhs, rhs);\n\t}\n\ttemplate <typename\
    \ T>\n\tT RMaQ_nodef(const T& lhs, const T& rhs) {\n\t\treturn std::max(lhs, rhs);\n\
    \t}\n}  // namespace\n\ntemplate <typename T>\nclass RSQ : public SegTree<T, RSQ_nodef>\
    \ {\n\tusing Base = SegTree<T, RSQ_nodef>;\n\n  public:\n\ttemplate <class...\
    \ Args>\n\tRSQ(Args&&... args) : Base(std::forward<Args>(args)..., 0) {}\n};\n\
    \ntemplate <typename T, typename U = void>\nclass RMiQ : public SegTree<T, RMiQ_nodef>\
    \ {\n\tusing Base = SegTree<T, RMiQ_nodef>;\n\n  public:\n\ttemplate <class...\
    \ Args>\n\tRMiQ(Args&&... args) : Base(std::forward<Args>(args)...) {}\n};\ntemplate\
    \ <typename T>\nclass RMiQ<T, std::enable_if_t<std::numeric_limits<T>::is_specialized,\
    \ std::nullptr_t>>\n\t: public SegTree<T, RMiQ_nodef> {\n\tusing Base = SegTree<T,\
    \ RMiQ_nodef>;\n\n  public:\n\ttemplate <class... Args>\n\tRMiQ(Args&&... args)\
    \ : Base(std::forward<Args>(args)..., std::numeric_limits<T>::max()) {}\n};\n\n\
    template <typename T, typename U = void>\nclass RMaQ : public SegTree<T, RMaQ_nodef>\
    \ {\n\tusing Base = SegTree<T, RMaQ_nodef>;\n\n  public:\n\ttemplate <class...\
    \ Args>\n\tRMaQ(Args&&... args) : Base(std::forward<Args>(args)...) {}\n};\ntemplate\
    \ <typename T>\nclass RMaQ<T, std::enable_if_t<std::numeric_limits<T>::is_specialized,\
    \ std::nullptr_t>>\n\t: public SegTree<T, RMaQ_nodef> {\n\tusing Base = SegTree<T,\
    \ RMaQ_nodef>;\n\n  public:\n\ttemplate <class... Args>\n\tRMaQ(Args&&... args)\
    \ : Base(std::forward<Args>(args)..., std::numeric_limits<T>::min()) {}\n};\n\
    #line 5 \"test/yosupo/point_set_range_composite.test.cpp\"\nusing ModInt = StaticModInt<998244353>;\n\
    using MP = std::pair<ModInt, ModInt>;\nMP nodef(const MP& lhs, const MP& rhs)\
    \ {\n\treturn {lhs.first * rhs.first, lhs.second * rhs.first + rhs.second};\n\
    }\nclass MySeg : public SegTree<MP, nodef> {\n\tusing Base = SegTree<MP, nodef>;\n\
    \n  public:\n\tMySeg(int n) : Base(n, MP{0, 0}, MP{1, 0}) {}\n};\nint n, q;\n\
    int main() {\n\tscanf(\"%d%d\", &n, &q);\n\tMySeg st(n);\n\trep(i, n) {\n\t\t\
    int a, b;\n\t\tscanf(\"%d%d\", &a, &b);\n\t\tst.update(i, {a, b});\n\t}\n\trep(i,\
    \ q) {\n\t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\tint p, c,\
    \ d;\n\t\t\tscanf(\"%d%d%d\", &p, &c, &d);\n\t\t\tst.update(p, {c, d});\n\t\t\
    } else {\n\t\t\tint l, r, x;\n\t\t\tscanf(\"%d%d%d\", &l, &r, &x);\n\t\t\tauto\
    \ p = st.query(l, r);\n\t\t\tprintf(\"%d\\n\", p.first * x + p.second);\n\t\t\
    }\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"../../math/StaticModInt.hpp\"\n#include \"../../data-structure/SegTree.hpp\"\
    \n#include \"../../other/template.hpp\"\nusing ModInt = StaticModInt<998244353>;\n\
    using MP = std::pair<ModInt, ModInt>;\nMP nodef(const MP& lhs, const MP& rhs)\
    \ {\n\treturn {lhs.first * rhs.first, lhs.second * rhs.first + rhs.second};\n\
    }\nclass MySeg : public SegTree<MP, nodef> {\n\tusing Base = SegTree<MP, nodef>;\n\
    \n  public:\n\tMySeg(int n) : Base(n, MP{0, 0}, MP{1, 0}) {}\n};\nint n, q;\n\
    int main() {\n\tscanf(\"%d%d\", &n, &q);\n\tMySeg st(n);\n\trep(i, n) {\n\t\t\
    int a, b;\n\t\tscanf(\"%d%d\", &a, &b);\n\t\tst.update(i, {a, b});\n\t}\n\trep(i,\
    \ q) {\n\t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\tint p, c,\
    \ d;\n\t\t\tscanf(\"%d%d%d\", &p, &c, &d);\n\t\t\tst.update(p, {c, d});\n\t\t\
    } else {\n\t\t\tint l, r, x;\n\t\t\tscanf(\"%d%d%d\", &l, &r, &x);\n\t\t\tauto\
    \ p = st.query(l, r);\n\t\t\tprintf(\"%d\\n\", p.first * x + p.second);\n\t\t\
    }\n\t}\n\treturn 0;\n}"
  dependsOn:
  - math/StaticModInt.hpp
  - other/template.hpp
  - other/type_traits.hpp
  - data-structure/SegTree.hpp
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2023-01-15 02:50:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.test.cpp
- /verify/test/yosupo/point_set_range_composite.test.cpp.html
title: test/yosupo/point_set_range_composite.test.cpp
---
