---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algebraic/DynamicModInt.hpp
    title: algebraic/DynamicModInt.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic/StaticModInt.hpp
    title: algebraic/StaticModInt.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n#line 2 \"other/template.hpp\"\
    \n#define _CRT_SECURE_NO_WARNINGS\n#pragma target(\"avx2\")\n#pragma optimize(\"\
    O3\")\n#pragma optimize(\"unroll-loops\")\n#include <algorithm>\n#include <bitset>\n\
    #include <cassert>\n#include <cfloat>\n#include <climits>\n#include <cmath>\n\
    #include <complex>\n#include <ctime>\n#include <deque>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <iterator>\n\
    #include <list>\n#include <map>\n#include <memory>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <stack>\n#include <string>\n#include <string.h>\n\
    #include <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include\
    \ <vector>\n#define rep(i,n) for(int i=0;i<(n);i++)\n#define REP(i,n) for(int\
    \ i=1;i<=(n);i++)\n#define all(V) V.begin(),V.end()\ntypedef unsigned int uint;\n\
    typedef long long lint;\ntypedef unsigned long long ulint;\ntypedef std::pair<int,\
    \ int> P;\ntypedef std::pair<lint, lint> LP;\nconstexpr int INF = INT_MAX/2;\n\
    constexpr lint LINF = LLONG_MAX/2;\nconstexpr double eps = DBL_EPSILON;\nconstexpr\
    \ double PI=3.141592653589793238462643383279;\ntemplate<class T>\nclass prique\
    \ :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};\ntemplate\
    \ <class T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\tif (lhs < rhs)\
    \ {\n\t\tlhs = rhs;\n\t\treturn 1;\n\t}\n\treturn 0;\n}\ntemplate <class T, class\
    \ U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs > rhs) {\n\t\tlhs =\
    \ rhs;\n\t\treturn 1;\n\t}\n\treturn 0;\n}\ninline lint gcd(lint a, lint b) {\n\
    \twhile (b) {\n\t\tlint c = a;\n\t\ta = b; b = c % b;\n\t}\n\treturn a;\n}\ninline\
    \ lint lcm(lint a, lint b) {\n\treturn a / gcd(a, b) * b;\n}\nbool isprime(lint\
    \ n) {\n\tif (n == 1)return false;\n\tfor (int i = 2; i * i <= n; i++) {\n\t\t\
    if (n % i == 0)return false;\n\t}\n\treturn true;\n}\ntemplate<typename T>\nT\
    \ mypow(T a, lint b) {\n\tT res(1);\n\twhile(b){\n\t\tif(b&1)res*=a;\n\t\ta*=a;\n\
    \t\tb>>=1;\n\t}\n\treturn res;\n}\nlint modpow(lint a, lint b, lint m) {\n\tlint\
    \ res(1);\n\twhile(b){\n\t\tif(b&1){\n\t\t\tres*=a;res%=m;\n\t\t}\n\t\ta*=a;a%=m;\n\
    \t\tb>>=1;\n\t}\n\treturn res;\n}\ntemplate<typename T>\nvoid printArray(std::vector<T>&\
    \ vec) {\n\trep(i, vec.size()){\n\t\tstd::cout << vec[i];\n\t\tstd::cout<<(i==(int)vec.size()-1?\"\
    \\n\":\" \");\n\t}\n}\ntemplate<typename T>\nvoid printArray(T l, T r) {\n\tT\
    \ rprev = std::prev(r);\n\tfor (T i = l; i != rprev; i++) {\n\t\tstd::cout <<\
    \ *i << \" \";\n\t}\n\tstd::cout << *rprev << std::endl;\n}\nLP extGcd(lint a,lint\
    \ b) {\n\tif(b==0)return {1,0};\n\tLP s=extGcd(b,a%b);\n\tstd::swap(s.first,s.second);\n\
    \ts.second-=a/b*s.first;\n\treturn s;\n}\nLP ChineseRem(const lint& b1,const lint&\
    \ m1,const lint& b2,const lint& m2) {\n\tlint p=extGcd(m1,m2).first;\n\tlint tmp=(b2-b1)*p%m2;\n\
    \tlint r=(b1+m1*tmp+m1*m2)%(m1*m2);\n\treturn std::make_pair(r,m1*m2);\n}\ntemplate<typename\
    \ F>\ninline constexpr decltype(auto) lambda_fix(F&& f){\n\treturn [f=std::forward<F>(f)](auto&&...\
    \ args){\n\t\treturn f(f,std::forward<decltype(args)>(args)...);\n\t};\n}\n#line\
    \ 3 \"algebraic/DynamicModInt.hpp\"\nclass DynamicModInt {\n\tlint value;\npublic:\n\
    \tstatic unsigned int modulo;\n\tDynamicModInt() : value(0) {}\n\ttemplate<typename\
    \ T>\n\tDynamicModInt(T value = 0) : value(value) {\n\t\tif (value < 0)value =\
    \ -(lint)(-value % modulo) + modulo;\n\t\tthis->value = value % modulo;\n\t}\n\
    \tstatic inline void setMod(const unsigned int& mod){modulo=mod;}\n\tinline DynamicModInt\
    \ inv()const{return mypow(*this,modulo-2);}\n\tinline operator int()const { return\
    \ value; }\n\tinline DynamicModInt& operator+=(const DynamicModInt& x) {\n\t\t\
    value += x.value;\n\t\tif (value >= modulo)value -= modulo;\n\t\treturn *this;\n\
    \t}\n\tinline DynamicModInt& operator++() {\n\t\tif (value == modulo - 1)value\
    \ = 0;\n\t\telse value++;\n\t\treturn *this;\n\t}\n\tinline DynamicModInt operator++(int){\n\
    \t\tDynamicModInt res=*this;\n\t\t--*this;\n\t\treturn res;\n\t}\n\tinline DynamicModInt\
    \ operator-()const {\n\t\treturn DynamicModInt(0) -= *this;\n\t}\n\tinline DynamicModInt&\
    \ operator-=(const DynamicModInt& x) {\n\t\tvalue -= x.value;\n\t\tif (value <\
    \ 0)value += modulo;\n\t\treturn *this;\n\t}\n\tinline DynamicModInt& operator--()\
    \ {\n\t\tif (value == 0)value = modulo - 1;\n\t\telse value--;\n\t\treturn *this;\n\
    \t}\n\tinline DynamicModInt operator--(int){\n\t\tDynamicModInt res=*this;\n\t\
    \t--*this;\n\t\treturn res;\n\t}\n\tinline DynamicModInt& operator*=(const DynamicModInt&\
    \ x) {\n\t\tvalue = value * x.value % modulo;\n\t\treturn *this;\n\t}\n\tinline\
    \ DynamicModInt& operator/=(const DynamicModInt& rhs) {\n\t\treturn *this*=rhs.inv();\n\
    \t}\n\ttemplate<typename T> DynamicModInt operator+(const T& rhs)const { return\
    \ DynamicModInt(*this) += rhs; }\n\ttemplate<typename T> DynamicModInt& operator+=(const\
    \ T& rhs) { return operator+=(DynamicModInt(rhs)); }\n\ttemplate<typename T> DynamicModInt\
    \ operator-(const T& rhs)const { return DynamicModInt(*this) -= rhs; }\n\ttemplate<typename\
    \ T> DynamicModInt& operator-=(const T& rhs) { return operator-=(DynamicModInt(rhs));\
    \ }\n\ttemplate<typename T> DynamicModInt operator*(const T& rhs)const { return\
    \ DynamicModInt(*this) *= rhs; }\n\ttemplate<typename T> DynamicModInt& operator*=(const\
    \ T& rhs) { return operator*=(DynamicModInt(rhs)); }\n\ttemplate<typename T> DynamicModInt\
    \ operator/(const T& rhs)const { return DynamicModInt(*this) /= rhs; }\n\ttemplate<typename\
    \ T> DynamicModInt& operator/=(const T& rhs) { return operator/=(DynamicModInt(rhs));\
    \ }\n};\nunsigned int DynamicModInt::modulo=1000000007;\nstd::istream& operator>>(std::istream&\
    \ ist, DynamicModInt& x) {\n\tlint a;\n\tist >> a;\n\tx = a;\n\treturn ist;\n\
    }\n#line 4 \"algebraic/StaticModInt.hpp\"\ntemplate<unsigned int modulo>\nclass\
    \ StaticModInt {\n\tlint value;\npublic:\n\tstatic constexpr unsigned int mod_value\
    \ = modulo;\n\tStaticModInt() : value(0) {}\n\ttemplate<typename T>\n\tStaticModInt(T\
    \ value = 0) : value(value) {\n\t\tthis -> value = (value < 0 ? -(-value % modulo)\
    \ + modulo : value) % modulo;\n\t}\n\tinline StaticModInt inv()const{return mypow(*this,modulo-2);}\n\
    \tinline operator int()const { return value; }\n\tinline StaticModInt& operator+=(const\
    \ StaticModInt& x) {\n\t\tvalue += x.value;\n\t\tif (value >= modulo)value -=\
    \ modulo;\n\t\treturn *this;\n\t}\n\tinline StaticModInt& operator++() {\n\t\t\
    if (value == modulo - 1)value = 0;\n\t\telse value++;\n\t\treturn *this;\n\t}\n\
    \tinline StaticModInt operator++(int){\n\t\tStaticModInt res=*this;\n\t\t--*this;\n\
    \t\treturn res;\n\t}\n\tinline StaticModInt operator-()const {\n\t\treturn StaticModInt(0)\
    \ -= *this;\n\t}\n\tinline StaticModInt& operator-=(const StaticModInt& x) {\n\
    \t\tvalue -= x.value;\n\t\tif (value < 0)value += modulo;\n\t\treturn *this;\n\
    \t}\n\tinline StaticModInt& operator--() {\n\t\tif (value == 0)value = modulo\
    \ - 1;\n\t\telse value--;\n\t\treturn *this;\n\t}\n\tinline StaticModInt operator--(int){\n\
    \t\tStaticModInt res=*this;\n\t\t--*this;\n\t\treturn res;\n\t}\n\tinline StaticModInt&\
    \ operator*=(const StaticModInt& x) {\n\t\tvalue = value * x.value % modulo;\n\
    \t\treturn *this;\n\t}\n\tinline StaticModInt& operator/=(const StaticModInt&\
    \ rhs) {\n\t\treturn *this*=rhs.inv();\n\t}\n\ttemplate<typename T> StaticModInt\
    \ operator+(const T& rhs)const { return StaticModInt(*this) += rhs; }\n\ttemplate<typename\
    \ T> StaticModInt& operator+=(const T& rhs) { return operator+=(StaticModInt(rhs));\
    \ }\n\ttemplate<typename T> StaticModInt operator-(const T& rhs)const { return\
    \ StaticModInt(*this) -= rhs; }\n\ttemplate<typename T> StaticModInt& operator-=(const\
    \ T& rhs) { return operator-=(StaticModInt(rhs)); }\n\ttemplate<typename T> StaticModInt\
    \ operator*(const T& rhs)const { return StaticModInt(*this) *= rhs; }\n\ttemplate<typename\
    \ T> StaticModInt& operator*=(const T& rhs) { return operator*=(StaticModInt(rhs));\
    \ }\n\ttemplate<typename T> StaticModInt operator/(const T& rhs)const { return\
    \ StaticModInt(*this) /= rhs; }\n\ttemplate<typename T> StaticModInt& operator/=(const\
    \ T& rhs) { return operator/=(StaticModInt(rhs)); }\n};\ntemplate<unsigned int\
    \ modulo>\nstd::istream& operator>>(std::istream& ist, StaticModInt<modulo>& x)\
    \ {\n\tlint a;\n\tist >> a;\n\tx = a;\n\treturn ist;\n}\n#line 3 \"data-structure/SegTree.hpp\"\
    \ntemplate<class T, T (*nodef)(const T&, const T&)>\nclass SegTree {\nprotected:\n\
    \tunsigned int n = 1, rank = 0;\n\tstd::vector<T> node;\n\tT ident;\npublic:\n\
    \tSegTree(unsigned int m, T init, T e_):ident(e_) {\n\t\twhile (n < m) {\n\t\t\
    \tn *= 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2 * n, ident);\n\t\tfor (unsigned\
    \ int i = n; i < 2 * n; i++)node[i] = init;\n\t\tfor (unsigned int i = n - 1;\
    \ i > 0; i--)node[i] = nodef(node[i << 1], node[i << 1 | 1]);\n\t}\n\tSegTree(const\
    \ std::vector<T>& initvec, T e_):ident(e_) {\n\t\tunsigned int m = initvec.size();\n\
    \t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2 *\
    \ n, ident);\n\t\tfor (unsigned int i = n; i < 2 * n; i++) {\n\t\t\tif (i - n\
    \ < m)node[i] = initvec[i - n];\n\t\t}\n\t\tfor (unsigned int i = n - 1; i > 0;\
    \ i--)node[i] = nodef(node[i << 1], node[i << 1 | 1]);\n\t}\n\tvirtual void update(int\
    \ i, T x) {\n\t\ti += n;\n\t\tnode[i] = x;\n\t\twhile (i != 1) {\n\t\t\ti >>=\
    \ 1;\n\t\t\tnode[i] = nodef(node[2 * i], node[2 * i + 1]);\n\t\t}\n\t}\n\tvirtual\
    \ T query(int l, int r) {\n\t\tl += n; r += n;\n\t\tT ls = ident, rs = ident;\n\
    \t\twhile (l < r) {\n\t\t\tif (l & 1) ls = nodef(ls, node[l++]);\n\t\t\tif (r\
    \ & 1) rs = nodef(node[--r], rs);\n\t\t\tl >>= 1; r >>= 1;\n\t\t}\n\t\treturn\
    \ nodef(ls, rs);\n\t}\n\tvirtual T operator[](const int& x) {\n\t\treturn node[n\
    \ + x];\n\t}\n\tvoid print() {\n\t\trep(i, n)std::cout << operator[](i) << \"\
    \ \";\n\t\tstd::cout << std::endl;\n\t}\n};\nstatic lint RSQ_nodef(const lint&\
    \ lhs, const lint& rhs){return lhs + rhs;}\nclass RSQ :public SegTree<lint, RSQ_nodef>\
    \ {\n\tusing Base = SegTree<lint, RSQ_nodef>;\npublic:\n\ttemplate<class... Args>\n\
    \tRSQ(Args... args):Base(args..., 0){}\n};\nstatic lint RMiQ_nodef(const lint&\
    \ lhs, const lint& rhs){return std::min(lhs, rhs);}\nclass RMiQ :public SegTree<lint,\
    \ RMiQ_nodef> {\n\tusing Base = SegTree<lint, RMiQ_nodef>;\npublic:\n\ttemplate<class...\
    \ Args>\n\tRMiQ(Args... args):Base(args..., LINF){}\n};\nstatic lint RMaQ_nodef(const\
    \ lint& lhs, const lint& rhs){return std::max(lhs,rhs);}\nclass RMaQ :public SegTree<lint,\
    \ RMaQ_nodef> {\n\tusing Base = SegTree<lint, RMaQ_nodef>;\npublic:\n\ttemplate<class...\
    \ Args>\n\tRMaQ(Args... args):Base(args..., -LINF){}\n};\n#line 4 \"data-structure/IntervalSegTree.hpp\"\
    \ntemplate<typename T, typename U,\n\tT (*nodef)(const T&, const T&),\n\tvoid\
    \ (*lazyf)(U&, const U&),\n\tvoid (*updf)(T&, const U&, const unsigned int&)>\n\
    class IntervalSegTree :public SegTree<T, nodef> {\n\tusing Base = SegTree<T, nodef>;\n\
    protected:\n\tusing Base::n;\n\tusing Base::rank;\n\tusing Base::node;\n\tusing\
    \ Base::ident;\n\tstd::vector<U> lazy;\n\tstd::vector<bool> lazyflag;\n\tstd::vector<int>\
    \ width;\n\tvoid eval(int k) {\n\t\tfor (int i = rank; i > 0; i--) {\n\t\t\tint\
    \ nk = k >> i;\n\t\t\tif (lazyflag[nk]) {\n\t\t\t\tupdf(node[2 * nk], lazy[nk],\
    \ width[2 * nk]);\n\t\t\t\tupdf(node[2 * nk + 1], lazy[nk], width[2 * nk + 1]);\n\
    \t\t\t\tif (lazyflag[2 * nk])lazyf(lazy[2 * nk], lazy[nk]);\n\t\t\t\telse lazy[2\
    \ * nk] = lazy[nk];\n\t\t\t\tif (lazyflag[2 * nk + 1])lazyf(lazy[2 * nk + 1],\
    \ lazy[nk]);\n\t\t\t\telse lazy[2 * nk + 1] = lazy[nk];\n\t\t\t\tlazyflag[2 *\
    \ nk] = lazyflag[2 * nk + 1] = true;\n\t\t\t\tlazyflag[nk] = false;\n\t\t\t}\n\
    \t\t}\n\t}\npublic:\n\tIntervalSegTree(unsigned int m, T init, T e_) :Base(m,\
    \ init, e_) {\n\t\tlazy.resize(2 * n); lazyflag.resize(2 * n); width.resize(2\
    \ * n);\n\t\twidth[1] = n;\n\t\tfor (unsigned int i = 2; i < 2 * n; i++) {\n\t\
    \t\twidth[i] = width[i >> 1] >> 1;\n\t\t}\n\t}\n\tIntervalSegTree(const std::vector<T>&\
    \ initvec, T e_) :Base(initvec, e_) {\n\t\tlazy.resize(2 * n); lazyflag.resize(2\
    \ * n); width.resize(2 * n);\n\t\twidth[1] = n;\n\t\tfor (unsigned int i = 2;\
    \ i < 2 * n; i++) {\n\t\t\twidth[i] = width[i >> 1] >> 1;\n\t\t}\n\t}\n\tvoid\
    \ update(int i, U x) {\n\t\ti += n;\n\t\teval(i);\n\t\tupdf(node[i], x, width[i]);\n\
    \t\tif (lazyflag[i])lazyf(lazy[i], x);\n\t\telse {\n\t\t\tlazyflag[i] = true;\n\
    \t\t\tlazy[i] = x;\n\t\t}\n\t\twhile (i /= 2)node[i] = nodef(node[2 * i], node[2\
    \ * i + 1]);\n\t}\n\tvoid update(int l, int r, U x) {\n\t\tl += n; r += n;\n\t\
    \tint nl = l, nr = r;\n\t\twhile (!(nl & 1))nl >>= 1;\n\t\twhile (!(nr & 1))nr\
    \ >>= 1;\n\t\tnr--;\n\t\teval(nl); eval(nr);\n\t\twhile (l < r) {\n\t\t\tif (l\
    \ & 1) {\n\t\t\t\tupdf(node[l], x, width[l]);\n\t\t\t\tif (lazyflag[l])lazyf(lazy[l],\
    \ x);\n\t\t\t\telse {\n\t\t\t\t\tlazyflag[l] = true;\n\t\t\t\t\tlazy[l] = x;\n\
    \t\t\t\t}\n\t\t\t\tl++;\n\t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\tr--;\n\t\t\t\tupdf(node[r],\
    \ x, width[r]);\n\t\t\t\tif (lazyflag[r])lazyf(lazy[r], x);\n\t\t\t\telse {\n\t\
    \t\t\t\tlazyflag[r] = true;\n\t\t\t\t\tlazy[r] = x;\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    l >>= 1; r >>= 1;\n\t\t}\n\t\twhile (nl >>= 1)node[nl] = nodef(node[2 * nl], node[2\
    \ * nl + 1]);\n\t\twhile (nr >>= 1)node[nr] = nodef(node[2 * nr], node[2 * nr\
    \ + 1]);\n\t}\n\tT query(int l, int r) {\n\t\tl += n; r += n;\n\t\teval(l); eval(r\
    \ - 1);\n\t\tT ls = ident, rs = ident;\n\t\twhile (l < r) {\n\t\t\tif (l & 1)ls\
    \ = nodef(ls, node[l++]);\n\t\t\tif (r & 1)rs = nodef(node[--r], rs);\n\t\t\t\
    l >>= 1; r >>= 1;\n\t\t}\n\t\treturn nodef(ls, rs);\n\t}\n\tT operator[](const\
    \ int& x) {\n\t\teval(n + x);\n\t\treturn node[n + x];\n\t}\n\tT queryForAll()\
    \ {\n\t\treturn node[1];\n\t}\n};\nstatic lint RAQRSQ_nodef(const lint& a, const\
    \ lint& b){return a + b;}\nstatic void RAQRSQ_lazyf(lint& a, const lint& b){a\
    \ += b;}\nstatic void RAQRSQ_updf(lint& a, const lint& b, const unsigned int&\
    \ width){a += width * b;}\nclass RAQRSQ :public IntervalSegTree<lint, lint, RAQRSQ_nodef,\
    \ RAQRSQ_lazyf, RAQRSQ_updf> {\n\tusing Base = IntervalSegTree<lint, lint, RAQRSQ_nodef,\
    \ RAQRSQ_lazyf, RAQRSQ_updf>;\npublic:\n\ttemplate<class... Args> RAQRSQ(Args...\
    \ args):Base(args..., 0){}\n};\nstatic lint RAQRMiQ_nodef(const lint& a, const\
    \ lint& b){return std::min(a, b);}\nstatic void RAQRMiQ_lazyf(lint& a, const lint&\
    \ b){a += b;}\nstatic void RAQRMiQ_updf(lint& a, const lint& b, const unsigned\
    \ int& width){a += b;}\nclass RAQRMiQ :public IntervalSegTree<lint, lint, RAQRMiQ_nodef,\
    \ RAQRMiQ_lazyf, RAQRMiQ_updf> {\n\tusing Base = IntervalSegTree<lint, lint, RAQRMiQ_nodef,\
    \ RAQRMiQ_lazyf, RAQRMiQ_updf>;\npublic:\n\ttemplate<class... Args> RAQRMiQ(Args...\
    \ args):Base(args..., LINF){}\n};\nstatic lint RAQRMaQ_nodef(const lint& a, const\
    \ lint& b){return std::max(a, b);}\nstatic void RAQRMaQ_lazyf(lint& a, const lint&\
    \ b){a += b;}\nstatic void RAQRMaQ_updf(lint& a, const lint& b, const unsigned\
    \ int& width){a += b;}\nclass RAQRMaQ :public IntervalSegTree<lint, lint, RAQRMaQ_nodef,\
    \ RAQRMaQ_lazyf, RAQRMaQ_updf> {\n\tusing Base = IntervalSegTree<lint, lint, RAQRMaQ_nodef,\
    \ RAQRMaQ_lazyf, RAQRMaQ_updf>;\npublic:\n\ttemplate<class... Args> RAQRMaQ(Args...\
    \ args):Base(args..., -LINF){}\n};\nstatic lint RUQRSQ_nodef(const lint& a, const\
    \ lint& b){return a + b;}\nstatic void RUQRSQ_lazyf(lint& a, const lint& b){a\
    \ = b;}\nstatic void RUQRSQ_updf(lint& a, const lint& b, const unsigned int& width){a\
    \ = width * b;}\nclass RUQRSQ :public IntervalSegTree<lint, lint, RUQRSQ_nodef,\
    \ RUQRSQ_lazyf, RUQRSQ_updf> {\n\tusing Base = IntervalSegTree<lint, lint, RUQRSQ_nodef,\
    \ RUQRSQ_lazyf, RUQRSQ_updf>;\npublic:\n\ttemplate<class... Args> RUQRSQ(Args...\
    \ args):Base(args..., 0){}\n};\nstatic lint RUQRMiQ_nodef(const lint& a, const\
    \ lint& b){return std::min(a, b);}\nstatic void RUQRMiQ_lazyf(lint& a, const lint&\
    \ b){a = b;}\nstatic void RUQRMiQ_updf(lint& a, const lint& b, const unsigned\
    \ int& width){a = b;}\nclass RUQRMiQ :public IntervalSegTree<lint, lint, RUQRMiQ_nodef,\
    \ RUQRMiQ_lazyf, RUQRMiQ_updf> {\n\tusing Base = IntervalSegTree<lint, lint, RUQRMiQ_nodef,\
    \ RUQRMiQ_lazyf, RUQRMiQ_updf>;\npublic:\n\ttemplate<class... Args> RUQRMiQ(Args...\
    \ args):Base(args..., LINF){}\n};\nstatic lint RUQRMaQ_nodef(const lint& a, const\
    \ lint& b){return std::max(a, b);}\nstatic void RUQRMaQ_lazyf(lint& a, const lint&\
    \ b){a = b;}\nstatic void RUQRMaQ_updf(lint& a, const lint& b, const unsigned\
    \ int& width){a = b;}\nclass RUQRMaQ :public IntervalSegTree<lint, lint, RUQRMaQ_nodef,\
    \ RUQRMaQ_lazyf, RUQRMaQ_updf> {\n\tusing Base = IntervalSegTree<lint, lint, RUQRMaQ_nodef,\
    \ RUQRMaQ_lazyf, RUQRMaQ_updf>;\npublic:\n\ttemplate<class... Args> RUQRMaQ(Args...\
    \ args):Base(args..., -LINF){}\n};\n#line 5 \"test/yosupo/range_affine_range_sum.test.cpp\"\
    \nusing ModInt=StaticModInt<998244353>;\nusing MP = std::pair<ModInt, ModInt>;\n\
    ModInt nodef(const ModInt& a,const ModInt& b){return a+b;}\nvoid lazyf(MP& a,const\
    \ MP& b){a={a.first*b.first,a.second*b.first+b.second};}\nvoid updf(ModInt& a,const\
    \ MP& b,const unsigned int& width){a=b.first*a+b.second*width;}\nclass MySeg:public\
    \ IntervalSegTree<ModInt, MP, nodef, lazyf, updf>{\n\tusing Base = IntervalSegTree<ModInt,\
    \ MP, nodef, lazyf, updf>;\npublic:\n\tMySeg(const std::vector<ModInt>& initvec):Base(initvec,\
    \ 0){}\n};\nint n,q;\nstd::vector<ModInt> vec;\nint main(){\n\tscanf(\"%d%d\"\
    ,&n,&q);\n\tvec.resize(n);\n\trep(i,n){\n\t\tint tmp;\n\t\tscanf(\"%d\",&tmp);\n\
    \t\tvec[i]=tmp;\n\t}\n\tMySeg st(vec);\n\trep(i,q){\n\t\tint t;\n\t\tscanf(\"\
    %d\",&t);\n\t\tif(t==0){\n\t\t\tint l,r,b,c;\n\t\t\tscanf(\"%d%d%d%d\",&l,&r,&b,&c);\n\
    \t\t\tst.update(l,r,{b,c});\n\t\t}\n\t\telse{\n\t\t\tint l,r;\n\t\t\tscanf(\"\
    %d%d\",&l,&r);\n\t\t\tprintf(\"%d\\n\",st.query(l,r));\n\t\t}\n\t}\n\treturn 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include \"../../other/template.hpp\"\n#include \"../../algebraic/StaticModInt.hpp\"\
    \n#include \"../../data-structure/IntervalSegTree.hpp\"\nusing ModInt=StaticModInt<998244353>;\n\
    using MP = std::pair<ModInt, ModInt>;\nModInt nodef(const ModInt& a,const ModInt&\
    \ b){return a+b;}\nvoid lazyf(MP& a,const MP& b){a={a.first*b.first,a.second*b.first+b.second};}\n\
    void updf(ModInt& a,const MP& b,const unsigned int& width){a=b.first*a+b.second*width;}\n\
    class MySeg:public IntervalSegTree<ModInt, MP, nodef, lazyf, updf>{\n\tusing Base\
    \ = IntervalSegTree<ModInt, MP, nodef, lazyf, updf>;\npublic:\n\tMySeg(const std::vector<ModInt>&\
    \ initvec):Base(initvec, 0){}\n};\nint n,q;\nstd::vector<ModInt> vec;\nint main(){\n\
    \tscanf(\"%d%d\",&n,&q);\n\tvec.resize(n);\n\trep(i,n){\n\t\tint tmp;\n\t\tscanf(\"\
    %d\",&tmp);\n\t\tvec[i]=tmp;\n\t}\n\tMySeg st(vec);\n\trep(i,q){\n\t\tint t;\n\
    \t\tscanf(\"%d\",&t);\n\t\tif(t==0){\n\t\t\tint l,r,b,c;\n\t\t\tscanf(\"%d%d%d%d\"\
    ,&l,&r,&b,&c);\n\t\t\tst.update(l,r,{b,c});\n\t\t}\n\t\telse{\n\t\t\tint l,r;\n\
    \t\t\tscanf(\"%d%d\",&l,&r);\n\t\t\tprintf(\"%d\\n\",st.query(l,r));\n\t\t}\n\t\
    }\n\treturn 0;\n}"
  dependsOn:
  - other/template.hpp
  - algebraic/StaticModInt.hpp
  - algebraic/DynamicModInt.hpp
  - data-structure/IntervalSegTree.hpp
  - data-structure/SegTree.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-11-21 16:06:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.test.cpp
- /verify/test/yosupo/range_affine_range_sum.test.cpp.html
title: test/yosupo/range_affine_range_sum.test.cpp
---
