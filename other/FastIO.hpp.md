---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/many_aplusb.test.cpp
    title: test/yosupo/many_aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_kth_smallest.test.cpp
    title: test/yosupo/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/shortest_path.test.cpp
    title: test/yosupo/shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Fast IO library
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
    #ifndef __clang__\n#ifdef ONLINE_JUDGE\n#ifdef _WIN64\n#pragma GCC target(\"avx2\"\
    )\n#else\n#pragma GCC target(\"avx512f\")\n#endif\n#elif defined EVAL\n#else\n\
    #pragma GCC target(\"avx2\")\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC\
    \ optimize(\"unroll-loops\")\n#endif\n#include <string.h>\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cfloat>\n#include\
    \ <chrono>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
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
    \ double eps = DBL_EPSILON * 10;\nconstexpr double PI = 3.141592653589793238462643383279;\n\
    \ntemplate <class T>\nclass prique : public std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> {};\nint popcount(uint x) {\n#if __cplusplus >= 202002L\n\t\
    return std::popcount(x);\n#else\n#ifndef __clang__\n\treturn __builtin_popcount(x);\n\
    #endif\n#endif\n\tx = (x & 0x55555555) + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333)\
    \ + (x >> 2 & 0x33333333);\n\tx = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\t\
    x = (x & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x\
    \ >> 16 & 0x0000ffff);\n}\ntemplate <class F>\ninline constexpr decltype(auto)\
    \ lambda_fix(F&& f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\
    \treturn f(f, std::forward<decltype(args)>(args)...);\n\t};\n}\ntemplate <class\
    \ T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n\
    }\ntemplate <class T, class... Args>\nconstexpr auto make_vec(size_t n, Args&&...\
    \ args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(n, make_vec<T>(std::forward<Args>(args)...));\n\
    }\ntemplate <class T, class U>\nstd::istream& operator>>(std::istream& ist, std::pair<T,\
    \ U>& x) {\n\treturn ist >> x.first >> x.second;\n}\ntemplate <class T, class\
    \ U>\nstd::ostream& operator<<(std::ostream& ost, const std::pair<T, U>& x) {\n\
    \treturn ost << x.first << \" \" << x.second;\n}\ntemplate <class Container,\n\
    \t\t  std::enable_if_t<!std::is_same<Container, std::string>::value, std::nullptr_t>\
    \ = nullptr>\nauto operator>>(std::istream& ist, Container& cont)\n\t-> decltype(typename\
    \ Container::iterator(), std::cin)& {\n\tContainer tmp;\n\twhile (true) {\n\t\t\
    typename Container::value_type t;\n\t\tist >> t;\n\t\ttmp.emplace_back(t);\n\t\
    \tif (getchar() == '\\n') break;\n\t}\n\tcont = Container(std::move(tmp));\n\t\
    return ist;\n}\ntemplate <class Container,\n\t\t  std::enable_if_t<!std::is_same<Container,\
    \ std::string>::value, std::nullptr_t> = nullptr>\nauto operator<<(std::ostream&\
    \ ost, const Container& cont)\n\t-> decltype(typename Container::iterator(), std::cout)&\
    \ {\n\tfor (auto it = cont.begin(); it != cont.end(); it++) {\n\t\tif (it != cont.begin())\
    \ ost << ' ';\n\t\tost << *it;\n\t}\n\treturn ost;\n}\ntemplate <class Container>\n\
    auto sum(const Container& cont) -> decltype(typename Container::iterator(), 0LL)\
    \ {\n\tlint res = 0;\n\tfor (auto it = cont.begin(); it != cont.end(); it++) res\
    \ += *it;\n\treturn res;\n}\ntemplate <class T, class U>\nconstexpr inline bool\
    \ chmax(T& lhs, const U& rhs) noexcept {\n\tif (lhs < rhs) {\n\t\tlhs = rhs;\n\
    \t\treturn true;\n\t}\n\treturn false;\n}\ntemplate <class T, class U>\nconstexpr\
    \ inline bool chmin(T& lhs, const U& rhs) noexcept {\n\tif (lhs > rhs) {\n\t\t\
    lhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\nconstexpr inline lint gcd(lint\
    \ a, lint b) noexcept {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\tb = c\
    \ % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint b) noexcept { return\
    \ a / gcd(a, b) * b; }\nconstexpr bool isprime(lint n) noexcept {\n\tif (n ==\
    \ 1) return false;\n\tfor (int i = 2; i * i <= n; i++) {\n\t\tif (n % i == 0)\
    \ return false;\n\t}\n\treturn true;\n}\ntemplate <class T>\nconstexpr T mypow(T\
    \ a, lint b) noexcept {\n\tT res(1);\n\twhile (true) {\n\t\tif (b & 1) res *=\
    \ a;\n\t\tb >>= 1;\n\t\tif (!b) break;\n\t\ta *= a;\n\t}\n\treturn res;\n}\nconstexpr\
    \ lint modpow(lint a, lint b, lint m) noexcept {\n\ta %= m;\n\tlint res(1);\n\t\
    while (b) {\n\t\tif (b & 1) res *= a, res %= m;\n\t\ta *= a, a %= m, b >>= 1;\n\
    \t}\n\treturn res;\n}\nLP extGcd(lint a, lint b) noexcept {\n\tif (b == 0) return\
    \ {1, 0};\n\tLP s = extGcd(b, a % b);\n\tstd::swap(s.first, s.second);\n\ts.second\
    \ -= a / b * s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1, const lint&\
    \ m1, const lint& b2, const lint& m2) noexcept {\n\tauto p = extGcd(m1, m2);\n\
    \tlint g = gcd(m1, m2), l = m1 / g * m2;\n\tlint tmp = (b2 - b1) / g * p.first\
    \ % (m2 / g);\n\tlint r = (b1 + m1 * tmp + l) % l;\n\treturn {r, l};\n}\nint LCS(const\
    \ std::string& a, const std::string& b) {\n\tauto dp = make_vec<int>(a.size()\
    \ + 1, b.size() + 1);\n\trep(i, a.size()) {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i\
    \ + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j + 1], dp[i][j]);\n\t\t\tif (a[i] ==\
    \ b[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()],\
    \ dp[i][b.size()]);\n\t}\n\trep(j, b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\
    \treturn dp[a.size()][b.size()];\n}\ntemplate <class T, std::enable_if_t<std::is_convertible<int,\
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
    }\n#line 3 \"other/FastIO.hpp\"\nnamespace FastIO {\n\tstatic constexpr size_t\
    \ buf_size = 1 << 18;\n\tstatic constexpr size_t integer_size = 19;\n\n\tstatic\
    \ char inbuf[buf_size + 1] = {};\n\tstatic char outbuf[buf_size + 1] = {};\n\n\
    \tclass Scanner {\n\t\tsize_t pos = 0, end = buf_size;\n\t\tvoid load() {\n\t\t\
    \tend = fread(inbuf, 1, buf_size, stdin);\n\t\t\tinbuf[end] = '\\0';\n\t\t}\n\t\
    \tvoid ignore_space() {\n\t\t\twhile (inbuf[pos] <= ' ') {\n\t\t\t\tif (__builtin_expect(++pos\
    \ == end, 0)) reload();\n\t\t\t}\n\t\t}\n\t\tchar next() { return inbuf[pos++];\
    \ }\n\t\tchar next_nonspace() {\n\t\t\tignore_space();\n\t\t\treturn inbuf[pos++];\n\
    \t\t}\n\n\t  public:\n\t\tScanner() { load(); }\n\t\tvoid reload() {\n\t\t\tsize_t\
    \ length = end - pos;\n\t\t\tmemmove(inbuf, inbuf + pos, length);\n\t\t\tend =\
    \ length + fread(inbuf + length, 1, buf_size - length, stdin);\n\t\t\tinbuf[end]\
    \ = '\\0';\n\t\t\tpos = 0;\n\t\t}\n\t\tvoid scan() {}\n\t\tvoid scan(char& c)\
    \ { c = next_nonspace(); }\n\t\tvoid scan(std::string& s) {\n\t\t\tignore_space();\n\
    \t\t\ts = \"\";\n\t\t\tdo {\n\t\t\t\tsize_t start = pos;\n\t\t\t\twhile (inbuf[pos]\
    \ > ' ') pos++;\n\t\t\t\ts += std::string(inbuf + start, inbuf + pos);\n\t\t\t\
    \tif (inbuf[pos] != '\\0') break;\n\t\t\t\treload();\n\t\t\t} while (true);\n\t\
    \t}\n\t\ttemplate <typename T, std::enable_if_t<std::is_integral<T>::value,\n\t\
    \t\t\t\t\t\t\t\t\t\t   std::nullptr_t> = nullptr>\n\t\tvoid scan(T& x) {\n\t\t\
    \tchar c = next_nonspace();\n\t\t\tif (__builtin_expect(pos + integer_size >=\
    \ end, 0)) reload();\n\t\t\tbool minus = false;\n\t\t\tif (c == '-')\n\t\t\t\t\
    minus = true, x = 0;\n\t\t\telse\n\t\t\t\tx = c & 15;\n\t\t\twhile ((c = next())\
    \ >= '0') x = x * 10 + (c & 15);\n\t\t\tif (minus) x = -x;\n\t\t}\n\t\ttemplate\
    \ <typename T, class... Args>\n\t\tvoid scan(T& x, Args&... args) {\n\t\t\tscan(x);\n\
    \t\t\tscan(args...);\n\t\t}\n\t\ttemplate <typename T>\n\t\tScanner& operator>>(T&\
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
    \tpos = 0;\n\t\t}\n\t\tvoid print() {}\n\t\tvoid print(char c) {\n\t\t\toutbuf[pos++]\
    \ = c;\n\t\t\tif (__builtin_expect(pos == buf_size, 0)) flush();\n\t\t}\n\t\t\
    void print(char* s) {\n\t\t\twhile (*s != 0) {\n\t\t\t\toutbuf[pos++] = *s++;\n\
    \t\t\t\tif (pos == buf_size) flush();\n\t\t\t}\n\t\t}\n\t\ttemplate <typename\
    \ T, std::enable_if_t<std::is_integral<T>::value,\n\t\t\t\t\t\t\t\t\t\t\t   std::nullptr_t>\
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
    \ * @title Fast IO library\n */\n"
  code: "#pragma once\n#include \"template.hpp\"\nnamespace FastIO {\n\tstatic constexpr\
    \ size_t buf_size = 1 << 18;\n\tstatic constexpr size_t integer_size = 19;\n\n\
    \tstatic char inbuf[buf_size + 1] = {};\n\tstatic char outbuf[buf_size + 1] =\
    \ {};\n\n\tclass Scanner {\n\t\tsize_t pos = 0, end = buf_size;\n\t\tvoid load()\
    \ {\n\t\t\tend = fread(inbuf, 1, buf_size, stdin);\n\t\t\tinbuf[end] = '\\0';\n\
    \t\t}\n\t\tvoid ignore_space() {\n\t\t\twhile (inbuf[pos] <= ' ') {\n\t\t\t\t\
    if (__builtin_expect(++pos == end, 0)) reload();\n\t\t\t}\n\t\t}\n\t\tchar next()\
    \ { return inbuf[pos++]; }\n\t\tchar next_nonspace() {\n\t\t\tignore_space();\n\
    \t\t\treturn inbuf[pos++];\n\t\t}\n\n\t  public:\n\t\tScanner() { load(); }\n\t\
    \tvoid reload() {\n\t\t\tsize_t length = end - pos;\n\t\t\tmemmove(inbuf, inbuf\
    \ + pos, length);\n\t\t\tend = length + fread(inbuf + length, 1, buf_size - length,\
    \ stdin);\n\t\t\tinbuf[end] = '\\0';\n\t\t\tpos = 0;\n\t\t}\n\t\tvoid scan() {}\n\
    \t\tvoid scan(char& c) { c = next_nonspace(); }\n\t\tvoid scan(std::string& s)\
    \ {\n\t\t\tignore_space();\n\t\t\ts = \"\";\n\t\t\tdo {\n\t\t\t\tsize_t start\
    \ = pos;\n\t\t\t\twhile (inbuf[pos] > ' ') pos++;\n\t\t\t\ts += std::string(inbuf\
    \ + start, inbuf + pos);\n\t\t\t\tif (inbuf[pos] != '\\0') break;\n\t\t\t\treload();\n\
    \t\t\t} while (true);\n\t\t}\n\t\ttemplate <typename T, std::enable_if_t<std::is_integral<T>::value,\n\
    \t\t\t\t\t\t\t\t\t\t\t   std::nullptr_t> = nullptr>\n\t\tvoid scan(T& x) {\n\t\
    \t\tchar c = next_nonspace();\n\t\t\tif (__builtin_expect(pos + integer_size >=\
    \ end, 0)) reload();\n\t\t\tbool minus = false;\n\t\t\tif (c == '-')\n\t\t\t\t\
    minus = true, x = 0;\n\t\t\telse\n\t\t\t\tx = c & 15;\n\t\t\twhile ((c = next())\
    \ >= '0') x = x * 10 + (c & 15);\n\t\t\tif (minus) x = -x;\n\t\t}\n\t\ttemplate\
    \ <typename T, class... Args>\n\t\tvoid scan(T& x, Args&... args) {\n\t\t\tscan(x);\n\
    \t\t\tscan(args...);\n\t\t}\n\t\ttemplate <typename T>\n\t\tScanner& operator>>(T&\
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
    \tpos = 0;\n\t\t}\n\t\tvoid print() {}\n\t\tvoid print(char c) {\n\t\t\toutbuf[pos++]\
    \ = c;\n\t\t\tif (__builtin_expect(pos == buf_size, 0)) flush();\n\t\t}\n\t\t\
    void print(char* s) {\n\t\t\twhile (*s != 0) {\n\t\t\t\toutbuf[pos++] = *s++;\n\
    \t\t\t\tif (pos == buf_size) flush();\n\t\t\t}\n\t\t}\n\t\ttemplate <typename\
    \ T, std::enable_if_t<std::is_integral<T>::value,\n\t\t\t\t\t\t\t\t\t\t\t   std::nullptr_t>\
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
    \ * @title Fast IO library\n */"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: other/FastIO.hpp
  requiredBy: []
  timestamp: '2023-01-08 03:21:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/shortest_path.test.cpp
  - test/yosupo/range_kth_smallest.test.cpp
  - test/yosupo/many_aplusb.test.cpp
documentation_of: other/FastIO.hpp
layout: document
redirect_from:
- /library/other/FastIO.hpp
- /library/other/FastIO.hpp.html
title: Fast IO library
---
