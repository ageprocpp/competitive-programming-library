---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/IntervalSegTree.hpp
    title: data-structure/IntervalSegTree.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E
  bundledCode: "#line 1 \"test/aoj/DSL_2_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E\"\
    \n#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#pragma target(\"\
    avx2\")\n#pragma optimize(\"O3\")\n#pragma optimize(\"unroll-loops\")\n#include\
    \ <string.h>\n#include <algorithm>\n#include <bitset>\n#include <cassert>\n#include\
    \ <cfloat>\n#include <climits>\n#include <cmath>\n#include <complex>\n#include\
    \ <ctime>\n#include <deque>\n#include <fstream>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <iterator>\n#include <list>\n#include\
    \ <map>\n#include <memory>\n#include <queue>\n#include <random>\n#include <set>\n\
    #include <stack>\n#include <string>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n#define rep(i, n) for (int i = 0; i < (n);\
    \ i++)\n#define REP(i, n) for (int i = 1; i <= (n); i++)\n#define all(V) V.begin(),\
    \ V.end()\ntypedef unsigned int uint;\ntypedef long long lint;\ntypedef unsigned\
    \ long long ulint;\ntypedef std::pair<int, int> P;\ntypedef std::pair<lint, lint>\
    \ LP;\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF = LLONG_MAX / 2;\n\
    constexpr double eps = DBL_EPSILON;\nconstexpr double PI = 3.141592653589793238462643383279;\n\
    template <class T>\nclass prique : public std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> {\n};\ntemplate <typename F>\ninline constexpr decltype(auto)\
    \ lambda_fix(F&& f) {\n\treturn [f = std::forward<F>(f)](auto&&... args) {\n\t\
    \treturn f(f, std::forward<decltype(args)>(args)...);\n\t};\n}\ntemplate <typename\
    \ T>\nstd::vector<T> make_vec(size_t n) {\n\treturn std::vector<T>(n);\n}\ntemplate\
    \ <typename T, class... Args>\nauto make_vec(size_t n, Args&&... args) {\n\treturn\
    \ std::vector<decltype(make_vec<T>(args...))>(\n\t\tn, make_vec<T>(std::forward<Args>(args)...));\n\
    }\ntemplate <class T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\t\
    if (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\n\
    template <class T, class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs\
    \ > rhs) {\n\t\tlhs = rhs;\n\t\treturn true;\n\t}\n\treturn false;\n}\ninline\
    \ lint gcd(lint a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b;\n\t\t\
    b = c % b;\n\t}\n\treturn a;\n}\ninline lint lcm(lint a, lint b) { return a /\
    \ gcd(a, b) * b; }\nbool isprime(lint n) {\n\tif (n == 1) return false;\n\tfor\
    \ (int i = 2; i * i <= n; i++) {\n\t\tif (n % i == 0) return false;\n\t}\n\treturn\
    \ true;\n}\ntemplate <typename T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile\
    \ (b) {\n\t\tif (b & 1) res *= a;\n\t\ta *= a;\n\t\tb >>= 1;\n\t}\n\treturn res;\n\
    }\nlint modpow(lint a, lint b, lint m) {\n\tlint res(1);\n\twhile (b) {\n\t\t\
    if (b & 1) {\n\t\t\tres *= a;\n\t\t\tres %= m;\n\t\t}\n\t\ta *= a;\n\t\ta %= m;\n\
    \t\tb >>= 1;\n\t}\n\treturn res;\n}\ntemplate <typename T>\nvoid printArray(std::vector<T>&\
    \ vec) {\n\trep(i, vec.size()) {\n\t\tstd::cout << vec[i];\n\t\tstd::cout << (i\
    \ == (int)vec.size() - 1 ? \"\\n\" : \" \");\n\t}\n}\ntemplate <typename T>\n\
    void printArray(T l, T r) {\n\tT rprev = std::prev(r);\n\tfor (T i = l; i != r;\
    \ i++) {\n\t\tstd::cout << *i;\n\t\tstd::cout << (i == rprev ? \"\\n\" : \" \"\
    );\n\t}\n}\nLP extGcd(lint a, lint b) {\n\tif (b == 0) return {1, 0};\n\tLP s\
    \ = extGcd(b, a % b);\n\tstd::swap(s.first, s.second);\n\ts.second -= a / b *\
    \ s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1, const lint& m1, const\
    \ lint& b2, const lint& m2) {\n\tlint p = extGcd(m1, m2).first;\n\tlint tmp =\
    \ (b2 - b1) * p % m2;\n\tlint r = (b1 + m1 * tmp + m1 * m2) % (m1 * m2);\n\treturn\
    \ std::make_pair(r, m1 * m2);\n}\nint LCS(const std::string& a, const std::string&\
    \ b) {\n\tauto dp = make_vec<int>(a.size() + 1, b.size() + 1);\n\trep(i, a.size())\
    \ {\n\t\trep(j, b.size()) {\n\t\t\tchmax(dp[i + 1][j], dp[i][j]);\n\t\t\tchmax(dp[i][j\
    \ + 1], dp[i][j]);\n\t\t\tif (a[i] == b[j]) chmax(dp[i + 1][j + 1], dp[i][j] +\
    \ 1);\n\t\t}\n\t\tchmax(dp[i + 1][b.size()], dp[i][b.size()]);\n\t}\n\trep(j,\
    \ b.size()) chmax(dp[a.size()][j + 1], dp[a.size()][j]);\n\treturn dp[a.size()][b.size()];\n\
    }\n#line 3 \"data-structure/SegTree.hpp\"\ntemplate <typename T, T (*nodef)(const\
    \ T&, const T&)>\nclass SegTree {\n  protected:\n\tunsigned int n = 1, rank =\
    \ 0;\n\tstd::vector<T> node;\n\tT ident;\n\n  public:\n\tSegTree(unsigned int\
    \ m, T init, T e_) : ident(e_) {\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\
    \t\t}\n\t\tnode.resize(2 * n, ident);\n\t\tfor (unsigned int i = n; i < 2 * n;\
    \ i++) node[i] = init;\n\t\tfor (unsigned int i = n - 1; i > 0; i--)\n\t\t\tnode[i]\
    \ = nodef(node[i << 1], node[i << 1 | 1]);\n\t}\n\ttemplate <typename U>\n\tSegTree(const\
    \ std::vector<U>& initvec, T e_) : ident(e_) {\n\t\tunsigned int m = initvec.size();\n\
    \t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2 *\
    \ n, ident);\n\t\tfor (unsigned int i = n; i < 2 * n; i++) {\n\t\t\tif (i - n\
    \ < m) node[i] = initvec[i - n];\n\t\t}\n\t\tfor (unsigned int i = n - 1; i >\
    \ 0; i--)\n\t\t\tnode[i] = nodef(node[i << 1], node[i << 1 | 1]);\n\t}\n\tvoid\
    \ update(int i, T x) {\n\t\ti += n;\n\t\tnode[i] = x;\n\t\twhile (i != 1) {\n\t\
    \t\ti >>= 1;\n\t\t\tnode[i] = nodef(node[2 * i], node[2 * i + 1]);\n\t\t}\n\t\
    }\n\tT query(int l, int r) const {\n\t\tl += n;\n\t\tr += n;\n\t\tT ls = ident,\
    \ rs = ident;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ls = nodef(ls, node[l++]);\n\
    \t\t\tif (r & 1) rs = nodef(node[--r], rs);\n\t\t\tl >>= 1;\n\t\t\tr >>= 1;\n\t\
    \t}\n\t\treturn nodef(ls, rs);\n\t}\n\tT operator[](const int& x) const { return\
    \ node[n + x]; }\n\tT queryForAll() const { return node[1]; }\n\n  private:\n\t\
    template <typename F>\n\tint max_right(int st, F& check, T& acc, int k, int l,\
    \ int r) const {\n\t\tif (l + 1 == r) {\n\t\t\tacc = nodef(acc, node[k]);\n\t\t\
    \treturn check(acc) ? -1 : k - n;\n\t\t}\n\t\tint m = (l + r) >> 1;\n\t\tif (m\
    \ <= st) return max_right(st, check, acc, (k << 1) | 1, m, r);\n\t\tif (st <=\
    \ l && check(nodef(acc, node[k]))) {\n\t\t\tacc = nodef(acc, node[k]);\n\t\t\t\
    return -1;\n\t\t}\n\t\tint vl = max_right(st, check, acc, k << 1, l, m);\n\t\t\
    if (vl != -1) return vl;\n\t\treturn max_right(st, check, acc, (k << 1) | 1, m,\
    \ r);\n\t}\n\n  public:\n\ttemplate <typename F>\n\tint max_right(int st, F check)\
    \ const {\n\t\tT acc = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\
    \t}\n\ttemplate <bool (*check)(const T&)>\n\tint max_right(int st) const {\n\t\
    \tT acc = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\t}\n};\nstatic\
    \ lint RSQ_nodef(const lint& lhs, const lint& rhs) { return lhs + rhs; }\nclass\
    \ RSQ : public SegTree<lint, RSQ_nodef> {\n\tusing Base = SegTree<lint, RSQ_nodef>;\n\
    \n  public:\n\ttemplate <class... Args>\n\tRSQ(Args&&... args) : Base(std::forward<Args>(args)...,\
    \ 0) {}\n};\nstatic lint RMiQ_nodef(const lint& lhs, const lint& rhs) {\n\treturn\
    \ std::min(lhs, rhs);\n}\nclass RMiQ : public SegTree<lint, RMiQ_nodef> {\n\t\
    using Base = SegTree<lint, RMiQ_nodef>;\n\n  public:\n\ttemplate <class... Args>\n\
    \tRMiQ(Args&&... args) : Base(std::forward<Args>(args)..., LINF) {}\n};\nstatic\
    \ lint RMaQ_nodef(const lint& lhs, const lint& rhs) {\n\treturn std::max(lhs,\
    \ rhs);\n}\nclass RMaQ : public SegTree<lint, RMaQ_nodef> {\n\tusing Base = SegTree<lint,\
    \ RMaQ_nodef>;\n\n  public:\n\ttemplate <class... Args>\n\tRMaQ(Args&&... args)\
    \ : Base(std::forward<Args>(args)..., -LINF) {}\n};\n#line 4 \"data-structure/IntervalSegTree.hpp\"\
    \ntemplate <typename T, typename U, T (*nodef)(const T&, const T&),\n\t\t  void\
    \ (*lazyf)(U&, const U&),\n\t\t  void (*updf)(T&, const U&, const unsigned int&)>\n\
    class IntervalSegTree : public SegTree<T, nodef> {\n\tusing Base = SegTree<T,\
    \ nodef>;\n\tusing Base::ident;\n\tusing Base::n;\n\tusing Base::node;\n\tusing\
    \ Base::rank;\n\tstd::vector<U> lazy;\n\tstd::vector<bool> lazyflag;\n\tstd::vector<int>\
    \ width;\n\tvoid eval(int k) {\n\t\tfor (int i = rank; i > 0; i--) {\n\t\t\tint\
    \ nk = k >> i;\n\t\t\tif (lazyflag[nk]) {\n\t\t\t\tupdf(node[2 * nk], lazy[nk],\
    \ width[2 * nk]);\n\t\t\t\tupdf(node[2 * nk + 1], lazy[nk], width[2 * nk + 1]);\n\
    \t\t\t\tif (lazyflag[2 * nk])\n\t\t\t\t\tlazyf(lazy[2 * nk], lazy[nk]);\n\t\t\t\
    \telse\n\t\t\t\t\tlazy[2 * nk] = lazy[nk];\n\t\t\t\tif (lazyflag[2 * nk + 1])\n\
    \t\t\t\t\tlazyf(lazy[2 * nk + 1], lazy[nk]);\n\t\t\t\telse\n\t\t\t\t\tlazy[2 *\
    \ nk + 1] = lazy[nk];\n\t\t\t\tlazyflag[2 * nk] = lazyflag[2 * nk + 1] = true;\n\
    \t\t\t\tlazyflag[nk] = false;\n\t\t\t}\n\t\t}\n\t}\n\n  public:\n\tIntervalSegTree(unsigned\
    \ int m, T e_) : Base(m, T(), e_) {\n\t\tlazy.resize(2 * n);\n\t\tlazyflag.resize(2\
    \ * n);\n\t\twidth.resize(2 * n);\n\t\twidth[1] = n;\n\t\tfor (unsigned int i\
    \ = 2; i < 2 * n; i++) {\n\t\t\twidth[i] = width[i >> 1] >> 1;\n\t\t}\n\t}\n\t\
    IntervalSegTree(unsigned int m, T init, T e_) : Base(m, init, e_) {\n\t\tlazy.resize(2\
    \ * n);\n\t\tlazyflag.resize(2 * n);\n\t\twidth.resize(2 * n);\n\t\twidth[1] =\
    \ n;\n\t\tfor (unsigned int i = 2; i < 2 * n; i++) {\n\t\t\twidth[i] = width[i\
    \ >> 1] >> 1;\n\t\t}\n\t}\n\tIntervalSegTree(const std::vector<T>& initvec, T\
    \ e_) : Base(initvec, e_) {\n\t\tlazy.resize(2 * n);\n\t\tlazyflag.resize(2 *\
    \ n);\n\t\twidth.resize(2 * n);\n\t\twidth[1] = n;\n\t\tfor (unsigned int i =\
    \ 2; i < 2 * n; i++) {\n\t\t\twidth[i] = width[i >> 1] >> 1;\n\t\t}\n\t}\n\tvoid\
    \ update(int i, U x) {\n\t\ti += n;\n\t\teval(i);\n\t\tupdf(node[i], x, width[i]);\n\
    \t\tif (lazyflag[i])\n\t\t\tlazyf(lazy[i], x);\n\t\telse {\n\t\t\tlazyflag[i]\
    \ = true;\n\t\t\tlazy[i] = x;\n\t\t}\n\t\twhile (i /= 2) node[i] = nodef(node[2\
    \ * i], node[2 * i + 1]);\n\t}\n\tvoid update(int l, int r, U x) {\n\t\tl += n;\n\
    \t\tr += n;\n\t\tint nl = l, nr = r;\n\t\twhile (!(nl & 1)) nl >>= 1;\n\t\twhile\
    \ (!(nr & 1)) nr >>= 1;\n\t\tnr--;\n\t\teval(nl);\n\t\teval(nr);\n\t\twhile (l\
    \ < r) {\n\t\t\tif (l & 1) {\n\t\t\t\tupdf(node[l], x, width[l]);\n\t\t\t\tif\
    \ (lazyflag[l])\n\t\t\t\t\tlazyf(lazy[l], x);\n\t\t\t\telse {\n\t\t\t\t\tlazyflag[l]\
    \ = true;\n\t\t\t\t\tlazy[l] = x;\n\t\t\t\t}\n\t\t\t\tl++;\n\t\t\t}\n\t\t\tif\
    \ (r & 1) {\n\t\t\t\tr--;\n\t\t\t\tupdf(node[r], x, width[r]);\n\t\t\t\tif (lazyflag[r])\n\
    \t\t\t\t\tlazyf(lazy[r], x);\n\t\t\t\telse {\n\t\t\t\t\tlazyflag[r] = true;\n\t\
    \t\t\t\tlazy[r] = x;\n\t\t\t\t}\n\t\t\t}\n\t\t\tl >>= 1;\n\t\t\tr >>= 1;\n\t\t\
    }\n\t\twhile (nl >>= 1) node[nl] = nodef(node[2 * nl], node[2 * nl + 1]);\n\t\t\
    while (nr >>= 1) node[nr] = nodef(node[2 * nr], node[2 * nr + 1]);\n\t}\n\tT query(int\
    \ l, int r) {\n\t\tl += n;\n\t\tr += n;\n\t\teval(l);\n\t\teval(r - 1);\n\t\t\
    T ls = ident, rs = ident;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ls = nodef(ls,\
    \ node[l++]);\n\t\t\tif (r & 1) rs = nodef(node[--r], rs);\n\t\t\tl >>= 1;\n\t\
    \t\tr >>= 1;\n\t\t}\n\t\treturn nodef(ls, rs);\n\t}\n\tT operator[](const int&\
    \ x) {\n\t\teval(n + x);\n\t\treturn node[n + x];\n\t}\n\n  private:\n\ttemplate\
    \ <typename F>\n\tint max_right(int st, F& check, T& acc, int k, int l, int r)\
    \ {\n\t\teval(k);\n\t\tif (l + 1 == r) {\n\t\t\tacc = nodef(acc, node[k]);\n\t\
    \t\treturn check(acc) ? -1 : k - n;\n\t\t}\n\t\tint m = (l + r) >> 1;\n\t\tif\
    \ (m <= st) return max_right(st, check, acc, (k << 1) | 1, m, r);\n\t\tif (st\
    \ <= l && check(nodef(acc, node[k]))) {\n\t\t\tacc = nodef(acc, node[k]);\n\t\t\
    \treturn -1;\n\t\t}\n\t\tint vl = max_right(st, check, acc, k << 1, l, m);\n\t\
    \tif (vl != -1) return vl;\n\t\treturn max_right(st, check, acc, (k << 1) | 1,\
    \ m, r);\n\t}\n\n  public:\n\ttemplate <typename F>\n\tint max_right(int st, F\
    \ check) {\n\t\tT acc = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\
    \t}\n\ttemplate <bool (*check)(const T&)>\n\tint max_right(int st) {\n\t\tT acc\
    \ = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\t}\n};\nstatic lint\
    \ RAQRSQ_nodef(const lint& a, const lint& b) { return a + b; }\nstatic void RAQRSQ_lazyf(lint&\
    \ a, const lint& b) { a += b; }\nstatic void RAQRSQ_updf(lint& a, const lint&\
    \ b, const unsigned int& width) {\n\ta += width * b;\n}\nclass RAQRSQ : public\
    \ IntervalSegTree<lint, lint, RAQRSQ_nodef, RAQRSQ_lazyf,\n\t\t\t\t\t\t\t\t\t\
    \  RAQRSQ_updf> {\n\tusing Base =\n\t\tIntervalSegTree<lint, lint, RAQRSQ_nodef,\
    \ RAQRSQ_lazyf, RAQRSQ_updf>;\n\n  public:\n\ttemplate <class... Args>\n\tRAQRSQ(Args&&...\
    \ args) : Base(std::forward<Args>(args)..., 0) {}\n};\nstatic lint RAQRMiQ_nodef(const\
    \ lint& a, const lint& b) {\n\treturn std::min(a, b);\n}\nstatic void RAQRMiQ_lazyf(lint&\
    \ a, const lint& b) { a += b; }\nstatic void RAQRMiQ_updf(lint& a, const lint&\
    \ b, const unsigned int& width) {\n\ta += b;\n}\nclass RAQRMiQ : public IntervalSegTree<lint,\
    \ lint, RAQRMiQ_nodef, RAQRMiQ_lazyf,\n\t\t\t\t\t\t\t\t\t   RAQRMiQ_updf> {\n\t\
    using Base =\n\t\tIntervalSegTree<lint, lint, RAQRMiQ_nodef, RAQRMiQ_lazyf, RAQRMiQ_updf>;\n\
    \n  public:\n\ttemplate <class... Args>\n\tRAQRMiQ(Args&&... args) : Base(std::forward<Args>(args)...,\
    \ LINF) {}\n};\nstatic lint RAQRMaQ_nodef(const lint& a, const lint& b) {\n\t\
    return std::max(a, b);\n}\nstatic void RAQRMaQ_lazyf(lint& a, const lint& b) {\
    \ a += b; }\nstatic void RAQRMaQ_updf(lint& a, const lint& b, const unsigned int&\
    \ width) {\n\ta += b;\n}\nclass RAQRMaQ : public IntervalSegTree<lint, lint, RAQRMaQ_nodef,\
    \ RAQRMaQ_lazyf,\n\t\t\t\t\t\t\t\t\t   RAQRMaQ_updf> {\n\tusing Base =\n\t\tIntervalSegTree<lint,\
    \ lint, RAQRMaQ_nodef, RAQRMaQ_lazyf, RAQRMaQ_updf>;\n\n  public:\n\ttemplate\
    \ <class... Args>\n\tRAQRMaQ(Args&&... args) : Base(std::forward<Args>(args)...,\
    \ -LINF) {}\n};\nstatic lint RUQRSQ_nodef(const lint& a, const lint& b) { return\
    \ a + b; }\nstatic void RUQRSQ_lazyf(lint& a, const lint& b) { a = b; }\nstatic\
    \ void RUQRSQ_updf(lint& a, const lint& b, const unsigned int& width) {\n\ta =\
    \ width * b;\n}\nclass RUQRSQ : public IntervalSegTree<lint, lint, RUQRSQ_nodef,\
    \ RUQRSQ_lazyf,\n\t\t\t\t\t\t\t\t\t  RUQRSQ_updf> {\n\tusing Base =\n\t\tIntervalSegTree<lint,\
    \ lint, RUQRSQ_nodef, RUQRSQ_lazyf, RUQRSQ_updf>;\n\n  public:\n\ttemplate <class...\
    \ Args>\n\tRUQRSQ(Args&&... args) : Base(std::forward<Args>(args)..., 0) {}\n\
    };\nstatic lint RUQRMiQ_nodef(const lint& a, const lint& b) {\n\treturn std::min(a,\
    \ b);\n}\nstatic void RUQRMiQ_lazyf(lint& a, const lint& b) { a = b; }\nstatic\
    \ void RUQRMiQ_updf(lint& a, const lint& b, const unsigned int& width) {\n\ta\
    \ = b;\n}\nclass RUQRMiQ : public IntervalSegTree<lint, lint, RUQRMiQ_nodef, RUQRMiQ_lazyf,\n\
    \t\t\t\t\t\t\t\t\t   RUQRMiQ_updf> {\n\tusing Base =\n\t\tIntervalSegTree<lint,\
    \ lint, RUQRMiQ_nodef, RUQRMiQ_lazyf, RUQRMiQ_updf>;\n\n  public:\n\ttemplate\
    \ <class... Args>\n\tRUQRMiQ(Args&&... args) : Base(std::forward<Args>(args)...,\
    \ LINF) {}\n};\nstatic lint RUQRMaQ_nodef(const lint& a, const lint& b) {\n\t\
    return std::max(a, b);\n}\nstatic void RUQRMaQ_lazyf(lint& a, const lint& b) {\
    \ a = b; }\nstatic void RUQRMaQ_updf(lint& a, const lint& b, const unsigned int&\
    \ width) {\n\ta = b;\n}\nclass RUQRMaQ : public IntervalSegTree<lint, lint, RUQRMaQ_nodef,\
    \ RUQRMaQ_lazyf,\n\t\t\t\t\t\t\t\t\t   RUQRMaQ_updf> {\n\tusing Base =\n\t\tIntervalSegTree<lint,\
    \ lint, RUQRMaQ_nodef, RUQRMaQ_lazyf, RUQRMaQ_updf>;\n\n  public:\n\ttemplate\
    \ <class... Args>\n\tRUQRMaQ(Args&&... args) : Base(std::forward<Args>(args)...,\
    \ -LINF) {}\n};\n#line 4 \"test/aoj/DSL_2_E.test.cpp\"\nint n, q;\nint main()\
    \ {\n\tscanf(\"%d%d\", &n, &q);\n\tRAQRSQ st(n, 0);\n\trep(i, q) {\n\t\tint t;\n\
    \t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\tint s, t, x;\n\t\t\tscanf(\"\
    %d%d%d\", &s, &t, &x);\n\t\t\tst.update(s - 1, t, x);\n\t\t} else {\n\t\t\tint\
    \ p;\n\t\t\tscanf(\"%d\", &p);\n\t\t\tprintf(\"%d\\n\", st[p - 1]);\n\t\t}\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E\"\n#include\
    \ \"../../data-structure/IntervalSegTree.hpp\"\n#include \"../../other/template.hpp\"\
    \nint n, q;\nint main() {\n\tscanf(\"%d%d\", &n, &q);\n\tRAQRSQ st(n, 0);\n\t\
    rep(i, q) {\n\t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\tint\
    \ s, t, x;\n\t\t\tscanf(\"%d%d%d\", &s, &t, &x);\n\t\t\tst.update(s - 1, t, x);\n\
    \t\t} else {\n\t\t\tint p;\n\t\t\tscanf(\"%d\", &p);\n\t\t\tprintf(\"%d\\n\",\
    \ st[p - 1]);\n\t\t}\n\t}\n}"
  dependsOn:
  - data-structure/IntervalSegTree.hpp
  - other/template.hpp
  - data-structure/SegTree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_E.test.cpp
  requiredBy: []
  timestamp: '2020-12-15 16:49:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_E.test.cpp
- /verify/test/aoj/DSL_2_E.test.cpp.html
title: test/aoj/DSL_2_E.test.cpp
---
