---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algebraic/DynamicModInt.hpp
    title: algebraic/DynamicModInt.hpp
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #pragma target(\"avx2\")\n#pragma optimize(\"O3\")\n#pragma optimize(\"unroll-loops\"\
    )\n#include <string.h>\n#include <algorithm>\n#include <bitset>\n#include <cassert>\n\
    #include <cfloat>\n#include <climits>\n#include <cmath>\n#include <complex>\n\
    #include <ctime>\n#include <deque>\n#include <fstream>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <iterator>\n#include <list>\n\
    #include <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include\
    \ <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n#include\
    \ <unordered_set>\n#include <utility>\n#include <vector>\n#define rep(i, n) for\
    \ (int i = 0; i < (n); i++)\n#define REP(i, n) for (int i = 1; i <= (n); i++)\n\
    #define all(V) V.begin(), V.end()\ntypedef unsigned int uint;\ntypedef long long\
    \ lint;\ntypedef unsigned long long ulint;\ntypedef std::pair<int, int> P;\ntypedef\
    \ std::pair<lint, lint> LP;\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint\
    \ LINF = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr double\
    \ PI = 3.141592653589793238462643383279;\ntemplate <class T>\nclass prique : public\
    \ std::priority_queue<T, std::vector<T>, std::greater<T>> {\n};\ntemplate <class\
    \ T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\tif (lhs < rhs) {\n\
    \t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class T,\
    \ class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs > rhs) {\n\t\t\
    lhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ninline lint gcd(lint a,\
    \ lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\tb = c % b;\n\t}\n\
    \treturn a;\n}\ninline lint lcm(lint a, lint b) {\n\treturn a / gcd(a, b) * b;\n\
    }\nbool isprime(lint n) {\n\tif (n == 1) return false;\n\tfor (int i = 2; i *\
    \ i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn true;\n}\n\
    template <typename T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile (b) {\n\t\t\
    if (b & 1) res *= a;\n\t\ta *= a;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\nlint modpow(lint\
    \ a, lint b, lint m) {\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\t\
    res *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\t\
    }\n\treturn res;\n}\ntemplate <typename T>\nvoid printArray(std::vector<T>& vec)\
    \ {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\t\tstd::cout << (i ==\
    \ (int)vec.size() - 1 ? \"\\n\" : \" \");\n\t}\n}\ntemplate <typename T>\nvoid\
    \ printArray(T l, T r) {\n\tT rprev = std::prev(r);\n\tfor (T i = l; i != r; i++)\
    \ {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev ? \"\\n\" : \" \");\n\t\
    }\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b,\
    \ a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b * s.first;\n\t\
    return s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const lint& b2, const\
    \ lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\tlint tmp = (b2 - b1) * p %\
    \ m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\treturn std::make_pair(r,\
    \ m1 * m2);\n}\ntemplate <typename F>\ninline constexpr decltype(auto) lambda_fix(F&&\
    \ f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <typename T>\nstd::vector<T> make_vec(size_t n) {\n\treturn\
    \ std::vector<T>(n);\n}\ntemplate <typename T, class... Args>\nauto make_vec(size_t\
    \ n, Args&&... args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\
    \t\tn, make_vec<T>(std::forward<Args>(args)...));\n}\n#line 3 \"algebraic/DynamicModInt.hpp\"\
    \nclass DynamicModInt {\n\tlint value;\n\n  public:\n\tstatic uint modulo;\n\t\
    DynamicModInt() : value(0) {}\n\ttemplate <typename T>\n\tDynamicModInt(T value\
    \ = 0) : value(value) {\n\t\tif (value < 0) value = -(lint)(-value % modulo) +\
    \ modulo;\n\t\tthis->value = value % modulo;\n\t}\n\tstatic inline void setMod(const\
    \ uint& mod) { modulo = mod; }\n\tinline DynamicModInt inv() const { return mypow(*this,\
    \ modulo - 2); }\n\tinline operator int() const { return value; }\n\tinline DynamicModInt&\
    \ operator+=(const DynamicModInt& x) {\n\t\tvalue += x.value;\n\t\tif (value >=\
    \ modulo) value -= modulo;\n\t\treturn *this;\n\t}\n\tinline DynamicModInt& operator++()\
    \ {\n\t\tif (value == modulo - 1)\n\t\t\tvalue = 0;\n\t\telse\n\t\t\tvalue++;\n\
    \t\treturn *this;\n\t}\n\tinline DynamicModInt operator++(int) {\n\t\tDynamicModInt\
    \ res = *this;\n\t\t--*this;\n\t\treturn res;\n\t}\n\tinline DynamicModInt operator-()\
    \ const { return DynamicModInt(0) -= *this; }\n\tinline DynamicModInt& operator-=(const\
    \ DynamicModInt& x) {\n\t\tvalue -= x.value;\n\t\tif (value < 0) value += modulo;\n\
    \t\treturn *this;\n\t}\n\tinline DynamicModInt& operator--() {\n\t\tif (value\
    \ == 0)\n\t\t\tvalue = modulo - 1;\n\t\telse\n\t\t\tvalue--;\n\t\treturn *this;\n\
    \t}\n\tinline DynamicModInt operator--(int) {\n\t\tDynamicModInt res = *this;\n\
    \t\t--*this;\n\t\treturn res;\n\t}\n\tinline DynamicModInt& operator*=(const DynamicModInt&\
    \ x) {\n\t\tvalue = value * x.value % modulo;\n\t\treturn *this;\n\t}\n\tinline\
    \ DynamicModInt& operator/=(const DynamicModInt& rhs) {\n\t\treturn *this *= rhs.inv();\n\
    \t}\n\ttemplate <typename T>\n\tDynamicModInt operator+(const T& rhs) const {\n\
    \t\treturn DynamicModInt(*this) += rhs;\n\t}\n\ttemplate <typename T>\n\tDynamicModInt&\
    \ operator+=(const T& rhs) {\n\t\treturn operator+=(DynamicModInt(rhs));\n\t}\n\
    \ttemplate <typename T>\n\tDynamicModInt operator-(const T& rhs) const {\n\t\t\
    return DynamicModInt(*this) -= rhs;\n\t}\n\ttemplate <typename T>\n\tDynamicModInt&\
    \ operator-=(const T& rhs) {\n\t\treturn operator-=(DynamicModInt(rhs));\n\t}\n\
    \ttemplate <typename T>\n\tDynamicModInt operator*(const T& rhs) const {\n\t\t\
    return DynamicModInt(*this) *= rhs;\n\t}\n\ttemplate <typename T>\n\tDynamicModInt&\
    \ operator*=(const T& rhs) {\n\t\treturn operator*=(DynamicModInt(rhs));\n\t}\n\
    \ttemplate <typename T>\n\tDynamicModInt operator/(const T& rhs) const {\n\t\t\
    return DynamicModInt(*this) /= rhs;\n\t}\n\ttemplate <typename T>\n\tDynamicModInt&\
    \ operator/=(const T& rhs) {\n\t\treturn operator/=(DynamicModInt(rhs));\n\t}\n\
    };\nuint DynamicModInt::modulo = 1000000007;\nstd::istream& operator>>(std::istream&\
    \ ist, DynamicModInt& x) {\n\tlint a;\n\tist >> a;\n\tx = a;\n\treturn ist;\n\
    }\n#line 4 \"algebraic/LagrangeInterpolation.hpp\"\nDynamicModInt arithmetic_lagrange_interpolation(\n\
    \tconst DynamicModInt& a, const DynamicModInt& d,\n\tconst std::vector<DynamicModInt>&\
    \ y, const DynamicModInt& t) {\n\tconst int n = y.size() - 1;\n\tDynamicModInt\
    \ res = 0, ft = 1;\n\trep(i, n + 1) ft *= t - (a + d * i);\n\tDynamicModInt f\
    \ = 1;\n\tREP(i, n) f *= -d * i;\n\tres += y[0] / f * ft / (t - a);\n\trep(i,\
    \ n) {\n\t\tf *= i + 1;\n\t\tf /= i - n;\n\t\tres += y[i + 1] / f * ft / (t -\
    \ (a + d * (i + 1)));\n\t}\n\treturn res;\n}\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\n#include \"DynamicModInt.hpp\"\
    \nDynamicModInt arithmetic_lagrange_interpolation(\n\tconst DynamicModInt& a,\
    \ const DynamicModInt& d,\n\tconst std::vector<DynamicModInt>& y, const DynamicModInt&\
    \ t) {\n\tconst int n = y.size() - 1;\n\tDynamicModInt res = 0, ft = 1;\n\trep(i,\
    \ n + 1) ft *= t - (a + d * i);\n\tDynamicModInt f = 1;\n\tREP(i, n) f *= -d *\
    \ i;\n\tres += y[0] / f * ft / (t - a);\n\trep(i, n) {\n\t\tf *= i + 1;\n\t\t\
    f /= i - n;\n\t\tres += y[i + 1] / f * ft / (t - (a + d * (i + 1)));\n\t}\n\t\
    return res;\n}"
  dependsOn:
  - other/template.hpp
  - algebraic/DynamicModInt.hpp
  isVerificationFile: false
  path: algebraic/LagrangeInterpolation.hpp
  requiredBy: []
  timestamp: '2020-12-08 15:45:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebraic/LagrangeInterpolation.hpp
layout: document
redirect_from:
- /library/algebraic/LagrangeInterpolation.hpp
- /library/algebraic/LagrangeInterpolation.hpp.html
title: algebraic/LagrangeInterpolation.hpp
---
