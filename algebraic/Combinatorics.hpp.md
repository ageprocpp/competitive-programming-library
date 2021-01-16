---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic/StaticModInt.hpp
    title: StaticModInt
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Combinatorics/ModCombinatorics
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #ifdef ONLINE_JUDGE\n#pragma GCC target(\"avx512f\")\n#else\n#pragma GCC target(\"\
    avx2\")\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n#include <string.h>\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cfloat>\n#include <climits>\n#include <cmath>\n\
    #include <complex>\n#include <ctime>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#define rep(i,\
    \ n) for (int i = 0; i < int(n); i++)\n#define REP(i, n) for (int i = 1; i <=\
    \ int(n); i++)\n#define all(V) V.begin(), V.end()\n\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\nusing uint = unsigned int;\nusing lint = long long;\n\
    using ulint = unsigned long long;\nusing P = std::pair<int, int>;\nusing LP =\
    \ std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF\
    \ = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr double PI =\
    \ 3.141592653589793238462643383279;\n\nnamespace std {\n\ttemplate <template <class...>\
    \ class Temp, class T>\n\tclass is_template_with_type_of : public std::false_type\
    \ {};\n\ttemplate <template <class...> class Temp, class... Args>\n\tclass is_template_with_type_of<Temp,\
    \ Temp<Args...>>\n\t\t: public std::true_type {};\n\ttemplate <template <auto...>\
    \ class Temp, class T>\n\tclass is_template_with_non_type_of : public std::false_type\
    \ {};\n\ttemplate <template <auto...> class Temp, auto... Args>\n\tclass is_template_with_non_type_of<Temp,\
    \ Temp<Args...>>\n\t\t: public std::true_type {};\n};\t// namespace std\ntemplate\
    \ <class T>\nclass prique : public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {\n};\ntemplate <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f)\
    \ {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\t\
    return std::vector<T>(n);\n}\ntemplate <class T, class... Args>\nconstexpr auto\
    \ make_vec(size_t n, Args&&... args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\
    \t\tn, make_vec<T>(std::forward<Args>(args)...));\n}\ntemplate <class T, class\
    \ U>\nconstexpr inline bool chmax(T& lhs, const U& rhs) {\n\tif (lhs < rhs) {\n\
    \t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class T,\
    \ class U>\nconstexpr inline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs > rhs)\
    \ {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\nconstexpr inline\
    \ lint gcd(lint a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\t\
    b = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint b) { return a /\
    \ gcd(a, b) * b; }\nconstexpr bool isprime(lint n) {\n\tif (n == 1) return false;\n\
    \tfor (int i = 2; i * i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\
    \treturn true;\n}\ntemplate <class T>\nconstexpr T mypow(T a, lint b) {\n\tT res(1);\n\
    \twhile (true) {\n\t\tif (b & 1) res *= a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\
    \t\ta *= a;\n\t}\n\treturn res;\n}\nconstexpr lint modpow(lint a, lint b, lint\
    \ m) {\n\ta %= m;\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\tres\
    \ *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\t}\n\
    \treturn res;\n}\ntemplate <class T>\nconstexpr void printArray(const std::vector<T>&\
    \ vec, char split = ' ') {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\
    \t\tstd::cout << (i == (int)vec.size() - 1 ? '\\n' : split);\n\t}\n}\ntemplate\
    \ <class T>\nconstexpr void printArray(T l, T r, char split = ' ') {\n\tT rprev\
    \ = std::prev(r);\n\tfor (T i = l; i != r; i++) {\n\t\tstd::cout << *i;\n\t\t\
    std::cout << (i == rprev ? '\\n' : split);\n\t}\n}\nconstexpr LP extGcd(lint a,\
    \ lint b) {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b, a % b);\n\tstd::swap(s.first,\
    \ s.second);\n\ts.second -= a / b * s.first;\n\treturn s;\n}\nconstexpr LP ChineseRem(const\
    \ lint& b1, const lint& m1, const lint& b2, const lint& m2) {\n\tlint p = extGcd(m1,\
    \ m2).first;\n\tlint tmp = (b2 - b1) * p % m2;\n\tlint r = (b1 + m1 * tmp + m1\
    \ * m2) % (m1 * m2);\n\treturn std::make_pair(r, m1 * m2);\n}\nint LCS(const std::string&\
    \ a, const std::string& b) {\n\tauto dp = make_vec<int>(a.size() + 1, b.size()\
    \ + 1);\n\trep(i, a.size()) {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j],\
    \ dp[i][j]);\n\t\t\tchmax(dp[i][j + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i\
    \ + 1][j + 1], dp[i][j] + 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\
    \t}\n\trep(j, b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn\
    \ dp[a.size()][b.size()];\n}\n#line 3 \"algebraic/StaticModInt.hpp\"\ntemplate\
    \ <uint modulo>\nclass StaticModInt {\n\tstd::conditional_t<(modulo > INT_MAX\
    \ >> 1), lint, int> value;\n\n  public:\n\tstatic constexpr uint mod_value = modulo;\n\
    \tconstexpr StaticModInt() : value(0) {}\n\ttemplate <class T, std::enable_if_t<!std::is_convertible_v<T,\
    \ StaticModInt>,\n\t\t\t\t\t\t\t\t\t\tstd::nullptr_t> = nullptr>\n\tconstexpr\
    \ StaticModInt(T value = 0) : value(value) {\n\t\tthis->value =\n\t\t\t(value\
    \ < 0 ? -(-value % modulo) + modulo : lint(value)) % modulo;\n\t}\n\tinline constexpr\
    \ StaticModInt inv() const {\n\t\treturn mypow(*this, modulo - 2);\n\t}\n\tinline\
    \ constexpr operator int() const { return value; }\n\tinline constexpr StaticModInt&\
    \ operator+=(const StaticModInt& x) {\n\t\tvalue = value + x.value;\n\t\tif (value\
    \ >= modulo) value -= modulo;\n\t\treturn *this;\n\t}\n\tinline constexpr StaticModInt&\
    \ operator++() {\n\t\tif (value == modulo - 1)\n\t\t\tvalue = 0;\n\t\telse\n\t\
    \t\tvalue++;\n\t\treturn *this;\n\t}\n\tinline constexpr StaticModInt operator++(int)\
    \ {\n\t\tStaticModInt res = *this;\n\t\t++*this;\n\t\treturn res;\n\t}\n\tinline\
    \ constexpr StaticModInt operator-() const {\n\t\treturn StaticModInt(0) -= *this;\n\
    \t}\n\tinline constexpr StaticModInt& operator-=(const StaticModInt& x) {\n\t\t\
    value -= x.value;\n\t\tif (value < 0) value += modulo;\n\t\treturn *this;\n\t\
    }\n\tinline constexpr StaticModInt& operator--() {\n\t\tif (value == 0)\n\t\t\t\
    value = modulo - 1;\n\t\telse\n\t\t\tvalue--;\n\t\treturn *this;\n\t}\n\tinline\
    \ constexpr StaticModInt operator--(int) {\n\t\tStaticModInt res = *this;\n\t\t\
    --*this;\n\t\treturn res;\n\t}\n\tinline constexpr StaticModInt& operator*=(const\
    \ StaticModInt& x) {\n\t\tvalue = (lint)value * x.value % modulo;\n\t\treturn\
    \ *this;\n\t}\n\tinline constexpr StaticModInt& operator/=(const StaticModInt&\
    \ rhs) {\n\t\treturn *this *= rhs.inv();\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ StaticModInt operator+(const T& rhs) const {\n\t\treturn StaticModInt(*this)\
    \ += rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr StaticModInt& operator+=(const\
    \ T& rhs) {\n\t\treturn operator+=(StaticModInt(rhs));\n\t}\n\ttemplate <class\
    \ T>\n\tconstexpr StaticModInt operator-(const T& rhs) const {\n\t\treturn StaticModInt(*this)\
    \ -= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr StaticModInt& operator-=(const\
    \ T& rhs) {\n\t\treturn operator-=(StaticModInt(rhs));\n\t}\n\ttemplate <class\
    \ T>\n\tconstexpr StaticModInt operator*(const T& rhs) const {\n\t\treturn StaticModInt(*this)\
    \ *= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr StaticModInt& operator*=(const\
    \ T& rhs) {\n\t\treturn operator*=(StaticModInt(rhs));\n\t}\n\ttemplate <class\
    \ T>\n\tconstexpr StaticModInt operator/(const T& rhs) const {\n\t\treturn StaticModInt(*this)\
    \ /= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr StaticModInt& operator/=(const\
    \ T& rhs) {\n\t\treturn operator/=(StaticModInt(rhs));\n\t}\n};\ntemplate <uint\
    \ modulo>\nstd::istream& operator>>(std::istream& ist, StaticModInt<modulo>& x)\
    \ {\n\tlint a;\n\tist >> a;\n\tx = a;\n\treturn ist;\n}\n\n/**\n * @title StaticModInt\n\
    \ */\n#line 4 \"algebraic/Combinatorics.hpp\"\ntemplate <typename T>\nclass Combinatorics\
    \ {\n  protected:\n\tstd::vector<T> factorial;\n\tvoid append(int n) noexcept\
    \ {\n\t\twhile (factorial.size() <= n) {\n\t\t\tfactorial.emplace_back(factorial.back()\
    \ * factorial.size());\n\t\t}\n\t}\n\n  public:\n\tCombinatorics() noexcept :\
    \ factorial(1, 1) {}\n\tCombinatorics(int n) noexcept : factorial(1, 1) { append(n);\
    \ }\n\tvirtual T getComb(int a, int b) noexcept {\n\t\tappend(a);\n\t\treturn\
    \ factorial[a] / factorial[a - b] / factorial[b];\n\t}\n\tvirtual T getDcomb(int\
    \ a, int b) noexcept { return getComb(a + b - 1, b); }\n};\ntemplate <typename\
    \ T, typename std::enable_if_t<\n\t\t\t\t\t\t  std::is_template_with_non_type_of<StaticModInt,\
    \ T>,\n\t\t\t\t\t\t  std::nullptr_t> = nullptr>\nclass ModCombinatorics : Combinatorics<T>\
    \ {\n\tusing Combinatorics<T>::factorial;\n\tstd::vector<T> inv;\n\tvoid append(int\
    \ n) noexcept {\n\t\tint tmp = factorial.size();\n\t\tif (n < tmp) return;\n\t\
    \tCombinatorics<T>::append(n);\n\t\tinv.resize(n + 1);\n\t\tinv[n] = T(1) / factorial.back();\n\
    \t\tfor (int i = n; i > tmp; i--) inv[i - 1] = inv[i] * i;\n\t}\n\n  public:\n\
    \tModCombinatorics() noexcept : Combinatorics<T>(), inv(1, 1) {}\n\tModCombinatorics(int\
    \ n) noexcept : Combinatorics<T>(n), inv(1, 1) {\n\t\tappend(n);\n\t}\n\tT getComb(int\
    \ a, int b) noexcept override {\n\t\tappend(a);\n\t\treturn factorial[a] * inv[a\
    \ - b] * inv[b];\n\t}\n\tT getDcomb(int a, int b) noexcept override { return getComb(a\
    \ + b - 1, b); }\n\tT perm(int a, int b) noexcept {\n\t\tappend(a);\n\t\treturn\
    \ factorial[a] * inv[a - b];\n\t}\n};\n\n/**\n * @title Combinatorics/ModCombinatorics\n\
    \ */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\n#include \"StaticModInt.hpp\"\
    \ntemplate <typename T>\nclass Combinatorics {\n  protected:\n\tstd::vector<T>\
    \ factorial;\n\tvoid append(int n) noexcept {\n\t\twhile (factorial.size() <=\
    \ n) {\n\t\t\tfactorial.emplace_back(factorial.back() * factorial.size());\n\t\
    \t}\n\t}\n\n  public:\n\tCombinatorics() noexcept : factorial(1, 1) {}\n\tCombinatorics(int\
    \ n) noexcept : factorial(1, 1) { append(n); }\n\tvirtual T getComb(int a, int\
    \ b) noexcept {\n\t\tappend(a);\n\t\treturn factorial[a] / factorial[a - b] /\
    \ factorial[b];\n\t}\n\tvirtual T getDcomb(int a, int b) noexcept { return getComb(a\
    \ + b - 1, b); }\n};\ntemplate <typename T, typename std::enable_if_t<\n\t\t\t\
    \t\t\t  std::is_template_with_non_type_of<StaticModInt, T>,\n\t\t\t\t\t\t  std::nullptr_t>\
    \ = nullptr>\nclass ModCombinatorics : Combinatorics<T> {\n\tusing Combinatorics<T>::factorial;\n\
    \tstd::vector<T> inv;\n\tvoid append(int n) noexcept {\n\t\tint tmp = factorial.size();\n\
    \t\tif (n < tmp) return;\n\t\tCombinatorics<T>::append(n);\n\t\tinv.resize(n +\
    \ 1);\n\t\tinv[n] = T(1) / factorial.back();\n\t\tfor (int i = n; i > tmp; i--)\
    \ inv[i - 1] = inv[i] * i;\n\t}\n\n  public:\n\tModCombinatorics() noexcept :\
    \ Combinatorics<T>(), inv(1, 1) {}\n\tModCombinatorics(int n) noexcept : Combinatorics<T>(n),\
    \ inv(1, 1) {\n\t\tappend(n);\n\t}\n\tT getComb(int a, int b) noexcept override\
    \ {\n\t\tappend(a);\n\t\treturn factorial[a] * inv[a - b] * inv[b];\n\t}\n\tT\
    \ getDcomb(int a, int b) noexcept override { return getComb(a + b - 1, b); }\n\
    \tT perm(int a, int b) noexcept {\n\t\tappend(a);\n\t\treturn factorial[a] * inv[a\
    \ - b];\n\t}\n};\n\n/**\n * @title Combinatorics/ModCombinatorics\n */"
  dependsOn:
  - other/template.hpp
  - algebraic/StaticModInt.hpp
  isVerificationFile: false
  path: algebraic/Combinatorics.hpp
  requiredBy: []
  timestamp: '2021-01-16 15:12:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebraic/Combinatorics.hpp
layout: document
redirect_from:
- /library/algebraic/Combinatorics.hpp
- /library/algebraic/Combinatorics.hpp.html
title: Combinatorics/ModCombinatorics
---
