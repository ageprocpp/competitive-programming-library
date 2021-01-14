---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic/StaticModInt.hpp
    title: algebraic/StaticModInt.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ int(n); i++)\n#define all(V) V.begin(), V.end()\n\nusing lint = long long;\n\
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
    \t};\n}\ntemplate <class T>\nstd::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n\
    }\ntemplate <class T, class... Args>\nauto make_vec(size_t n, Args&&... args)\
    \ {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\t\tn, make_vec<T>(std::forward<Args>(args)...));\n\
    }\ntemplate <class T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\t\
    if (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\
    template <class T, class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs\
    \ > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ninline\
    \ lint gcd(lint a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\t\
    b = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint b) { return a /\
    \ gcd(a, b) * b; }\nbool isprime(lint n) {\n\tif (n == 1) return false;\n\tfor\
    \ (int i = 2; i * i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn\
    \ true;\n}\ntemplate <class T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile (true)\
    \ {\n\t\tif (b & 1) res *= a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\t\ta *= a;\n\
    \t}\n\treturn res;\n}\nlint modpow(lint a, lint b, lint m) {\n\ta %= m;\n\tlint\
    \ res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\tres *= a;\n\t\t\tres %= m;\n\
    \t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\ntemplate\
    \ <class T>\nvoid printArray(const std::vector<T>& vec, char split = ' ') {\n\t\
    rep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\t\tstd::cout << (i == (int)vec.size()\
    \ - 1 ? '\\n' : split);\n\t}\n}\ntemplate <class T>\nvoid printArray(T l, T r,\
    \ char split = ' ') {\n\tT rprev = std::prev(r);\n\tfor (T i = l; i != r; i++)\
    \ {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev ? '\\n' : split);\n\t\
    }\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b,\
    \ a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b * s.first;\n\t\
    return s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const lint& b2, const\
    \ lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\tlint tmp = (b2 - b1) * p %\
    \ m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\treturn std::make_pair(r,\
    \ m1 * m2);\n}\nint LCS(const std::string& a, const std::string& b) {\n\tauto\
    \ dp = make_vec<int>(a.size() + 1, b.size() + 1);\n\trep(i, a.size()) {\n\t\t\
    rep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j\
    \ + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i + 1][j + 1], dp[i][j] +\
    \ 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\t}\n\trep(j,\
    \ b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn dp[a.size()][b.size()];\n\
    }\n#line 3 \"algebraic/StaticModInt.hpp\"\ntemplate <uint modulo>\nclass StaticModInt\
    \ {\n\tint value;\n\n  public:\n\tstatic constexpr uint mod_value = modulo;\n\t\
    StaticModInt() : value(0) {}\n\ttemplate <class T, std::enable_if_t<!std::is_convertible_v<T,\
    \ StaticModInt>,\n\t\t\t\t\t\t\t\t\t\tstd::nullptr_t> = nullptr>\n\tStaticModInt(T\
    \ value = 0) : value(value) {\n\t\tthis->value =\n\t\t\t(value < 0 ? -(-value\
    \ % modulo) + modulo : value) % modulo;\n\t}\n\tinline StaticModInt inv() const\
    \ { return mypow(*this, modulo - 2); }\n\tinline operator int() const { return\
    \ value; }\n\tinline StaticModInt& operator+=(const StaticModInt& x) {\n\t\tvalue\
    \ += x.value;\n\t\tif (value >= modulo) value -= modulo;\n\t\treturn *this;\n\t\
    }\n\tinline StaticModInt& operator++() {\n\t\tif (value == modulo - 1)\n\t\t\t\
    value = 0;\n\t\telse\n\t\t\tvalue++;\n\t\treturn *this;\n\t}\n\tinline StaticModInt\
    \ operator++(int) {\n\t\tStaticModInt res = *this;\n\t\t++*this;\n\t\treturn res;\n\
    \t}\n\tinline StaticModInt operator-() const { return StaticModInt(0) -= *this;\
    \ }\n\tinline StaticModInt& operator-=(const StaticModInt& x) {\n\t\tvalue -=\
    \ x.value;\n\t\tif (value < 0) value += modulo;\n\t\treturn *this;\n\t}\n\tinline\
    \ StaticModInt& operator--() {\n\t\tif (value == 0)\n\t\t\tvalue = modulo - 1;\n\
    \t\telse\n\t\t\tvalue--;\n\t\treturn *this;\n\t}\n\tinline StaticModInt operator--(int)\
    \ {\n\t\tStaticModInt res = *this;\n\t\t--*this;\n\t\treturn res;\n\t}\n\tinline\
    \ StaticModInt& operator*=(const StaticModInt& x) {\n\t\tvalue = (lint)value *\
    \ x.value % modulo;\n\t\treturn *this;\n\t}\n\tinline StaticModInt& operator/=(const\
    \ StaticModInt& rhs) {\n\t\treturn *this *= rhs.inv();\n\t}\n\ttemplate <class\
    \ T>\n\tStaticModInt operator+(const T& rhs) const {\n\t\treturn StaticModInt(*this)\
    \ += rhs;\n\t}\n\ttemplate <class T>\n\tStaticModInt& operator+=(const T& rhs)\
    \ {\n\t\treturn operator+=(StaticModInt(rhs));\n\t}\n\ttemplate <class T>\n\t\
    StaticModInt operator-(const T& rhs) const {\n\t\treturn StaticModInt(*this) -=\
    \ rhs;\n\t}\n\ttemplate <class T>\n\tStaticModInt& operator-=(const T& rhs) {\n\
    \t\treturn operator-=(StaticModInt(rhs));\n\t}\n\ttemplate <class T>\n\tStaticModInt\
    \ operator*(const T& rhs) const {\n\t\treturn StaticModInt(*this) *= rhs;\n\t\
    }\n\ttemplate <class T>\n\tStaticModInt& operator*=(const T& rhs) {\n\t\treturn\
    \ operator*=(StaticModInt(rhs));\n\t}\n\ttemplate <class T>\n\tStaticModInt operator/(const\
    \ T& rhs) const {\n\t\treturn StaticModInt(*this) /= rhs;\n\t}\n\ttemplate <class\
    \ T>\n\tStaticModInt& operator/=(const T& rhs) {\n\t\treturn operator/=(StaticModInt(rhs));\n\
    \t}\n};\ntemplate <uint modulo>\nstd::istream& operator>>(std::istream& ist, StaticModInt<modulo>&\
    \ x) {\n\tlint a;\n\tist >> a;\n\tx = a;\n\treturn ist;\n}\n#line 4 \"algebraic/NumberTheoreticTransform.hpp\"\
    \n// 1012924417,5,2^21\n// 924844033,5,2^21\n// 998244353,3,2^23\n// 1224736769,3,2^24\n\
    // 167772161,3,2^25\n// 469762049,3,2^26\nclass NumberTheoreticTransform {\n \
    \ private:\n\ttemplate <unsigned int modulo>\n\tstatic void ntt(std::vector<StaticModInt<modulo>>&\
    \ a) {\n\t\tint sz = a.size();\n\t\tif (sz == 1) return;\n\t\tStaticModInt<modulo>\
    \ root =\n\t\t\tmodulo == 924844033 || modulo == 1012924417 ? 5 : 3;\n\t\tif (inverse)\n\
    \t\t\troot = mypow(root, modulo - 1 - (modulo - 1) / sz);\n\t\telse\n\t\t\troot\
    \ = mypow(root, (modulo - 1) / sz);\n\t\tstd::vector<StaticModInt<modulo>> b(sz),\
    \ roots((sz >> 1) + 1, 1);\n\t\trep(i, sz >> 1) roots[i + 1] = roots[i] * root;\n\
    \t\tfor (int i = sz >> 1, w = 1; w < sz; i >>= 1, w <<= 1) {\n\t\t\tfor (int j\
    \ = 0; j < i; j++) {\n\t\t\t\tfor (int k = 0; k < w; k++) {\n\t\t\t\t\tb[k + ((w\
    \ * j) << 1)] =\n\t\t\t\t\t\ta[k + w * j] + a[k + w * j + (sz >> 1)];\n\t\t\t\t\
    \tb[k + ((w * j) << 1) + w] =\n\t\t\t\t\t\troots[w * j] *\n\t\t\t\t\t\t(a[k +\
    \ w * j] - a[k + w * j + (sz >> 1)]);\n\t\t\t\t}\n\t\t\t}\n\t\t\tstd::swap(a,\
    \ b);\n\t\t}\n\t}\n\n  public:\n\tstatic bool inverse;\n\ttemplate <unsigned int\
    \ modulo, class T>\n\tstatic std::vector<StaticModInt<modulo>> multiply(std::vector<T>\
    \ f,\n\t\t\t\t\t\t\t\t\t\t\t\t\t  std::vector<T> g) {\n\t\tif (f.size() < g.size())\
    \ std::swap(f, g);\n\t\tstd::vector<StaticModInt<modulo>> nf, ng;\n\t\tint sz\
    \ = 1;\n\t\twhile (sz < f.size() + g.size()) sz <<= 1;\n\t\tnf.resize(sz);\n\t\
    \tng.resize(sz);\n\t\trep(i, f.size()) {\n\t\t\tnf[i] = f[i];\n\t\t\tif (i < g.size())\
    \ ng[i] = g[i];\n\t\t}\n\t\tinverse = false;\n\t\tntt(nf);\n\t\tntt(ng);\n\t\t\
    rep(i, sz) nf[i] *= ng[i];\n\t\tinverse = true;\n\t\tntt(nf);\n\t\tStaticModInt<modulo>\
    \ szinv = StaticModInt<modulo>(sz).inv();\n\t\trep(i, sz) nf[i] *= szinv;\n\t\t\
    return nf;\n\t}\n\ttemplate <class T>\n\tstatic std::vector<lint> multiply_plain(std::vector<T>\
    \ f,\n\t\t\t\t\t\t\t\t\t\t\tstd::vector<T> g) {\n\t\tconst unsigned int mod1 =\
    \ 998244353, mod2 = 1224736769;\n\t\tstd::vector<StaticModInt<mod1>> mul1 = multiply(f,\
    \ g);\n\t\tstd::vector<StaticModInt<mod2>> mul2 = multiply(f, g, mod2);\n\t\t\
    std::vector<lint> res(mul1.size());\n\t\trep(i, mul1.size()) res[i] =\n\t\t\t\
    ChineseRem(mul1[i], mod1, mul2[i], mod2).first;\n\t\treturn res;\n\t}\n};\nbool\
    \ NumberTheoreticTransform::inverse = false;\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\n#include \"StaticModInt.hpp\"\
    \n// 1012924417,5,2^21\n// 924844033,5,2^21\n// 998244353,3,2^23\n// 1224736769,3,2^24\n\
    // 167772161,3,2^25\n// 469762049,3,2^26\nclass NumberTheoreticTransform {\n \
    \ private:\n\ttemplate <unsigned int modulo>\n\tstatic void ntt(std::vector<StaticModInt<modulo>>&\
    \ a) {\n\t\tint sz = a.size();\n\t\tif (sz == 1) return;\n\t\tStaticModInt<modulo>\
    \ root =\n\t\t\tmodulo == 924844033 || modulo == 1012924417 ? 5 : 3;\n\t\tif (inverse)\n\
    \t\t\troot = mypow(root, modulo - 1 - (modulo - 1) / sz);\n\t\telse\n\t\t\troot\
    \ = mypow(root, (modulo - 1) / sz);\n\t\tstd::vector<StaticModInt<modulo>> b(sz),\
    \ roots((sz >> 1) + 1, 1);\n\t\trep(i, sz >> 1) roots[i + 1] = roots[i] * root;\n\
    \t\tfor (int i = sz >> 1, w = 1; w < sz; i >>= 1, w <<= 1) {\n\t\t\tfor (int j\
    \ = 0; j < i; j++) {\n\t\t\t\tfor (int k = 0; k < w; k++) {\n\t\t\t\t\tb[k + ((w\
    \ * j) << 1)] =\n\t\t\t\t\t\ta[k + w * j] + a[k + w * j + (sz >> 1)];\n\t\t\t\t\
    \tb[k + ((w * j) << 1) + w] =\n\t\t\t\t\t\troots[w * j] *\n\t\t\t\t\t\t(a[k +\
    \ w * j] - a[k + w * j + (sz >> 1)]);\n\t\t\t\t}\n\t\t\t}\n\t\t\tstd::swap(a,\
    \ b);\n\t\t}\n\t}\n\n  public:\n\tstatic bool inverse;\n\ttemplate <unsigned int\
    \ modulo, class T>\n\tstatic std::vector<StaticModInt<modulo>> multiply(std::vector<T>\
    \ f,\n\t\t\t\t\t\t\t\t\t\t\t\t\t  std::vector<T> g) {\n\t\tif (f.size() < g.size())\
    \ std::swap(f, g);\n\t\tstd::vector<StaticModInt<modulo>> nf, ng;\n\t\tint sz\
    \ = 1;\n\t\twhile (sz < f.size() + g.size()) sz <<= 1;\n\t\tnf.resize(sz);\n\t\
    \tng.resize(sz);\n\t\trep(i, f.size()) {\n\t\t\tnf[i] = f[i];\n\t\t\tif (i < g.size())\
    \ ng[i] = g[i];\n\t\t}\n\t\tinverse = false;\n\t\tntt(nf);\n\t\tntt(ng);\n\t\t\
    rep(i, sz) nf[i] *= ng[i];\n\t\tinverse = true;\n\t\tntt(nf);\n\t\tStaticModInt<modulo>\
    \ szinv = StaticModInt<modulo>(sz).inv();\n\t\trep(i, sz) nf[i] *= szinv;\n\t\t\
    return nf;\n\t}\n\ttemplate <class T>\n\tstatic std::vector<lint> multiply_plain(std::vector<T>\
    \ f,\n\t\t\t\t\t\t\t\t\t\t\tstd::vector<T> g) {\n\t\tconst unsigned int mod1 =\
    \ 998244353, mod2 = 1224736769;\n\t\tstd::vector<StaticModInt<mod1>> mul1 = multiply(f,\
    \ g);\n\t\tstd::vector<StaticModInt<mod2>> mul2 = multiply(f, g, mod2);\n\t\t\
    std::vector<lint> res(mul1.size());\n\t\trep(i, mul1.size()) res[i] =\n\t\t\t\
    ChineseRem(mul1[i], mod1, mul2[i], mod2).first;\n\t\treturn res;\n\t}\n};\nbool\
    \ NumberTheoreticTransform::inverse = false;"
  dependsOn:
  - other/template.hpp
  - algebraic/StaticModInt.hpp
  isVerificationFile: false
  path: algebraic/NumberTheoreticTransform.hpp
  requiredBy: []
  timestamp: '2021-01-14 16:19:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/convolution_mod.test.cpp
documentation_of: algebraic/NumberTheoreticTransform.hpp
layout: document
redirect_from:
- /library/algebraic/NumberTheoreticTransform.hpp
- /library/algebraic/NumberTheoreticTransform.hpp.html
title: algebraic/NumberTheoreticTransform.hpp
---
