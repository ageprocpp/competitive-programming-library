---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/FibonacciHeap.hpp
    title: data-structure/FibonacciHeap.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/PrioritizableBinaryHeap.hpp
    title: data-structure/PrioritizableBinaryHeap.hpp
  - icon: ':heavy_check_mark:'
    path: graph/Dijkstra.hpp
    title: Dijkstra's algorithm
  - icon: ':heavy_check_mark:'
    path: other/FastIO.hpp
    title: Fast IO library
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/yosupo/shortest_path.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"other/template.hpp\"\
    \n#define _CRT_SECURE_NO_WARNINGS\n#ifndef __clang__\n#ifdef ONLINE_JUDGE\n#pragma\
    \ GCC target(\"avx512f\")\n#elif defined EVAL\n#else\n#pragma GCC target(\"avx2\"\
    )\n#endif\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n#endif\n#include <string.h>\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cfloat>\n#include <climits>\n#include\
    \ <cmath>\n#include <complex>\n#include <ctime>\n#include <deque>\n#include <fstream>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <stack>\n#include <string>\n#include <unordered_map>\n\
    #include <unordered_set>\n#include <utility>\n#include <vector>\n\n#define rep(i,\
    \ n) for (int i = 0; i < int(n); i++)\n#define REP(i, n) for (int i = 1; i <=\
    \ int(n); i++)\n#define all(V) V.begin(), V.end()\n\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\nusing uint = unsigned int;\nusing lint = long long;\n\
    using ulint = unsigned long long;\nusing IP = std::pair<int, int>;\nusing LP =\
    \ std::pair<lint, lint>;\n\nconstexpr int INF = INT_MAX / 2;\nconstexpr lint LINF\
    \ = LLONG_MAX / 2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr double PI =\
    \ 3.141592653589793238462643383279;\n\ntemplate <class T>\nclass prique : public\
    \ std::priority_queue<T, std::vector<T>, std::greater<T>> {\n};\nint popcount(uint\
    \ x) {\n#if __cplusplus >= 202002L\n\treturn std::popcount(x);\n#else\n#ifndef\
    \ __clang__\n\treturn __builtin_popcount(x);\n#endif\n#endif\n\tx = (x & 0x55555555)\
    \ + (x >> 1 & 0x55555555);\n\tx = (x & 0x33333333) + (x >> 2 & 0x33333333);\n\t\
    x = (x & 0x0f0f0f0f) + (x >> 4 & 0x0f0f0f0f);\n\tx = (x & 0x00ff00ff) + (x >>\
    \ 8 & 0x00ff00ff);\n\treturn (x & 0x0000ffff) + (x >> 16 & 0x0000ffff);\n}\ntemplate\
    \ <class F>\ninline constexpr decltype(auto) lambda_fix(F&& f) {\n\treturn [f\
    \ = std::forward<F>(f)](auto&&... args) {\n\t\treturn f(f, std::forward<decltype(args)>(args)...);\n\
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
    other/FastIO.hpp\"\nnamespace FastIO {\n\tstatic constexpr size_t buf_size = 1\
    \ << 18;\n\tstatic constexpr size_t integer_size = 19;\n\n\tstatic char inbuf[buf_size\
    \ + 1] = {};\n\tstatic char outbuf[buf_size + 1] = {};\n\n\tclass Scanner {\n\t\
    \tsize_t pos = 0, end = buf_size;\n\t\tvoid load() {\n\t\t\tend = fread(inbuf,\
    \ 1, buf_size, stdin);\n\t\t\tinbuf[end] = '\\0';\n\t\t}\n\t\tvoid ignore_space()\
    \ {\n\t\t\twhile (inbuf[pos] <= ' ') {\n\t\t\t\tif (__builtin_expect(++pos ==\
    \ end, 0)) reload();\n\t\t\t}\n\t\t}\n\t\tchar next() { return inbuf[pos++]; }\n\
    \t\tchar next_nonspace() {\n\t\t\tignore_space();\n\t\t\treturn inbuf[pos++];\n\
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
    \ * @title Fast IO library\n */\n#line 3 \"data-structure/PrioritizableBinaryHeap.hpp\"\
    \n\n// assign priorities to indexed nodes\ntemplate <class T, class Compare =\
    \ std::less<>>\nclass PrioritizableBinaryHeap {\n\tstd::vector<std::pair<int,\
    \ T>> heap;\n\tstd::vector<int> rev;\n\tCompare comp;\n\n\tvoid up_heap(int id\
    \ = -1) {\n\t\tif (id == -1) id = heap.size() - 1;\n\t\twhile (id > 1) {\n\t\t\
    \tauto &vp = heap[id >> 1], &vx = heap[id];\n\t\t\tif (comp(vp.second, vx.second))\
    \ {\n\t\t\t\tstd::swap(rev[vp.first], rev[vx.first]);\n\t\t\t\tstd::swap(vp, vx);\n\
    \t\t\t\tid >>= 1;\n\t\t\t} else\n\t\t\t\treturn;\n\t\t}\n\t}\n\tvoid down_heap(int\
    \ id = 1) {\n\t\twhile ((id << 1) < heap.size()) {\n\t\t\tint il = id << 1, ir\
    \ = id << 1 | 1, swap = -1;\n\t\t\tauto &vl = heap[il], &vx = heap[id];\n\t\t\t\
    if (comp(vx.second, vl.second)) swap = il;\n\t\t\tif (ir < heap.size()) {\n\t\t\
    \t\tauto& vr = heap[ir];\n\t\t\t\tif (comp(vx.second, vr.second)) {\n\t\t\t\t\t\
    if (swap == -1 || comp(vl.second, vr.second)) swap = ir;\n\t\t\t\t}\n\t\t\t}\n\
    \t\t\tif (swap == -1) return;\n\t\t\tstd::swap(rev[vx.first], rev[heap[swap].first]);\n\
    \t\t\tstd::swap(vx, heap[swap]);\n\t\t\tid = swap;\n\t\t}\n\t}\n\n  public:\n\t\
    PrioritizableBinaryHeap(int n) : heap(1), rev(n, -1) {}\n\t[[nodiscard]] bool\
    \ empty() const noexcept { return heap.size() == 1; }\n\t[[nodiscard]] size_t\
    \ size() const noexcept { return heap.size() - 1; }\n\t[[nodiscard]] auto top()\
    \ const noexcept { return heap[1]; }\n\tvoid pop() {\n\t\trev[heap.back().first]\
    \ = 1;\n\t\trev[heap[1].first] = -1;\n\t\theap[1] = std::move(heap.back());\n\t\
    \theap.pop_back();\n\t\tdown_heap();\n\t}\n\tvoid push(int id, const T& x) {\n\
    \t\trev[id] = heap.size();\n\t\theap.emplace_back(id, x);\n\t\tup_heap();\n\t\
    }\n\tvoid prioritize(int id, const T& x) {\n\t\tif (heap[rev[id]].second > x)\
    \ decrease_key(id, x);\n\t\telse increase_key(id, x);\n\t}\n\tvoid decrease_key(int\
    \ id, const T& x) {\n\t\tif (rev[id] == -1) {\n\t\t\tpush(id, x);\n\t\t\treturn;\n\
    \t\t}\n\t\theap[rev[id]].second = x;\n\t\tdown_heap(rev[id]);\n\t}\n\tvoid increase_key(int\
    \ id, const T& x) {\n\t\tif (rev[id] == -1) {\n\t\t\tpush(id, x);\n\t\t\treturn;\n\
    \t\t}\n\t\theap[rev[id]].second = x;\n\t\tup_heap(rev[id]);\n\t}\n};\n#line 3\
    \ \"data-structure/FibonacciHeap.hpp\"\ntemplate <class T, class Compare = std::less<T>>\n\
    class FibonacciHeap {\n\tclass Tree {\n\t  public:\n\t\tTree* par;\n\t\ttypename\
    \ std::list<Tree*>::iterator in_par;\n\t\tint root_index;\n\t\tT root_key;\n\t\
    \tstd::list<Tree*> children;\n\t\tint rank = 0;\n\t\tbool damaged = false;\n\n\
    \t\tTree(int index, T key, Tree* par_ = nullptr)\n\t\t\t: root_index(index), root_key(key),\
    \ par(par_) {}\n\t\tTree& meld(Tree& t) {\n\t\t\tif (comp(root_key, t.root_key))\
    \ std::swap(*this, t);\n\t\t\tchildren.push_back(&t);\n\t\t\trank++;\n\t\t\treturn\
    \ *this;\n\t\t}\n\t\tvoid cut(FibonacciHeap& heap) {\n\t\t\tif (!par) return;\n\
    \t\t\tif (par->damaged) par->cut(heap);\n\t\t\tpar->children.erase(in_par);\n\t\
    \t\theap.l.emplace_front(this);\n\t\t}\n\t};\n\n\tstatic constexpr int MAX_DEPTH\
    \ = 30;\n\n\tsize_t n = 0;\n\tstd::list<Tree*> l;\n\tstd::vector<Tree*> rev;\n\
    \ttypename std::list<Tree*>::iterator top_itr = l.end();\n\tstatic Compare comp;\n\
    \tvoid update_top() {\n\t\tif (empty()) return;\n\t\ttop_itr = l.begin();\n\t\t\
    auto itr = l.begin();\n\t\twhile (++itr != l.end()) {\n\t\t\tif (comp((*top_itr)->root_key,\
    \ (*itr)->root_key)) top_itr = itr;\n\t\t}\n\t}\n\n  public:\n\tFibonacciHeap(int\
    \ n_) : rev(n_) {}\n\t~FibonacciHeap() {\n\t\tlambda_fix([&](auto self, std::list<Tree*>\
    \ l) -> void {\n\t\t\tfor (auto& i : l) {\n\t\t\t\tself(self, i->children);\n\t\
    \t\t\tdelete i;\n\t\t\t}\n\t\t})(l);\n\t}\n\t[[nodiscard]] bool empty() const\
    \ { return l.empty(); }\n\t[[nodiscard]] size_t size() const { return n; }\n\t\
    void push(int index, T key) {\n\t\tn++;\n\t\tl.emplace_front(new Tree(index, key));\n\
    \t\tif (top_itr == l.end() || (*top_itr)->root_key < key)\n\t\t\ttop_itr = l.begin();\n\
    \t}\n\tvoid meld(FibonacciHeap& t) { meld(t.l); }\n\tvoid meld(std::list<Tree*>&\
    \ l_) {\n\t\tstd::array<Tree*, MAX_DEPTH> ar;\n\t\tar.fill(nullptr);\n\t\tl.splice(l.end(),\
    \ l_);\n\t\tauto add = lambda_fix([&](auto self, Tree* t) -> void {\n\t\t\tif\
    \ (!ar[t->rank])\n\t\t\t\tar[t->rank] = t;\n\t\t\telse {\n\t\t\t\tint rank = t->rank;\n\
    \t\t\t\tt->meld(*ar[rank]);\n\t\t\t\tar[rank] = nullptr;\n\t\t\t\tself(self, t);\n\
    \t\t\t}\n\t\t});\n\t\tfor (const auto& i : l) add(i);\n\t\tl.clear();\n\t\tfor\
    \ (const auto& i : ar)\n\t\t\tif (i) l.emplace_back(i);\n\t\tupdate_top();\n\t\
    }\n\t[[nodiscard]] std::pair<int, T> top() const {\n\t\treturn {(*top_itr)->root_index,\
    \ (*top_itr)->root_key};\n\t}\n\tvoid pop() {\n\t\tn--;\n\t\tauto new_trees =\
    \ (*top_itr)->children;\n\t\tauto tree_address = *top_itr;\n\t\tl.erase(top_itr);\n\
    \t\ttop_itr = l.end();\n\t\tmeld(new_trees);\n\t\tdelete tree_address;\n\t\tupdate_top();\n\
    \t}\n\tvoid increase_key(int id, T key) {\n\t\trev[id]->root_key = key;\n\t\t\
    rev[id]->cut(*this);\n\t}\n};\ntemplate <class T, class Compare>\nCompare FibonacciHeap<T,\
    \ Compare>::comp = Compare();\n#line 5 \"graph/Dijkstra.hpp\"\ntemplate <class\
    \ T>\nclass Dijkstra {\n\tint N;\n\tstd::vector<std::vector<std::pair<int, T>>>\
    \ vec, rev;\n\tbool exec(int s, int t, std::vector<T> &dist) {\n\t\tdist.assign(N,\
    \ std::numeric_limits<T>::max());\n\t\tdist[s] = 0;\n\t\tPrioritizableBinaryHeap<T,\
    \ std::greater<T>> que(N);\n\t\t// FibonacciHeap<T, std::greater<T>> que;\n\t\t\
    que.push(s, 0);\n\t\twhile (!que.empty()) {\n\t\t\tauto p = que.top();\n\t\t\t\
    que.pop();\n\t\t\t// if (dist[p.first] < p.second) continue;\n\t\t\tfor (auto\
    \ i : vec[p.first]) {\n\t\t\t\tif (chmin(dist[i.first], p.second + i.second))\n\
    \t\t\t\t\tque.increase_key(i.first, dist[i.first]);\n\t\t\t\t// que.push(i.first,\
    \ dist[i.first]);\n\t\t\t}\n\t\t}\n\t\treturn dist[t] != std::numeric_limits<T>::max();\n\
    \t}\n\n  public:\n\tDijkstra(int N) : N(N), vec(N), rev(N) {}\n\tvoid add_edge(int\
    \ from, int to, T cost) {\n\t\tvec[from].push_back({to, cost});\n\t\trev[to].push_back({from,\
    \ cost});\n\t}\n\tT get_dist(int s, int t) {\n\t\tstd::vector<T> dist;\n\t\tif\
    \ (!exec(s, t, dist)) return -1;\n\t\treturn dist[t];\n\t}\n\tstd::vector<int>\
    \ get_path(int s, int t) {\n\t\treturn get_dist_and_path(s, t).second;\n\t}\n\t\
    std::pair<T, std::vector<int>> get_dist_and_path(int s, int t) {\n\t\tstd::vector<T>\
    \ dist;\n\t\tstd::vector<int> res = {t};\n\t\tstd::vector<bool> used(N);\n\t\t\
    if (!exec(s, t, dist)) return {-1, {}};\n\t\tused[t] = true;\n\t\tint head = t;\n\
    \t\twhile (head != s) {\n\t\t\tfor (auto i : rev[head]) {\n\t\t\t\tif (!used[i.first]\
    \ && dist[i.first] + i.second == dist[head]) {\n\t\t\t\t\tused[i.first] = true;\n\
    \t\t\t\t\thead = i.first;\n\t\t\t\t\tres.emplace_back(head);\n\t\t\t\t\tbreak;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tstd::reverse(all(res));\n\t\treturn {dist[t], res};\n\
    \t}\n\tstd::vector<T> get_dists(int s) {\n\t\tstd::vector<T> dist;\n\t\texec(s,\
    \ s, dist);\n\t\treturn dist;\n\t}\n};\n\n/**\n * @title Dijkstra's algorithm\n\
    \ */\n#line 5 \"test/yosupo/shortest_path.test.cpp\"\nFastIO::Scanner cin;\nFastIO::Printer\
    \ cout;\nint N, M, s, t, a, b, c;\nint main() {\n\tcin >> N >> M >> s >> t;\n\t\
    Dijkstra<lint> d(N);\n\trep(i, M) {\n\t\tcin >> a >> b >> c;\n\t\td.add_edge(a,\
    \ b, c);\n\t}\n\tauto res = d.get_dist_and_path(s, t);\n\tif (res.first == -1)\n\
    \t\tputs(\"-1\");\n\telse {\n\t\tcout << res.first << ' ' << res.second.size()\
    \ - 1 << '\\n';\n\t\trep(i, res.second.size() - 1) cout << res.second[i] << '\
    \ '\n\t\t\t\t\t\t\t\t\t\t   << res.second[i + 1] << '\\n';\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../other/FastIO.hpp\"\n#include\
    \ \"../../graph/Dijkstra.hpp\"\nFastIO::Scanner cin;\nFastIO::Printer cout;\n\
    int N, M, s, t, a, b, c;\nint main() {\n\tcin >> N >> M >> s >> t;\n\tDijkstra<lint>\
    \ d(N);\n\trep(i, M) {\n\t\tcin >> a >> b >> c;\n\t\td.add_edge(a, b, c);\n\t\
    }\n\tauto res = d.get_dist_and_path(s, t);\n\tif (res.first == -1)\n\t\tputs(\"\
    -1\");\n\telse {\n\t\tcout << res.first << ' ' << res.second.size() - 1 << '\\\
    n';\n\t\trep(i, res.second.size() - 1) cout << res.second[i] << ' '\n\t\t\t\t\t\
    \t\t\t\t\t   << res.second[i + 1] << '\\n';\n\t}\n}"
  dependsOn:
  - other/template.hpp
  - other/FastIO.hpp
  - graph/Dijkstra.hpp
  - data-structure/PrioritizableBinaryHeap.hpp
  - data-structure/FibonacciHeap.hpp
  isVerificationFile: true
  path: test/yosupo/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2021-05-20 00:07:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/shortest_path.test.cpp
- /verify/test/yosupo/shortest_path.test.cpp.html
title: test/yosupo/shortest_path.test.cpp
---
