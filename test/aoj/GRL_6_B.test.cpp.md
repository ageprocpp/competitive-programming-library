---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/MinCostFlow.hpp
    title: graph/MinCostFlow.hpp
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B
  bundledCode: "#line 1 \"test/aoj/GRL_6_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B\"\
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
    \ 3 \"graph/MinCostFlow.hpp\"\nclass MinCostFlow{\n    class edge{\n    public:\n\
    \        int to,cap;\n        lint cost;\n        int rev,id;\n    };\n    int\
    \ n,idx=0,s,t;\n    lint curres=0;\n    std::vector<std::vector<edge>> vec;\n\
    \    std::vector<int> prevv,preve;\n    std::vector<lint> h,dist;\n    bool negative=false;\n\
    \    lint BellmanFord(){\n        dist.assign(n,LINF);\n        dist[s]=0;\n \
    \       rep(i,n-1){\n            rep(j,n){\n                rep(k,vec[j].size()){\n\
    \                    const edge &e=vec[j][k];\n                    if(e.cap>0&&chmin(dist[e.to],dist[j]+e.cost+h[j]-h[e.to])){\n\
    \                        prevv[e.to]=j;\n                        preve[e.to]=k;\n\
    \                    }\n                }\n            }\n        }\n        if(dist[t]==LINF){\n\
    \            std::cerr<<\"The demand is over maximum flow.\"<<std::endl;\n   \
    \         return -1;\n        }\n        rep(i,n)h[i]+=dist[i];\n        for(int\
    \ i=t;i!=s;i=prevv[i]){\n            vec[prevv[i]][preve[i]].cap--;\n        \
    \    vec[i][vec[prevv[i]][preve[i]].rev].cap++;\n        }\n        return h[t];\n\
    \    }\npublic:\n    MinCostFlow(int n,int s,int t):n(n),s(s),t(t){\n        vec.resize(n);\n\
    \        h.resize(n);\n        dist.resize(n);\n        prevv.resize(n);\n   \
    \     preve.resize(n);\n    }\n    void add_edge(int from,int to,int cap,lint\
    \ cost){\n        if(cost<0)negative=true;\n        vec[from].push_back({to,cap,cost,(int)vec[to].size(),-1});\n\
    \        vec[to].push_back({from,0,-cost,(int)vec[from].size()-1,idx++});\n  \
    \  }\n    lint add_flow(int f){\n        if(negative){\n            curres+=BellmanFord();\n\
    \            f--;\n            negative=false;\n        }\n        while(f>0){\n\
    \            dist.assign(n,LINF);\n            dist[s]=0;\n            prique<LP>\
    \ que;\n            que.push({0,s});\n            while(!que.empty()){\n     \
    \           LP p=que.top();\n                que.pop();\n                if(dist[p.second]<p.first)continue;\n\
    \                rep(i,vec[p.second].size()){\n                    edge &e=vec[p.second][i];\n\
    \                    if(e.cap>0&&chmin(dist[e.to],dist[p.second]+e.cost+h[p.second]-h[e.to])){\n\
    \                        prevv[e.to]=p.second;\n                        preve[e.to]=i;\n\
    \                        que.push({dist[e.to],e.to});\n                    }\n\
    \                }\n            }\n            if(dist[t]==LINF){\n          \
    \      std::cerr<<\"The demand is over the maximum flow.\"<<std::endl;\n     \
    \           return -1;\n            }\n            rep(i,n)h[i]+=dist[i];\n  \
    \          int d=f;\n            for(int i=t;i!=s;i=prevv[i]){\n             \
    \   chmin(d,vec[prevv[i]][preve[i]].cap);\n            }\n            f-=d;\n\
    \            curres+=(lint)d*h[t];\n            for(int i=t;i!=s;i=prevv[i]){\n\
    \                vec[prevv[i]][preve[i]].cap-=d;\n                vec[i][vec[prevv[i]][preve[i]].rev].cap+=d;\n\
    \            }\n        }\n        return curres;\n    }\n    std::vector<lint>\
    \ restore(){\n        std::vector<lint> res(idx);\n        rep(i,n){\n       \
    \     for(const auto& j:vec[i]){\n                if(j.id!=-1)res[j.id]=j.cap;\n\
    \            }\n        }\n        return res;\n    }\n    void reset(){\n   \
    \     rep(i,n){\n            for(auto& j:vec[i]){\n                if(j.id!=-1){\n\
    \                    vec[j.to][j.rev].cap+=j.cap;\n                    j.cap=0;\n\
    \                }\n            }\n        }\n    }\n};\n#line 4 \"test/aoj/GRL_6_B.test.cpp\"\
    \nint n,m,f;\nint main(){\n    scanf(\"%d%d%d\",&n,&m,&f);\n    MinCostFlow mcf(n,0,n-1);\n\
    \    rep(i,m){\n        int u,v,c,d;\n        scanf(\"%d%d%d%d\",&u,&v,&c,&d);\n\
    \        mcf.add_edge(u,v,c,d);\n    }\n    printf(\"%d\\n\",mcf.add_flow(f));\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B\"\n#include\
    \ \"../../other/template.hpp\"\n#include \"../../graph/MinCostFlow.hpp\"\nint\
    \ n,m,f;\nint main(){\n    scanf(\"%d%d%d\",&n,&m,&f);\n    MinCostFlow mcf(n,0,n-1);\n\
    \    rep(i,m){\n        int u,v,c,d;\n        scanf(\"%d%d%d%d\",&u,&v,&c,&d);\n\
    \        mcf.add_edge(u,v,c,d);\n    }\n    printf(\"%d\\n\",mcf.add_flow(f));\n\
    }"
  dependsOn:
  - other/template.hpp
  - graph/MinCostFlow.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_B.test.cpp
  requiredBy: []
  timestamp: '2020-09-20 14:20:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_B.test.cpp
- /verify/test/aoj/GRL_6_B.test.cpp.html
title: test/aoj/GRL_6_B.test.cpp
---
