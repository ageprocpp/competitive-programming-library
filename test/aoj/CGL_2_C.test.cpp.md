---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/Geometry.hpp
    title: math/Geometry.hpp
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
    ERROR: 1e-8
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_C
  bundledCode: "#line 1 \"test/aoj/CGL_2_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_C\"\
    \n#define ERROR \"1e-8\"\n#line 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n\
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
    }\n#line 2 \"math/Geometry.hpp\"\nstatic bool equal(double lhs, double rhs) {\
    \ return std::abs(lhs - rhs) < eps; }\n\nclass Point2D : public std::complex<double>\
    \ {\n\tusing C = std::complex<double>;\n\n  public:\n\tPoint2D() = default;\n\t\
    Point2D(double x, double y) : C(x, y) {}\n\tPoint2D(const std::complex<double>&\
    \ c) : C(c) {}\n\tPoint2D(std::complex<double>&& c) : C(c) {}\n\n\tdouble get_x()\
    \ const { return real(); }\n\tdouble get_y() const { return imag(); }\n\n\tdouble\
    \ abs() const { return std::abs(*this); }\n\tbool equals(const Point2D& x) {\n\
    \t\treturn equal(real(), x.real()) && equal(imag(), x.imag());\n\t}\n\n\tPoint2D\
    \ unit() const { return Point2D(*this / abs()); }\n\tPoint2D normal() const {\
    \ return *this * std::complex<double>(0, 1); }\n\n\tfriend double dot(const Point2D&\
    \ lhs, const Point2D& rhs);\n\tfriend double cross(const Point2D& lhs, const Point2D&\
    \ rhs);\n\tfriend Point2D rotate(const Point2D& p, double theta);\n};\n\ndouble\
    \ dot(const Point2D& lhs, const Point2D& rhs) {\n\treturn lhs.real() * rhs.real()\
    \ + lhs.imag() * rhs.imag();\n}\ndouble cross(const Point2D& lhs, const Point2D&\
    \ rhs) {\n\treturn lhs.real() * rhs.imag() - lhs.imag() * rhs.real();\n}\nPoint2D\
    \ rotate(const Point2D& p, double theta) {\n\treturn Point2D(p * std::polar(1.0,\
    \ theta));\n}\n\nclass Line2D {\n  protected:\n\tPoint2D s, t;\n\n  public:\n\t\
    Line2D() = default;\n\tLine2D(const Point2D& s_, const Point2D& t_) : s(s_), t(t_)\
    \ {}\n\tLine2D(double A, double B, double C) {\n\t\tif (equal(A, 0))\n\t\t\ts\
    \ = Point2D(0, C / B), t = Point2D(1, C / B);\n\t\telse if (equal(B, 0))\n\t\t\
    \ts = Point2D(C / A, 0), t = Point2D(C / A, 1);\n\t\telse\n\t\t\ts = Point2D(0,\
    \ C / B), t = Point2D(C / A, 0);\n\t}\n\n\tfriend Point2D projection(const Line2D&\
    \ l, const Point2D& p);\n\tfriend bool is_orthogonal(const Line2D& a, const Line2D&\
    \ b);\n\tfriend bool is_parallel(const Line2D& a, const Line2D& b);\n\tfriend\
    \ Point2D cross_point(const Line2D& a, const Line2D& b);\n};\n\nclass Segment2D\
    \ : public Line2D {\n  public:\n\tSegment2D() = default;\n\tSegment2D(const Point2D&\
    \ s, const Point2D& t) : Line2D(s, t) {}\n\n\tfriend bool is_intersect(const Segment2D&\
    \ a, const Segment2D& b);\n\tfriend double distance(const Segment2D& l, const\
    \ Point2D& p);\n\tfriend double distance(const Segment2D& a, const Segment2D&\
    \ b);\n};\n\nclass Circle2D {\n\tPoint2D p;\n\tdouble r;\n\n  public:\n\tCircle2D()\
    \ = default;\n\tCircle2D(const Point2D& p_, double r_) : p(p_), r(r_) {}\n};\n\
    \nPoint2D projection(const Line2D& l, const Point2D& p) {\n\tdouble t = dot(p\
    \ - l.s, l.s - l.t) / std::norm(l.s - l.t);\n\treturn l.s + (l.s - l.t) * t;\n\
    }\n\nPoint2D reflection(const Line2D& l, const Point2D& p) {\n\treturn p + (projection(l,\
    \ p) - p) * 2.0;\n}\n\n// 1: COUNTER_CLOCKWISE\n// -1: CLOCKWISE\n// 2: ONLine2D_BACK\n\
    // -2: ONLine2D_FRONT\n// 0: ON_Segment2D\nint counter_clockwise(const Point2D&\
    \ a, Point2D b, Point2D c) {\n\tb -= a, c -= a;\n\tif (cross(b, c) > eps) return\
    \ 1;\n\tif (cross(b, c) < -eps) return -1;\n\tif (dot(b, c) < 0) return 2;\n\t\
    if (std::norm(b) < std::norm(c)) return -2;\n\treturn 0;\n}\n\nbool is_orthogonal(const\
    \ Line2D& a, const Line2D& b) {\n\treturn equal(dot(a.t - a.s, b.t - b.s), 0);\n\
    }\n\nbool is_parallel(const Line2D& a, const Line2D& b) {\n\treturn equal(cross(a.t\
    \ - a.s, b.t - b.s), 0);\n}\n\nbool is_intersect(const Segment2D& a, const Segment2D&\
    \ b) {\n\treturn counter_clockwise(a.s, a.t, b.s) *\n\t\t\t\t   counter_clockwise(a.s,\
    \ a.t, b.t) <=\n\t\t\t   0 &&\n\t\t   counter_clockwise(b.s, b.t, a.s) *\n\t\t\
    \t\t   counter_clockwise(b.s, b.t, a.t) <=\n\t\t\t   0;\n}\n\nPoint2D cross_point(const\
    \ Line2D& a, const Line2D& b) {\n\tdouble d1 = cross(a.t - a.s, b.t - b.s);\n\t\
    double d2 = cross(a.t - a.s, a.t - b.s);\n\tif (equal(std::abs(d1), 0) && equal(std::abs(d2),\
    \ 0)) return a.s;\n\treturn b.s + (b.t - b.s) * (d2 / d1);\n}\n\ndouble distance(const\
    \ Point2D& x, const Point2D& y) { return std::abs(x - y); }\n\ndouble distance(const\
    \ Segment2D& l, const Point2D& p) {\n\tif (dot(l.t - l.s, p - l.s) < eps) return\
    \ std::abs(p - l.s);\n\tif (dot(l.s - l.t, p - l.t) < eps) return std::abs(p -\
    \ l.t);\n\treturn std::abs(cross(l.t - l.s, p - l.s) / (l.t - l.s));\n}\n\ndouble\
    \ distance(const Segment2D& a, const Segment2D& b) {\n\tif (is_intersect(a, b))\
    \ return 0;\n\tdouble ans = distance(a, b.s);\n\tchmin(ans, distance(a, b.t));\n\
    \tchmin(ans, distance(b, a.s));\n\tchmin(ans, distance(b, a.t));\n\treturn ans;\n\
    }\n\ndouble polygon_area(const std::vector<Point2D>& v) {\n\tdouble res = cross(v.back(),\
    \ v[0]);\n\trep(i, v.size() - 1) res += cross(v[i], v[i + 1]);\n\treturn res *\
    \ 0.5;\n}\n\nbool is_convex(const std::vector<Point2D>& v) {\n\tconst int n =\
    \ v.size();\n\tif (counter_clockwise(v[n - 1], v[0], v[1]) == -1) return false;\n\
    \tif (counter_clockwise(v[n - 2], v[n - 1], v[0]) == -1) return false;\n\trep(i,\
    \ n - 2) {\n\t\tif (counter_clockwise(v[i], v[i + 1], v[i + 2]) == -1) return\
    \ false;\n\t}\n\treturn true;\n}\n\nint is_contained(const std::vector<Point2D>&\
    \ v, const Point2D& p) {\n\tbool in = false;\n\trep(i, v.size()) {\n\t\tPoint2D\
    \ a = v[i] - p, b = v[i == v.size() - 1 ? 0 : i + 1] - p;\n\t\tif (a.get_y() >\
    \ b.get_y()) std::swap(a, b);\n\t\tif (a.get_y() < eps && eps < b.get_y() && cross(a,\
    \ b) < -eps)\n\t\t\tin ^= true;\n\t\tif (cross(a, b) == 0 && dot(a, b) <= 0) return\
    \ 1;\n\t}\n\treturn in ? 2 : 0;\n}\n\nstd::vector<Point2D> convex_hull(std::vector<Point2D>\
    \ p) {\n\tint n = p.size(), k = 0;\n\tstd::sort(all(p), [](const Point2D& a, const\
    \ Point2D& b) {\n\t\treturn a.get_x() != b.get_x() ? a.get_x() < b.get_x()\n\t\
    \t\t\t\t\t\t\t\t  : a.get_y() < b.get_y();\n\t});\n\tstd::vector<Point2D> res(2\
    \ * n);\n\tfor (int i = 0; i < n; res[k++] = p[i++]) {\n\t\twhile (k >= 2 &&\n\
    \t\t\t   cross(res[k - 1] - res[k - 2], p[i] - res[k - 1]) < -eps)\n\t\t\tk--;\n\
    \t}\n\tfor (int i = n - 2, t = k + 1; i >= 0; res[k++] = p[i--]) {\n\t\twhile\
    \ (k >= t &&\n\t\t\t   cross(res[k - 1] - res[k - 2], p[i] - res[k - 1]) < -eps)\n\
    \t\t\tk--;\n\t}\n\tres.resize(k - 1);\n\treturn res;\n}\n\ndouble convex_polygon_diameter(const\
    \ std::vector<Point2D>& p) {\n\tint cur = 0;\n\tdouble res = 0;\n\trep(i, p.size())\
    \ {\n\t\tdouble cur_dist = distance(p[i], p[cur]), nxt_dist;\n\t\twhile (true)\
    \ {\n\t\t\tnxt_dist = distance(p[i], p[cur + 1 == p.size() ? 0 : cur + 1]);\n\t\
    \t\tif (cur_dist > nxt_dist) break;\n\t\t\tcur_dist = nxt_dist;\n\t\t\tcur = cur\
    \ + 1 == p.size() ? 0 : cur + 1;\n\t\t}\n\t\tchmax(res, cur_dist);\n\t}\n\treturn\
    \ res;\n}\n\nstd::istream& operator>>(std::istream& ist, Point2D& p) {\n\tdouble\
    \ x, y;\n\tist >> x >> y;\n\tp = Point2D(x, y);\n\treturn ist;\n}\n\nstd::ostream&\
    \ operator<<(std::ostream& ost, const Point2D& p) {\n\tost << p.get_x() << ' '\
    \ << p.get_y();\n\treturn ost;\n}\n#line 5 \"test/aoj/CGL_2_C.test.cpp\"\nint\
    \ main() {\n\tint q;\n\tstd::cin >> q;\n\trep(i, q) {\n\t\tint x0, y0, x1, y1,\
    \ x2, y2, x3, y3;\n\t\tstd::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;\n\
    \t\tSegment2D s0(Point2D(x0, y0), Point2D(x1, y1)),\n\t\t\ts1(Point2D(x2, y2),\
    \ Point2D(x3, y3));\n\t\tstd::cout << std::fixed << std::setprecision(12) << cross_point(s0,\
    \ s1)\n\t\t\t\t  << std::endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_C\"\n#define\
    \ ERROR \"1e-8\"\n#include \"../../other/template.hpp\"\n#include \"../../math/Geometry.hpp\"\
    \nint main() {\n\tint q;\n\tstd::cin >> q;\n\trep(i, q) {\n\t\tint x0, y0, x1,\
    \ y1, x2, y2, x3, y3;\n\t\tstd::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3\
    \ >> y3;\n\t\tSegment2D s0(Point2D(x0, y0), Point2D(x1, y1)),\n\t\t\ts1(Point2D(x2,\
    \ y2), Point2D(x3, y3));\n\t\tstd::cout << std::fixed << std::setprecision(12)\
    \ << cross_point(s0, s1)\n\t\t\t\t  << std::endl;\n\t}\n}"
  dependsOn:
  - other/template.hpp
  - math/Geometry.hpp
  isVerificationFile: true
  path: test/aoj/CGL_2_C.test.cpp
  requiredBy: []
  timestamp: '2023-06-16 19:42:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_2_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_2_C.test.cpp
- /verify/test/aoj/CGL_2_C.test.cpp.html
title: test/aoj/CGL_2_C.test.cpp
---
