---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: algebraic/MyComplex.hpp
    title: MyComplex
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: FastFourierTransform
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #ifdef ONLINE_JUDGE\n#pragma GCC target(\"avx512f\")\n#elif defined EVAL\n#else\n\
    #pragma GCC target(\"avx2\")\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC\
    \ optimize(\"unroll-loops\")\n#include <string.h>\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <cfloat>\n#include\
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
    constexpr lint LINF = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr\
    \ double PI = 3.141592653589793238462643383279;\n\ntemplate <class T>\nclass prique\
    \ : public std::priority_queue<T, std::vector<T>, std::greater<T>> {\n};\ntemplate\
    \ <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f) {\n\treturn [f\
    \ = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
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
    \ <class InputIter>\nconstexpr void printArray(InputIter l, InputIter r, char\
    \ split = ' ') {\n\tauto rprev = std::prev(r);\n\tfor (auto i = l; i != r; i++)\
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
    algebraic/MyComplex.hpp\"\nclass MyComplex {\n\tdouble realvalue, imagvalue;\n\
    \n  public:\n\tMyComplex() : realvalue(0), imagvalue(0) {}\n\ttemplate <class\
    \ T, class U>\n\tMyComplex(const T& realvalue, const U& imagvalue)\n\t\t: realvalue(realvalue),\
    \ imagvalue(imagvalue) {}\n\ttemplate <class T>\n\tMyComplex(const T& realvalue)\
    \ : realvalue(realvalue), imagvalue(0) {}\n\ttemplate <class T>\n\tMyComplex(const\
    \ std::complex<T>& c)\n\t\t: realvalue(c.real()), imagvalue(c.imag()) {}\n\tdouble&\
    \ real() { return this->realvalue; }\n\tdouble& imag() { return this->imagvalue;\
    \ }\n\tdouble abs() const { return hypot(realvalue, imagvalue); }\n\tMyComplex&\
    \ operator+=(const MyComplex& rhs) {\n\t\tthis->realvalue += rhs.realvalue;\n\t\
    \tthis->imagvalue += rhs.imagvalue;\n\t\treturn *this;\n\t}\n\tMyComplex& operator-=(const\
    \ MyComplex& rhs) {\n\t\tthis->realvalue -= rhs.realvalue;\n\t\tthis->imagvalue\
    \ -= rhs.imagvalue;\n\t\treturn *this;\n\t}\n\tMyComplex& operator*=(const MyComplex&\
    \ rhs) {\n\t\tdouble pastreal = this->realvalue;\n\t\tthis->realvalue =\n\t\t\t\
    this->realvalue * rhs.realvalue - this->imagvalue * rhs.imagvalue;\n\t\tthis->imagvalue\
    \ =\n\t\t\tpastreal * rhs.imagvalue + rhs.realvalue * this->imagvalue;\n\t\treturn\
    \ *this;\n\t}\n\tMyComplex& operator/=(const MyComplex& rhs) {\n\t\t*this *= MyComplex(rhs.realvalue,\
    \ -rhs.imagvalue);\n\t\tdouble dnm =\n\t\t\trhs.realvalue * rhs.realvalue - rhs.imagvalue\
    \ * rhs.imagvalue;\n\t\tthis->realvalue /= dnm;\n\t\tthis->imagvalue /= dnm;\n\
    \t\treturn *this;\n\t}\n\n\ttemplate <class T>\n\tMyComplex operator+(const T&\
    \ rhs) const {\n\t\treturn MyComplex(*this) += rhs;\n\t}\n\ttemplate <class T>\n\
    \tMyComplex& operator+=(const T& rhs) const {\n\t\treturn operator+=(MyComplex(rhs));\n\
    \t}\n\ttemplate <class T>\n\tMyComplex operator-(const T& rhs) const {\n\t\treturn\
    \ MyComplex(*this) -= rhs;\n\t}\n\ttemplate <class T>\n\tMyComplex& operator-=(const\
    \ T& rhs) const {\n\t\treturn operator-=(MyComplex(rhs));\n\t}\n\ttemplate <class\
    \ T>\n\tMyComplex operator*(const T& rhs) const {\n\t\treturn MyComplex(*this)\
    \ *= rhs;\n\t}\n\ttemplate <class T>\n\tMyComplex& operator*=(const T& rhs) const\
    \ {\n\t\treturn operator*=(MyComplex(rhs));\n\t}\n\ttemplate <class T>\n\tMyComplex\
    \ operator/(const T& rhs) const {\n\t\treturn MyComplex(*this) /= rhs;\n\t}\n\t\
    template <class T>\n\tMyComplex& operator/=(const T& rhs) const {\n\t\treturn\
    \ operator/=(MyComplex(rhs));\n\t}\n};\n\n/**\n * @title MyComplex\n */\n#line\
    \ 4 \"algebraic/FastFourierTransform.hpp\"\nclass FastFourierTransform {\n  private:\n\
    \tstatic void dft(std::vector<MyComplex>& a) {\n\t\tint sz = a.size();\n\t\tif\
    \ (sz == 1) return;\n\t\tMyComplex root =\n\t\t\tstd::polar(1.0, (inverse ? -1\
    \ : 1) * 2.0 * acos(-1) / sz);\n\t\tstd::vector<MyComplex> b(sz), roots((sz >>\
    \ 1) + 1, 1);\n\t\trep(i, sz >> 1) roots[i + 1] = roots[i] * root;\n\t\tfor (int\
    \ i = sz >> 1, w = 1; w < sz; i >>= 1, w <<= 1) {\n\t\t\tfor (int j = 0; j < i;\
    \ j++) {\n\t\t\t\tfor (int k = 0; k < w; k++) {\n\t\t\t\t\tb[k + ((w * j) << 1)]\
    \ =\n\t\t\t\t\t\ta[k + w * j] + a[k + w * j + (sz >> 1)];\n\t\t\t\t\tb[k + ((w\
    \ * j) << 1) + w] =\n\t\t\t\t\t\troots[w * j] *\n\t\t\t\t\t\t(a[k + w * j] - a[k\
    \ + w * j + (sz >> 1)]);\n\t\t\t\t}\n\t\t\t}\n\t\t\tstd::swap(a, b);\n\t\t}\n\t\
    }\n\n  public:\n\tstatic constexpr bool inverse = false;\n\ttemplate <class T>\n\
    \tstatic std::vector<double> multiply(std::vector<T> f, std::vector<T> g) {\n\t\
    \tif (f.size() < g.size()) std::swap(f, g);\n\t\tstd::vector<MyComplex> nf, ng;\n\
    \t\tint sz = 1;\n\t\twhile (sz < f.size() + g.size()) sz *= 2;\n\t\tnf.resize(sz);\n\
    \t\tng.resize(sz);\n\t\trep(i, f.size()) {\n\t\t\tnf[i] = f[i];\n\t\t\tif (i <\
    \ g.size()) ng[i] = g[i];\n\t\t}\n\t\tinverse = false;\n\t\tdft(nf);\n\t\tdft(ng);\n\
    \t\trep(i, sz) nf[i] *= ng[i];\n\t\tinverse = true;\n\t\tdft(nf);\n\t\tstd::vector<double>\
    \ res(sz);\n\t\trep(i, sz) res[i] = nf[i].real() / sz;\n\t\treturn res;\n\t}\n\
    };\n\n/**\n * @title FastFourierTransform\n */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\n#include \"MyComplex.hpp\"\
    \nclass FastFourierTransform {\n  private:\n\tstatic void dft(std::vector<MyComplex>&\
    \ a) {\n\t\tint sz = a.size();\n\t\tif (sz == 1) return;\n\t\tMyComplex root =\n\
    \t\t\tstd::polar(1.0, (inverse ? -1 : 1) * 2.0 * acos(-1) / sz);\n\t\tstd::vector<MyComplex>\
    \ b(sz), roots((sz >> 1) + 1, 1);\n\t\trep(i, sz >> 1) roots[i + 1] = roots[i]\
    \ * root;\n\t\tfor (int i = sz >> 1, w = 1; w < sz; i >>= 1, w <<= 1) {\n\t\t\t\
    for (int j = 0; j < i; j++) {\n\t\t\t\tfor (int k = 0; k < w; k++) {\n\t\t\t\t\
    \tb[k + ((w * j) << 1)] =\n\t\t\t\t\t\ta[k + w * j] + a[k + w * j + (sz >> 1)];\n\
    \t\t\t\t\tb[k + ((w * j) << 1) + w] =\n\t\t\t\t\t\troots[w * j] *\n\t\t\t\t\t\t\
    (a[k + w * j] - a[k + w * j + (sz >> 1)]);\n\t\t\t\t}\n\t\t\t}\n\t\t\tstd::swap(a,\
    \ b);\n\t\t}\n\t}\n\n  public:\n\tstatic constexpr bool inverse = false;\n\ttemplate\
    \ <class T>\n\tstatic std::vector<double> multiply(std::vector<T> f, std::vector<T>\
    \ g) {\n\t\tif (f.size() < g.size()) std::swap(f, g);\n\t\tstd::vector<MyComplex>\
    \ nf, ng;\n\t\tint sz = 1;\n\t\twhile (sz < f.size() + g.size()) sz *= 2;\n\t\t\
    nf.resize(sz);\n\t\tng.resize(sz);\n\t\trep(i, f.size()) {\n\t\t\tnf[i] = f[i];\n\
    \t\t\tif (i < g.size()) ng[i] = g[i];\n\t\t}\n\t\tinverse = false;\n\t\tdft(nf);\n\
    \t\tdft(ng);\n\t\trep(i, sz) nf[i] *= ng[i];\n\t\tinverse = true;\n\t\tdft(nf);\n\
    \t\tstd::vector<double> res(sz);\n\t\trep(i, sz) res[i] = nf[i].real() / sz;\n\
    \t\treturn res;\n\t}\n};\n\n/**\n * @title FastFourierTransform\n */"
  dependsOn:
  - other/template.hpp
  - algebraic/MyComplex.hpp
  isVerificationFile: false
  path: algebraic/FastFourierTransform.hpp
  requiredBy: []
  timestamp: '2021-02-24 00:36:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebraic/FastFourierTransform.hpp
layout: document
redirect_from:
- /library/algebraic/FastFourierTransform.hpp
- /library/algebraic/FastFourierTransform.hpp.html
title: FastFourierTransform
---
