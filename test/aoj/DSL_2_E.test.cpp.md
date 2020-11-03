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
    \ <algorithm>\n#include <bitset>\n#include <cassert>\n#include <cfloat>\n#include\
    \ <climits>\n#include <cmath>\n#include <complex>\n#include <ctime>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <iterator>\n#include <list>\n#include <map>\n#include <memory>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <string.h>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <vector>\n#define rep(i,n) for(int i=0;i<(n);i++)\n\
    #define REP(i,n) for(int i=1;i<=(n);i++)\n#define all(V) V.begin(),V.end()\ntypedef\
    \ unsigned int uint;\ntypedef long long lint;\ntypedef unsigned long long ulint;\n\
    typedef std::pair<int, int> P;\ntypedef std::pair<lint, lint> LP;\nconstexpr int\
    \ INF = INT_MAX/2;\nconstexpr lint LINF = LLONG_MAX/2;\nconstexpr double eps =\
    \ DBL_EPSILON;\nconstexpr double PI=3.141592653589793238462643383279;\ntemplate<class\
    \ T>\nclass prique :public std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ {};\ntemplate <class T, class U>\ninline bool chmax(T& lhs, const U& rhs) {\n\
    \tif (lhs < rhs) {\n\t\tlhs = rhs;\n\t\treturn 1;\n\t}\n\treturn 0;\n}\ntemplate\
    \ <class T, class U>\ninline bool chmin(T& lhs, const U& rhs) {\n\tif (lhs > rhs)\
    \ {\n\t\tlhs = rhs;\n\t\treturn 1;\n\t}\n\treturn 0;\n}\ninline lint gcd(lint\
    \ a, lint b) {\n\twhile (b) {\n\t\tlint c = a;\n\t\ta = b; b = c % b;\n\t}\n\t\
    return a;\n}\ninline lint lcm(lint a, lint b) {\n\treturn a / gcd(a, b) * b;\n\
    }\nbool isprime(lint n) {\n\tif (n == 1)return false;\n\tfor (int i = 2; i * i\
    \ <= n; i++) {\n\t\tif (n % i == 0)return false;\n\t}\n\treturn true;\n}\ntemplate<typename\
    \ T>\nT mypow(T a, lint b) {\n\tT res(1);\n\twhile(b){\n\t\tif(b&1)res*=a;\n\t\
    \ta*=a;\n\t\tb>>=1;\n\t}\n\treturn res;\n}\nlint modpow(lint a, lint b, lint m)\
    \ {\n\tlint res(1);\n\twhile(b){\n\t\tif(b&1){\n\t\t\tres*=a;res%=m;\n\t\t}\n\t\
    \ta*=a;a%=m;\n\t\tb>>=1;\n\t}\n\treturn res;\n}\ntemplate<typename T>\nvoid printArray(std::vector<T>&\
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
    \ 3 \"data-structure/SegTree.hpp\"\ntemplate<typename T>\nclass SegTree {\nprotected:\n\
    \tunsigned int n = 1, rank = 0;\n\tstd::vector<T> node;\n\tT nodee;\n\tvirtual\
    \ T nodef(const T&, const T&)const = 0;\npublic:\n\tSegTree(unsigned int m, T\
    \ init, T nodee):nodee(nodee) {\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\
    \t\t}\n\t\tnode.resize(2 * n, nodee);\n\t\tfor (unsigned int i = n; i < 2 * n;\
    \ i++)node[i] = init;\n\t}\n\tSegTree(const std::vector<T>& initvec, T nodee):nodee(nodee)\
    \ {\n\t\tunsigned int m = initvec.size();\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\
    \t\t\trank++;\n\t\t}\n\t\tnode.resize(2 * n, nodee);\n\t\tfor (unsigned int i\
    \ = n; i < 2 * n; i++) {\n\t\t\tif (i - n < m)node[i] = initvec[i - n];\n\t\t\
    }\n\t}\n\tvirtual void update(int i, T x) {\n\t\ti += n;\n\t\tnode[i] = x;\n\t\
    \twhile (i != 1) {\n\t\t\ti >>= 1;\n\t\t\tnode[i] = nodef(node[2 * i], node[2\
    \ * i + 1]);\n\t\t}\n\t}\n\tvirtual T query(int l, int r) {\n\t\tl += n; r +=\
    \ n;\n\t\tT ls = nodee, rs = nodee;\n\t\twhile (l < r) {\n\t\t\tif (l & 1) ls\
    \ = nodef(ls, node[l++]);\n\t\t\tif (r & 1) rs = nodef(node[--r], rs);\n\t\t\t\
    l >>= 1; r >>= 1;\n\t\t}\n\t\treturn nodef(ls, rs);\n\t}\n\tvirtual T operator[](const\
    \ int& x) {\n\t\treturn node[n + x];\n\t}\n\tvoid print() {\n\t\trep(i, n)std::cout\
    \ << operator[](i) << \" \";\n\t\tstd::cout << std::endl;\n\t}\n};\nclass RSQ\
    \ :public SegTree<lint> {\n\tlint nodef(const lint& lhs,const lint& rhs)const{return\
    \ lhs+rhs;}\npublic:\n\tRSQ(int size, const lint& def = 0) :SegTree<lint>(size,\
    \ def, 0) {\n\t\tfor(int i=n-1;i>0;i--)node[i]=nodef(node[i<<1],node[i<<1|1]);\n\
    \t}\n\tRSQ(const std::vector<lint>& initvec) :SegTree<lint>(initvec, 0) {\n\t\t\
    for(int i=n-1;i>0;i--)node[i]=nodef(node[i<<1],node[i<<1|1]);\n\t}\n};\nclass\
    \ RMiQ :public SegTree<lint> {\n\tlint nodef(const lint& lhs,const lint& rhs)const{return\
    \ std::min(lhs,rhs);}\npublic:\n\tRMiQ(int size, const lint& def = 0) :SegTree<lint>(size,\
    \ def, LINF) {\n\t\tfor(int i=n-1;i>0;i--)node[i]=nodef(node[i<<1],node[i<<1|1]);\n\
    \t}\n\tRMiQ(const std::vector<lint>& initvec) :SegTree<lint>(initvec, LINF) {\n\
    \t\tfor(int i=n-1;i>0;i--)node[i]=nodef(node[i<<1],node[i<<1|1]);\n\t}\n};\nclass\
    \ RMaQ :public SegTree<lint> {\n\tlint nodef(const lint& lhs,const lint& rhs)const{return\
    \ std::max(lhs,rhs);}\npublic:\n\tRMaQ(int size, const lint& def = 0) :SegTree<lint>(size,\
    \ def, -LINF) {\n\t\tfor(int i=n-1;i>0;i--)node[i]=nodef(node[i<<1],node[i<<1|1]);\n\
    \t}\n\tRMaQ(const std::vector<lint>& initvec) :SegTree<lint>(initvec, -LINF) {\n\
    \t\tfor(int i=n-1;i>0;i--)node[i]=nodef(node[i<<1],node[i<<1|1]);\n\t}\n};\n#line\
    \ 4 \"data-structure/IntervalSegTree.hpp\"\ntemplate<typename T, typename U>\n\
    class IntervalSegTree :public SegTree<T> {\nprotected:\n\tusing SegTree<T>::n;\n\
    \tusing SegTree<T>::rank;\n\tusing SegTree<T>::node;\n\tusing SegTree<T>::nodef;\n\
    \tusing SegTree<T>::nodee;\n\tstd::vector<U> lazy;\n\tstd::vector<bool> lazyflag;\n\
    \tstd::vector<int> width;\n\tvirtual void lazyf(U&, const U&) = 0;\n\tvirtual\
    \ void updf(T&, const U&, const unsigned int&) = 0;\n\tvoid eval(int k) {\n\t\t\
    for (int i = rank; i > 0; i--) {\n\t\t\tint nk = k >> i;\n\t\t\tif (lazyflag[nk])\
    \ {\n\t\t\t\tupdf(node[2 * nk], lazy[nk], width[2 * nk]);\n\t\t\t\tupdf(node[2\
    \ * nk + 1], lazy[nk], width[2 * nk + 1]);\n\t\t\t\tif (lazyflag[2 * nk])lazyf(lazy[2\
    \ * nk], lazy[nk]);\n\t\t\t\telse lazy[2 * nk] = lazy[nk];\n\t\t\t\tif (lazyflag[2\
    \ * nk + 1])lazyf(lazy[2 * nk + 1], lazy[nk]);\n\t\t\t\telse lazy[2 * nk + 1]\
    \ = lazy[nk];\n\t\t\t\tlazyflag[2 * nk] = lazyflag[2 * nk + 1] = true;\n\t\t\t\
    \tlazyflag[nk] = false;\n\t\t\t}\n\t\t}\n\t}\npublic:\n\tIntervalSegTree(unsigned\
    \ int m, T init, T nodee) :SegTree<T>(m, init, nodee) {\n\t\tlazy.resize(2 * n);\
    \ lazyflag.resize(2 * n); width.resize(2 * n);\n\t\twidth[1] = n;\n\t\tfor (unsigned\
    \ int i = 2; i < 2 * n; i++) {\n\t\t\twidth[i] = width[i >> 1] >> 1;\n\t\t}\n\t\
    }\n\tIntervalSegTree(T nodee, const std::vector<T>& initvec) :SegTree<T>(initvec,\
    \ nodee) {\n\t\tlazy.resize(2 * n); lazyflag.resize(2 * n); width.resize(2 * n);\n\
    \t\twidth[1] = n;\n\t\tfor (unsigned int i = 2; i < 2 * n; i++) {\n\t\t\twidth[i]\
    \ = width[i >> 1] >> 1;\n\t\t}\n\t}\n\tvoid update(int i, U x) {\n\t\ti += n;\n\
    \t\teval(i);\n\t\tupdf(node[i], x, width[i]);\n\t\tif (lazyflag[i])lazyf(lazy[i],\
    \ x);\n\t\telse {\n\t\t\tlazyflag[i] = true;\n\t\t\tlazy[i] = x;\n\t\t}\n\t\t\
    while (i /= 2)node[i] = nodef(node[2 * i], node[2 * i + 1]);\n\t}\n\tvoid update(int\
    \ l, int r, U x) {\n\t\tl += n; r += n;\n\t\tint nl = l, nr = r;\n\t\twhile (!(nl\
    \ & 1))nl >>= 1;\n\t\twhile (!(nr & 1))nr >>= 1;\n\t\tnr--;\n\t\teval(nl); eval(nr);\n\
    \t\twhile (l < r) {\n\t\t\tif (l & 1) {\n\t\t\t\tupdf(node[l], x, width[l]);\n\
    \t\t\t\tif (lazyflag[l])lazyf(lazy[l], x);\n\t\t\t\telse {\n\t\t\t\t\tlazyflag[l]\
    \ = true;\n\t\t\t\t\tlazy[l] = x;\n\t\t\t\t}\n\t\t\t\tl++;\n\t\t\t}\n\t\t\tif\
    \ (r & 1) {\n\t\t\t\tr--;\n\t\t\t\tupdf(node[r], x, width[r]);\n\t\t\t\tif (lazyflag[r])lazyf(lazy[r],\
    \ x);\n\t\t\t\telse {\n\t\t\t\t\tlazyflag[r] = true;\n\t\t\t\t\tlazy[r] = x;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tl >>= 1; r >>= 1;\n\t\t}\n\t\twhile (nl >>= 1)node[nl]\
    \ = nodef(node[2 * nl], node[2 * nl + 1]);\n\t\twhile (nr >>= 1)node[nr] = nodef(node[2\
    \ * nr], node[2 * nr + 1]);\n\t}\n\tT query(int l, int r) {\n\t\tl += n; r +=\
    \ n;\n\t\teval(l); eval(r - 1);\n\t\tT ls = nodee, rs = nodee;\n\t\twhile (l <\
    \ r) {\n\t\t\tif (l & 1)ls = nodef(ls, node[l++]);\n\t\t\tif (r & 1)rs = nodef(node[--r],\
    \ rs);\n\t\t\tl >>= 1; r >>= 1;\n\t\t}\n\t\treturn nodef(ls, rs);\n\t}\n\tT operator[](const\
    \ int& x) {\n\t\teval(n + x);\n\t\treturn node[n + x];\n\t}\n\tT queryForAll()\
    \ {\n\t\treturn node[1];\n\t}\n};\nclass RAQRSQ :public IntervalSegTree<lint,\
    \ lint> {\n\tlint nodef(const lint& a, const lint& b)const { return a + b; }\n\
    \tvoid lazyf(lint& a, const lint& b) { a += b; }\n\tvoid updf(lint& a, const lint&\
    \ b, const unsigned int& width) { a += width * b; }\npublic:\n\tRAQRSQ(int size,\
    \ const lint& def = 0) :IntervalSegTree<lint, lint>(size, def, 0) {\n\t\tfor (int\
    \ i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);\n\t}\n\t\
    RAQRSQ(const std::vector<lint>& initvec) :IntervalSegTree<lint, lint>((lint)0,\
    \ initvec) {\n\t\tfor (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i],\
    \ node[2 * i + 1]);\n\t}\n};\nclass RAQRMiQ :public IntervalSegTree<lint, lint>\
    \ {\n\tlint nodef(const lint& a, const lint& b)const { return std::min(a, b);\
    \ }\n\tvoid lazyf(lint& a, const lint& b) { a += b; }\n\tvoid updf(lint& a, const\
    \ lint& b, const unsigned int& width) { a += b; }\npublic:\n\tRAQRMiQ(int size,\
    \ const lint& def = 0) :IntervalSegTree<lint, lint>(size, def, LINF) {\n\t\tfor\
    \ (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);\n\t\
    }\n\tRAQRMiQ(const std::vector<lint>& initvec) :IntervalSegTree<lint, lint>(LINF,\
    \ initvec) {\n\t\tfor (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i],\
    \ node[2 * i + 1]);\n\t}\n};\nclass RAQRMaQ :public IntervalSegTree<lint, lint>\
    \ {\n\tlint nodef(const lint& a, const lint& b)const { return std::max(a, b);\
    \ }\n\tvoid lazyf(lint& a, const lint& b) { a += b; }\n\tvoid updf(lint& a, const\
    \ lint& b, const unsigned int& width) { a += b; }\npublic:\n\tRAQRMaQ(unsigned\
    \ int size, const lint& def = 0) :IntervalSegTree<lint, lint>(size, def, -LINF)\
    \ {\n\t\tfor (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 *\
    \ i + 1]);\n\t}\n\tRAQRMaQ(const std::vector<lint>& initvec) :IntervalSegTree<lint,\
    \ lint>(-LINF, initvec) {\n\t\tfor (int i = n - 1; i > 0; i--)node[i] = nodef(node[2\
    \ * i], node[2 * i + 1]);\n\t}\n};\nclass RUQRSQ :public IntervalSegTree<lint,\
    \ lint> {\n\tlint nodef(const lint& a, const lint& b)const { return a + b; }\n\
    \tvoid lazyf(lint& a, const lint& b) { a = b; }\n\tvoid updf(lint& a, const lint&\
    \ b, const unsigned int& width) { a = width * b; }\npublic:\n\tRUQRSQ(int size,\
    \ const lint& def = 0) :IntervalSegTree<lint, lint>(size, def, 0) {\n\t\tfor (int\
    \ i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);\n\t}\n\t\
    RUQRSQ(const std::vector<lint>& initvec) :IntervalSegTree<lint, lint>((lint)0,\
    \ initvec) {\n\t\tfor (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i],\
    \ node[2 * i + 1]);\n\t}\n};\nclass RUQRMiQ :public IntervalSegTree<lint, lint>\
    \ {\n\tlint nodef(const lint& a, const lint& b)const { return std::min(a, b);\
    \ }\n\tvoid lazyf(lint& a, const lint& b) { a = b; }\n\tvoid updf(lint& a, const\
    \ lint& b, const unsigned int& width) { a = b; }\npublic:\n\tRUQRMiQ(int size,\
    \ const lint& def = 0) :IntervalSegTree<lint, lint>(size, def, LINF) {\n\t\tfor\
    \ (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);\n\t\
    }\n\tRUQRMiQ(const std::vector<lint>& initvec) :IntervalSegTree<lint, lint>(LINF,\
    \ initvec) {\n\t\tfor (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i],\
    \ node[2 * i + 1]);\n\t}\n};\nclass RUQRMaQ :public IntervalSegTree<lint, lint>\
    \ {\n\tlint nodef(const lint& a, const lint& b)const { return std::max(a, b);\
    \ }\n\tvoid lazyf(lint& a, const lint& b) { a = b; }\n\tvoid updf(lint& a, const\
    \ lint& b, const unsigned int& width) { a = b; }\npublic:\n\tRUQRMaQ(int size,\
    \ const lint& def = 0) :IntervalSegTree<lint, lint>(size, def, -LINF) {\n\t\t\
    for (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i], node[2 * i + 1]);\n\
    \t}\n\tRUQRMaQ(const std::vector<lint>& initvec) :IntervalSegTree<lint, lint>(-LINF,\
    \ initvec) {\n\t\tfor (int i = n - 1; i > 0; i--)node[i] = nodef(node[2 * i],\
    \ node[2 * i + 1]);\n\t}\n};\n#line 4 \"test/aoj/DSL_2_E.test.cpp\"\nint n,q;\n\
    int main(){\n\tscanf(\"%d%d\",&n,&q);\n\tRAQRSQ st(n,0);\n\trep(i,q){\n\t\tint\
    \ t;\n\t\tscanf(\"%d\",&t);\n\t\tif(t==0){\n\t\t\tint s,t,x;\n\t\t\tscanf(\"%d%d%d\"\
    ,&s,&t,&x);\n\t\t\tst.update(s-1,t,x);\n\t\t}\n\t\telse{\n\t\t\tint p;\n\t\t\t\
    scanf(\"%d\",&p);\n\t\t\tprintf(\"%d\\n\",st[p-1]);\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../data-structure/IntervalSegTree.hpp\"\
    \nint n,q;\nint main(){\n\tscanf(\"%d%d\",&n,&q);\n\tRAQRSQ st(n,0);\n\trep(i,q){\n\
    \t\tint t;\n\t\tscanf(\"%d\",&t);\n\t\tif(t==0){\n\t\t\tint s,t,x;\n\t\t\tscanf(\"\
    %d%d%d\",&s,&t,&x);\n\t\t\tst.update(s-1,t,x);\n\t\t}\n\t\telse{\n\t\t\tint p;\n\
    \t\t\tscanf(\"%d\",&p);\n\t\t\tprintf(\"%d\\n\",st[p-1]);\n\t\t}\n\t}\n}"
  dependsOn:
  - other/template.hpp
  - data-structure/IntervalSegTree.hpp
  - data-structure/SegTree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_E.test.cpp
  requiredBy: []
  timestamp: '2020-09-12 16:29:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_E.test.cpp
- /verify/test/aoj/DSL_2_E.test.cpp.html
title: test/aoj/DSL_2_E.test.cpp
---
