---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_xor_min.test.cpp
    title: test/yosupo/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Trie
    links: []
  bundledCode: "#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
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
    }\n#line 3 \"string/Trie.hpp\"\ntemplate <int char_size, int base>\nclass Trie\
    \ {\n\tclass Node {\n\t  public:\n\t\tstd::vector<int> next;\n\t\tint c, cnt =\
    \ 0, lastcnt = 0;\n\t\tNode(int c_) : c(c_) { next.assign(char_size, -1); }\n\t\
    };\n\n  protected:\n\tstd::vector<Node> nodes;\n\n  public:\n\tTrie() : nodes(1,\
    \ 0) {}\n\tvoid insert(const std::string &word, int word_id) {\n\t\tint node_id\
    \ = 0;\n\t\tfor (char i : word) {\n\t\t\tint c = i - base;\n\t\t\tint &next_id\
    \ = nodes[node_id].next[c];\n\t\t\tif (next_id == -1) {\n\t\t\t\tnext_id = nodes.size();\n\
    \t\t\t\tnodes.push_back(Node(c));\n\t\t\t}\n\t\t\tnodes[node_id].cnt++;\n\t\t\t\
    node_id = next_id;\n\t\t}\n\t\tnodes[node_id].cnt++;\n\t\tnodes[node_id].lastcnt++;\n\
    \t}\n\tvoid insert(const std::string &word) { insert(word, nodes[0].cnt); }\n\t\
    void erase(const std::string &word) {\n\t\tstd::vector<int> path;\n\t\tpath.reserve(word.size());\n\
    \t\tint node_id = 0;\n\t\tfor (char i : word) {\n\t\t\tint c = i - base;\n\t\t\
    \tif (nodes[node_id].next[c] == -1 || nodes[node_id].cnt == 0) return;\n\t\t\t\
    path.emplace_back(node_id);\n\t\t\tnode_id = nodes[node_id].next[c];\n\t\t}\n\t\
    \tnodes[node_id].lastcnt--;\n\t\tnodes[node_id].cnt--;\n\t\tfor (int i : path)\
    \ nodes[i].cnt--;\n\t}\n\tbool search(const std::string &word, bool prefix = false)\
    \ const {\n\t\tint node_id = 0;\n\t\tfor (char i : word) {\n\t\t\tint c = i -\
    \ base;\n\t\t\tif (nodes[node_id].next[c] == -1 || nodes[node_id].cnt == 0)\n\t\
    \t\t\treturn false;\n\t\t\tnode_id = nodes[node_id].next[c];\n\t\t}\n\t\treturn\
    \ prefix || nodes[node_id].lastcnt;\n\t}\n\tbool start_with(const std::string\
    \ &prefix) const {\n\t\treturn search(prefix, true);\n\t}\n\tint size() const\
    \ { return nodes[0].cnt; }\n};\ntemplate <unsigned int bit>\nclass BinaryTrie\
    \ : public Trie<2, '0'> {\n  public:\n\tvoid insert(int n) {\n\t\tTrie<2, '0'>::insert(std::bitset<bit>(n).to_string());\n\
    \t}\n\tvoid erase(int n) { Trie<2, '0'>::erase(std::bitset<bit>(n).to_string());\
    \ }\n\tbool search(int n, bool prefix = false) const {\n\t\treturn Trie<2, '0'>::search(std::bitset<bit>(n).to_string());\n\
    \t}\n\tbool start_with(int n) const {\n\t\treturn Trie<2, '0'>::start_with(std::bitset<bit>(n).to_string());\n\
    \t}\n\tint xor_min(int n) const {\n\t\tint node_id = 0, res = 0;\n\t\tstd::string\
    \ binary = std::bitset<bit>(n).to_string();\n\t\trep(i, bit) {\n\t\t\tint c =\
    \ binary[i] - '0';\n\t\t\tif (nodes[node_id].next[c] == -1 ||\n\t\t\t\tnodes[nodes[node_id].next[c]].cnt\
    \ == 0) {\n\t\t\t\tres += 1 << (bit - i - 1);\n\t\t\t\tnode_id = nodes[node_id].next[1\
    \ - c];\n\t\t\t} else\n\t\t\t\tnode_id = nodes[node_id].next[c];\n\t\t}\n\t\t\
    return res;\n\t}\n\tint xor_max(int n) const {\n\t\tint node_id = 0, res = 0;\n\
    \t\tstd::string binary = std::bitset<bit>(n).to_string();\n\t\trep(i, bit) {\n\
    \t\t\tint c = binary[i] - '0';\n\t\t\tif (nodes[node_id].next[1 - c] == -1 ||\n\
    \t\t\t\tnodes[nodes[node_id].next[1 - c]].cnt == 0) {\n\t\t\t\tnode_id = nodes[node_id].next[c];\n\
    \t\t\t} else {\n\t\t\t\tres += 1 << (bit - i - 1);\n\t\t\t\tnode_id = nodes[node_id].next[1\
    \ - c];\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\n/**\n * @title Trie\n */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\ntemplate <int char_size,\
    \ int base>\nclass Trie {\n\tclass Node {\n\t  public:\n\t\tstd::vector<int> next;\n\
    \t\tint c, cnt = 0, lastcnt = 0;\n\t\tNode(int c_) : c(c_) { next.assign(char_size,\
    \ -1); }\n\t};\n\n  protected:\n\tstd::vector<Node> nodes;\n\n  public:\n\tTrie()\
    \ : nodes(1, 0) {}\n\tvoid insert(const std::string &word, int word_id) {\n\t\t\
    int node_id = 0;\n\t\tfor (char i : word) {\n\t\t\tint c = i - base;\n\t\t\tint\
    \ &next_id = nodes[node_id].next[c];\n\t\t\tif (next_id == -1) {\n\t\t\t\tnext_id\
    \ = nodes.size();\n\t\t\t\tnodes.push_back(Node(c));\n\t\t\t}\n\t\t\tnodes[node_id].cnt++;\n\
    \t\t\tnode_id = next_id;\n\t\t}\n\t\tnodes[node_id].cnt++;\n\t\tnodes[node_id].lastcnt++;\n\
    \t}\n\tvoid insert(const std::string &word) { insert(word, nodes[0].cnt); }\n\t\
    void erase(const std::string &word) {\n\t\tstd::vector<int> path;\n\t\tpath.reserve(word.size());\n\
    \t\tint node_id = 0;\n\t\tfor (char i : word) {\n\t\t\tint c = i - base;\n\t\t\
    \tif (nodes[node_id].next[c] == -1 || nodes[node_id].cnt == 0) return;\n\t\t\t\
    path.emplace_back(node_id);\n\t\t\tnode_id = nodes[node_id].next[c];\n\t\t}\n\t\
    \tnodes[node_id].lastcnt--;\n\t\tnodes[node_id].cnt--;\n\t\tfor (int i : path)\
    \ nodes[i].cnt--;\n\t}\n\tbool search(const std::string &word, bool prefix = false)\
    \ const {\n\t\tint node_id = 0;\n\t\tfor (char i : word) {\n\t\t\tint c = i -\
    \ base;\n\t\t\tif (nodes[node_id].next[c] == -1 || nodes[node_id].cnt == 0)\n\t\
    \t\t\treturn false;\n\t\t\tnode_id = nodes[node_id].next[c];\n\t\t}\n\t\treturn\
    \ prefix || nodes[node_id].lastcnt;\n\t}\n\tbool start_with(const std::string\
    \ &prefix) const {\n\t\treturn search(prefix, true);\n\t}\n\tint size() const\
    \ { return nodes[0].cnt; }\n};\ntemplate <unsigned int bit>\nclass BinaryTrie\
    \ : public Trie<2, '0'> {\n  public:\n\tvoid insert(int n) {\n\t\tTrie<2, '0'>::insert(std::bitset<bit>(n).to_string());\n\
    \t}\n\tvoid erase(int n) { Trie<2, '0'>::erase(std::bitset<bit>(n).to_string());\
    \ }\n\tbool search(int n, bool prefix = false) const {\n\t\treturn Trie<2, '0'>::search(std::bitset<bit>(n).to_string());\n\
    \t}\n\tbool start_with(int n) const {\n\t\treturn Trie<2, '0'>::start_with(std::bitset<bit>(n).to_string());\n\
    \t}\n\tint xor_min(int n) const {\n\t\tint node_id = 0, res = 0;\n\t\tstd::string\
    \ binary = std::bitset<bit>(n).to_string();\n\t\trep(i, bit) {\n\t\t\tint c =\
    \ binary[i] - '0';\n\t\t\tif (nodes[node_id].next[c] == -1 ||\n\t\t\t\tnodes[nodes[node_id].next[c]].cnt\
    \ == 0) {\n\t\t\t\tres += 1 << (bit - i - 1);\n\t\t\t\tnode_id = nodes[node_id].next[1\
    \ - c];\n\t\t\t} else\n\t\t\t\tnode_id = nodes[node_id].next[c];\n\t\t}\n\t\t\
    return res;\n\t}\n\tint xor_max(int n) const {\n\t\tint node_id = 0, res = 0;\n\
    \t\tstd::string binary = std::bitset<bit>(n).to_string();\n\t\trep(i, bit) {\n\
    \t\t\tint c = binary[i] - '0';\n\t\t\tif (nodes[node_id].next[1 - c] == -1 ||\n\
    \t\t\t\tnodes[nodes[node_id].next[1 - c]].cnt == 0) {\n\t\t\t\tnode_id = nodes[node_id].next[c];\n\
    \t\t\t} else {\n\t\t\t\tres += 1 << (bit - i - 1);\n\t\t\t\tnode_id = nodes[node_id].next[1\
    \ - c];\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\n/**\n * @title Trie\n */"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: string/Trie.hpp
  requiredBy: []
  timestamp: '2023-06-16 19:42:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/set_xor_min.test.cpp
documentation_of: string/Trie.hpp
layout: document
redirect_from:
- /library/string/Trie.hpp
- /library/string/Trie.hpp.html
title: Trie
---
