---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic/NumberTheoreticTransform.hpp
    title: NumberTheoreticTransform
  - icon: ':heavy_check_mark:'
    path: algebraic/StaticModInt.hpp
    title: StaticModInt
  - icon: ':heavy_check_mark:'
    path: other/FastIO.hpp
    title: Fast IO library
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"test/yosupo/convolution_mod_1000000007.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\n#line\
    \ 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#ifdef ONLINE_JUDGE\n\
    #pragma GCC target(\"avx512f\")\n#else\n#pragma GCC target(\"avx2\")\n#endif\n\
    #pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#include\
    \ <string.h>\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include\
    \ <cassert>\n#include <cfloat>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <ctime>\n#include <deque>\n#include <fstream>\n#include\
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
    \treturn dp[a.size()][b.size()];\n}\n#line 3 \"other/FastIO.hpp\"\nnamespace FastIO\
    \ {\n\tstatic constexpr size_t buf_size = 1 << 18;\n\tstatic constexpr size_t\
    \ integer_size = 19;\n\n\tstatic char inbuf[buf_size + 1] = {};\n\tstatic char\
    \ outbuf[buf_size + 1] = {};\n\n\tclass Scanner {\n\t\tsize_t pos = 0, end = buf_size;\n\
    \t\tvoid load() {\n\t\t\tend = fread(inbuf, 1, buf_size, stdin);\n\t\t\tinbuf[end]\
    \ = '\\0';\n\t\t}\n\t\tvoid ignore_space() {\n\t\t\twhile (inbuf[pos] <= ' ')\
    \ {\n\t\t\t\tif (__builtin_expect(++pos == end, 0)) reload();\n\t\t\t}\n\t\t}\n\
    \t\tchar next() { return inbuf[pos++]; }\n\t\tchar next_nonspace() {\n\t\t\tignore_space();\n\
    \t\t\treturn inbuf[pos++];\n\t\t}\n\n\t  public:\n\t\tScanner() { load(); }\n\t\
    \tvoid reload() {\n\t\t\tsize_t length = end - pos;\n\t\t\tmemmove(inbuf, inbuf\
    \ + pos, length);\n\t\t\tend = length + fread(inbuf + length, 1, buf_size - length,\
    \ stdin);\n\t\t\tinbuf[end] = '\\0';\n\t\t\tpos = 0;\n\t\t}\n\t\tvoid scan(char&\
    \ c) { c = next_nonspace(); }\n\t\tvoid scan(std::string& s) {\n\t\t\tignore_space();\n\
    \t\t\ts = \"\";\n\t\t\tdo {\n\t\t\t\tsize_t start = pos;\n\t\t\t\twhile (inbuf[pos]\
    \ > ' ') pos++;\n\t\t\t\ts += std::string(inbuf + start, inbuf + pos);\n\t\t\t\
    \tif (inbuf[pos] != '\\0') break;\n\t\t\t\treload();\n\t\t\t} while (true);\n\t\
    \t}\n\t\ttemplate <typename T, std::enable_if_t<std::is_integral_v<T>,\n\t\t\t\
    \t\t\t\t\t\t\t\t   std::nullptr_t> = nullptr>\n\t\tvoid scan(T& x) {\n\t\t\tchar\
    \ c = next_nonspace();\n\t\t\tif (__builtin_expect(pos + integer_size >= end,\
    \ 0)) reload();\n\t\t\tbool minus = false;\n\t\t\tif (c == '-')\n\t\t\t\tminus\
    \ = true, x = 0;\n\t\t\telse\n\t\t\t\tx = c & 15;\n\t\t\twhile ((c = next()) >=\
    \ '0') x = x * 10 + (c & 15);\n\t\t\tif (minus) x = -x;\n\t\t}\n\t\ttemplate <typename\
    \ T, class... Args>\n\t\tvoid scan(T& x, Args&... args) {\n\t\t\tscan(x);\n\t\t\
    \tscan(args...);\n\t\t}\n\t\ttemplate <typename T>\n\t\tScanner& operator>>(T&\
    \ x) {\n\t\t\tscan(x);\n\t\t\treturn *this;\n\t\t}\n\t};\n\n\tclass Printer {\n\
    \t\tstatic constexpr size_t block_size = 10000;\n\t\tstatic const std::unique_ptr<char[]>\
    \ block_str;\n\t\tsize_t pos = 0;\n\n\t\tstatic constexpr lint powers[] = {1,\n\
    \t\t\t\t\t\t\t\t\t\t  10,\n\t\t\t\t\t\t\t\t\t\t  100,\n\t\t\t\t\t\t\t\t\t\t  1000,\n\
    \t\t\t\t\t\t\t\t\t\t  10000,\n\t\t\t\t\t\t\t\t\t\t  100000,\n\t\t\t\t\t\t\t\t\t\
    \t  1000000,\n\t\t\t\t\t\t\t\t\t\t  10000000,\n\t\t\t\t\t\t\t\t\t\t  100000000,\n\
    \t\t\t\t\t\t\t\t\t\t  1000000000,\n\t\t\t\t\t\t\t\t\t\t  10000000000,\n\t\t\t\t\
    \t\t\t\t\t\t  100000000000,\n\t\t\t\t\t\t\t\t\t\t  1000000000000,\n\t\t\t\t\t\t\
    \t\t\t\t  10000000000000,\n\t\t\t\t\t\t\t\t\t\t  100000000000000,\n\t\t\t\t\t\t\
    \t\t\t\t  1000000000000000,\n\t\t\t\t\t\t\t\t\t\t  10000000000000000,\n\t\t\t\t\
    \t\t\t\t\t\t  100000000000000000,\n\t\t\t\t\t\t\t\t\t\t  1000000000000000000};\n\
    \n\t\tstatic std::unique_ptr<char[]> precompute() {\n\t\t\tstd::unique_ptr<char[]>\
    \ res(new char[block_size * 4]);\n\t\t\trep(i, block_size) {\n\t\t\t\tsize_t j\
    \ = 4, k = i;\n\t\t\t\twhile (j--) {\n\t\t\t\t\tres[i * 4 + j] = k % 10 + '0';\n\
    \t\t\t\t\tk /= 10;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\t\ttemplate\
    \ <typename T>\n\t\tsize_t integer_digits(T n) {\n\t\t\tif (n >= powers[9]) {\n\
    \t\t\t\tif (n >= powers[13]) {\n\t\t\t\t\tif (n >= powers[16]) {\n\t\t\t\t\t\t\
    if (n >= powers[17]) {\n\t\t\t\t\t\t\tif (n >= powers[18]) return 19;\n\t\t\t\t\
    \t\t\treturn 18;\n\t\t\t\t\t\t}\n\t\t\t\t\t\treturn 17;\n\t\t\t\t\t}\n\t\t\t\t\
    \tif (n >= powers[14]) {\n\t\t\t\t\t\tif (n >= powers[15]) return 16;\n\t\t\t\t\
    \t\treturn 15;\n\t\t\t\t\t}\n\t\t\t\t\treturn 14;\n\t\t\t\t}\n\t\t\t\tif (n >=\
    \ powers[11]) {\n\t\t\t\t\tif (n >= powers[12]) return 13;\n\t\t\t\t\treturn 12;\n\
    \t\t\t\t}\n\t\t\t\tif (n >= powers[10]) return 11;\n\t\t\t\treturn 10;\n\t\t\t\
    }\n\t\t\tif (n >= powers[4]) {\n\t\t\t\tif (n >= powers[7]) {\n\t\t\t\t\tif (n\
    \ >= powers[8]) return 9;\n\t\t\t\t\treturn 8;\n\t\t\t\t}\n\t\t\t\tif (n >= powers[5])\
    \ {\n\t\t\t\t\tif (n >= powers[6]) return 7;\n\t\t\t\t\treturn 6;\n\t\t\t\t}\n\
    \t\t\t\treturn 5;\n\t\t\t}\n\t\t\tif (n >= powers[2]) {\n\t\t\t\tif (n >= powers[3])\
    \ return 4;\n\t\t\t\treturn 3;\n\t\t\t}\n\t\t\tif (n >= powers[1]) return 2;\n\
    \t\t\treturn 1;\n\t\t}\n\n\t  public:\n\t\tPrinter() = default;\n\t\t~Printer()\
    \ { flush(); }\n\t\tvoid flush() {\n\t\t\tfwrite(outbuf, 1, pos, stdout);\n\t\t\
    \tpos = 0;\n\t\t}\n\t\tvoid print(){}\n\t\tvoid print(char c) {\n\t\t\toutbuf[pos++]\
    \ = c;\n\t\t\tif (__builtin_expect(pos == buf_size, 0)) flush();\n\t\t}\n\t\t\
    void print(char* s) {\n\t\t\twhile (*s != 0) {\n\t\t\t\toutbuf[pos++] = *s++;\n\
    \t\t\t\tif (pos == buf_size) flush();\n\t\t\t}\n\t\t}\n\t\ttemplate <typename\
    \ T, std::enable_if_t<std::is_integral_v<T>,\n\t\t\t\t\t\t\t\t\t\t\t   std::nullptr_t>\
    \ = nullptr>\n\t\tvoid print(T x) {\n\t\t\tif (__builtin_expect(pos + integer_size\
    \ >= buf_size, 0)) flush();\n\t\t\tif (x < 0) print('-'), x = -x;\n\t\t\tsize_t\
    \ digit = integer_digits(x);\n\t\t\tsize_t len = digit;\n\t\t\twhile (len >= 4)\
    \ {\n\t\t\t\tlen -= 4;\n\t\t\t\tmemcpy(outbuf + pos + len,\n\t\t\t\t\t   block_str.get()\
    \ + (x % block_size) * 4, 4);\n\t\t\t\tx /= 10000;\n\t\t\t}\n\t\t\tmemcpy(outbuf\
    \ + pos, block_str.get() + x * 4 + 4 - len, len);\n\t\t\tpos += digit;\n\t\t}\n\
    \t\ttemplate <typename T, class... Args>\n\t\tvoid print(const T& x, const Args&...\
    \ args) {\n\t\t\tprint(x);\n\t\t\tprint(' ');\n\t\t\tprint(args...);\n\t\t}\n\t\
    \ttemplate <class... Args>\n\t\tvoid println(const Args&... args) {\n\t\t\tprint(args...);\n\
    \t\t\tprint('\\n');\n\t\t}\n\t\ttemplate <typename T>\n\t\tPrinter& operator<<(const\
    \ T& x) {\n\t\t\tprint(x);\n\t\t\treturn *this;\n\t\t}\n\t};\n\tconst std::unique_ptr<char[]>\
    \ Printer::block_str = Printer::precompute();\n};\t// namespace FastIO\n\n/**\n\
    \ * @title Fast IO library\n */\n#line 4 \"other/type_traits.hpp\"\n\nclass ModInt__Base\
    \ {};\nclass StaticModInt__Base : ModInt__Base {};\nclass DynamicModInt__Base\
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
    /**\n * @title NumberTheoreticTransform\n */\n#line 5 \"test/yosupo/convolution_mod_1000000007.test.cpp\"\
    \nFastIO::Scanner cin;\nFastIO::Printer cout;\nint N, M;\nstd::vector<int> a,\
    \ b;\nint main() {\n\tcin >> N >> M;\n\ta.resize(N);\n\tb.resize(M);\n\trep(i,\
    \ N) cin >> a[i];\n\trep(i, M) cin >> b[i];\n\tauto res = NumberTheoreticTransform::multiply<1000000007>(a,\
    \ b);\n\trep(i, N + M - 2) cout << (int)res[i] << ' ';\n\tcout << (int)res[N +\
    \ M - 2] << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n#include \"../../other/template.hpp\"\n#include \"../../other/FastIO.hpp\"\n\
    #include \"../../algebraic/NumberTheoreticTransform.hpp\"\nFastIO::Scanner cin;\n\
    FastIO::Printer cout;\nint N, M;\nstd::vector<int> a, b;\nint main() {\n\tcin\
    \ >> N >> M;\n\ta.resize(N);\n\tb.resize(M);\n\trep(i, N) cin >> a[i];\n\trep(i,\
    \ M) cin >> b[i];\n\tauto res = NumberTheoreticTransform::multiply<1000000007>(a,\
    \ b);\n\trep(i, N + M - 2) cout << (int)res[i] << ' ';\n\tcout << (int)res[N +\
    \ M - 2] << '\\n';\n}"
  dependsOn:
  - other/template.hpp
  - other/FastIO.hpp
  - algebraic/NumberTheoreticTransform.hpp
  - algebraic/StaticModInt.hpp
  - other/type_traits.hpp
  isVerificationFile: true
  path: test/yosupo/convolution_mod_1000000007.test.cpp
  requiredBy: []
  timestamp: '2021-01-31 21:24:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/convolution_mod_1000000007.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp.html
title: test/yosupo/convolution_mod_1000000007.test.cpp
---
