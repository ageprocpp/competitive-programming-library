---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/Matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: math/StaticModInt.hpp
    title: StaticModInt
  - icon: ':heavy_check_mark:'
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/yosupo/matrix_det.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\
    \n#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n\
    #ifdef ONLINE_JUDGE\n#ifdef _WIN64\n#pragma GCC target(\"avx2\")\n#else\n#pragma\
    \ GCC target(\"avx512f\")\n#endif\n#elif defined EVAL\n#else\n#pragma GCC target(\"\
    avx2\")\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n#endif\n#include <string.h>\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cfloat>\n#include <climits>\n#include\
    \ <cmath>\n#include <complex>\n#include <ctime>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#define rep(i,\
    \ n) for (int i = 0; i < (n); i++)\n#define REP(i, n) for (int i = 1; i <= (n);\
    \ i++)\n#define all(V) V.begin(), V.end()\n\nusing i128 = __int128_t;\nusing u128\
    \ = __uint128_t;\nusing uint = unsigned int;\nusing lint = long long;\nusing ulint\
    \ = unsigned long long;\nusing IP = std::pair<int, int>;\nusing LP = std::pair<lint,\
    \ lint>;\n\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF = LLONG_MAX\
    \ / 2;\nconstexpr double eps = DBL_EPSILON * 10;\nconstexpr double PI = 3.141592653589793238462643383279;\n\
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
    \treturn ost << x.first << \" \" << x.second;\n}\ntemplate <class Container,\n\
    #if __cplusplus >= 201703L\n\t\t  std::enable_if_t<!std::is_same_v<Container,\
    \ std::string>,\n#else\n\t\t  std::enable_if_t<!std::is_same<Container, std::string>::value,\n\
    #endif\n\t\t\t\t\t\t   std::nullptr_t> = nullptr>\nauto operator>>(std::istream&\
    \ ist, Container& cont)\n\t-> decltype(typename Container::iterator(), std::cin)&\
    \ {\n\tstd::vector<typename Container::value_type> tmp;\n\twhile (true) {\n\t\t\
    typename Container::value_type t;\n\t\tist >> t;\n\t\ttmp.emplace_back(t);\n\t\
    \tif (getchar() == '\\n') break;\n\t}\n\tcont = Container(std::move(tmp));\n\t\
    return ist;\n}\ntemplate <class Container,\n#if __cplusplus >= 201703L\n\t\t \
    \ std::enable_if_t<!std::is_same_v<Container, std::string>,\n#else\n\t\t  std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value,\n#endif\n\t\t\t\t\t\t   std::nullptr_t> = nullptr>\nauto\
    \ operator<<(std::ostream& ost, const Container& cont)\n\t-> decltype(typename\
    \ Container::iterator(), std::cout)& {\n\tfor (auto it = cont.begin(); it != cont.end();\
    \ it++) {\n\t\tif (it != cont.begin()) ost << ' ';\n\t\tost << *it;\n\t}\n\treturn\
    \ ost;\n}\ntemplate <class Container>\nauto sum(const Container& cont)\n\t-> decltype(typename\
    \ Container::iterator(), 0LL) {\n\tlint res = 0;\n\tfor (auto it = cont.begin();\
    \ it != cont.end(); it++) res += *it;\n\treturn res;\n}\ntemplate <class T, class\
    \ U>\nconstexpr inline bool chmax(T& lhs, const U& rhs) noexcept {\n\tif (lhs\
    \ < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ntemplate\
    \ <class T, class U>\nconstexpr inline bool chmin(T& lhs, const U& rhs) noexcept\
    \ {\n\tif (lhs > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n\
    }\nconstexpr inline lint gcd(lint a, lint b) noexcept {\n\twhile (b) {\n\t\tlint\
    \ c = a;\n\t\ta = b;\n\t\tb = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint\
    \ a, lint b) noexcept { return a / gcd(a, b) * b; }\nconstexpr bool isprime(lint\
    \ n) noexcept {\n\tif (n == 1) return false;\n\tfor (int i = 2; i * i <= n; i++)\
    \ {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn true;\n}\ntemplate <class\
    \ T>\nconstexpr T mypow(T a, lint b) noexcept {\n\tT res(1);\n\twhile (true) {\n\
    \t\tif (b & 1) res *= a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\t\ta *= a;\n\t}\n\
    \treturn res;\n}\nconstexpr lint modpow(lint a, lint b, lint m) noexcept {\n\t\
    a %= m;\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) res *= a, res %= m;\n\t\
    \ta *= a, a %= m, b >>= 1;\n\t}\n\treturn res;\n}\nLP extGcd(lint a, lint b) noexcept\
    \ {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b, a % b);\n\tstd::swap(s.first,\
    \ s.second);\n\ts.second -= a / b * s.first;\n\treturn s;\n}\nLP ChineseRem(const\
    \ lint& b1, const lint& m1, const lint& b2,\n\t\t\t  const lint& m2) noexcept\
    \ {\n\tauto p = extGcd(m1, m2);\n\tlint g = gcd(m1, m2), l = m1 / g * m2;\n\t\
    lint tmp = (b2 - b1) / g * p.first % (m2 / g);\n\tlint r = (b1 + m1 * tmp + l)\
    \ % l;\n\treturn {r, l};\n}\nint LCS(const std::string& a, const std::string&\
    \ b) {\n\tauto dp = make_vec<int>(a.size() + 1, b.size() + 1);\n\trep(i, a.size())\
    \ {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j\
    \ + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i + 1][j + 1], dp[i][j] +\
    \ 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\t}\n\trep(j,\
    \ b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn dp[a.size()][b.size()];\n\
    }\ntemplate <class T, std::enable_if_t<std::is_convertible<int, T>::value,\n\t\
    \t\t\t\t\t\t\t\tstd::nullptr_t> = nullptr>\nvoid compress(std::vector<T>& vec)\
    \ {\n\tauto tmp = vec;\n\tstd::sort(all(tmp));\n\ttmp.erase(std::unique(all(tmp)),\
    \ tmp.end());\n\tfor (T& i : vec) i = std::lower_bound(all(tmp), i) - tmp.begin();\n\
    }\ntemplate <class T>\nvoid compress(T* l, T* r) {\n\tstd::vector<T> tmp(l, r);\n\
    \tstd::sort(all(tmp));\n\ttmp.erase(std::unique(all(tmp)), tmp.end());\n\tfor\
    \ (auto i = l; i < r; i++) {\n\t\t*i = std::lower_bound(all(tmp), *i) - tmp.begin();\n\
    \t}\n}\ntemplate <class InputIter>\nvoid compress(InputIter l, InputIter r) {\n\
    \tstd::vector<typename InputIter::value_type> tmp(l, r);\n\tstd::sort(all(tmp));\n\
    \ttmp.erase(std::unique(all(tmp)), tmp.end());\n\tfor (auto i = l; i < r; i++)\
    \ {\n\t\t*i = std::lower_bound(all(tmp), *i) - tmp.begin();\n\t}\n}\n#line 3 \"\
    other/type_traits.hpp\"\n\nclass ModInt__Base {};\nclass StaticModInt__Base :\
    \ ModInt__Base {};\nclass DynamicModInt__Base : ModInt__Base {};\n\ntemplate <class\
    \ T>\nclass is_ModInt : public std::is_base_of<ModInt__Base, T> {};\ntemplate\
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
    \n/**\n * @title StaticModInt\n */\n#line 3 \"math/Matrix.hpp\"\n\ntemplate <class\
    \ T, std::enable_if_t<\n#if __cplusplus >= 201703L\n\t\t\t\t\t   std::is_same_v<decltype(T()\
    \ / T()), T>\n#else\n\t\t\t\t\t   std::is_same<decltype(T() / T()), T>::value\n\
    #endif\n\t\t\t\t\t   ,\n\t\t\t\t\t   std::nullptr_t> = nullptr>\nclass Matrix\
    \ {\n  protected:\n\tuint N, M;\n\tstd::vector<std::vector<T>> elems;\n\n  public:\n\
    \tMatrix() = default;\n\tMatrix(uint N_, uint M_) : N(N_), M(M_), elems(N, std::vector<T>(M))\
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
    \t\treturn res;\n\t}\n};\n\n/**\n * @title Matrix\n */\n#line 5 \"test/yosupo/matrix_det.test.cpp\"\
    \nusing ModInt = StaticModInt<998244353>;\nint N;\nint main() {\n\tscanf(\"%d\"\
    , &N);\n\tSquareMatrix<ModInt> m(N);\n\trep(i, N) rep(j, N) std::cin >> m[i][j];\n\
    \tstd::cout << m.determinant() << std::endl;\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../math/StaticModInt.hpp\"\n#include\
    \ \"../../math/Matrix.hpp\"\nusing ModInt = StaticModInt<998244353>;\nint N;\n\
    int main() {\n\tscanf(\"%d\", &N);\n\tSquareMatrix<ModInt> m(N);\n\trep(i, N)\
    \ rep(j, N) std::cin >> m[i][j];\n\tstd::cout << m.determinant() << std::endl;\n\
    \treturn 0;\n}"
  dependsOn:
  - other/template.hpp
  - math/StaticModInt.hpp
  - other/type_traits.hpp
  - math/Matrix.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_det.test.cpp
  requiredBy: []
  timestamp: '2021-09-11 00:07:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/matrix_det.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_det.test.cpp
- /verify/test/yosupo/matrix_det.test.cpp.html
title: test/yosupo/matrix_det.test.cpp
---
