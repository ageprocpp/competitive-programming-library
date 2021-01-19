---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
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
    \ 3.141592653589793238462643383279;\n\ntemplate <class T>\nclass prique : public\
    \ std::priority_queue<T, std::vector<T>, std::greater<T>> {\n};\ntemplate <class\
    \ F>\ninline constexpr decltype(auto) lambda_fix(F&& f) {\n\treturn [f = std::forward<F>(f)](auto&&...\
    \ args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\t};\n}\n\
    template <class T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n\
    }\ntemplate <class T, class... Args>\nconstexpr auto make_vec(size_t n, Args&&...\
    \ args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\t\tn, make_vec<T>(std::forward<Args>(args)...));\n\
    }\ntemplate <class T, class U>\nconstexpr inline bool chmax(T& lhs, const U& rhs)\
    \ {\n\tif (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\ntemplate <class T, class U>\nconstexpr inline bool chmin(T& lhs, const U& rhs)\
    \ {\n\tif (lhs > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\nconstexpr inline lint gcd(lint a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\
    \t\ta = b;\n\t\tb = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint\
    \ b) { return a / gcd(a, b) * b; }\nconstexpr bool isprime(lint n) {\n\tif (n\
    \ == 1) return false;\n\tfor (int i = 2; i * i <= n; i++) {\n\t\tif (n % i ==\
    \ 0) return false;\n\t}\n\treturn true;\n}\ntemplate <class T>\nconstexpr T mypow(T\
    \ a, lint b) {\n\tT res(1);\n\twhile (true) {\n\t\tif (b & 1) res *= a;\n\t\t\
    b >>= 1;\n\t\tif (!b) break;\n\t\ta *= a;\n\t}\n\treturn res;\n}\nconstexpr lint\
    \ modpow(lint a, lint b, lint m) {\n\ta %= m;\n\tlint res(1);\n\twhile (b) {\n\
    \t\tif (b & 1) {\n\t\t\tres *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\ta\
    \ %= m;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\ntemplate <class T>\nconstexpr void\
    \ printArray(const std::vector<T>& vec, char split = ' ') {\n\trep(i, vec.size())\
    \ {\n\t\tstd::cout << vec[i];\n\t\tstd::cout << (i == (int)vec.size() - 1 ? '\\\
    n' : split);\n\t}\n}\ntemplate <class T>\nconstexpr void printArray(T l, T r,\
    \ char split = ' ') {\n\tT rprev = std::prev(r);\n\tfor (T i = l; i != r; i++)\
    \ {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev ? '\\n' : split);\n\t\
    }\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b,\
    \ a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b * s.first;\n\t\
    return s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const lint& b2, const\
    \ lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\tlint tmp = (b2 - b1) * p %\
    \ m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\treturn {r, m1 * m2};\n\
    }\nint LCS(const std::string& a, const std::string& b) {\n\tauto dp = make_vec<int>(a.size()\
    \ + 1, b.size() + 1);\n\trep(i, a.size()) {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i\
    \ + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j + 1], dp[i][j]);\n\t\t\tif (a[i] ==\
    \ b[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()],\
    \ dp[i][b.size()]);\n\t}\n\trep(j, b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\
    \treturn dp[a.size()][b.size()];\n}\n#line 3 \"algebraic/DynamicModInt.hpp\"\n\
    class DynamicModInt : DynamicModInt__Base {\n\tstatic uint modulo;\n\n\tint value;\n\
    \tstatic constexpr void setMod(uint mod) { modulo = mod; }\n\tconstexpr DynamicModInt()\
    \ : value(0) {}\n\ttemplate <class T>\n\tconstexpr DynamicModInt(T value = 0)\
    \ : value(value) {\n\t\tthis->value =\n\t\t\t(value < 0 ? -(-value % modulo) +\
    \ modulo : lint(value)) % modulo;\n\t}\n\n\tinline constexpr DynamicModInt inv()\
    \ const {\n\t\treturn mypow(*this, modulo - 2);\n\t}\n\tinline constexpr operator\
    \ int() const { return value; }\n\tinline constexpr DynamicModInt& operator+=(const\
    \ DynamicModInt& x) {\n\t\tvalue = value + x.value;\n\t\tif (value >= modulo)\
    \ value -= modulo;\n\t\treturn *this;\n\t}\n\tinline constexpr DynamicModInt&\
    \ operator++() {\n\t\tif (value == modulo - 1)\n\t\t\tvalue = 0;\n\t\telse\n\t\
    \t\tvalue++;\n\t\treturn *this;\n\t}\n\tinline constexpr DynamicModInt operator++(int)\
    \ {\n\t\tDynamicModInt res = *this;\n\t\t++*this;\n\t\treturn res;\n\t}\n\tinline\
    \ constexpr DynamicModInt operator-() const {\n\t\treturn DynamicModInt(0) -=\
    \ *this;\n\t}\n\tinline constexpr DynamicModInt& operator-=(const DynamicModInt&\
    \ x) {\n\t\tvalue -= x.value;\n\t\tif (value < 0) value += modulo;\n\t\treturn\
    \ *this;\n\t}\n\tinline constexpr DynamicModInt& operator--() {\n\t\tif (value\
    \ == 0)\n\t\t\tvalue = modulo - 1;\n\t\telse\n\t\t\tvalue--;\n\t\treturn *this;\n\
    \t}\n\tinline constexpr DynamicModInt operator--(int) {\n\t\tDynamicModInt res\
    \ = *this;\n\t\t--*this;\n\t\treturn res;\n\t}\n\tinline constexpr DynamicModInt&\
    \ operator*=(const DynamicModInt& x) {\n\t\tvalue = (lint)value * x.value % modulo;\n\
    \t\treturn *this;\n\t}\n\tinline constexpr DynamicModInt& operator/=(const DynamicModInt&\
    \ rhs) {\n\t\treturn *this *= rhs.inv();\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ DynamicModInt operator+(const T& rhs) const {\n\t\treturn DynamicModInt(*this)\
    \ += rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr DynamicModInt& operator+=(const\
    \ T& rhs) {\n\t\treturn operator+=(DynamicModInt(rhs));\n\t}\n\ttemplate <class\
    \ T>\n\tconstexpr DynamicModInt operator-(const T& rhs) const {\n\t\treturn DynamicModInt(*this)\
    \ -= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr DynamicModInt& operator-=(const\
    \ T& rhs) {\n\t\treturn operator-=(DynamicModInt(rhs));\n\t}\n\ttemplate <class\
    \ T>\n\tconstexpr DynamicModInt operator*(const T& rhs) const {\n\t\treturn DynamicModInt(*this)\
    \ *= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr DynamicModInt& operator*=(const\
    \ T& rhs) {\n\t\treturn operator*=(DynamicModInt(rhs));\n\t}\n\ttemplate <class\
    \ T>\n\tconstexpr DynamicModInt operator/(const T& rhs) const {\n\t\treturn DynamicModInt(*this)\
    \ /= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr DynamicModInt& operator/=(const\
    \ T& rhs) {\n\t\treturn operator/=(DynamicModInt(rhs));\n\t}\n};\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\nclass DynamicModInt : DynamicModInt__Base\
    \ {\n\tstatic uint modulo;\n\n\tint value;\n\tstatic constexpr void setMod(uint\
    \ mod) { modulo = mod; }\n\tconstexpr DynamicModInt() : value(0) {}\n\ttemplate\
    \ <class T>\n\tconstexpr DynamicModInt(T value = 0) : value(value) {\n\t\tthis->value\
    \ =\n\t\t\t(value < 0 ? -(-value % modulo) + modulo : lint(value)) % modulo;\n\
    \t}\n\n\tinline constexpr DynamicModInt inv() const {\n\t\treturn mypow(*this,\
    \ modulo - 2);\n\t}\n\tinline constexpr operator int() const { return value; }\n\
    \tinline constexpr DynamicModInt& operator+=(const DynamicModInt& x) {\n\t\tvalue\
    \ = value + x.value;\n\t\tif (value >= modulo) value -= modulo;\n\t\treturn *this;\n\
    \t}\n\tinline constexpr DynamicModInt& operator++() {\n\t\tif (value == modulo\
    \ - 1)\n\t\t\tvalue = 0;\n\t\telse\n\t\t\tvalue++;\n\t\treturn *this;\n\t}\n\t\
    inline constexpr DynamicModInt operator++(int) {\n\t\tDynamicModInt res = *this;\n\
    \t\t++*this;\n\t\treturn res;\n\t}\n\tinline constexpr DynamicModInt operator-()\
    \ const {\n\t\treturn DynamicModInt(0) -= *this;\n\t}\n\tinline constexpr DynamicModInt&\
    \ operator-=(const DynamicModInt& x) {\n\t\tvalue -= x.value;\n\t\tif (value <\
    \ 0) value += modulo;\n\t\treturn *this;\n\t}\n\tinline constexpr DynamicModInt&\
    \ operator--() {\n\t\tif (value == 0)\n\t\t\tvalue = modulo - 1;\n\t\telse\n\t\
    \t\tvalue--;\n\t\treturn *this;\n\t}\n\tinline constexpr DynamicModInt operator--(int)\
    \ {\n\t\tDynamicModInt res = *this;\n\t\t--*this;\n\t\treturn res;\n\t}\n\tinline\
    \ constexpr DynamicModInt& operator*=(const DynamicModInt& x) {\n\t\tvalue = (lint)value\
    \ * x.value % modulo;\n\t\treturn *this;\n\t}\n\tinline constexpr DynamicModInt&\
    \ operator/=(const DynamicModInt& rhs) {\n\t\treturn *this *= rhs.inv();\n\t}\n\
    \ttemplate <class T>\n\tconstexpr DynamicModInt operator+(const T& rhs) const\
    \ {\n\t\treturn DynamicModInt(*this) += rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ DynamicModInt& operator+=(const T& rhs) {\n\t\treturn operator+=(DynamicModInt(rhs));\n\
    \t}\n\ttemplate <class T>\n\tconstexpr DynamicModInt operator-(const T& rhs) const\
    \ {\n\t\treturn DynamicModInt(*this) -= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ DynamicModInt& operator-=(const T& rhs) {\n\t\treturn operator-=(DynamicModInt(rhs));\n\
    \t}\n\ttemplate <class T>\n\tconstexpr DynamicModInt operator*(const T& rhs) const\
    \ {\n\t\treturn DynamicModInt(*this) *= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ DynamicModInt& operator*=(const T& rhs) {\n\t\treturn operator*=(DynamicModInt(rhs));\n\
    \t}\n\ttemplate <class T>\n\tconstexpr DynamicModInt operator/(const T& rhs) const\
    \ {\n\t\treturn DynamicModInt(*this) /= rhs;\n\t}\n\ttemplate <class T>\n\tconstexpr\
    \ DynamicModInt& operator/=(const T& rhs) {\n\t\treturn operator/=(DynamicModInt(rhs));\n\
    \t}\n};"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: algebraic/DynamicModInt.hpp
  requiredBy: []
  timestamp: '2021-01-19 14:37:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebraic/DynamicModInt.hpp
layout: document
redirect_from:
- /library/algebraic/DynamicModInt.hpp
- /library/algebraic/DynamicModInt.hpp.html
title: algebraic/DynamicModInt.hpp
---
