---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/CountPrime.hpp
    title: math/CountPrime.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#line 1 \"test/yosupo/counting_primes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/counting_primes\"\n#line 2 \"other/template.hpp\"\
    \n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n#pragma GCC optimize(\"\
    O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#endif\n#include <string.h>\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cfloat>\n#include <chrono>\n#include <climits>\n#include <cmath>\n#include\
    \ <complex>\n#include <ctime>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#define rep(i,\
    \ n) for (int i = 0; i < int(n); i++)\n#define REP(i, n) for (int i = 1; i <=\
    \ int(n); i++)\n#define all(V) V.begin(), V.end()\n\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\nusing uint = unsigned int;\nusing lint = long long;\n\
    using ulint = unsigned long long;\nusing IP = std::pair<int, int>;\nusing LP =\
    \ std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF\
    \ = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON * 10;\nconstexpr double\
    \ PI = 3.141592653589793238462643383279;\n\ntemplate <class T>\nclass prique :\
    \ public std::priority_queue<T, std::vector<T>, std::greater<T>> {};\nint popcount(uint\
    \ x) {\n#if __cplusplus >= 202002L\n\treturn std::popcount(x);\n#else\n#ifndef\
    \ __clang__\n\treturn __builtin_popcount(x);\n#endif\n#endif\n\tx = (x & 0x55555555)\
    \ + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333) + (x >> 2 & 0x33333333);\n\t\
    x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\tx = (x & 0x00ff00ff) + (x >>\
    \ 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x >> 16 & 0x0000ffff);\n}\ntemplate\
    \ <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f) {\n\treturn [f\
    \ = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
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
    }\n#line 3 \"math/CountPrime.hpp\"\n\nlint count_prime(lint x) {\n\tstatic constexpr\
    \ int table[] = {\n\t\t1,\t 1,\t  1,   1,\t1,\t 1,\t  2,   2,\t3,\t 4,\t  4, \
    \  5,\t5,\t 5,\t  6,   7,\t7,\t 7,\n\t\t8,\t 8,\t  9,   10,\t10,\t 11,  11,  11,\t\
    12,\t 12,  12,  13,\t14,\t 14,  14,  15,\t15,\t 16,\n\t\t17,\t 17,  17,  18,\t\
    18,\t 19,  19,  19,\t20,\t 20,  20,  20,\t21,\t 21,  22,  23,\t23,\t 24,\n\t\t\
    25,\t 25,  26,  26,\t26,\t 26,  26,  26,\t26,\t 27,  27,  28,\t28,\t 28,  29,\
    \  30,\t30,\t 30,\n\t\t30,\t 30,  31,  32,\t32,\t 32,  33,  33,\t33,\t 34,  34,\
    \  35,\t36,\t 36,  37,  37,\t37,\t 38,\n\t\t39,\t 39,  39,  39,\t39,\t 40,  41,\
    \  41,\t42,\t 43,  43,  43,\t43,\t 43,  43,  44,\t44,\t 44,\n\t\t44,\t 44,  45,\
    \  46,\t46,\t 47,  48,  48,\t49,\t 49,  49,  50,\t51,\t 51,  51,  52,\t52,\t 53,\n\
    \t\t53,\t 53,  54,  54,\t54,\t 55,  55,  55,\t56,\t 57,  57,  57,\t58,\t 58, \
    \ 59,  60,\t60,\t 60,\n\t\t61,\t 61,  62,  62,\t62,\t 63,  63,  63,\t63,\t 64,\
    \  64,  65,\t66,\t 66,  67,  67,\t67,\t 68,\n\t\t68,\t 68,  68,  69,\t69,\t 69,\
    \  70,  70,\t70,\t 70,  70,  71,\t72,\t 72,  73,  73,\t73,\t 74,\n\t\t75,\t 75,\
    \  75,  76,\t76,\t 76,  77,  77,\t78,\t 79,  79,  80,\t80,\t 80,  81,  82,\t82,\t\
    \ 82,\n\t\t83,\t 83,  84,  85,\t85,\t 85,  86,  86,\t86,\t 86,  86,  87,\t88,\t\
    \ 88,  88,  88,\t88,\t 89,\n\t\t90,\t 90,  91,  92,\t92,\t 93,  93,  93,\t94,\t\
    \ 94,  94,  94,\t95,\t 95,  96,  97,\t97,\t 98,\n\t\t98,\t 98,  98,  98,\t98,\t\
    \ 99,  100, 100, 100, 101, 101, 102, 103, 103, 103, 104, 104, 105,\n\t\t105, 105,\
    \ 106, 106, 106, 106, 106, 106, 107, 108, 108, 109, 110, 110, 111, 111, 111, 111,\n\
    \t\t112, 112, 112, 113, 113, 114, 114, 114, 115, 116, 116, 117, 117, 117, 118,\
    \ 119, 119, 119,\n\t\t120, 120, 120, 120, 120, 121, 122, 122, 123, 123, 123, 124,\
    \ 125, 125, 125, 126, 126, 127,\n\t\t128, 128, 129, 130, 130, 130, 130, 130, 131,\
    \ 132, 132, 132, 132, 132, 133, 134, 134, 135,\n\t\t135, 135, 136, 136, 136, 137,\
    \ 138, 138, 138, 139, 139, 139, 140, 140, 141, 141, 141, 142,\n\t\t142, 142, 143,\
    \ 144, 144, 144, 145, 145, 146, 147, 147, 147, 148, 148, 149, 149, 149, 150,\n\
    \t\t150, 150, 150, 151, 151, 152, 153, 153, 153, 154, 154, 155, 155, 155, 155,\
    \ 156, 156, 156,\n\t\t157, 157, 158, 158, 158, 159, 160, 160, 161, 161, 161, 162,\
    \ 162, 162, 162, 163, 163, 163,\n\t\t164, 164, 165, 166, 166, 166, 166, 166, 167,\
    \ 168, 168, 168, 169, 169, 170, 171, 171, 172,\n\t\t173, 173, 173, 173, 173, 174,\
    \ 175, 175, 175, 175, 175, 176, 177, 177, 178, 179, 179, 180,\n\t\t180, 180, 180,\
    \ 181, 181, 181, 182, 182, 183, 184, 184, 185, 185, 185, 186, 186, 186, 187,\n\
    \t\t188, 188, 188, 189, 189, 190, 190, 190, 190, 191, 191, 192, 192, 192, 193,\
    \ 193, 193, 193,\n\t\t194, 194, 195, 196, 196, 197, 198, 198, 199, 199, 199, 199,\
    \ 200, 200, 200, 201, 201, 202,\n\t\t202, 202, 203, 203, 203, 204, 204, 204, 205,\
    \ 206, 206, 206, 207, 207, 207, 208, 208, 209,\n\t\t210, 210, 211, 211, 211, 212,\
    \ 213, 213, 213, 214, 214, 215, 216, 216, 217, 218, 218, 218,\n\t\t218, 218, 219,\
    \ 220, 220, 220, 220, 220, 221, 222, 222, 222, 223, 223, 224, 224, 224, 225,\n\
    \t\t226, 226, 226, 227, 227, 228, 229, 229, 230, 230, 230, 231, 231, 231, 232,\
    \ 232, 232, 232,\n\t\t233, 233, 234, 235, 235, 235, 236, 236, 236, 236, 236, 237,\
    \ 237, 237, 237, 238, 238, 239,\n\t\t240, 240, 241, 242, 242, 243, 243, 243, 243,\
    \ 244, 244, 244, 244, 244, 245, 245, 245, 246,\n\t\t247, 247, 248, 248, 248, 248,\
    \ 249, 249, 249, 250, 250, 250, 251, 251, 252, 253, 253, 254,\n\t\t254, 254, 255,\
    \ 256, 256, 256, 257, 257, 258, 258, 258, 259, 260, 260, 260, 260, 260, 261,\n\
    \t\t262, 262, 262, 262, 262, 263, 264, 264, 265, 266, 266, 267, 267, 267, 268,\
    \ 269, 269, 269,\n\t\t270, 270, 271, 272, 272, 273, 273, 273, 274, 274, 274, 275,\
    \ 276, 276, 276, 277, 277, 277,\n\t\t278, 278, 278, 279, 279, 280, 280, 280, 281,\
    \ 281, 281, 281, 282, 282, 283, 284, 284, 285,\n\t\t286, 286, 287, 287, 287, 287,\
    \ 288, 288, 288, 289, 289, 290, 290, 290, 290, 291, 291, 292,\n\t\t292, 292, 293,\
    \ 294, 294, 294, 295, 295, 295, 296, 296, 297, 298, 298, 299, 299, 299, 300,\n\
    \t\t300, 300, 300, 301, 301, 302, 303, 303, 304, 305, 305, 305, 305, 305, 306,\
    \ 307, 307, 307,\n\t\t307, 307, 308, 309, 309, 310, 311, 311, 312, 312, 312, 313,\
    \ 314, 314, 314, 314, 314, 315,\n\t\t316, 316, 317, 317, 317, 318, 318, 318, 318,\
    \ 319, 319, 319, 320, 320, 321, 322, 322, 322,\n\t\t323, 323, 324, 324, 324, 325,\
    \ 325, 325, 325, 326, 326, 327, 327, 327, 328, 329, 329, 330,\n\t\t330, 330, 330,\
    \ 331, 331, 331, 332, 332, 333, 333, 333, 334, 335, 335, 336, 336, 336, 337,\n\
    \t\t338, 338, 338, 339, 339, 339, 340, 340, 341, 341, 341, 342, 342, 342, 343,\
    \ 344, 344, 344,\n\t\t345, 345, 345, 346, 346, 347, 348, 348, 348, 348, 348, 349,\
    \ 350, 350, 350, 350, 350, 351,\n\t\t352, 352, 353, 354, 354, 355, 355, 355, 356,\
    \ 357, 357, 357, 358, 358, 359, 360, 360, 360,\n\t\t360, 360, 361, 361, 361, 362,\
    \ 363, 363, 363, 364, 364, 365, 366, 366, 366, 367, 367, 368,\n\t\t368, 368, 369,\
    \ 369, 369, 369, 370, 370, 371, 372, 372, 373, 374, 374, 374, 374, 374, 374,\n\
    \t\t375, 375, 375, 376, 376, 377, 377, 377, 378, 379, 379, 380, 380, 380, 381,\
    \ 382, 382, 382,\n\t\t382, 382, 382, 383, 383, 384, 385, 385, 386, 386, 386, 386,\
    \ 387, 387, 387, 388, 388, 389,\n\t\t390, 390, 391, 392, 392, 392, 392, 392, 393,\
    \ 394, 394, 394, 394, 394, 395, 395, 395, 396,\n\t\t397, 397, 398, 398, 398, 399,\
    \ 400, 400, 400, 401, 401, 402, 403, 403, 404, 404, 404, 405,\n\t\t405, 405, 406,\
    \ 407, 407, 407, 408, 408, 409, 410, 410, 410, 410, 410, 411, 411, 411, 412,\n\
    \t\t412, 412, 412, 413, 413, 413, 414, 414, 415, 416, 416, 417, 417, 417, 417,\
    \ 418, 418, 418,\n\t\t419, 419, 420, 420, 420, 421, 422, 422, 423, 423, 423, 424,\
    \ 425, 425, 425, 426, 426, 426,\n\t\t427, 427, 427, 428, 428, 429, 429, 429, 430,\
    \ 431, 431, 431, 432, 432, 433, 434, 434, 435,\n\t\t436, 436, 436, 436, 436, 437,\
    \ 437, 437, 437, 437, 437, 438, 439, 439, 440, 441, 441, 441,\n\t\t441, 441, 442,\
    \ 443, 443, 443, 444, 444, 445, 446, 446, 447, 447, 447, 448, 448, 448, 449,\n\
    \t\t450, 450, 450, 450, 450, 451, 452, 452, 452, 453, 453, 454, 454, 454, 454,\
    \ 454, 454, 454,\n\t\t455, 455, 456, 457, 457, 458, 459, 459, 460, 460, 460, 460,\
    \ 461, 461, 461, 462, 462, 463,\n\t\t463, 463, 464, 465, 465, 466, 466, 466, 467,\
    \ 468, 468, 468, 469, 469, 469, 470, 470, 471,\n\t\t472, 472, 473, 473, 473, 474,\
    \ 475, 475, 475, 476, 476, 477, 478, 478, 479, 479, 479, 479,\n\t\t479, 479, 480};\n\
    \n\tint b_ = std::sqrt(x) + 1, b = 0;\n\tint c_ = std::cbrt(x) + 1, c = 0;\n\t\
    std::vector<bool> vec(c_ * c_ + 1, true);\n\tstd::vector<int> primes = {-1};\n\
    \tfor (int i = 2; i <= c_ * c_; i++) {\n\t\tif (vec[i]) {\n\t\t\tprimes.emplace_back(i);\n\
    \t\t\tif (i < b_) {\n\t\t\t\tb++;\n\t\t\t\tif (i < c_) c++;\n\t\t\t}\n\t\t\tfor\
    \ (int j = i << 1; j < vec.size(); j += i) vec[j] = false;\n\t\t}\n\t}\n\tlint\
    \ now = c, cnt = 0, sum = 0;\n\tfor (int i = primes.size() - 1; i > 0; i--) {\n\
    \t\tsum += cnt;\n\t\tbool f = false;\n\t\twhile (lint(primes[i]) * primes[now\
    \ + 1] <= x) {\n\t\t\tcnt++, sum++, now++;\n\t\t\tif (now == b) {\n\t\t\t\tsum\
    \ += lint(i - 1) * cnt;\n\t\t\t\tf = true;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\
    \tif (f) break;\n\t}\n\tauto phi = lambda_fix([&](auto self, lint u, int v) ->\
    \ lint {\n\t\tif (u <= primes[v]) return 1;\n\t\tif (v < 5) {\n\t\t\tint cnt =\
    \ 0;\n\t\t\tfor (int i = 1; i <= u; i++) {\n\t\t\t\tbool f = true;\n\t\t\t\tREP(j,\
    \ v) if (i % primes[j] == 0) f = false;\n\t\t\t\tif (f) cnt++;\n\t\t\t}\n\t\t\t\
    return cnt;\n\t\t}\n\t\tif (v == 5) {\n\t\t\treturn 480 * (u / 2310) + table[(u\
    \ % 2310 - 1) >> 1];\n\t\t}\n\t\treturn self(self, u, v - 1) - self(self, u /\
    \ primes[v], v - 1);\n\t});\n\treturn phi(x, c) + lint(b + c - 2) * (b - c + 1)\
    \ / 2 - sum;\n}\n#line 4 \"test/yosupo/counting_primes.test.cpp\"\nint main()\
    \ {\n\tlint N;\n\tstd::cin >> N;\n\tstd::cout << count_prime(N) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../math/CountPrime.hpp\"\nint main()\
    \ {\n\tlint N;\n\tstd::cin >> N;\n\tstd::cout << count_prime(N) << '\\n';\n}"
  dependsOn:
  - other/template.hpp
  - math/CountPrime.hpp
  isVerificationFile: true
  path: test/yosupo/counting_primes.test.cpp
  requiredBy: []
  timestamp: '2023-06-16 19:42:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/counting_primes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/counting_primes.test.cpp
- /verify/test/yosupo/counting_primes.test.cpp.html
title: test/yosupo/counting_primes.test.cpp
---
