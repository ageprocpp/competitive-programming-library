---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: basic/template.hpp
    title: basic/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Matrix
    links: []
  bundledCode: "#line 2 \"basic/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #ifndef __clang__\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
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
    }\n#line 3 \"math/Matrix.hpp\"\n\ntemplate <class T, std::enable_if_t<\n#if __cplusplus\
    \ >= 201703L\n\t\t\t\t\t   std::is_same_v<decltype(T() / T()), T>\n#else\n\t\t\
    \t\t\t   std::is_same<decltype(T() / T()), T>::value\n#endif\n\t\t\t\t\t   ,\n\
    \t\t\t\t\t   std::nullptr_t> = nullptr>\nclass Matrix {\n  protected:\n\tuint\
    \ N, M;\n\tstd::vector<std::vector<T>> elems;\n\n  public:\n\tMatrix() = default;\n\
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
    memo *= memo;\n\t\t}\n\t\treturn res;\n\t}\n\n\tconstexpr T determinant() const\
    \ {\n\t\tSquareMatrix<T> tmp = *this;\n\t\tT res(1);\n\t\trep(i, N) {\n\t\t\t\
    if (tmp[i][i] == 0) {\n\t\t\t\tfor (int j = i + 1; j < N; j++) {\n\t\t\t\t\tif\
    \ (tmp[j][i]) {\n\t\t\t\t\t\tstd::swap(tmp[i], tmp[j]);\n\t\t\t\t\t\tres = -res;\n\
    \t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tres *= tmp[i][i];\n\
    \t\t\tfor (int j = i + 1; j < N; j++) {\n\t\t\t\tT inv = T(1) / tmp[i][i];\n\t\
    \t\t\tfor (int k = i + 1; k < N; k++) {\n\t\t\t\t\ttmp[j][k] -= tmp[j][i] * inv\
    \ * tmp[i][k];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\ntemplate\
    \ <class T, uint N, uint M>\nclass FixedMatrix {\n  protected:\n\tstd::array<std::array<T,\
    \ M>, N> elems;\n\n  public:\n\tconstexpr FixedMatrix() { rep(i, N) elems[i].fill(0);\
    \ }\n\tconstexpr FixedMatrix(std::initializer_list<T> init) {\n\t\tauto ite =\
    \ init.begin();\n\t\trep(i, N) rep(j, M) elems[i][j] = *ite++;\n\t}\n\tconstexpr\
    \ FixedMatrix(const FixedMatrix<T, N, M>& rhs) {\n\t\telems = rhs.elems;\n\t}\n\
    \tconstexpr FixedMatrix(FixedMatrix<T, N, M>&& rhs) {\n\t\telems = std::move(rhs.elems);\n\
    \t}\n\tconstexpr std::array<T, N>& operator[](uint idx) { return elems[idx]; }\n\
    \tconstexpr const std::array<T, N>& operator[](uint idx) const {\n\t\treturn elems[idx];\n\
    \t}\n\tconstexpr decltype(elems)& data() { return elems; }\n\tconstexpr const\
    \ decltype(elems)& data() const { return elems; }\n\n\tconstexpr FixedMatrix<T,\
    \ N, M> operator=(const FixedMatrix<T, N, M>& rhs) {\n\t\telems = rhs.elems;\n\
    \t\treturn *this;\n\t}\n\tconstexpr FixedMatrix<T, N, M> operator=(FixedMatrix<T,\
    \ N, M>&& rhs) {\n\t\telems = std::move(rhs.elems);\n\t\treturn *this;\n\t}\n\n\
    \tconstexpr FixedMatrix<T, N, M> operator+=(const FixedMatrix<T, N, M>& rhs) {\n\
    \t\trep(i, N) rep(j, M) elems[i][j] += rhs.elems[i][j];\n\t\treturn *this;\n\t\
    }\n\n\tconstexpr FixedMatrix<T, N, M> operator+(\n\t\tconst FixedMatrix<T, N,\
    \ M>& rhs) const {\n\t\tFixedMatrix<T, N, M> res = *this;\n\t\treturn res += rhs;\n\
    \t}\n\n\ttemplate <uint L>\n\tconstexpr FixedMatrix<T, N, L> operator*(\n\t\t\
    const FixedMatrix<T, M, L>& rhs) const {\n\t\tFixedMatrix<T, N, L> res;\n\t\t\
    rep(i, N) rep(j, M) rep(k, L) res[i][k] +=\n\t\t\telems[i][j] * rhs.elems[j][k];\n\
    \t\treturn res;\n\t}\n};\n\ntemplate <class T, uint N>\nclass FixedSquareMatrix\
    \ : public FixedMatrix<T, N, N> {\n\tusing FixedMatrix<T, N, N>::FixedMatrix;\n\
    \tusing FixedMatrix<T, N, N>::elems;\n\n  public:\n\tusing FixedMatrix<T, N, N>::operator*;\n\
    \tconstexpr FixedSquareMatrix(const FixedMatrix<T, N, N>& obj)\n\t\t: FixedMatrix<T,\
    \ N, N>(obj) {}\n\tconstexpr FixedSquareMatrix(FixedMatrix<T, N, N>&& obj)\n\t\
    \t: FixedMatrix<T, N, N>(obj) {}\n\n\tconstexpr FixedSquareMatrix<T, N>& operator*=(\n\
    \t\tconst FixedSquareMatrix<T, N>& rhs) {\n\t\t*this = *this * rhs;\n\t\treturn\
    \ *this;\n\t}\n\n\tconstexpr FixedSquareMatrix<T, N> pow(lint p) const {\n\t\t\
    FixedSquareMatrix<T, N> res, memo = *this;\n\t\trep(i, N) res[i][i] = 1;\n\t\t\
    while (p) {\n\t\t\tif (p & 1) res *= memo;\n\t\t\tp >>= 1;\n\t\t\tmemo *= memo;\n\
    \t\t}\n\t\treturn res;\n\t}\n\n\tconstexpr T determinant() const {\n\t\tFixedSquareMatrix<T,\
    \ N> tmp = *this;\n\t\tT res(1);\n\t\trep(i, N) {\n\t\t\tif (tmp[i][i] == 0) {\n\
    \t\t\t\tfor (int j = i + 1; j < N; j++) {\n\t\t\t\t\tif (tmp[j][i]) {\n\t\t\t\t\
    \t\tstd::swap(tmp[i], tmp[j]);\n\t\t\t\t\t\tres = -res;\n\t\t\t\t\t\tbreak;\n\t\
    \t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tres *= tmp[i][i];\n\t\t\tfor (int j = i +\
    \ 1; j < N; j++) {\n\t\t\t\tT inv = T(1) / tmp[i][i];\n\t\t\t\tfor (int k = i\
    \ + 1; k < N; k++) {\n\t\t\t\t\ttmp[j][k] -= tmp[j][i] * inv * tmp[i][k];\n\t\t\
    \t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tconstexpr static FixedSquareMatrix<T,\
    \ N> ident() {\n\t\tFixedSquareMatrix<T, N> res;\n\t\trep(i, N) res[i][i] = 1;\n\
    \t\treturn res;\n\t}\n};\n\n/**\n * @title Matrix\n */\n"
  code: "#pragma once\n#include \"../basic/template.hpp\"\n\ntemplate <class T, std::enable_if_t<\n\
    #if __cplusplus >= 201703L\n\t\t\t\t\t   std::is_same_v<decltype(T() / T()), T>\n\
    #else\n\t\t\t\t\t   std::is_same<decltype(T() / T()), T>::value\n#endif\n\t\t\t\
    \t\t   ,\n\t\t\t\t\t   std::nullptr_t> = nullptr>\nclass Matrix {\n  protected:\n\
    \tuint N, M;\n\tstd::vector<std::vector<T>> elems;\n\n  public:\n\tMatrix() =\
    \ default;\n\tMatrix(uint N_, uint M_) : N(N_), M(M_), elems(N, std::vector<T>(M))\
    \ {}\n\tstd::vector<T>& operator[](uint idx) { return elems[idx]; }\n\tconst std::vector<T>&\
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
    memo *= memo;\n\t\t}\n\t\treturn res;\n\t}\n\n\tconstexpr T determinant() const\
    \ {\n\t\tSquareMatrix<T> tmp = *this;\n\t\tT res(1);\n\t\trep(i, N) {\n\t\t\t\
    if (tmp[i][i] == 0) {\n\t\t\t\tfor (int j = i + 1; j < N; j++) {\n\t\t\t\t\tif\
    \ (tmp[j][i]) {\n\t\t\t\t\t\tstd::swap(tmp[i], tmp[j]);\n\t\t\t\t\t\tres = -res;\n\
    \t\t\t\t\t\tbreak;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tres *= tmp[i][i];\n\
    \t\t\tfor (int j = i + 1; j < N; j++) {\n\t\t\t\tT inv = T(1) / tmp[i][i];\n\t\
    \t\t\tfor (int k = i + 1; k < N; k++) {\n\t\t\t\t\ttmp[j][k] -= tmp[j][i] * inv\
    \ * tmp[i][k];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\ntemplate\
    \ <class T, uint N, uint M>\nclass FixedMatrix {\n  protected:\n\tstd::array<std::array<T,\
    \ M>, N> elems;\n\n  public:\n\tconstexpr FixedMatrix() { rep(i, N) elems[i].fill(0);\
    \ }\n\tconstexpr FixedMatrix(std::initializer_list<T> init) {\n\t\tauto ite =\
    \ init.begin();\n\t\trep(i, N) rep(j, M) elems[i][j] = *ite++;\n\t}\n\tconstexpr\
    \ FixedMatrix(const FixedMatrix<T, N, M>& rhs) {\n\t\telems = rhs.elems;\n\t}\n\
    \tconstexpr FixedMatrix(FixedMatrix<T, N, M>&& rhs) {\n\t\telems = std::move(rhs.elems);\n\
    \t}\n\tconstexpr std::array<T, N>& operator[](uint idx) { return elems[idx]; }\n\
    \tconstexpr const std::array<T, N>& operator[](uint idx) const {\n\t\treturn elems[idx];\n\
    \t}\n\tconstexpr decltype(elems)& data() { return elems; }\n\tconstexpr const\
    \ decltype(elems)& data() const { return elems; }\n\n\tconstexpr FixedMatrix<T,\
    \ N, M> operator=(const FixedMatrix<T, N, M>& rhs) {\n\t\telems = rhs.elems;\n\
    \t\treturn *this;\n\t}\n\tconstexpr FixedMatrix<T, N, M> operator=(FixedMatrix<T,\
    \ N, M>&& rhs) {\n\t\telems = std::move(rhs.elems);\n\t\treturn *this;\n\t}\n\n\
    \tconstexpr FixedMatrix<T, N, M> operator+=(const FixedMatrix<T, N, M>& rhs) {\n\
    \t\trep(i, N) rep(j, M) elems[i][j] += rhs.elems[i][j];\n\t\treturn *this;\n\t\
    }\n\n\tconstexpr FixedMatrix<T, N, M> operator+(\n\t\tconst FixedMatrix<T, N,\
    \ M>& rhs) const {\n\t\tFixedMatrix<T, N, M> res = *this;\n\t\treturn res += rhs;\n\
    \t}\n\n\ttemplate <uint L>\n\tconstexpr FixedMatrix<T, N, L> operator*(\n\t\t\
    const FixedMatrix<T, M, L>& rhs) const {\n\t\tFixedMatrix<T, N, L> res;\n\t\t\
    rep(i, N) rep(j, M) rep(k, L) res[i][k] +=\n\t\t\telems[i][j] * rhs.elems[j][k];\n\
    \t\treturn res;\n\t}\n};\n\ntemplate <class T, uint N>\nclass FixedSquareMatrix\
    \ : public FixedMatrix<T, N, N> {\n\tusing FixedMatrix<T, N, N>::FixedMatrix;\n\
    \tusing FixedMatrix<T, N, N>::elems;\n\n  public:\n\tusing FixedMatrix<T, N, N>::operator*;\n\
    \tconstexpr FixedSquareMatrix(const FixedMatrix<T, N, N>& obj)\n\t\t: FixedMatrix<T,\
    \ N, N>(obj) {}\n\tconstexpr FixedSquareMatrix(FixedMatrix<T, N, N>&& obj)\n\t\
    \t: FixedMatrix<T, N, N>(obj) {}\n\n\tconstexpr FixedSquareMatrix<T, N>& operator*=(\n\
    \t\tconst FixedSquareMatrix<T, N>& rhs) {\n\t\t*this = *this * rhs;\n\t\treturn\
    \ *this;\n\t}\n\n\tconstexpr FixedSquareMatrix<T, N> pow(lint p) const {\n\t\t\
    FixedSquareMatrix<T, N> res, memo = *this;\n\t\trep(i, N) res[i][i] = 1;\n\t\t\
    while (p) {\n\t\t\tif (p & 1) res *= memo;\n\t\t\tp >>= 1;\n\t\t\tmemo *= memo;\n\
    \t\t}\n\t\treturn res;\n\t}\n\n\tconstexpr T determinant() const {\n\t\tFixedSquareMatrix<T,\
    \ N> tmp = *this;\n\t\tT res(1);\n\t\trep(i, N) {\n\t\t\tif (tmp[i][i] == 0) {\n\
    \t\t\t\tfor (int j = i + 1; j < N; j++) {\n\t\t\t\t\tif (tmp[j][i]) {\n\t\t\t\t\
    \t\tstd::swap(tmp[i], tmp[j]);\n\t\t\t\t\t\tres = -res;\n\t\t\t\t\t\tbreak;\n\t\
    \t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tres *= tmp[i][i];\n\t\t\tfor (int j = i +\
    \ 1; j < N; j++) {\n\t\t\t\tT inv = T(1) / tmp[i][i];\n\t\t\t\tfor (int k = i\
    \ + 1; k < N; k++) {\n\t\t\t\t\ttmp[j][k] -= tmp[j][i] * inv * tmp[i][k];\n\t\t\
    \t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tconstexpr static FixedSquareMatrix<T,\
    \ N> ident() {\n\t\tFixedSquareMatrix<T, N> res;\n\t\trep(i, N) res[i][i] = 1;\n\
    \t\treturn res;\n\t}\n};\n\n/**\n * @title Matrix\n */"
  dependsOn:
  - basic/template.hpp
  isVerificationFile: false
  path: math/Matrix.hpp
  requiredBy: []
  timestamp: '2023-06-25 16:21:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/Matrix.hpp
layout: document
redirect_from:
- /library/math/Matrix.hpp
- /library/math/Matrix.hpp.html
title: Matrix
---
