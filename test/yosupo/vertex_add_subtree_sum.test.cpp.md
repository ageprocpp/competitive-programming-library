---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: graph/HeavyLightDecomposition.hpp
    title: graph/HeavyLightDecomposition.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/BIT.hpp
    title: data-structure/BIT.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo/vertex_add_subtree_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n#line 2 \"other/template.hpp\"\
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
    \ 3 \"graph/HeavyLightDecomposition.hpp\"\nclass HeavyLightDecomposition{\n\t\
    int n,index=0;\n\tvoid size_dfs(int node){\n\t\tsize[node]=1;\n\t\tfor(int &i:vec[node]){\n\
    \t\t\tif(par[node]==i)continue;\n\t\t\tpar[i]=node;\n\t\t\tsize_dfs(i);\n\t\t\t\
    size[node]+=size[i];\n\t\t\tif(size[i]>size[vec[node][0]])std::swap(i,vec[node][0]);\n\
    \t\t}\n\t}\n\tvoid build_dfs(int node){\n\t\tlabel[node]=index++;\n\t\tfor(int&\
    \ i:vec[node]){\n\t\t\tif(par[node]!=i){\n\t\t\t\thead[i]=(i==vec[node][0]?head[node]:i);\n\
    \t\t\t\tbuild_dfs(i);\n\t\t\t}\n\t\t}\n\t\tlast[node]=index;\n\t}\npublic:\n\t\
    std::vector<std::vector<int>> vec;\n\tstd::vector<int> size,par,head,label,last;\n\
    \tHeavyLightDecomposition(){}\n\tHeavyLightDecomposition(int m):n(m){init(n);}\n\
    \tvoid init(int m){\n\t\tn=m;\n\t\tvec.resize(n);size.resize(n);par.resize(n);head.resize(n);label.resize(n);last.resize(n);\n\
    \t}\n\tvoid add_edge(int u,int v){\n\t\tvec[u].emplace_back(v);\n\t\tvec[v].emplace_back(u);\n\
    \t}\n\tvoid build(int root){\n\t\tstd::fill(all(par),-1);\n\t\tsize_dfs(root);\n\
    \t\tbuild_dfs(root);\n\t}\n\ttemplate<typename F>\n\tvoid each_edge(int u,int\
    \ v,const F &func)const{\n\t\twhile(true){\n\t\t\tif(label[u]>label[v])std::swap(u,v);\n\
    \t\t\tif(head[u]==head[v]){\n\t\t\t\tif(label[u]!=label[v])func(label[u]+1,label[v]);\n\
    \t\t\t\treturn;\n\t\t\t}\n\t\t\tfunc(label[head[v]],label[v]);\n\t\t\tv=par[head[v]];\n\
    \t\t}\n\t}\n\ttemplate<typename F>\n\tvoid each_vertex(int u,int v,const F& func)const{\n\
    \t\twhile(true){\n\t\t\tif(label[u]>label[v])std::swap(u,v);\n\t\t\tif(head[u]==head[v]){\n\
    \t\t\t\tfunc(label[u],label[v]);\n\t\t\t\treturn;\n\t\t\t}\n\t\t\tfunc(label[head[v]],label[v]);\n\
    \t\t\tv=par[head[v]];\n\t\t}\n\t}\n\tint lca(int u,int v)const{\n\t\twhile(true){\n\
    \t\t\tif(label[u]>label[v])std::swap(u,v);\n\t\t\tif(head[u]==head[v])return u;\n\
    \t\t\tv=par[head[v]];\n\t\t}\n\t}\n\tvoid clear(){\n\t\tvec.clear();size.clear();par.clear();head.clear();label.clear();last.clear();\n\
    \t}\n};\n#line 3 \"data-structure/BIT.hpp\"\ntemplate<typename T>\nclass BIT {\n\
    \tint n;\n\tstd::vector<T> bit;\nprivate:\n\tT query(int a) {\n\t\tT cnt = 0;\n\
    \t\twhile (a > 0) {\n\t\t\tcnt += bit[a];\n\t\t\ta -= a & -a;\n\t\t}\n\t\treturn\
    \ cnt;\n\t}\npublic:\n\tBIT(int n) :n(n) {bit.resize(n + 1);}\n\tvoid add(int\
    \ a, T x) {\n\t\ta++;\n\t\twhile (a <= n) {\n\t\t\tbit[a] += x;\n\t\t\ta += a\
    \ & -a;\n\t\t}\n\t}\n\tT query(int l, int r) {return query(r) - query(l);}\n\t\
    void clear() {bit.assign(n + 1, 0);}\n\tint lower_bound(T x){\n\t\tint p=0,k=1;\n\
    \t\twhile(k*2<=n)k*=2;\n\t\twhile(k>0){\n\t\t\tif(p+k<=n&&bit[p+k]<x){\n\t\t\t\
    \tx-=bit[p+k];\n\t\t\t\tp+=k;\n\t\t\t}\n\t\t\tk/=2;\n\t\t}\n\t\treturn p;\n\t\
    }\n\tint upper_bound(T x){\n\t\tint p=0,k=1;\n\t\twhile(k*2<=n)k*=2;\n\t\twhile(k>0){\n\
    \t\t\tif(p+k<=n&&bit[p+k]<=x){\n\t\t\t\tx-=bit[p+k];\n\t\t\t\tp+=k;\n\t\t\t}\n\
    \t\t\tk/=2;\n\t\t}\n\t\treturn p;\n\t}\n};\n#line 5 \"test/yosupo/vertex_add_subtree_sum.test.cpp\"\
    \nint n,q,a[500010];\nint main(){\n\tscanf(\"%d%d\",&n,&q);\n\trep(i,n)scanf(\"\
    %d\",a+i);\n\tHeavyLightDecomposition hld(n);\n\tBIT<lint> bit(n);\n\tREP(i,n-1){\n\
    \t\tint p;\n\t\tscanf(\"%d\",&p);\n\t\thld.add_edge(i,p);\n\t}\n\thld.build(0);\n\
    \trep(i,n)bit.add(hld.label[i],a[i]);\n\trep(i,q){\n\t\tint t;\n\t\tscanf(\"%d\"\
    ,&t);\n\t\tif(t==0){\n\t\t\tint u,x;\n\t\t\tscanf(\"%d%d\",&u,&x);\n\t\t\tbit.add(hld.label[u],x);\n\
    \t\t}\n\t\telse{\n\t\t\tint u;\n\t\t\tscanf(\"%d\",&u);\n\t\t\tprintf(\"%lld\\\
    n\",bit.query(hld.label[u],hld.last[u]));\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include \"../../other/template.hpp\"\n#include \"../../graph/HeavyLightDecomposition.hpp\"\
    \n#include \"../../data-structure/BIT.hpp\"\nint n,q,a[500010];\nint main(){\n\
    \tscanf(\"%d%d\",&n,&q);\n\trep(i,n)scanf(\"%d\",a+i);\n\tHeavyLightDecomposition\
    \ hld(n);\n\tBIT<lint> bit(n);\n\tREP(i,n-1){\n\t\tint p;\n\t\tscanf(\"%d\",&p);\n\
    \t\thld.add_edge(i,p);\n\t}\n\thld.build(0);\n\trep(i,n)bit.add(hld.label[i],a[i]);\n\
    \trep(i,q){\n\t\tint t;\n\t\tscanf(\"%d\",&t);\n\t\tif(t==0){\n\t\t\tint u,x;\n\
    \t\t\tscanf(\"%d%d\",&u,&x);\n\t\t\tbit.add(hld.label[u],x);\n\t\t}\n\t\telse{\n\
    \t\t\tint u;\n\t\t\tscanf(\"%d\",&u);\n\t\t\tprintf(\"%lld\\n\",bit.query(hld.label[u],hld.last[u]));\n\
    \t\t}\n\t}\n}"
  dependsOn:
  - other/template.hpp
  - graph/HeavyLightDecomposition.hpp
  - data-structure/BIT.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-12 16:29:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html
title: test/yosupo/vertex_add_subtree_sum.test.cpp
---
