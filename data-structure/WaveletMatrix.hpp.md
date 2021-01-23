---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/SuccinctBitVector.hpp
    title: Succinct Bit Vector
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_kth_smallest.test.cpp
    title: test/yosupo/range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Wavelet Matrix
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
    \treturn dp[a.size()][b.size()];\n}\n#line 3 \"data-structure/SuccinctBitVector.hpp\"\
    \nclass SuccinctBitVector {\n\tstd::vector<bool> v;\n\tusing u8 = uint_least8_t;\n\
    \tusing u16 = uint_least16_t;\n\tusing u32 = uint_least32_t;\n\n\tconstexpr static\
    \ u8 chunk_bit = 10;\n\tconstexpr static u8 blocks_bit = 4;\n\tconstexpr static\
    \ u16 chunk_size = 1 << chunk_bit;  // log ^ 2 N bit\n\tconstexpr static u8 block_size\
    \ = 1 << blocks_bit;  // log N / 2 bit\n\tconstexpr static u8 blocks_in_chunk\
    \ = 1 << (chunk_bit - blocks_bit);\n\n\tsize_t N;\t\t\t\t\t\t\t // MAX 2 ^ 32\n\
    \tstd::vector<u32> chunks;\t\t\t // log N: 32\n\tstd::vector<u16> blocks, block_num;\t\
    \ // 2 log log N: 10\n\n  public:\n\tSuccinctBitVector() = default;\n\tSuccinctBitVector(const\
    \ std::vector<bool>& vec) { init(vec); }\n\tvoid init(const std::vector<bool>&\
    \ vec) {\n\t\tN = vec.size();\n\t\tchunks.resize((N + chunk_size - 1) >> chunk_bit,\
    \ 0);\n\t\tblocks.resize((N + block_size - 1) >> blocks_bit, 0);\n\t\tblock_num.resize((N\
    \ + block_size - 1) >> blocks_bit, 0);\n\t\trep(i, N) {\n\t\t\tif (vec[i]) {\n\
    \t\t\t\tchunks[i >> chunk_bit]++;\n\t\t\t\tblocks[i >> blocks_bit]++;\n\t\t\t\t\
    block_num[i >> blocks_bit] |= 1 << (i & (block_size - 1));\n\t\t\t}\n\t\t}\n\t\
    \trep(i, chunks.size() - 1) chunks[i + 1] += chunks[i];\n\t\trep(i, blocks.size()\
    \ - 1) {\n\t\t\tif ((i & (blocks_in_chunk - 1)) != blocks_in_chunk - 1)\n\t\t\t\
    \tblocks[i + 1] += blocks[i];\n\t\t}\n\t\tv = vec;\n\t}\n\tint rank(bool b, int\
    \ x) const {\n\t\tint res = 0;\n\t\tres += x >= chunk_size ? chunks[(x >> chunk_bit)\
    \ - 1] : 0;\n\t\tres += (x & (chunk_size - 1)) >= block_size\n\t\t\t\t   ? blocks[(x\
    \ >> blocks_bit) - 1]\n\t\t\t\t   : 0;\n\t\tres += __builtin_popcount(block_num[x\
    \ >> blocks_bit] &\n\t\t\t\t\t\t((1 << ((x & (block_size - 1)) + 1)) - 1));\n\t\
    \treturn b ? res : x + 1 - res;\n\t}\n\tsize_t size() const { return N; }\n};\n\
    \n/**\n * @title Succinct Bit Vector\n */\n#line 4 \"data-structure/WaveletMatrix.hpp\"\
    \ntemplate <typename T>\nconstexpr static int8_t bit_count() {\n\tint8_t res =\
    \ 0;\n\tstd::make_unsigned_t<T> x = ~0;\n\twhile (x) {\n\t\tres++;\n\t\tx >>=\
    \ 1;\n\t}\n\treturn res;\n}\ntemplate <typename T, int8_t word_size = bit_count<T>()>\n\
    class WaveletMatrix {\n\tusing i8 = int8_t;\n\n\tint N;\n\tstd::array<SuccinctBitVector,\
    \ word_size> bit;\n\tstd::array<int, word_size> zero_cnt;\n\tstd::vector<int>\
    \ head;\n\n  public:\n\tWaveletMatrix(std::vector<T> vec) : N(vec.size()), head(vec.size())\
    \ {\n\t\tzero_cnt.fill(0);\n\t\tstd::vector<T> nvec(N);\n\t\tstd::vector<bool>\
    \ bvec;\n\t\tbvec.reserve(N);\n\t\tfor (i8 i = word_size - 1; i >= 0; i--) {\n\
    \t\t\tint cnt[] = {0, 0};\n\t\t\tbvec.resize(0);\n\t\t\tfor (T j : vec) {\n\t\t\
    \t\tbvec.emplace_back(j & (1LL << i));\n\t\t\t\tif (!(j & (1LL << i))) {\n\t\t\
    \t\t\tcnt[1]++;\n\t\t\t\t\tzero_cnt[i]++;\n\t\t\t\t}\n\t\t\t}\n\t\t\tnvec.resize(N);\n\
    \t\t\tfor (T j : vec) {\n\t\t\t\tif (j & (1LL << i))\n\t\t\t\t\tnvec[cnt[1]++]\
    \ = j;\n\t\t\t\telse\n\t\t\t\t\tnvec[cnt[0]++] = j;\n\t\t\t}\n\t\t\tvec = std::move(nvec);\n\
    \t\t\tbit[i].init(bvec);\n\t\t}\n\t\tREP(i, N - 1) {\n\t\t\tif (vec[i - 1] ==\
    \ vec[i])\n\t\t\t\thead[i] = head[i - 1];\n\t\t\telse\n\t\t\t\thead[i] = i;\n\t\
    \t}\n\t}\n\tint rank(int r, lint c) const {\n\t\tfor (i8 i = word_size - 1; i\
    \ >= 0; i--) {\n\t\t\tr--;\n\t\t\tif (c & ((lint)1 << i))\n\t\t\t\tr = bit[i].rank(false,\
    \ bit[i].size() - 1) +\n\t\t\t\t\tbit[i].rank(true, r);\n\t\t\telse\n\t\t\t\t\
    r = bit[i].rank(false, r);\n\t\t}\n\t\treturn r - head[r];\n\t}\n\tT quantile(int\
    \ l, int r, int k) const {\n\t\tT res = 0;\n\t\tfor (i8 i = word_size - 1; i >=\
    \ 0; i--) {\n\t\t\tconst int z_r = bit[i].rank(false, r - 1), o_r = r - z_r;\n\
    \t\t\tconst int z_l = !l ? 0 : bit[i].rank(false, l - 1), o_l = l - z_l;\n\t\t\
    \tif (k <= z_r - z_l) {\n\t\t\t\tl = z_l;\n\t\t\t\tr = z_r;\n\t\t\t} else {\n\t\
    \t\t\tl = r = zero_cnt[i];\n\t\t\t\tl += o_l;\n\t\t\t\tr += o_r;\n\t\t\t\tk -=\
    \ z_r - z_l;\n\t\t\t\tres |= (1 << i);\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\
    };\n\n/**\n * @title Wavelet Matrix\n */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\n#include \"SuccinctBitVector.hpp\"\
    \ntemplate <typename T>\nconstexpr static int8_t bit_count() {\n\tint8_t res =\
    \ 0;\n\tstd::make_unsigned_t<T> x = ~0;\n\twhile (x) {\n\t\tres++;\n\t\tx >>=\
    \ 1;\n\t}\n\treturn res;\n}\ntemplate <typename T, int8_t word_size = bit_count<T>()>\n\
    class WaveletMatrix {\n\tusing i8 = int8_t;\n\n\tint N;\n\tstd::array<SuccinctBitVector,\
    \ word_size> bit;\n\tstd::array<int, word_size> zero_cnt;\n\tstd::vector<int>\
    \ head;\n\n  public:\n\tWaveletMatrix(std::vector<T> vec) : N(vec.size()), head(vec.size())\
    \ {\n\t\tzero_cnt.fill(0);\n\t\tstd::vector<T> nvec(N);\n\t\tstd::vector<bool>\
    \ bvec;\n\t\tbvec.reserve(N);\n\t\tfor (i8 i = word_size - 1; i >= 0; i--) {\n\
    \t\t\tint cnt[] = {0, 0};\n\t\t\tbvec.resize(0);\n\t\t\tfor (T j : vec) {\n\t\t\
    \t\tbvec.emplace_back(j & (1LL << i));\n\t\t\t\tif (!(j & (1LL << i))) {\n\t\t\
    \t\t\tcnt[1]++;\n\t\t\t\t\tzero_cnt[i]++;\n\t\t\t\t}\n\t\t\t}\n\t\t\tnvec.resize(N);\n\
    \t\t\tfor (T j : vec) {\n\t\t\t\tif (j & (1LL << i))\n\t\t\t\t\tnvec[cnt[1]++]\
    \ = j;\n\t\t\t\telse\n\t\t\t\t\tnvec[cnt[0]++] = j;\n\t\t\t}\n\t\t\tvec = std::move(nvec);\n\
    \t\t\tbit[i].init(bvec);\n\t\t}\n\t\tREP(i, N - 1) {\n\t\t\tif (vec[i - 1] ==\
    \ vec[i])\n\t\t\t\thead[i] = head[i - 1];\n\t\t\telse\n\t\t\t\thead[i] = i;\n\t\
    \t}\n\t}\n\tint rank(int r, lint c) const {\n\t\tfor (i8 i = word_size - 1; i\
    \ >= 0; i--) {\n\t\t\tr--;\n\t\t\tif (c & ((lint)1 << i))\n\t\t\t\tr = bit[i].rank(false,\
    \ bit[i].size() - 1) +\n\t\t\t\t\tbit[i].rank(true, r);\n\t\t\telse\n\t\t\t\t\
    r = bit[i].rank(false, r);\n\t\t}\n\t\treturn r - head[r];\n\t}\n\tT quantile(int\
    \ l, int r, int k) const {\n\t\tT res = 0;\n\t\tfor (i8 i = word_size - 1; i >=\
    \ 0; i--) {\n\t\t\tconst int z_r = bit[i].rank(false, r - 1), o_r = r - z_r;\n\
    \t\t\tconst int z_l = !l ? 0 : bit[i].rank(false, l - 1), o_l = l - z_l;\n\t\t\
    \tif (k <= z_r - z_l) {\n\t\t\t\tl = z_l;\n\t\t\t\tr = z_r;\n\t\t\t} else {\n\t\
    \t\t\tl = r = zero_cnt[i];\n\t\t\t\tl += o_l;\n\t\t\t\tr += o_r;\n\t\t\t\tk -=\
    \ z_r - z_l;\n\t\t\t\tres |= (1 << i);\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\
    };\n\n/**\n * @title Wavelet Matrix\n */"
  dependsOn:
  - other/template.hpp
  - data-structure/SuccinctBitVector.hpp
  isVerificationFile: false
  path: data-structure/WaveletMatrix.hpp
  requiredBy: []
  timestamp: '2021-01-19 14:37:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_kth_smallest.test.cpp
documentation_of: data-structure/WaveletMatrix.hpp
layout: document
redirect_from:
- /library/data-structure/WaveletMatrix.hpp
- /library/data-structure/WaveletMatrix.hpp.html
title: Wavelet Matrix
---
