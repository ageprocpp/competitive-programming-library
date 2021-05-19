---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #ifndef __clang__\n#ifdef ONLINE_JUDGE\n#pragma GCC target(\"avx512f\")\n#elif\
    \ defined EVAL\n#else\n#pragma GCC target(\"avx2\")\n#endif\n#pragma GCC optimize(\"\
    O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#endif\n#include <string.h>\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cfloat>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <ctime>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <iterator>\n#include <list>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n\n#define rep(i, n) for (int i = 0; i <\
    \ int(n); i++)\n#define REP(i, n) for (int i = 1; i <= int(n); i++)\n#define all(V)\
    \ V.begin(), V.end()\n\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using uint = unsigned int;\nusing lint = long long;\nusing ulint = unsigned long\
    \ long;\nusing IP = std::pair<int, int>;\nusing LP = std::pair<lint, lint>;\n\n\
    constexpr int INF = INT_MAX / 2;\nconstexpr lint LINF = LLONG_MAX / 2;\nconstexpr\
    \ double eps = DBL_EPSILON;\nconstexpr double PI = 3.141592653589793238462643383279;\n\
    \ntemplate <class T>\nclass prique : public std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> {\n};\nint popcount(uint x) {\n#if __cplusplus >= 202002L\n\
    \treturn std::popcount(x);\n#else\n#ifndef __clang__\n\treturn __builtin_popcount(x);\n\
    #endif\n#endif\n\tx = (x & 0x55555555) + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333)\
    \ + (x >> 2 & 0x33333333);\n\tx = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\t\
    x = (x & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x\
    \ >> 16 & 0x0000ffff);\n}\ntemplate <class F>\ninline constexpr decltype(auto)\
    \ lambda_fix(F&& f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\
    \treturn f(f, std::forward<decltype(args)>(args)...);\n\t};\n}\ntemplate <class\
    \ T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n\
    }\ntemplate <class T, class... Args>\nconstexpr auto make_vec(size_t n, Args&&...\
    \ args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\t\tn, make_vec<T>(std::forward<Args>(args)...));\n\
    }\ntemplate <class T, class U>\nstd::istream& operator>>(std::istream& ist, std::pair<T,\
    \ U>& x) {\n\treturn ist >> x.first >> x.second;\n}\ntemplate <class T, class\
    \ U>\nstd::ostream& operator<<(std::ostream& ost, const std::pair<T, U>& x) {\n\
    \treturn ost << x.first << \" \" << x.second;\n}\ntemplate <class T, class U>\n\
    constexpr inline bool chmax(T& lhs, const U& rhs) noexcept {\n\tif (lhs < rhs)\
    \ {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class\
    \ T, class U>\nconstexpr inline bool chmin(T& lhs, const U& rhs) noexcept {\n\t\
    if (lhs > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\
    constexpr inline lint gcd(lint a, lint b) noexcept {\n\twhile (b) {\n\t\tlint\
    \ c = a;\n\t\ta = b;\n\t\tb = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint\
    \ a, lint b) noexcept { return a / gcd(a, b) * b; }\nconstexpr bool isprime(lint\
    \ n) noexcept {\n\tif (n == 1) return false;\n\tfor (int i = 2; i * i <= n; i++)\
    \ {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn true;\n}\ntemplate <class\
    \ T>\nconstexpr T mypow(T a, lint b) noexcept {\n\tT res(1);\n\twhile (true) {\n\
    \t\tif (b & 1) res *= a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\t\ta *= a;\n\t}\n\
    \treturn res;\n}\nconstexpr lint modpow(lint a, lint b, lint m) noexcept {\n\t\
    a %= m;\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\tres *= a;\n\t\t\
    \tres %= m;\n\t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\t}\n\treturn res;\n\
    }\ntemplate <class T>\nconstexpr void printArray(const std::vector<T>& vec, char\
    \ split = ' ') {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\t\tstd::cout\
    \ << (i == (int)vec.size() - 1 ? '\\n' : split);\n\t}\n}\ntemplate <class InputIter>\n\
    constexpr void printArray(InputIter l, InputIter r, char split = ' ') {\n\tauto\
    \ rprev = std::prev(r);\n\tfor (auto i = l; i != r; i++) {\n\t\tstd::cout << *i;\n\
    \t\tstd::cout << (i == rprev ? '\\n' : split);\n\t}\n}\nLP extGcd(lint a, lint\
    \ b) noexcept {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b, a % b);\n\t\
    std::swap(s.first, s.second);\n\ts.second -= a / b * s.first;\n\treturn s;\n}\n\
    LP ChineseRem(const lint& b1, const lint& m1, const lint& b2,\n\t\t\t  const lint&\
    \ m2) noexcept {\n\tauto p = extGcd(m1, m2);\n\tlint g = gcd(m1, m2), l = m1 /\
    \ g * m2;\n\tlint tmp = (b2 - b1) / g * p.first % (m2 / g);\n\tlint r = (b1 +\
    \ m1 * tmp + l) % l;\n\treturn {r, l};\n}\nint LCS(const std::string& a, const\
    \ std::string& b) {\n\tauto dp = make_vec<int>(a.size() + 1, b.size() + 1);\n\t\
    rep(i, a.size()) {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j], dp[i][j]);\n\
    \t\t\tchmax(dp[i][j + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i + 1][j\
    \ + 1], dp[i][j] + 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\
    \t}\n\trep(j, b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn\
    \ dp[a.size()][b.size()];\n}\ntemplate <class T, std::enable_if_t<std::is_convertible<int,\
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
    algebraic/Matrix.hpp\"\n\ntemplate <class T>\nclass Matrix {\n  protected:\n\t\
    uint N, M;\n\tstd::vector<std::vector<T>> elems;\n\n  public:\n\tMatrix() = default;\n\
    \tMatrix(uint N_, uint M_) : N(N_), M(M_), elems(N, std::vector<T>(M)) {}\n\t\
    std::vector<T>& operator[](uint idx) { return elems[idx]; }\n\tconst std::vector<T>&\
    \ operator[](uint idx) const { return elems[idx]; }\n\tdecltype(elems)& data()\
    \ { return elems; }\n\tconst decltype(elems)& data() const { return elems; }\n\
    \n\tvoid resize(int N_, int M_) {\n\t\telems.resize(N_);\n\t\trep(i, N_) elems[i].resize(M_);\n\
    \t}\n\n\tMatrix operator*(Matrix rhs) const {\n\t\tMatrix<T> res(N, rhs.M);\n\t\
    \trep(i, N) rep(j, M) rep(k, rhs.M) res[i][k] +=\n\t\t\telems[i][j] * rhs.elems[j][k];\n\
    \t\treturn res;\n\t}\n};\n\ntemplate <class T>\nclass SquareMatrix : public Matrix<T>\
    \ {\n\tusing Matrix<T>::N;\n\tusing Matrix<T>::Matrix;\n\tusing Matrix<T>::elems;\n\
    \n  public:\n\tSquareMatrix(uint N_) : Matrix<T>(N_, N_) {}\n\tSquareMatrix<T>&\
    \ operator=(const Matrix<T>& rhs) {\n\t\telems = rhs.data();\n\t\treturn *this;\n\
    \t}\n\tSquareMatrix<T>& operator=(Matrix<T>&& rhs) {\n\t\telems = std::move(rhs.data());\n\
    \t\treturn *this;\n\t}\n\tSquareMatrix<T> operator*=(const SquareMatrix<T>& rhs)\
    \ {\n\t\t*this = *this * rhs;\n\t\treturn *this;\n\t}\n\tSquareMatrix<T> pow(lint\
    \ p) const {\n\t\tSquareMatrix<T> res{N}, memo = *this;\n\t\trep(i, N) res[i][i]\
    \ = 1;\n\t\twhile (p) {\n\t\t\tif (p & 1) res *= memo;\n\t\t\tp >>= 1;\n\t\t\t\
    memo *= memo;\n\t\t}\n\t\treturn res;\n\t}\n};\n\ntemplate <class T, uint N, uint\
    \ M>\nclass FixedMatrix {\n  protected:\n\tstd::array<std::array<T, M>, N> elems;\n\
    \n  public:\n\tFixedMatrix() { rep(i, N) elems[i].fill(0); }\n\tFixedMatrix(std::initializer_list<T>\
    \ init) {\n\t\tauto ite = init.begin();\n\t\trep(i, N) rep(j, M) elems[i][j] =\
    \ *ite++;\n\t}\n\tstd::array<T, N>& operator[](uint idx) { return elems[idx];\
    \ }\n\tdecltype(elems)& data() { return elems; }\n\tconst decltype(elems)& data()\
    \ const { return elems; }\n\n\ttemplate <uint L>\n\tFixedMatrix<T, N, L> operator*(const\
    \ FixedMatrix<T, M, L>& rhs) const {\n\t\tFixedMatrix<T, N, L> res;\n\t\trep(i,\
    \ N) rep(j, M) rep(k, L) res[i][k] +=\n\t\t\telems[i][j] * rhs.elems[j][k];\n\t\
    \treturn res;\n\t}\n};\n\ntemplate <class T, uint N>\nclass FixedSquareMatrix\
    \ : public FixedMatrix<T, N, N> {\n\tusing FixedMatrix<T, N, N>::FixedMatrix;\n\
    \tusing FixedMatrix<T, N, N>::elems;\n\n  public:\n\tusing FixedMatrix<T, N, N>::operator*;\n\
    \tFixedSquareMatrix(const FixedMatrix<T, N, N>& obj)\n\t\t: FixedMatrix<T, N,\
    \ N>(obj) {}\n\tFixedSquareMatrix<T, N>& operator=(const FixedMatrix<T, N, N>&\
    \ rhs) {\n\t\telems = rhs.data();\n\t\treturn *this;\n\t}\n\tFixedSquareMatrix<T,\
    \ N>& operator=(FixedMatrix<T, N, N>&& rhs) {\n\t\telems = std::move(rhs.data());\n\
    \t\treturn *this;\n\t}\n\tFixedSquareMatrix<T, N>& operator*=(const FixedSquareMatrix<T,\
    \ N>& rhs) {\n\t\t*this = *this * rhs;\n\t\treturn *this;\n\t}\n\tFixedSquareMatrix<T,\
    \ N> pow(lint p) const {\n\t\tFixedSquareMatrix<T, N> res, memo = *this;\n\t\t\
    rep(i, N) res[i][i] = 1;\n\t\twhile (p) {\n\t\t\tif (p & 1) res *= memo;\n\t\t\
    \tp >>= 1;\n\t\t\tmemo *= memo;\n\t\t}\n\t\treturn res;\n\t}\n\n\tstatic FixedSquareMatrix<T,\
    \ N> ident() {\n\t\tFixedSquareMatrix<T, N> res;\n\t\trep(i, N) res[i][i] = 1;\n\
    \t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\n\ntemplate <class T>\n\
    class Matrix {\n  protected:\n\tuint N, M;\n\tstd::vector<std::vector<T>> elems;\n\
    \n  public:\n\tMatrix() = default;\n\tMatrix(uint N_, uint M_) : N(N_), M(M_),\
    \ elems(N, std::vector<T>(M)) {}\n\tstd::vector<T>& operator[](uint idx) { return\
    \ elems[idx]; }\n\tconst std::vector<T>& operator[](uint idx) const { return elems[idx];\
    \ }\n\tdecltype(elems)& data() { return elems; }\n\tconst decltype(elems)& data()\
    \ const { return elems; }\n\n\tvoid resize(int N_, int M_) {\n\t\telems.resize(N_);\n\
    \t\trep(i, N_) elems[i].resize(M_);\n\t}\n\n\tMatrix operator*(Matrix rhs) const\
    \ {\n\t\tMatrix<T> res(N, rhs.M);\n\t\trep(i, N) rep(j, M) rep(k, rhs.M) res[i][k]\
    \ +=\n\t\t\telems[i][j] * rhs.elems[j][k];\n\t\treturn res;\n\t}\n};\n\ntemplate\
    \ <class T>\nclass SquareMatrix : public Matrix<T> {\n\tusing Matrix<T>::N;\n\t\
    using Matrix<T>::Matrix;\n\tusing Matrix<T>::elems;\n\n  public:\n\tSquareMatrix(uint\
    \ N_) : Matrix<T>(N_, N_) {}\n\tSquareMatrix<T>& operator=(const Matrix<T>& rhs)\
    \ {\n\t\telems = rhs.data();\n\t\treturn *this;\n\t}\n\tSquareMatrix<T>& operator=(Matrix<T>&&\
    \ rhs) {\n\t\telems = std::move(rhs.data());\n\t\treturn *this;\n\t}\n\tSquareMatrix<T>\
    \ operator*=(const SquareMatrix<T>& rhs) {\n\t\t*this = *this * rhs;\n\t\treturn\
    \ *this;\n\t}\n\tSquareMatrix<T> pow(lint p) const {\n\t\tSquareMatrix<T> res{N},\
    \ memo = *this;\n\t\trep(i, N) res[i][i] = 1;\n\t\twhile (p) {\n\t\t\tif (p &\
    \ 1) res *= memo;\n\t\t\tp >>= 1;\n\t\t\tmemo *= memo;\n\t\t}\n\t\treturn res;\n\
    \t}\n};\n\ntemplate <class T, uint N, uint M>\nclass FixedMatrix {\n  protected:\n\
    \tstd::array<std::array<T, M>, N> elems;\n\n  public:\n\tFixedMatrix() { rep(i,\
    \ N) elems[i].fill(0); }\n\tFixedMatrix(std::initializer_list<T> init) {\n\t\t\
    auto ite = init.begin();\n\t\trep(i, N) rep(j, M) elems[i][j] = *ite++;\n\t}\n\
    \tstd::array<T, N>& operator[](uint idx) { return elems[idx]; }\n\tdecltype(elems)&\
    \ data() { return elems; }\n\tconst decltype(elems)& data() const { return elems;\
    \ }\n\n\ttemplate <uint L>\n\tFixedMatrix<T, N, L> operator*(const FixedMatrix<T,\
    \ M, L>& rhs) const {\n\t\tFixedMatrix<T, N, L> res;\n\t\trep(i, N) rep(j, M)\
    \ rep(k, L) res[i][k] +=\n\t\t\telems[i][j] * rhs.elems[j][k];\n\t\treturn res;\n\
    \t}\n};\n\ntemplate <class T, uint N>\nclass FixedSquareMatrix : public FixedMatrix<T,\
    \ N, N> {\n\tusing FixedMatrix<T, N, N>::FixedMatrix;\n\tusing FixedMatrix<T,\
    \ N, N>::elems;\n\n  public:\n\tusing FixedMatrix<T, N, N>::operator*;\n\tFixedSquareMatrix(const\
    \ FixedMatrix<T, N, N>& obj)\n\t\t: FixedMatrix<T, N, N>(obj) {}\n\tFixedSquareMatrix<T,\
    \ N>& operator=(const FixedMatrix<T, N, N>& rhs) {\n\t\telems = rhs.data();\n\t\
    \treturn *this;\n\t}\n\tFixedSquareMatrix<T, N>& operator=(FixedMatrix<T, N, N>&&\
    \ rhs) {\n\t\telems = std::move(rhs.data());\n\t\treturn *this;\n\t}\n\tFixedSquareMatrix<T,\
    \ N>& operator*=(const FixedSquareMatrix<T, N>& rhs) {\n\t\t*this = *this * rhs;\n\
    \t\treturn *this;\n\t}\n\tFixedSquareMatrix<T, N> pow(lint p) const {\n\t\tFixedSquareMatrix<T,\
    \ N> res, memo = *this;\n\t\trep(i, N) res[i][i] = 1;\n\t\twhile (p) {\n\t\t\t\
    if (p & 1) res *= memo;\n\t\t\tp >>= 1;\n\t\t\tmemo *= memo;\n\t\t}\n\t\treturn\
    \ res;\n\t}\n\n\tstatic FixedSquareMatrix<T, N> ident() {\n\t\tFixedSquareMatrix<T,\
    \ N> res;\n\t\trep(i, N) res[i][i] = 1;\n\t\treturn res;\n\t}\n};"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: algebraic/Matrix.hpp
  requiredBy: []
  timestamp: '2021-05-20 00:07:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algebraic/Matrix.hpp
layout: document
redirect_from:
- /library/algebraic/Matrix.hpp
- /library/algebraic/Matrix.hpp.html
title: algebraic/Matrix.hpp
---
