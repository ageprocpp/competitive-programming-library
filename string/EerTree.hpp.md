---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: EerTree
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
    \ 3.141592653589793238462643383279;\n\nnamespace std {\n\ttemplate <template <class...>\
    \ class Temp, class T>\n\tclass is_template_with_type_of : public std::false_type\
    \ {};\n\ttemplate <template <class...> class Temp, class... Args>\n\tclass is_template_with_type_of<Temp,\
    \ Temp<Args...>>\n\t\t: public std::true_type {};\n\ttemplate <template <auto...>\
    \ class Temp, class T>\n\tclass is_template_with_non_type_of : public std::false_type\
    \ {};\n\ttemplate <template <auto...> class Temp, auto... Args>\n\tclass is_template_with_non_type_of<Temp,\
    \ Temp<Args...>>\n\t\t: public std::true_type {};\n};\t// namespace std\ntemplate\
    \ <class T>\nclass prique : public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {\n};\ntemplate <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f)\
    \ {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
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
    \ <class T>\nconstexpr void printArray(T l, T r, char split = ' ') {\n\tT rprev\
    \ = std::prev(r);\n\tfor (T i = l; i != r; i++) {\n\t\tstd::cout << *i;\n\t\t\
    std::cout << (i == rprev ? '\\n' : split);\n\t}\n}\nLP extGcd(lint a, lint b)\
    \ {\n\tif (b == 0) return {1, 0};\n\tLP s = extGcd(b, a % b);\n\tstd::swap(s.first,\
    \ s.second);\n\ts.second -= a / b * s.first;\n\treturn s;\n}\nLP ChineseRem(const\
    \ lint& b1, const lint& m1, const lint& b2, const lint& m2) {\n\tlint p = extGcd(m1,\
    \ m2).first;\n\tlint tmp = (b2 - b1) * p % m2;\n\tlint r = (b1 + m1 * tmp + m1\
    \ * m2) % (m1 * m2);\n\treturn {r, m1 * m2};\n}\nint LCS(const std::string& a,\
    \ const std::string& b) {\n\tauto dp = make_vec<int>(a.size() + 1, b.size() +\
    \ 1);\n\trep(i, a.size()) {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j],\
    \ dp[i][j]);\n\t\t\tchmax(dp[i][j + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i\
    \ + 1][j + 1], dp[i][j] + 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\
    \t}\n\trep(j, b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn\
    \ dp[a.size()][b.size()];\n}\n#line 3 \"string/EerTree.hpp\"\nclass EerTree {\n\
    \tclass Node {\n\t  public:\n\t\tint len;\n\t\tNode* suffix_link;\n\t\tstd::map<char,\
    \ Node*> edges;\n\t\tNode(int len) : len(len), suffix_link(nullptr) {}\n\t};\n\
    \tstd::vector<Node*> last;\n\tNode* root[2];\n\tstd::string s;\n\tsize_t size_\
    \ = 0;\n\tNode* make(Node* par, char c) {\n\t\tif (par->edges.find(c) == par->edges.end())\
    \ {\n\t\t\tpar->edges[c] = new Node(par->len + 2);\n\t\t\tsize_++;\n\t\t\tNode*\
    \ sl = par->suffix_link;\n\t\t\tif (par->len == -1)\n\t\t\t\tsl = root[0];\n\t\
    \t\telse {\n\t\t\t\twhile (true) {\n\t\t\t\t\tif (s[s.size() - sl->len - 2] ==\
    \ c) {\n\t\t\t\t\t\tsl = sl->edges[c];\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t} else if\
    \ (sl->len < 0) {\n\t\t\t\t\t\tsl = root[0];\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\
    \ else\n\t\t\t\t\t\tsl = sl->suffix_link;\n\t\t\t\t}\n\t\t\t}\n\t\t\tpar->edges[c]->suffix_link\
    \ = sl;\n\t\t}\n\t\treturn par->edges[c];\n\t}\n\n  public:\n\tvoid push(char\
    \ c) {\n\t\tNode* last_node = last.empty ? root[1] : last.back();\n\t\tfor (s\
    \ += c; s.size() - last_node->len - 2 < 0 ||\n\t\t\t\t\t s[s.size() - last_node->len\
    \ - 2] != c;\n\t\t\t last_node = last_node->suffix_link) {\n\t\t\tlast_node =\
    \ make(last_node, c);\n\t\t}\n\t\tlast.emplace_back(last_node);\n\t}\n\tEerTree()\
    \ {\n\t\troot[0] = new Node(0);\n\t\troot[0]->suffix_link = root[1] = new Node(-1);\n\
    \t\troot[1]->suffix_link = root[1];\n\t}\n\tEerTree(const std::string& s) : eerTree()\
    \ {\n\t\tfor (const char c : s) push(c);\n\t}\n\tsize_t size() const { return\
    \ size_; }\n\tsize_t count_end_with(int idx) {\n\t\tsize_t res = 0;\n\t\tfor (Node*\
    \ node = last[idx]; node != root[0] && node != root[1];\n\t\t\t node = node->suffix_link)\n\
    \t\t\tres++;\n\t\treturn res;\n\t}\n};\n\n/**\n * @title EerTree\n */\n"
  code: "#pragma once\n#include \"../other/template.hpp\"\nclass EerTree {\n\tclass\
    \ Node {\n\t  public:\n\t\tint len;\n\t\tNode* suffix_link;\n\t\tstd::map<char,\
    \ Node*> edges;\n\t\tNode(int len) : len(len), suffix_link(nullptr) {}\n\t};\n\
    \tstd::vector<Node*> last;\n\tNode* root[2];\n\tstd::string s;\n\tsize_t size_\
    \ = 0;\n\tNode* make(Node* par, char c) {\n\t\tif (par->edges.find(c) == par->edges.end())\
    \ {\n\t\t\tpar->edges[c] = new Node(par->len + 2);\n\t\t\tsize_++;\n\t\t\tNode*\
    \ sl = par->suffix_link;\n\t\t\tif (par->len == -1)\n\t\t\t\tsl = root[0];\n\t\
    \t\telse {\n\t\t\t\twhile (true) {\n\t\t\t\t\tif (s[s.size() - sl->len - 2] ==\
    \ c) {\n\t\t\t\t\t\tsl = sl->edges[c];\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t} else if\
    \ (sl->len < 0) {\n\t\t\t\t\t\tsl = root[0];\n\t\t\t\t\t\tbreak;\n\t\t\t\t\t}\
    \ else\n\t\t\t\t\t\tsl = sl->suffix_link;\n\t\t\t\t}\n\t\t\t}\n\t\t\tpar->edges[c]->suffix_link\
    \ = sl;\n\t\t}\n\t\treturn par->edges[c];\n\t}\n\n  public:\n\tvoid push(char\
    \ c) {\n\t\tNode* last_node = last.empty ? root[1] : last.back();\n\t\tfor (s\
    \ += c; s.size() - last_node->len - 2 < 0 ||\n\t\t\t\t\t s[s.size() - last_node->len\
    \ - 2] != c;\n\t\t\t last_node = last_node->suffix_link) {\n\t\t\tlast_node =\
    \ make(last_node, c);\n\t\t}\n\t\tlast.emplace_back(last_node);\n\t}\n\tEerTree()\
    \ {\n\t\troot[0] = new Node(0);\n\t\troot[0]->suffix_link = root[1] = new Node(-1);\n\
    \t\troot[1]->suffix_link = root[1];\n\t}\n\tEerTree(const std::string& s) : eerTree()\
    \ {\n\t\tfor (const char c : s) push(c);\n\t}\n\tsize_t size() const { return\
    \ size_; }\n\tsize_t count_end_with(int idx) {\n\t\tsize_t res = 0;\n\t\tfor (Node*\
    \ node = last[idx]; node != root[0] && node != root[1];\n\t\t\t node = node->suffix_link)\n\
    \t\t\tres++;\n\t\treturn res;\n\t}\n};\n\n/**\n * @title EerTree\n */"
  dependsOn:
  - other/template.hpp
  isVerificationFile: false
  path: string/EerTree.hpp
  requiredBy: []
  timestamp: '2021-01-18 13:26:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/EerTree.hpp
layout: document
redirect_from:
- /library/string/EerTree.hpp
- /library/string/EerTree.hpp.html
title: EerTree
---
