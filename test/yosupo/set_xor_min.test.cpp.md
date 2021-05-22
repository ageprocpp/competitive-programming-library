---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: string/Trie.hpp
    title: Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/yosupo/set_xor_min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \n#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n\
    #ifdef ONLINE_JUDGE\n#pragma GCC target(\"avx512f\")\n#elif defined EVAL\n#else\n\
    #pragma GCC target(\"avx2\")\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC\
    \ optimize(\"unroll-loops\")\n#endif\n#include <string.h>\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <cfloat>\n#include\
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
    constexpr lint LINF = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr\
    \ double PI = 3.141592653589793238462643383279;\n\ntemplate <class T>\nclass prique\
    \ : public std::priority_queue<T, std::vector<T>, std::greater<T>> {\n};\nint\
    \ popcount(uint x) {\n#if __cplusplus >= 202002L\n\treturn std::popcount(x);\n\
    #else\n#ifndef __clang__\n\treturn __builtin_popcount(x);\n#endif\n#endif\n\t\
    x = (x & 0x55555555) + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333) + (x >>\
    \ 2 & 0x33333333);\n\tx = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\tx = (x\
    \ & 0x00ff00ff) + (x >> 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x >> 16\
    \ & 0x0000ffff);\n}\ntemplate <class F>\ninline constexpr decltype(auto) lambda_fix(F&&\
    \ f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nconstexpr std::vector<T> make_vec(size_t n) {\n\t\
    return std::vector<T>(n);\n}\ntemplate <class T, class... Args>\nconstexpr auto\
    \ make_vec(size_t n, Args&&... args) {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\
    \t\tn, make_vec<T>(std::forward<Args>(args)...));\n}\ntemplate <class T, class\
    \ U>\nstd::istream& operator>>(std::istream& ist, std::pair<T, U>& x) {\n\treturn\
    \ ist >> x.first >> x.second;\n}\ntemplate <class T, class U>\nstd::ostream& operator<<(std::ostream&\
    \ ost, const std::pair<T, U>& x) {\n\treturn ost << x.first << \" \" << x.second;\n\
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
    \ m) noexcept {\n\ta %= m;\n\tlint res(1);\n\twhile (b) {\n\t\tif (b & 1) {\n\t\
    \t\tres *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\ta %= m;\n\t\tb >>= 1;\n\
    \t}\n\treturn res;\n}\ntemplate <class T>\nconstexpr void printArray(const std::vector<T>&\
    \ vec, char split = ' ') {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\
    \t\tstd::cout << (i == (int)vec.size() - 1 ? '\\n' : split);\n\t}\n}\ntemplate\
    \ <class InputIter>\nconstexpr void printArray(InputIter l, InputIter r, char\
    \ split = ' ') {\n\tauto rprev = std::prev(r);\n\tfor (auto i = l; i != r; i++)\
    \ {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev ? '\\n' : split);\n\t\
    }\n}\nLP extGcd(lint a, lint b) noexcept {\n\tif (b == 0) return {1, 0};\n\tLP\
    \ s = extGcd(b, a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b\
    \ * s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const\
    \ lint& b2,\n\t\t\t  const lint& m2) noexcept {\n\tauto p = extGcd(m1, m2);\n\t\
    lint g = gcd(m1, m2), l = m1 / g * m2;\n\tlint tmp = (b2 - b1) / g * p.first %\
    \ (m2 / g);\n\tlint r = (b1 + m1 * tmp + l) % l;\n\treturn {r, l};\n}\nint LCS(const\
    \ std::string& a, const std::string& b) {\n\tauto dp = make_vec<int>(a.size()\
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
    string/Trie.hpp\"\ntemplate <int char_size, int base>\nclass Trie {\n\tclass Node\
    \ {\n\t  public:\n\t\tstd::vector<int> next;\n\t\tint c, cnt = 0, lastcnt = 0;\n\
    \t\tNode(int c_) : c(c_) { next.assign(char_size, -1); }\n\t};\n\n  protected:\n\
    \tstd::vector<Node> nodes;\n\n  public:\n\tTrie() : nodes(1, 0) {}\n\tvoid insert(const\
    \ std::string &word, int word_id) {\n\t\tint node_id = 0;\n\t\tfor (char i : word)\
    \ {\n\t\t\tint c = i - base;\n\t\t\tint &next_id = nodes[node_id].next[c];\n\t\
    \t\tif (next_id == -1) {\n\t\t\t\tnext_id = nodes.size();\n\t\t\t\tnodes.push_back(Node(c));\n\
    \t\t\t}\n\t\t\tnodes[node_id].cnt++;\n\t\t\tnode_id = next_id;\n\t\t}\n\t\tnodes[node_id].cnt++;\n\
    \t\tnodes[node_id].lastcnt++;\n\t}\n\tvoid insert(const std::string &word) { insert(word,\
    \ nodes[0].cnt); }\n\tvoid erase(const std::string &word) {\n\t\tstd::vector<int>\
    \ path;\n\t\tpath.reserve(word.size());\n\t\tint node_id = 0;\n\t\tfor (char i\
    \ : word) {\n\t\t\tint c = i - base;\n\t\t\tif (nodes[node_id].next[c] == -1 ||\
    \ nodes[node_id].cnt == 0) return;\n\t\t\tpath.emplace_back(node_id);\n\t\t\t\
    node_id = nodes[node_id].next[c];\n\t\t}\n\t\tnodes[node_id].lastcnt--;\n\t\t\
    nodes[node_id].cnt--;\n\t\tfor (int i : path) nodes[i].cnt--;\n\t}\n\tbool search(const\
    \ std::string &word, bool prefix = false) const {\n\t\tint node_id = 0;\n\t\t\
    for (char i : word) {\n\t\t\tint c = i - base;\n\t\t\tif (nodes[node_id].next[c]\
    \ == -1 || nodes[node_id].cnt == 0)\n\t\t\t\treturn false;\n\t\t\tnode_id = nodes[node_id].next[c];\n\
    \t\t}\n\t\treturn prefix || nodes[node_id].lastcnt;\n\t}\n\tbool start_with(const\
    \ std::string &prefix) const {\n\t\treturn search(prefix, true);\n\t}\n\tint size()\
    \ const { return nodes[0].cnt; }\n};\ntemplate <unsigned int bit>\nclass BinaryTrie\
    \ : public Trie<2, '0'> {\n  public:\n\tvoid insert(int n) {\n\t\tTrie<2, '0'>::insert(std::bitset<bit>(n).to_string());\n\
    \t}\n\tvoid erase(int n) { Trie<2, '0'>::erase(std::bitset<bit>(n).to_string());\
    \ }\n\tbool search(int n, bool prefix = false) const {\n\t\treturn Trie<2, '0'>::search(std::bitset<bit>(n).to_string());\n\
    \t}\n\tbool start_with(int n) const {\n\t\treturn Trie<2, '0'>::start_with(std::bitset<bit>(n).to_string());\n\
    \t}\n\tint xor_min(int n) const {\n\t\tint node_id = 0, res = 0;\n\t\tstd::string\
    \ binary = std::bitset<bit>(n).to_string();\n\t\trep(i, bit) {\n\t\t\tint c =\
    \ binary[i] - '0';\n\t\t\tif (nodes[node_id].next[c] == -1 ||\n\t\t\t\tnodes[nodes[node_id].next[c]].cnt\
    \ == 0) {\n\t\t\t\tres += 1 << (bit - i - 1);\n\t\t\t\tnode_id = nodes[node_id].next[1\
    \ - c];\n\t\t\t} else\n\t\t\t\tnode_id = nodes[node_id].next[c];\n\t\t}\n\t\t\
    return res;\n\t}\n};\n\n/**\n * @title Trie\n */\n#line 4 \"test/yosupo/set_xor_min.test.cpp\"\
    \nint Q, t, x;\nint main() {\n\tscanf(\"%d\", &Q);\n\tBinaryTrie<30> trie;\n\t\
    rep(i, Q) {\n\t\tscanf(\"%d%d\", &t, &x);\n\t\tif (t == 0 && !trie.search(x))\
    \ trie.insert(x);\n\t\tif (t == 1) trie.erase(x);\n\t\tif (t == 2) printf(\"%d\\\
    n\", trie.xor_min(x));\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../string/Trie.hpp\"\nint Q, t,\
    \ x;\nint main() {\n\tscanf(\"%d\", &Q);\n\tBinaryTrie<30> trie;\n\trep(i, Q)\
    \ {\n\t\tscanf(\"%d%d\", &t, &x);\n\t\tif (t == 0 && !trie.search(x)) trie.insert(x);\n\
    \t\tif (t == 1) trie.erase(x);\n\t\tif (t == 2) printf(\"%d\\n\", trie.xor_min(x));\n\
    \t}\n}"
  dependsOn:
  - other/template.hpp
  - string/Trie.hpp
  isVerificationFile: true
  path: test/yosupo/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2021-05-20 00:07:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/set_xor_min.test.cpp
- /verify/test/yosupo/set_xor_min.test.cpp.html
title: test/yosupo/set_xor_min.test.cpp
---