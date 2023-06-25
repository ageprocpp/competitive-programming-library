---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: basic/template.hpp
    title: basic/template.hpp
  - icon: ':warning:'
    path: data-structure/PrioritizableBinaryHeap.hpp
    title: Prioritizable Binary Heap
  - icon: ':warning:'
    path: graph/Graph.hpp
    title: graph/Graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Dijkstra's algorithm
    links: []
  bundledCode: "#line 2 \"basic/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
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
    }\n#line 3 \"graph/Graph.hpp\"\ntemplate <typename>\nclass Dijkstra;\n\ntemplate\
    \ <bool weighted, typename W = std::conditional_t<weighted, int, void>>\nclass\
    \ Graph {\n\tsize_t N;\n\tstd::vector<\n\t\tstd::vector<std::conditional_t<weighted,\
    \ std::pair<int, W>, int>>>\n\t\tvec;\n\tusing weight_type = W;\n\n  public:\n\
    \tGraph(int N_) : N(N_), vec(N_) {}\n\tGraph(decltype(vec) v_) : N(v_.size()),\
    \ vec(v_) {}\n\n\tsize_t size() const { return N; }\n\tvoid add_edge(int s, int\
    \ t, bool directed) {\n\t\tif (directed)\n\t\t\tvec[s].emplace_back(t);\n\t\t\
    else\n\t\t\tvec[s].emplace_back(t), vec[t].emplace_back(s);\n\t}\n\tvoid add_edge(int\
    \ s, int t, W w, bool directed) {\n\t\tif (directed)\n\t\t\tvec[s].emplace_back(t,\
    \ w);\n\t\telse\n\t\t\tvec[s].emplace_back(t, w), vec[t].emplace_back(s, w);\n\
    \t}\n\n\tGraph<weighted, W> rev() const {\n\t\tGraph<weighted, W> res(N);\n\t\t\
    rep(i, N) {\n\t\t\tfor (const auto& j : vec[i]) {\n#if __cplusplus >= 201703L\n\
    \t\t\t\tif constexpr (weighted)\n#else\n\t\t\t\tif (weighted)\n#endif\n\t\t\t\t\
    \tres.vec[j.first].emplace_back(i, j.second);\n\t\t\t\telse\n\t\t\t\t\tres.vec[j].emplace_back(i);\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tfriend Dijkstra<W>;\n};\n#line 3 \"\
    data-structure/PrioritizableBinaryHeap.hpp\"\n\n// assign priorities to indexed\
    \ nodes\ntemplate <class T, class Compare = std::less<>>\nclass PrioritizableBinaryHeap\
    \ {\n\tstd::vector<std::pair<int, T>> heap;\n\tstd::vector<int> rev;\n\tCompare\
    \ comp;\n\n\tvoid up_heap(int id = -1) {\n\t\tif (id == -1) id = heap.size() -\
    \ 1;\n\t\twhile (id > 1) {\n\t\t\tauto &vp = heap[id >> 1], &vx = heap[id];\n\t\
    \t\tif (comp(vp.second, vx.second)) {\n\t\t\t\tstd::swap(rev[vp.first], rev[vx.first]);\n\
    \t\t\t\tstd::swap(vp, vx);\n\t\t\t\tid >>= 1;\n\t\t\t} else\n\t\t\t\treturn;\n\
    \t\t}\n\t}\n\tvoid down_heap(int id = 1) {\n\t\twhile ((id << 1) < heap.size())\
    \ {\n\t\t\tint il = id << 1, ir = id << 1 | 1, swap = -1;\n\t\t\tauto &vl = heap[il],\
    \ &vx = heap[id];\n\t\t\tif (comp(vx.second, vl.second)) swap = il;\n\t\t\tif\
    \ (ir < heap.size()) {\n\t\t\t\tauto& vr = heap[ir];\n\t\t\t\tif (comp(vx.second,\
    \ vr.second)) {\n\t\t\t\t\tif (swap == -1 || comp(vl.second, vr.second)) swap\
    \ = ir;\n\t\t\t\t}\n\t\t\t}\n\t\t\tif (swap == -1) return;\n\t\t\tstd::swap(rev[vx.first],\
    \ rev[heap[swap].first]);\n\t\t\tstd::swap(vx, heap[swap]);\n\t\t\tid = swap;\n\
    \t\t}\n\t}\n\n  public:\n\tPrioritizableBinaryHeap(int n) : heap(1), rev(n, -1)\
    \ {}\n\t[[nodiscard]] bool empty() const noexcept { return heap.size() == 1; }\n\
    \t[[nodiscard]] size_t size() const noexcept { return heap.size() - 1; }\n\t[[nodiscard]]\
    \ auto top() const noexcept { return heap[1]; }\n\tauto pop() {\n\t\tconst auto\
    \ tmp = heap[1];\n\t\trev[heap.back().first] = 1;\n\t\trev[heap[1].first] = -1;\n\
    \t\theap[1] = std::move(heap.back());\n\t\theap.pop_back();\n\t\tdown_heap();\n\
    \t\treturn tmp;\n\t}\n\tvoid push(int id, const T& x) {\n\t\trev[id] = heap.size();\n\
    \t\theap.emplace_back(id, x);\n\t\tup_heap();\n\t}\n\tvoid prioritize(int id,\
    \ const T& x) {\n\t\tif (heap[rev[id]].second > x)\n\t\t\tdecrease_key(id, x);\n\
    \t\telse\n\t\t\tincrease_key(id, x);\n\t}\n\tvoid decrease_key(int id, const T&\
    \ x) {\n\t\tif (rev[id] == -1) {\n\t\t\tpush(id, x);\n\t\t\treturn;\n\t\t}\n\t\
    \theap[rev[id]].second = x;\n\t\tdown_heap(rev[id]);\n\t}\n\tvoid increase_key(int\
    \ id, const T& x) {\n\t\tif (rev[id] == -1) {\n\t\t\tpush(id, x);\n\t\t\treturn;\n\
    \t\t}\n\t\theap[rev[id]].second = x;\n\t\tup_heap(rev[id]);\n\t}\n};\n\n/**\n\
    \ * @title Prioritizable Binary Heap\n */\n#line 5 \"graph/Dijkstra.hpp\"\ntemplate\
    \ <typename W>\nclass Dijkstra {\n\tGraph<true, W> G;\n\n  public:\n\tDijkstra()\
    \ {}\n\tDijkstra(const Graph<true, W>& G_) : G(G_) {}\n\tDijkstra(Graph<true,\
    \ W>&& G_) : G(G_) {}\n\n\tvoid set(const Graph<true, W>& G_) { G = G_; }\n\n\t\
    std::vector<W> operator()(int s) {\n\t\tstd::vector<W> dist(G.N, std::numeric_limits<W>::max());\n\
    \t\tdist[s] = 0;\n\t\tPrioritizableBinaryHeap<W, std::greater<W>> que(G.N);\n\t\
    \tque.push(s, 0);\n\t\twhile (!que.empty()) {\n\t\t\tauto p = que.pop();\n\t\t\
    \tfor (const auto& i : G.vec[p.first]) {\n\t\t\t\tif (chmin(dist[i.first], p.second\
    \ + i.second))\n\t\t\t\t\tque.increase_key(i.first, dist[i.first]);\n\t\t\t}\n\
    \t\t}\n\t\treturn dist;\n\t}\n\n\tW operator()(int s, int t) {\n\t\tstd::vector<W>\
    \ dist(G.N, std::numeric_limits<W>::max());\n\t\tdist[s] = 0;\n\t\tPrioritizableBinaryHeap<W,\
    \ std::greater<W>> que(G.N);\n\t\tque.push(s, 0);\n\t\twhile (!que.empty()) {\n\
    \t\t\tauto p = que.pop();\n\t\t\tif (p.first == t) break;\n\t\t\tfor (const auto&\
    \ i : G.vec[p.first]) {\n\t\t\t\tif (chmin(dist[i.first], p.second + i.second))\n\
    \t\t\t\t\tque.increase_key(i.first, dist[i.first]);\n\t\t\t}\n\t\t}\n\t\treturn\
    \ dist[t];\n\t}\n\n\tstd::pair<W, std::vector<int>> dist_and_path(int s, int t)\
    \ {\n\t\tstd::vector<W> from(G.N), dist(G.N, std::numeric_limits<W>::max());\n\
    \t\tdist[s] = 0;\n\t\tPrioritizableBinaryHeap<W, std::greater<W>> que(G.N);\n\t\
    \tque.push(s, 0);\n\t\twhile (!que.empty()) {\n\t\t\tauto p = que.top();\n\t\t\
    \tque.pop();\n\t\t\tif (p.first == t) break;\n\t\t\tfor (auto i : G.vec[p.first])\
    \ {\n\t\t\t\tif (chmin(dist[i.first], p.second + i.second)) {\n\t\t\t\t\tfrom[i.first]\
    \ = p.first;\n\t\t\t\t\tque.increase_key(i.first, dist[i.first]);\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t\tif (dist[t] == std::numeric_limits<W>::max()) return {dist[t],\
    \ {}};\n\t\tW res_dist = dist[t];\n\t\tstd::vector<int> res_vec = {t};\n\t\twhile\
    \ (t != s) res_vec.emplace_back(t = from[t]);\n\t\tstd::reverse(all(res_vec));\n\
    \t\treturn {res_dist, res_vec};\n\t}\n};\n\n/**\n * @title Dijkstra's algorithm\n\
    \ */\n"
  code: "#pragma once\n#include \"../basic/template.hpp\"\n#include \"Graph.hpp\"\n\
    #include \"../data-structure/PrioritizableBinaryHeap.hpp\"\ntemplate <typename\
    \ W>\nclass Dijkstra {\n\tGraph<true, W> G;\n\n  public:\n\tDijkstra() {}\n\t\
    Dijkstra(const Graph<true, W>& G_) : G(G_) {}\n\tDijkstra(Graph<true, W>&& G_)\
    \ : G(G_) {}\n\n\tvoid set(const Graph<true, W>& G_) { G = G_; }\n\n\tstd::vector<W>\
    \ operator()(int s) {\n\t\tstd::vector<W> dist(G.N, std::numeric_limits<W>::max());\n\
    \t\tdist[s] = 0;\n\t\tPrioritizableBinaryHeap<W, std::greater<W>> que(G.N);\n\t\
    \tque.push(s, 0);\n\t\twhile (!que.empty()) {\n\t\t\tauto p = que.pop();\n\t\t\
    \tfor (const auto& i : G.vec[p.first]) {\n\t\t\t\tif (chmin(dist[i.first], p.second\
    \ + i.second))\n\t\t\t\t\tque.increase_key(i.first, dist[i.first]);\n\t\t\t}\n\
    \t\t}\n\t\treturn dist;\n\t}\n\n\tW operator()(int s, int t) {\n\t\tstd::vector<W>\
    \ dist(G.N, std::numeric_limits<W>::max());\n\t\tdist[s] = 0;\n\t\tPrioritizableBinaryHeap<W,\
    \ std::greater<W>> que(G.N);\n\t\tque.push(s, 0);\n\t\twhile (!que.empty()) {\n\
    \t\t\tauto p = que.pop();\n\t\t\tif (p.first == t) break;\n\t\t\tfor (const auto&\
    \ i : G.vec[p.first]) {\n\t\t\t\tif (chmin(dist[i.first], p.second + i.second))\n\
    \t\t\t\t\tque.increase_key(i.first, dist[i.first]);\n\t\t\t}\n\t\t}\n\t\treturn\
    \ dist[t];\n\t}\n\n\tstd::pair<W, std::vector<int>> dist_and_path(int s, int t)\
    \ {\n\t\tstd::vector<W> from(G.N), dist(G.N, std::numeric_limits<W>::max());\n\
    \t\tdist[s] = 0;\n\t\tPrioritizableBinaryHeap<W, std::greater<W>> que(G.N);\n\t\
    \tque.push(s, 0);\n\t\twhile (!que.empty()) {\n\t\t\tauto p = que.top();\n\t\t\
    \tque.pop();\n\t\t\tif (p.first == t) break;\n\t\t\tfor (auto i : G.vec[p.first])\
    \ {\n\t\t\t\tif (chmin(dist[i.first], p.second + i.second)) {\n\t\t\t\t\tfrom[i.first]\
    \ = p.first;\n\t\t\t\t\tque.increase_key(i.first, dist[i.first]);\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t\tif (dist[t] == std::numeric_limits<W>::max()) return {dist[t],\
    \ {}};\n\t\tW res_dist = dist[t];\n\t\tstd::vector<int> res_vec = {t};\n\t\twhile\
    \ (t != s) res_vec.emplace_back(t = from[t]);\n\t\tstd::reverse(all(res_vec));\n\
    \t\treturn {res_dist, res_vec};\n\t}\n};\n\n/**\n * @title Dijkstra's algorithm\n\
    \ */"
  dependsOn:
  - basic/template.hpp
  - graph/Graph.hpp
  - data-structure/PrioritizableBinaryHeap.hpp
  isVerificationFile: false
  path: graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2023-06-25 16:21:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Dijkstra.hpp
layout: document
redirect_from:
- /library/graph/Dijkstra.hpp
- /library/graph/Dijkstra.hpp.html
title: Dijkstra's algorithm
---
