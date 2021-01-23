---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic/StaticModInt.hpp
    title: StaticModInt
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: other/type_traits.hpp
    title: other/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algebraic/Interpolation.hpp
    title: algebraic/Interpolation.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: NumberTheoreticTransform
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
    \treturn dp[a.size()][b.size()];\n}\n#line 4 \"other/type_traits.hpp\"\n\nclass\
    \ ModInt__Base {};\nclass StaticModInt__Base : ModInt__Base {};\nclass DynamicModInt__Base\
    \ : ModInt__Base {};\n\ntemplate <class T>\nclass is_ModInt : public std::is_base_of<ModInt__Base,\
    \ T> {};\ntemplate <class T>\nconstexpr bool is_ModInt_v = is_ModInt<T>::value;\n\
    \ntemplate <class T>\nclass is_StaticModInt : public std::is_base_of<StaticModInt__Base,\
    \ T> {};\ntemplate <class T>\nconstexpr bool is_StaticModInt_v = is_StaticModInt<T>::value;\n\
    \ntemplate <class T>\nclass is_DynamicModInt : public std::is_base_of<DynamicModInt__Base,\
    \ T> {};\ntemplate <class T>\nconstexpr bool is_DynamicModInt_v = is_DynamicModInt<T>::value;\n\
    #line 4 \"algebraic/StaticModInt.hpp\"\ntemplate <uint modulo>\nclass StaticModInt\
    \ : StaticModInt__Base {\n\tstd::conditional_t<(modulo > INT_MAX >> 1), lint,\
    \ int> value;\n\n  public:\n\tstatic constexpr uint mod_value = modulo;\n\tconstexpr\
    \ StaticModInt() : value(0) {}\n\ttemplate <class T, std::enable_if_t<!std::is_convertible_v<T,\
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
    \ */\n#line 4 \"algebraic/NumberTheoreticTransform.hpp\"\n// 1012924417, 5, 2^21\n\
    // 924844033, 5, 2^21\n// 998244353, 3, 2^23\n// 1224736769, 3, 2^24\n// 167772161,\
    \ 3, 2^25\n// 469762049, 3, 2^26\nclass NumberTheoreticTransform {\n\tstatic constexpr\
    \ uint bases[] = {1012924417, 924844033, 998244353,\n\t\t\t\t\t\t\t\t\t1224736769,\
    \ 167772161, 469762049};\n\n  private:\n\ttemplate <unsigned int modulo>\n\tstatic\
    \ void ntt(std::vector<StaticModInt<modulo>>& a) {\n\t\tint sz = a.size();\n\t\
    \tif (sz == 1) return;\n\t\tStaticModInt<modulo> root =\n\t\t\tmodulo == 924844033\
    \ || modulo == 1012924417 ? 5 : 3;\n\t\tif (inverse)\n\t\t\troot = mypow(root,\
    \ modulo - 1 - (modulo - 1) / sz);\n\t\telse\n\t\t\troot = mypow(root, (modulo\
    \ - 1) / sz);\n\t\tstd::vector<StaticModInt<modulo>> b(sz), roots((sz >> 1) +\
    \ 1, 1);\n\t\trep(i, sz >> 1) roots[i + 1] = roots[i] * root;\n\t\tfor (int i\
    \ = sz >> 1, w = 1; w < sz; i >>= 1, w <<= 1) {\n\t\t\tfor (int j = 0; j < i;\
    \ j++) {\n\t\t\t\tfor (int k = 0; k < w; k++) {\n\t\t\t\t\tb[k + ((w * j) << 1)]\
    \ =\n\t\t\t\t\t\ta[k + w * j] + a[k + w * j + (sz >> 1)];\n\t\t\t\t\tb[k + ((w\
    \ * j) << 1) + w] =\n\t\t\t\t\t\troots[w * j] *\n\t\t\t\t\t\t(a[k + w * j] - a[k\
    \ + w * j + (sz >> 1)]);\n\t\t\t\t}\n\t\t\t}\n\t\t\tstd::swap(a, b);\n\t\t}\n\t\
    }\n\ttemplate <uint modulo, typename T>\n\tstatic std::vector<StaticModInt<modulo>>\
    \ internal_multiply(\n\t\tconst std::vector<T>& f, const std::vector<T>& g) {\n\
    \t\tstd::vector<StaticModInt<modulo>> nf(f.size()), ng(g.size());\n\t\trep(j,\
    \ f.size()) nf[j] = f[j];\n\t\trep(j, g.size()) ng[j] = g[j];\n\t\tinverse = false;\n\
    \t\tntt(nf);\n\t\tntt(ng);\n\t\trep(i, nf.size()) nf[i] *= ng[i];\n\t\tinverse\
    \ = true;\n\t\tntt(nf);\n\t\tStaticModInt<modulo> inv = StaticModInt<modulo>(nf.size()).inv();\n\
    \t\trep(i, nf.size()) nf[i] *= inv;\n\t\treturn nf;\n\t}\n\n  public:\n\tstatic\
    \ bool inverse;\n\n\ttemplate <uint modulo, typename T>\n\tstatic std::vector<StaticModInt<modulo>>\
    \ multiply(std::vector<T> f,\n\t\t\t\t\t\t\t\t\t\t\t\t\t  std::vector<T> g) {\n\
    \t\tsize_t sz = 1;\n\t\twhile (sz < f.size() + g.size()) sz <<= 1;\n\t\tf.resize(sz);\n\
    \t\tg.resize(sz);\n\t\trep(i, 6) {\n\t\t\tif (modulo == bases[i]) return internal_multiply<modulo>(f,\
    \ g);\n\t\t}\n\t\tconstexpr uint base1 = 998244353, base2 = 1224736769, base3\
    \ = 469762049;\n\t\tauto re1 = internal_multiply<base1>(f, g);\n\t\tauto re2 =\
    \ internal_multiply<base2>(f, g);\n\t\tauto re3 = internal_multiply<base3>(f,\
    \ g);\n\t\tstd::vector<StaticModInt<modulo>> res(re1.size());\n\t\tconstexpr int\
    \ r12 = StaticModInt<base2>(base1).inv();\n\t\tconstexpr int r13 = StaticModInt<base3>(base1).inv();\n\
    \t\tconstexpr int r23 = StaticModInt<base3>(base2).inv();\n\t\tconstexpr int p12\
    \ = StaticModInt<modulo>(base1) * base2;\n\t\trep(i, re1.size()) {\n\t\t\tre2[i]\
    \ = StaticModInt<base2>(re2[i] - re1[i]) * r12;\n\t\t\tre3[i] =\n\t\t\t\t(StaticModInt<base3>(re3[i]\
    \ - re1[i]) * r13 - re2[i]) * r23;\n\t\t\tres[i] = (StaticModInt<modulo>(re1[i])\
    \ +\n\t\t\t\t\t  StaticModInt<modulo>(re2[i]) * base1 +\n\t\t\t\t\t  StaticModInt<modulo>(re3[i])\
    \ * base1 * base2);\n\t\t}\n\t\treturn res;\n\t}\n\ttemplate <class T>\n\tstatic\
    \ std::vector<lint> multiply_plain(std::vector<T> f,\n\t\t\t\t\t\t\t\t\t\t\tstd::vector<T>\
    \ g) {\n\t\tconst uint mod1 = 998244353, mod2 = 1224736769;\n\t\tstd::vector<StaticModInt<mod1>>\
    \ mul1 = internal_multiply<mod1>(f, g);\n\t\tstd::vector<StaticModInt<mod2>> mul2\
    \ = internal_multiply<mod2>(f, g);\n\t\tstd::vector<lint> res(mul1.size());\n\t\
    \trep(i, mul1.size()) res[i] =\n\t\t\tChineseRem(mul1[i], mod1, mul2[i], mod2).first;\n\
    \t\treturn res;\n\t}\n};\nbool NumberTheoreticTransform::inverse = false;\n\n\
    /**\n * @title NumberTheoreticTransform\n */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\n#include \"StaticModInt.hpp\"\
    \n// 1012924417, 5, 2^21\n// 924844033, 5, 2^21\n// 998244353, 3, 2^23\n// 1224736769,\
    \ 3, 2^24\n// 167772161, 3, 2^25\n// 469762049, 3, 2^26\nclass NumberTheoreticTransform\
    \ {\n\tstatic constexpr uint bases[] = {1012924417, 924844033, 998244353,\n\t\t\
    \t\t\t\t\t\t\t1224736769, 167772161, 469762049};\n\n  private:\n\ttemplate <unsigned\
    \ int modulo>\n\tstatic void ntt(std::vector<StaticModInt<modulo>>& a) {\n\t\t\
    int sz = a.size();\n\t\tif (sz == 1) return;\n\t\tStaticModInt<modulo> root =\n\
    \t\t\tmodulo == 924844033 || modulo == 1012924417 ? 5 : 3;\n\t\tif (inverse)\n\
    \t\t\troot = mypow(root, modulo - 1 - (modulo - 1) / sz);\n\t\telse\n\t\t\troot\
    \ = mypow(root, (modulo - 1) / sz);\n\t\tstd::vector<StaticModInt<modulo>> b(sz),\
    \ roots((sz >> 1) + 1, 1);\n\t\trep(i, sz >> 1) roots[i + 1] = roots[i] * root;\n\
    \t\tfor (int i = sz >> 1, w = 1; w < sz; i >>= 1, w <<= 1) {\n\t\t\tfor (int j\
    \ = 0; j < i; j++) {\n\t\t\t\tfor (int k = 0; k < w; k++) {\n\t\t\t\t\tb[k + ((w\
    \ * j) << 1)] =\n\t\t\t\t\t\ta[k + w * j] + a[k + w * j + (sz >> 1)];\n\t\t\t\t\
    \tb[k + ((w * j) << 1) + w] =\n\t\t\t\t\t\troots[w * j] *\n\t\t\t\t\t\t(a[k +\
    \ w * j] - a[k + w * j + (sz >> 1)]);\n\t\t\t\t}\n\t\t\t}\n\t\t\tstd::swap(a,\
    \ b);\n\t\t}\n\t}\n\ttemplate <uint modulo, typename T>\n\tstatic std::vector<StaticModInt<modulo>>\
    \ internal_multiply(\n\t\tconst std::vector<T>& f, const std::vector<T>& g) {\n\
    \t\tstd::vector<StaticModInt<modulo>> nf(f.size()), ng(g.size());\n\t\trep(j,\
    \ f.size()) nf[j] = f[j];\n\t\trep(j, g.size()) ng[j] = g[j];\n\t\tinverse = false;\n\
    \t\tntt(nf);\n\t\tntt(ng);\n\t\trep(i, nf.size()) nf[i] *= ng[i];\n\t\tinverse\
    \ = true;\n\t\tntt(nf);\n\t\tStaticModInt<modulo> inv = StaticModInt<modulo>(nf.size()).inv();\n\
    \t\trep(i, nf.size()) nf[i] *= inv;\n\t\treturn nf;\n\t}\n\n  public:\n\tstatic\
    \ bool inverse;\n\n\ttemplate <uint modulo, typename T>\n\tstatic std::vector<StaticModInt<modulo>>\
    \ multiply(std::vector<T> f,\n\t\t\t\t\t\t\t\t\t\t\t\t\t  std::vector<T> g) {\n\
    \t\tsize_t sz = 1;\n\t\twhile (sz < f.size() + g.size()) sz <<= 1;\n\t\tf.resize(sz);\n\
    \t\tg.resize(sz);\n\t\trep(i, 6) {\n\t\t\tif (modulo == bases[i]) return internal_multiply<modulo>(f,\
    \ g);\n\t\t}\n\t\tconstexpr uint base1 = 998244353, base2 = 1224736769, base3\
    \ = 469762049;\n\t\tauto re1 = internal_multiply<base1>(f, g);\n\t\tauto re2 =\
    \ internal_multiply<base2>(f, g);\n\t\tauto re3 = internal_multiply<base3>(f,\
    \ g);\n\t\tstd::vector<StaticModInt<modulo>> res(re1.size());\n\t\tconstexpr int\
    \ r12 = StaticModInt<base2>(base1).inv();\n\t\tconstexpr int r13 = StaticModInt<base3>(base1).inv();\n\
    \t\tconstexpr int r23 = StaticModInt<base3>(base2).inv();\n\t\tconstexpr int p12\
    \ = StaticModInt<modulo>(base1) * base2;\n\t\trep(i, re1.size()) {\n\t\t\tre2[i]\
    \ = StaticModInt<base2>(re2[i] - re1[i]) * r12;\n\t\t\tre3[i] =\n\t\t\t\t(StaticModInt<base3>(re3[i]\
    \ - re1[i]) * r13 - re2[i]) * r23;\n\t\t\tres[i] = (StaticModInt<modulo>(re1[i])\
    \ +\n\t\t\t\t\t  StaticModInt<modulo>(re2[i]) * base1 +\n\t\t\t\t\t  StaticModInt<modulo>(re3[i])\
    \ * base1 * base2);\n\t\t}\n\t\treturn res;\n\t}\n\ttemplate <class T>\n\tstatic\
    \ std::vector<lint> multiply_plain(std::vector<T> f,\n\t\t\t\t\t\t\t\t\t\t\tstd::vector<T>\
    \ g) {\n\t\tconst uint mod1 = 998244353, mod2 = 1224736769;\n\t\tstd::vector<StaticModInt<mod1>>\
    \ mul1 = internal_multiply<mod1>(f, g);\n\t\tstd::vector<StaticModInt<mod2>> mul2\
    \ = internal_multiply<mod2>(f, g);\n\t\tstd::vector<lint> res(mul1.size());\n\t\
    \trep(i, mul1.size()) res[i] =\n\t\t\tChineseRem(mul1[i], mod1, mul2[i], mod2).first;\n\
    \t\treturn res;\n\t}\n};\nbool NumberTheoreticTransform::inverse = false;\n\n\
    /**\n * @title NumberTheoreticTransform\n */"
  dependsOn:
  - other/template.hpp
  - algebraic/StaticModInt.hpp
  - other/type_traits.hpp
  isVerificationFile: false
  path: algebraic/NumberTheoreticTransform.hpp
  requiredBy:
  - algebraic/Interpolation.hpp
  timestamp: '2021-01-19 14:37:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
documentation_of: algebraic/NumberTheoreticTransform.hpp
layout: document
redirect_from:
- /library/algebraic/NumberTheoreticTransform.hpp
- /library/algebraic/NumberTheoreticTransform.hpp.html
title: NumberTheoreticTransform
---
