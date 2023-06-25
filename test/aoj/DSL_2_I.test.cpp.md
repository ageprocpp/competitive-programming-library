---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: basic/template.hpp
    title: basic/template.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/IntervalSegTree.hpp
    title: Interval Segment Tree
  - icon: ':heavy_check_mark:'
    path: data-structure/SegTree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I
  bundledCode: "#line 1 \"test/aoj/DSL_2_I.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I\"\
    \n#line 2 \"basic/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n\
    #pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n#endif\n\
    #include <string.h>\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cfloat>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <complex>\n#include <ctime>\n#include <deque>\n#include\
    \ <fstream>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include <string>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n\n#define rep(i, n) for (int i = 0; i < int(n); i++)\n#define REP(i,\
    \ n) for (int i = 1; i <= int(n); i++)\n#define all(V) V.begin(), V.end()\n\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\nusing uint = unsigned int;\n\
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
    }\n#line 3 \"data-structure/SegTree.hpp\"\ntemplate <class T, T (*nodef)(const\
    \ T&, const T&)>\nclass SegTree {\n  protected:\n\tunsigned int n = 1, m = 1,\
    \ rank = 0;\n\tstd::vector<T> node;\n\tT ident;\n\n  public:\n\tSegTree(T e_)\
    \ : ident(e_) {}\n\tSegTree(unsigned int m_, T e_) : m(m_), ident(e_) {\n\t\t\
    while (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2 * n, ident);\n\
    \t}\n\tSegTree(unsigned int m_, T init, T e_) : m(m_), ident(e_) {\n\t\twhile\
    \ (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2 * n, ident);\n\
    \t\tfor (unsigned int i = n; i < 2 * n; i++) node[i] = init;\n\t\tfor (unsigned\
    \ int i = n - 1; i > 0; i--) node[i] = nodef(node[i << 1], node[i << 1 | 1]);\n\
    \t}\n\ttemplate <class U>\n\tSegTree(const std::vector<U>& initvec, T e_) : ident(e_)\
    \ {\n\t\tm = initvec.size();\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\
    \t\t}\n\t\tnode.resize(2 * n, ident);\n\t\tfor (unsigned int i = n; i < 2 * n;\
    \ i++) {\n\t\t\tif (i - n < m) node[i] = initvec[i - n];\n\t\t}\n\t\tfor (unsigned\
    \ int i = n - 1; i > 0; i--) node[i] = nodef(node[i << 1], node[i << 1 | 1]);\n\
    \t}\n\tvoid update(int i, T x) {\n\t\ti += n;\n\t\tnode[i] = x;\n\t\twhile (i\
    \ != 1) {\n\t\t\ti >>= 1;\n\t\t\tnode[i] = nodef(node[2 * i], node[2 * i + 1]);\n\
    \t\t}\n\t}\n\tT query(int l, int r) const {\n\t\tl += n;\n\t\tr += n;\n\t\tT ls\
    \ = ident, rs = ident;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ls = nodef(ls, node[l++]);\n\
    \t\t\tif (r & 1) rs = nodef(node[--r], rs);\n\t\t\tl >>= 1;\n\t\t\tr >>= 1;\n\t\
    \t}\n\t\treturn nodef(ls, rs);\n\t}\n\tconst T& operator[](const int& i) const\
    \ { return node[n + i]; }\n\tT query_all() const { return node[1]; }\n\tvoid fill(T\
    \ x) {\n\t\tfor (unsigned int i = n; i < 2 * n; i++) node[i] = x;\n\t\tfor (unsigned\
    \ int i = n - 1; i > 0; i--) node[i] = nodef(node[i << 1], node[i << 1 | 1]);\n\
    \t}\n\n  private:\n\ttemplate <class F>\n\tint max_right(int st, F& check, T&\
    \ acc, int k, int l, int r) const {\n\t\tif (l + 1 == r) {\n\t\t\tacc = nodef(acc,\
    \ node[k]);\n\t\t\treturn check(acc) ? m : k - n;\n\t\t}\n\t\tint mid = (l + r)\
    \ >> 1;\n\t\tif (mid <= st) return max_right(st, check, acc, (k << 1) | 1, mid,\
    \ r);\n\t\tif (st <= l && check(nodef(acc, node[k]))) {\n\t\t\tacc = nodef(acc,\
    \ node[k]);\n\t\t\treturn m;\n\t\t}\n\t\tint vl = max_right(st, check, acc, k\
    \ << 1, l, mid);\n\t\tif (vl != m) return vl;\n\t\treturn max_right(st, check,\
    \ acc, (k << 1) | 1, mid, r);\n\t}\n\n\ttemplate <class F>\n\tint min_left(int\
    \ st, F& check, T& acc, int k, int l, int r) const {\n\t\tif (l + 1 == r) {\n\t\
    \t\tacc = nodef(node[k], acc);\n\t\t\treturn check(acc) ? 0 : k - n + 1;\n\t\t\
    }\n\t\tint mid = (l + r) >> 1;\n\t\tif (st <= mid) return min_left(st, check,\
    \ acc, k << 1, l, mid);\n\t\tif (r <= st && check(nodef(node[k], acc))) {\n\t\t\
    \tacc = nodef(node[k], acc);\n\t\t\treturn 0;\n\t\t}\n\t\tint vr = min_left(st,\
    \ check, acc, (k << 1) | 1, mid, r);\n\t\tif (vr != 0) return vr;\n\t\treturn\
    \ min_left(st, check, acc, k << 1, l, mid);\n\t}\n\n  public:\n\ttemplate <class\
    \ F>\n\tint max_right(int st, F check) const {\n\t\tT acc = ident;\n\t\treturn\
    \ max_right(st, check, acc, 1, 0, n);\n\t}\n\ttemplate <bool (*check)(const T&)>\n\
    \tint max_right(int st) const {\n\t\tT acc = ident;\n\t\treturn max_right(st,\
    \ check, acc, 1, 0, n);\n\t}\n\n\ttemplate <class F>\n\tint min_left(int st, F\
    \ check) const {\n\t\tT acc = ident;\n\t\treturn min_left(st, check, acc, 1, 0,\
    \ n);\n\t}\n\ttemplate <bool (*check)(const T&)>\n\tint min_left(int st) const\
    \ {\n\t\tT acc = ident;\n\t\treturn min_left(st, check, acc, 1, 0, n);\n\t}\n\
    };\nnamespace {\n\ttemplate <typename T>\n\tT RSQ_nodef(const T& lhs, const T&\
    \ rhs) {\n\t\treturn lhs + rhs;\n\t}\n\ttemplate <typename T>\n\tT RMiQ_nodef(const\
    \ T& lhs, const T& rhs) {\n\t\treturn std::min(lhs, rhs);\n\t}\n\ttemplate <typename\
    \ T>\n\tT RMaQ_nodef(const T& lhs, const T& rhs) {\n\t\treturn std::max(lhs, rhs);\n\
    \t}\n}  // namespace\n\ntemplate <typename T>\nclass RSQ : public SegTree<T, RSQ_nodef>\
    \ {\n\tusing Base = SegTree<T, RSQ_nodef>;\n\n  public:\n\ttemplate <class...\
    \ Args>\n\tRSQ(Args&&... args) : Base(std::forward<Args>(args)..., 0) {}\n};\n\
    \ntemplate <typename T, typename U = void>\nclass RMiQ : public SegTree<T, RMiQ_nodef>\
    \ {\n\tusing Base = SegTree<T, RMiQ_nodef>;\n\n  public:\n\ttemplate <class...\
    \ Args>\n\tRMiQ(Args&&... args) : Base(std::forward<Args>(args)...) {}\n};\ntemplate\
    \ <typename T>\nclass RMiQ<T, std::enable_if_t<std::numeric_limits<T>::is_specialized>>\n\
    \t: public SegTree<T, RMiQ_nodef> {\n\tusing Base = SegTree<T, RMiQ_nodef>;\n\n\
    \  public:\n\ttemplate <class... Args>\n\tRMiQ(Args&&... args) : Base(std::forward<Args>(args)...,\
    \ std::numeric_limits<T>::max()) {}\n};\n\ntemplate <typename T, typename U =\
    \ void>\nclass RMaQ : public SegTree<T, RMaQ_nodef> {\n\tusing Base = SegTree<T,\
    \ RMaQ_nodef>;\n\n  public:\n\ttemplate <class... Args>\n\tRMaQ(Args&&... args)\
    \ : Base(std::forward<Args>(args)...) {}\n};\ntemplate <typename T>\nclass RMaQ<T,\
    \ std::enable_if_t<std::numeric_limits<T>::is_specialized>>\n\t: public SegTree<T,\
    \ RMaQ_nodef> {\n\tusing Base = SegTree<T, RMaQ_nodef>;\n\n  public:\n\ttemplate\
    \ <class... Args>\n\tRMaQ(Args&&... args) : Base(std::forward<Args>(args)...,\
    \ std::numeric_limits<T>::min()) {}\n};\n#line 4 \"data-structure/IntervalSegTree.hpp\"\
    \ntemplate <class T, class U, T (*nodef)(const T&, const T&),\n\t\t  void (*lazyf)(U&,\
    \ const U&),\n\t\t  void (*updf)(T&, const U&, const unsigned int&)>\nclass IntervalSegTree\
    \ : public SegTree<T, nodef> {\n\tusing Base = SegTree<T, nodef>;\n\tusing Base::ident;\n\
    \tusing Base::n;\n\tusing Base::node;\n\tusing Base::rank;\n\tstd::vector<U> lazy;\n\
    \tstd::vector<bool> lazyflag;\n\tstd::vector<int> width;\n\tvoid eval(int k) {\n\
    \t\tfor (int i = rank; i > 0; i--) {\n\t\t\tint nk = k >> i;\n\t\t\tif (lazyflag[nk])\
    \ {\n\t\t\t\tupdf(node[2 * nk], lazy[nk], width[2 * nk]);\n\t\t\t\tupdf(node[2\
    \ * nk + 1], lazy[nk], width[2 * nk + 1]);\n\t\t\t\tif (lazyflag[2 * nk])\n\t\t\
    \t\t\tlazyf(lazy[2 * nk], lazy[nk]);\n\t\t\t\telse\n\t\t\t\t\tlazy[2 * nk] = lazy[nk];\n\
    \t\t\t\tif (lazyflag[2 * nk + 1])\n\t\t\t\t\tlazyf(lazy[2 * nk + 1], lazy[nk]);\n\
    \t\t\t\telse\n\t\t\t\t\tlazy[2 * nk + 1] = lazy[nk];\n\t\t\t\tlazyflag[2 * nk]\
    \ = lazyflag[2 * nk + 1] = true;\n\t\t\t\tlazyflag[nk] = false;\n\t\t\t}\n\t\t\
    }\n\t}\n\n  public:\n\tIntervalSegTree(unsigned int m, T e_) : Base(m, T(), e_)\
    \ {\n\t\tlazy.resize(2 * n), lazyflag.resize(2 * n), width.resize(2 * n);\n\t\t\
    width[1] = n;\n\t\tfor (unsigned int i = 2; i < 2 * n; i++) width[i] = width[i\
    \ >> 1] >> 1;\n\t}\n\tIntervalSegTree(unsigned int m, T init, T e_) : Base(m,\
    \ init, e_) {\n\t\tlazy.resize(2 * n), lazyflag.resize(2 * n), width.resize(2\
    \ * n);\n\t\twidth[1] = n;\n\t\tfor (unsigned int i = 2; i < 2 * n; i++) width[i]\
    \ = width[i >> 1] >> 1;\n\t}\n\tIntervalSegTree(const std::vector<T>& initvec,\
    \ T e_) : Base(initvec, e_) {\n\t\tlazy.resize(2 * n), lazyflag.resize(2 * n),\
    \ width.resize(2 * n),\n\t\t\twidth[1] = n;\n\t\tfor (unsigned int i = 2; i <\
    \ 2 * n; i++) width[i] = width[i >> 1] >> 1;\n\t}\n\tvoid update(int i, U x) {\n\
    \t\ti += n;\n\t\teval(i);\n\t\tupdf(node[i], x, width[i]);\n\t\tif (lazyflag[i])\n\
    \t\t\tlazyf(lazy[i], x);\n\t\telse {\n\t\t\tlazyflag[i] = true;\n\t\t\tlazy[i]\
    \ = x;\n\t\t}\n\t\twhile (i /= 2) node[i] = nodef(node[2 * i], node[2 * i + 1]);\n\
    \t}\n\tvoid update(int l, int r, U x) {\n\t\tl += n, r += n;\n\t\tint nl = l,\
    \ nr = r;\n\t\twhile (!(nl & 1)) nl >>= 1;\n\t\twhile (!(nr & 1)) nr >>= 1;\n\t\
    \tnr--;\n\t\teval(nl), eval(nr);\n\t\twhile (l < r) {\n\t\t\tif (l & 1) {\n\t\t\
    \t\tupdf(node[l], x, width[l]);\n\t\t\t\tif (lazyflag[l])\n\t\t\t\t\tlazyf(lazy[l],\
    \ x);\n\t\t\t\telse\n\t\t\t\t\tlazyflag[l] = true, lazy[l] = x;\n\t\t\t\tl++;\n\
    \t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\tr--;\n\t\t\t\tupdf(node[r], x, width[r]);\n\
    \t\t\t\tif (lazyflag[r])\n\t\t\t\t\tlazyf(lazy[r], x);\n\t\t\t\telse\n\t\t\t\t\
    \tlazyflag[r] = true, lazy[r] = x;\n\t\t\t}\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\
    \twhile (nl >>= 1) node[nl] = nodef(node[2 * nl], node[2 * nl + 1]);\n\t\twhile\
    \ (nr >>= 1) node[nr] = nodef(node[2 * nr], node[2 * nr + 1]);\n\t}\n\tT query(int\
    \ l, int r) {\n\t\tl += n, r += n, eval(l);\n\t\teval(r - 1);\n\t\tT ls = ident,\
    \ rs = ident;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ls = nodef(ls, node[l++]);\n\
    \t\t\tif (r & 1) rs = nodef(node[--r], rs);\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\
    \treturn nodef(ls, rs);\n\t}\n\tT query_all() {\n\t\teval(1);\n\t\treturn node[1];\n\
    \t}\n\tT operator[](const int& x) {\n\t\teval(n + x);\n\t\treturn node[n + x];\n\
    \t}\n\n  private:\n\ttemplate <class F>\n\tint max_right(int st, F& check, T&\
    \ acc, int k, int l, int r) {\n\t\teval(k);\n\t\tif (l + 1 == r) {\n\t\t\tacc\
    \ = nodef(acc, node[k]);\n\t\t\treturn check(acc) ? -1 : k - n;\n\t\t}\n\t\tint\
    \ m = (l + r) >> 1;\n\t\tif (m <= st) return max_right(st, check, acc, (k << 1)\
    \ | 1, m, r);\n\t\tif (st <= l && check(nodef(acc, node[k]))) {\n\t\t\tacc = nodef(acc,\
    \ node[k]);\n\t\t\treturn -1;\n\t\t}\n\t\tint vl = max_right(st, check, acc, k\
    \ << 1, l, m);\n\t\tif (vl != -1) return vl;\n\t\treturn max_right(st, check,\
    \ acc, (k << 1) | 1, m, r);\n\t}\n\n\ttemplate <class F>\n\tint min_left(int st,\
    \ F& check, T& acc, int k, int l, int r) {\n\t\teval(k);\n\t\tif (l + 1 == r)\
    \ {\n\t\t\tacc = nodef(node[k], acc);\n\t\t\treturn check(acc) ? -1 : k - n +\
    \ 1;\n\t\t}\n\t\tint m = (l + r) >> 1;\n\t\tif (st <= m) return min_left(st, check,\
    \ acc, k << 1, l, m);\n\t\tif (r <= st && check(nodef(node[k], acc))) {\n\t\t\t\
    acc = nodef(node[k], acc);\n\t\t\treturn -1;\n\t\t}\n\t\tint vr = min_left(st,\
    \ check, acc, (k << 1) | 1, m, r);\n\t\tif (vr != -1) return vr;\n\t\treturn min_left(st,\
    \ check, acc, k << 1, l, m);\n\t}\n\n  public:\n\ttemplate <class F>\n\tint max_right(int\
    \ st, F check) {\n\t\tT acc = ident;\n\t\treturn max_right(st, check, acc, 1,\
    \ 0, n);\n\t}\n\ttemplate <bool (*check)(const T&)>\n\tint max_right(int st) {\n\
    \t\tT acc = ident;\n\t\treturn max_right(st, check, acc, 1, 0, n);\n\t}\n\n\t\
    template <class F>\n\tint min_left(int st, F check) {\n\t\tT acc = ident;\n\t\t\
    return min_left(st, check, acc, 1, 0, n);\n\t}\n\ttemplate <bool (*check)(const\
    \ T&)>\n\tint min_left(int st) {\n\t\tT acc = ident;\n\t\treturn min_left(st,\
    \ check, acc, 1, 0, n);\n\t}\n};\nnamespace {\n\ttemplate <class T>\n\tT RAQRSQ_nodef(const\
    \ T& a, const T& b) {\n\t\treturn a + b;\n\t}\n\ttemplate <class T>\n\tvoid RAQRSQ_lazyf(T&\
    \ a, const T& b) {\n\t\ta += b;\n\t}\n\ttemplate <class T>\n\tvoid RAQRSQ_updf(T&\
    \ a, const T& b, const unsigned int& width) {\n\t\ta += width * b;\n\t}\n\n\t\
    template <class T>\n\tT RAQRMiQ_nodef(const T& a, const T& b) {\n\t\treturn std::min(a,\
    \ b);\n\t}\n\ttemplate <class T>\n\tvoid RAQRMiQ_lazyf(T& a, const T& b) {\n\t\
    \ta += b;\n\t}\n\ttemplate <class T>\n\tvoid RAQRMiQ_updf(T& a, const T& b, const\
    \ unsigned int& width) {\n\t\ta += b;\n\t}\n\n\ttemplate <class T>\n\tT RChMiQRMiQ_nodef(const\
    \ T& a, const T& b) {\n\t\treturn std::min(a, b);\n\t}\n\ttemplate <class T>\n\
    \tvoid RChMiQRMiQ_lazyf(T& a, const T& b) {\n\t\tchmin(a, b);\n\t}\n\ttemplate\
    \ <class T>\n\tvoid RChMiQRMiQ_updf(T& a, const T& b, const unsigned int& width)\
    \ {\n\t\tchmin(a, b);\n\t}\n\n\ttemplate <class T>\n\tT RAQRMaQ_nodef(const T&\
    \ a, const T& b) {\n\t\treturn std::max(a, b);\n\t}\n\ttemplate <class T>\n\t\
    void RAQRMaQ_lazyf(T& a, const T& b) {\n\t\ta += b;\n\t}\n\ttemplate <class T>\n\
    \tvoid RAQRMaQ_updf(T& a, const T& b, const unsigned int& width) {\n\t\ta += b;\n\
    \t}\n\n\ttemplate <class T>\n\tT RChMaQRMaQ_nodef(const T& a, const T& b) {\n\t\
    \treturn std::max(a, b);\n\t}\n\ttemplate <class T>\n\tvoid RChMaQRMaQ_lazyf(T&\
    \ a, const T& b) {\n\t\tchmax(a, b);\n\t}\n\ttemplate <class T>\n\tvoid RChMaQRMaQ_updf(T&\
    \ a, const T& b, const unsigned int& width) {\n\t\tchmax(a, b);\n\t}\n\n\ttemplate\
    \ <class T>\n\tT RUQRSQ_nodef(const T& a, const T& b) {\n\t\treturn a + b;\n\t\
    }\n\ttemplate <class T>\n\tvoid RUQRSQ_lazyf(T& a, const T& b) {\n\t\ta = b;\n\
    \t}\n\ttemplate <class T>\n\tvoid RUQRSQ_updf(T& a, const T& b, const unsigned\
    \ int& width) {\n\t\ta = width * b;\n\t}\n\n\ttemplate <class T>\n\tT RUQRMiQ_nodef(const\
    \ T& a, const T& b) {\n\t\treturn std::min(a, b);\n\t}\n\ttemplate <class T>\n\
    \tvoid RUQRMiQ_lazyf(T& a, const T& b) {\n\t\ta = b;\n\t}\n\ttemplate <class T>\n\
    \tvoid RUQRMiQ_updf(T& a, const T& b, const unsigned int& width) {\n\t\ta = b;\n\
    \t}\n\n\ttemplate <class T>\n\tT RUQRMaQ_nodef(const T& a, const T& b) {\n\t\t\
    return std::max(a, b);\n\t}\n\ttemplate <class T>\n\tvoid RUQRMaQ_lazyf(T& a,\
    \ const T& b) {\n\t\ta = b;\n\t}\n\ttemplate <class T>\n\tvoid RUQRMaQ_updf(T&\
    \ a, const T& b, const unsigned int& width) {\n\t\ta = b;\n\t}\n}  // namespace\n\
    \ntemplate <class T>\nclass RAQRSQ\n\t: public IntervalSegTree<T, T, RAQRSQ_nodef,\
    \ RAQRSQ_lazyf, RAQRSQ_updf> {\n\tusing Base = IntervalSegTree<T, T, RAQRSQ_nodef,\
    \ RAQRSQ_lazyf, RAQRSQ_updf>;\n\n  public:\n\ttemplate <class... Args>\n\tRAQRSQ(Args&&...\
    \ args) : Base(std::forward<Args>(args)..., 0) {}\n};\ntemplate <class T>\nclass\
    \ RAQRMiQ\n\t: public IntervalSegTree<T, T, RAQRMiQ_nodef, RAQRMiQ_lazyf, RAQRMiQ_updf>\
    \ {\n\tusing Base =\n\t\tIntervalSegTree<T, T, RAQRMiQ_nodef, RAQRMiQ_lazyf, RAQRMiQ_updf>;\n\
    \n  public:\n\ttemplate <class... Args>\n\tRAQRMiQ(Args&&... args)\n\t\t: Base(std::forward<Args>(args)...,\
    \ std::numeric_limits<T>::max()) {}\n};\ntemplate <class T>\nclass RAQRMaQ\n\t\
    : public IntervalSegTree<T, T, RAQRMaQ_nodef, RAQRMaQ_lazyf, RAQRMaQ_updf> {\n\
    \tusing Base =\n\t\tIntervalSegTree<T, T, RAQRMaQ_nodef, RAQRMaQ_lazyf, RAQRMaQ_updf>;\n\
    \n  public:\n\ttemplate <class... Args>\n\tRAQRMaQ(Args&&... args)\n\t\t: Base(std::forward<Args>(args)...,\
    \ std::numeric_limits<T>::min()) {}\n};\ntemplate <class T>\nclass RChMiQRMiQ\
    \ : public IntervalSegTree<T, T, RChMiQRMiQ_nodef,\n\t\t\t\t\t\t\t\t\t\t  RChMiQRMiQ_lazyf,\
    \ RChMiQRMiQ_updf> {\n\tusing Base = IntervalSegTree<T, T, RChMiQRMiQ_nodef, RChMiQRMiQ_lazyf,\n\
    \t\t\t\t\t\t\t\t RChMiQRMiQ_updf>;\n\n  public:\n\ttemplate <class... Args>\n\t\
    RChMiQRMiQ(Args&&... args)\n\t\t: Base(std::forward<Args>(args)..., std::numeric_limits<T>::max())\
    \ {}\n};\ntemplate <class T>\nclass RChMaQRMaQ : public IntervalSegTree<T, T,\
    \ RChMaQRMaQ_nodef,\n\t\t\t\t\t\t\t\t\t\t  RChMaQRMaQ_lazyf, RChMaQRMaQ_updf>\
    \ {\n\tusing Base = IntervalSegTree<T, T, RChMaQRMaQ_nodef, RChMaQRMaQ_lazyf,\n\
    \t\t\t\t\t\t\t\t RChMaQRMaQ_updf>;\n\n  public:\n\ttemplate <class... Args>\n\t\
    RChMaQRMaQ(Args&&... args)\n\t\t: Base(std::forward<Args>(args)..., std::numeric_limits<T>::min())\
    \ {}\n};\ntemplate <class T>\nclass RUQRSQ\n\t: public IntervalSegTree<T, T, RUQRSQ_nodef,\
    \ RUQRSQ_lazyf, RUQRSQ_updf> {\n\tusing Base = IntervalSegTree<T, T, RUQRSQ_nodef,\
    \ RUQRSQ_lazyf, RUQRSQ_updf>;\n\n  public:\n\ttemplate <class... Args>\n\tRUQRSQ(Args&&...\
    \ args) : Base(std::forward<Args>(args)..., 0) {}\n};\ntemplate <class T>\nclass\
    \ RUQRMiQ\n\t: public IntervalSegTree<T, T, RUQRMiQ_nodef, RUQRMiQ_lazyf, RUQRMiQ_updf>\
    \ {\n\tusing Base =\n\t\tIntervalSegTree<T, T, RUQRMiQ_nodef, RUQRMiQ_lazyf, RUQRMiQ_updf>;\n\
    \n  public:\n\ttemplate <class... Args>\n\tRUQRMiQ(Args&&... args)\n\t\t: Base(std::forward<Args>(args)...,\
    \ std::numeric_limits<T>::max()) {}\n};\ntemplate <class T>\nclass RUQRMaQ\n\t\
    : public IntervalSegTree<T, T, RUQRMaQ_nodef, RUQRMaQ_lazyf, RUQRMaQ_updf> {\n\
    \tusing Base =\n\t\tIntervalSegTree<T, T, RUQRMaQ_nodef, RUQRMaQ_lazyf, RUQRMaQ_updf>;\n\
    \n  public:\n\ttemplate <class... Args>\n\tRUQRMaQ(Args&&... args)\n\t\t: Base(std::forward<Args>(args)...,\
    \ std::numeric_limits<T>::min()) {}\n};\n#line 4 \"test/aoj/DSL_2_I.test.cpp\"\
    \nint n, q;\nint main() {\n\tscanf(\"%d%d\", &n, &q);\n\tRUQRSQ<lint> st(n, 0);\n\
    \trep(i, q) {\n\t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\tint\
    \ s, t, x;\n\t\t\tscanf(\"%d%d%d\", &s, &t, &x);\n\t\t\tst.update(s, t + 1, x);\n\
    \t\t} else {\n\t\t\tint s, t;\n\t\t\tscanf(\"%d%d\", &s, &t);\n\t\t\tprintf(\"\
    %lld\\n\", st.query(s, t + 1));\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I\"\n#include\
    \ \"../../data-structure/IntervalSegTree.hpp\"\n#include \"../../basic/template.hpp\"\
    \nint n, q;\nint main() {\n\tscanf(\"%d%d\", &n, &q);\n\tRUQRSQ<lint> st(n, 0);\n\
    \trep(i, q) {\n\t\tint t;\n\t\tscanf(\"%d\", &t);\n\t\tif (t == 0) {\n\t\t\tint\
    \ s, t, x;\n\t\t\tscanf(\"%d%d%d\", &s, &t, &x);\n\t\t\tst.update(s, t + 1, x);\n\
    \t\t} else {\n\t\t\tint s, t;\n\t\t\tscanf(\"%d%d\", &s, &t);\n\t\t\tprintf(\"\
    %lld\\n\", st.query(s, t + 1));\n\t\t}\n\t}\n}"
  dependsOn:
  - data-structure/IntervalSegTree.hpp
  - basic/template.hpp
  - data-structure/SegTree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_I.test.cpp
  requiredBy: []
  timestamp: '2023-06-25 16:24:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_I.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_I.test.cpp
- /verify/test/aoj/DSL_2_I.test.cpp.html
title: test/aoj/DSL_2_I.test.cpp
---
