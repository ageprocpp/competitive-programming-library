---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/SegTree.hpp
    title: data-structure/SegTree.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL_2_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A\"\
    \n#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#ifdef ONLINE_JUDGE\n\
    #pragma GCC target(\"avx512f\")\n#else\n#pragma GCC target(\"avx2\")\n#endif\n\
    #pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#include\
    \ <string.h>\n#include <algorithm>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cfloat>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <ctime>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <iterator>\n#include <list>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n#define rep(i, n) for (int i = 0; i < int(n);\
    \ i++)\n#define REP(i, n) for (int i = 1; i <= int(n); i++)\n#define all(V) V.begin(),\
    \ V.end()\ntypedef unsigned int uint;\ntypedef long long lint;\ntypedef unsigned\
    \ long long ulint;\ntypedef std::pair<int, int> P;\ntypedef std::pair<lint, lint>\
    \ LP;\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF = LLONG_MAX / 2;\n\
    constexpr double eps = DBL_EPSILON;\nconstexpr double PI = 3.141592653589793238462643383279;\n\
    namespace std {\n\ttemplate <template <class...> class Temp, class T>\n\tclass\
    \ is_template_with_type_of : public std::false_type {};\n\ttemplate <template\
    \ <class...> class Temp, class... Args>\n\tclass is_template_with_type_of<Temp,\
    \ Temp<Args...>> : public std::true_type {};\n\ttemplate <template <auto...> class\
    \ Temp, class T>\n\tclass is_template_with_non_type_of : public std::false_type\
    \ {};\n\ttemplate <template <auto...> class Temp, auto... Args>\n\tclass is_template_with_non_type_of<Temp,\
    \ Temp<Args...>> : public std::true_type {};\n};\t// namespace std\ntemplate <class\
    \ T>\nclass prique : public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {\n};\ntemplate <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f)\
    \ {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
    \t};\n}\ntemplate <class T>\nstd::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n\
    }\ntemplate <class T, class... Args>\nauto make_vec(size_t n, Args&&... args)\
    \ {\n\treturn std::vector<decltype(make_vec<T>(args...))>(\n\t\tn, make_vec<T>(std::forward<Args>(args)...));\n\
    }\ntemplate <class T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\t\
    if (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\
    template <class T, class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs\
    \ > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ninline\
    \ lint gcd(lint a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\t\
    b = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint b) { return a /\
    \ gcd(a, b) * b; }\nbool isprime(lint n) {\n\tif (n == 1) return false;\n\tfor\
    \ (int i = 2; i * i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn\
    \ true;\n}\ntemplate <class T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile (b)\
    \ {\n\t\tif (b & 1) res *= a;\n\t\ta *= a;\n\t\tb >>= 1;\n\t}\n\treturn res;\n\
    }\nlint modpow(lint a, lint b, lint m) {\n\ta %= m;\n\tlint res(1);\n\twhile (b)\
    \ {\n\t\tif (b & 1) {\n\t\t\tres *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\
    \ta %= m;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\ntemplate <class T>\nvoid printArray(std::vector<T>&\
    \ vec, char split = ' ') {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\
    \t\tstd::cout << (i == (int)vec.size() - 1 ? '\\n' : split);\n\t}\n}\ntemplate\
    \ <class T>\nvoid printArray(T l, T r, char split = ' ') {\n\tT rprev = std::prev(r);\n\
    \tfor (T i = l; i != r; i++) {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev\
    \ ? '\\n' : split);\n\t}\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return\
    \ {1, 0};\n\tLP s = extGcd(b, a % b);\n\tstd::swap(s.first, s.second);\n\ts.second\
    \ -= a / b * s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1, const lint&\
    \ m1, const lint& b2, const lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\t\
    lint tmp = (b2 - b1) * p % m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\
    \treturn std::make_pair(r, m1 * m2);\n}\nint LCS(const std::string& a, const std::string&\
    \ b) {\n\tauto dp = make_vec<int>(a.size() + 1, b.size() + 1);\n\trep(i, a.size())\
    \ {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j\
    \ + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i + 1][j + 1], dp[i][j] +\
    \ 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\t}\n\trep(j,\
    \ b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn dp[a.size()][b.size()];\n\
    }\n#line 3 \"data-structure/SegTree.hpp\"\ntemplate <class T, T (*nodef)(const\
    \ T&, const T&)>\nclass SegTree {\n  protected:\n\tunsigned int n = 1, rank =\
    \ 0;\n\tstd::vector<T> node;\n\tT ident;\n\n  public:\n\tSegTree(unsigned int\
    \ m, T e_) : ident(e_) {\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\
    \t}\n\t\tnode.resize(2 * n, ident);\n\t}\n\tSegTree(unsigned int m, T init, T\
    \ e_) : ident(e_) {\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\
    \t\tnode.resize(2 * n, ident);\n\t\tfor (unsigned int i = n; i < 2 * n; i++) node[i]\
    \ = init;\n\t\tfor (unsigned int i = n - 1; i > 0; i--)\n\t\t\tnode[i] = nodef(node[i\
    \ << 1], node[i << 1 | 1]);\n\t}\n\ttemplate <class U>\n\tSegTree(const std::vector<U>&\
    \ initvec, T e_) : ident(e_) {\n\t\tunsigned int m = initvec.size();\n\t\twhile\
    \ (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2 * n, ident);\n\
    \t\tfor (unsigned int i = n; i < 2 * n; i++) {\n\t\t\tif (i - n < m) node[i] =\
    \ initvec[i - n];\n\t\t}\n\t\tfor (unsigned int i = n - 1; i > 0; i--)\n\t\t\t\
    node[i] = nodef(node[i << 1], node[i << 1 | 1]);\n\t}\n\tvoid update(int i, T\
    \ x) {\n\t\ti += n;\n\t\tnode[i] = x;\n\t\twhile (i != 1) {\n\t\t\ti >>= 1;\n\t\
    \t\tnode[i] = nodef(node[2 * i], node[2 * i + 1]);\n\t\t}\n\t}\n\tT query(int\
    \ l, int r) const {\n\t\tl += n;\n\t\tr += n;\n\t\tT ls = ident, rs = ident;\n\
    \t\twhile (l < r) {\n\t\t\tif (l & 1) ls = nodef(ls, node[l++]);\n\t\t\tif (r\
    \ & 1) rs = nodef(node[--r], rs);\n\t\t\tl >>= 1;\n\t\t\tr >>= 1;\n\t\t}\n\t\t\
    return nodef(ls, rs);\n\t}\n\tconst T& operator[](const int& x) const { return\
    \ node[n + x]; }\n\tT queryForAll() const { return node[1]; }\n\n  private:\n\t\
    template <class F>\n\tint max_right(int st, F& check, T& acc, int k, int l, int\
    \ r) const {\n\t\tif (l + 1 == r) {\n\t\t\tacc = nodef(acc, node[k]);\n\t\t\t\
    return check(acc) ? -1 : k - n;\n\t\t}\n\t\tint m = (l + r) >> 1;\n\t\tif (m <=\
    \ st) return max_right(st, check, acc, (k << 1) | 1, m, r);\n\t\tif (st <= l &&\
    \ check(nodef(acc, node[k]))) {\n\t\t\tacc = nodef(acc, node[k]);\n\t\t\treturn\
    \ -1;\n\t\t}\n\t\tint vl = max_right(st, check, acc, k << 1, l, m);\n\t\tif (vl\
    \ != -1) return vl;\n\t\treturn max_right(st, check, acc, (k << 1) | 1, m, r);\n\
    \t}\n\n  public:\n\ttemplate <class F>\n\tint max_right(int st, F check) const\
    \ {\n\t\tT acc = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\t}\n\
    \ttemplate <bool (*check)(const T&)>\n\tint max_right(int st) const {\n\t\tT acc\
    \ = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\t}\n};\nstatic lint\
    \ RSQ_nodef(const lint& lhs, const lint& rhs) { return lhs + rhs; }\nclass RSQ\
    \ : public SegTree<lint, RSQ_nodef> {\n\tusing Base = SegTree<lint, RSQ_nodef>;\n\
    \n  public:\n\ttemplate <class... Args>\n\tRSQ(Args&&... args) : Base(std::forward<Args>(args)...,\
    \ 0) {}\n};\nstatic lint RMiQ_nodef(const lint& lhs, const lint& rhs) {\n\treturn\
    \ std::min(lhs, rhs);\n}\nclass RMiQ : public SegTree<lint, RMiQ_nodef> {\n\t\
    using Base = SegTree<lint, RMiQ_nodef>;\n\n  public:\n\ttemplate <class... Args>\n\
    \tRMiQ(Args&&... args) : Base(std::forward<Args>(args)..., LINF) {}\n};\nstatic\
    \ lint RMaQ_nodef(const lint& lhs, const lint& rhs) {\n\treturn std::max(lhs,\
    \ rhs);\n}\nclass RMaQ : public SegTree<lint, RMaQ_nodef> {\n\tusing Base = SegTree<lint,\
    \ RMaQ_nodef>;\n\n  public:\n\ttemplate <class... Args>\n\tRMaQ(Args&&... args)\
    \ : Base(std::forward<Args>(args)..., -LINF) {}\n};\n#line 4 \"test/aoj/DSL_2_A.test.cpp\"\
    \nint n, q;\nint main() {\n\tscanf(\"%d%d\", &n, &q);\n\tRMiQ st(n, INT_MAX);\n\
    \trep(i, q) {\n\t\tint com, x, y;\n\t\tscanf(\"%d%d%d\", &com, &x, &y);\n\t\t\
    if (com == 0)\n\t\t\tst.update(x, y);\n\t\telse\n\t\t\tprintf(\"%d\\n\", st.query(x,\
    \ y + 1));\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A\"\n#include\
    \ \"../../data-structure/SegTree.hpp\"\n#include \"../../other/template.hpp\"\n\
    int n, q;\nint main() {\n\tscanf(\"%d%d\", &n, &q);\n\tRMiQ st(n, INT_MAX);\n\t\
    rep(i, q) {\n\t\tint com, x, y;\n\t\tscanf(\"%d%d%d\", &com, &x, &y);\n\t\tif\
    \ (com == 0)\n\t\t\tst.update(x, y);\n\t\telse\n\t\t\tprintf(\"%d\\n\", st.query(x,\
    \ y + 1));\n\t}\n}"
  dependsOn:
  - data-structure/SegTree.hpp
  - other/template.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2021-01-06 23:31:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.test.cpp
- /verify/test/aoj/DSL_2_A.test.cpp.html
title: test/aoj/DSL_2_A.test.cpp
---
