---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/template.hpp
    title: other/template.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic/StaticModInt.hpp
    title: algebraic/StaticModInt.hpp
  - icon: ':heavy_check_mark:'
    path: algebraic/DynamicModInt.hpp
    title: algebraic/DynamicModInt.hpp
  - icon: ':heavy_check_mark:'
    path: graph/HeavyLightDecomposition.hpp
    title: graph/HeavyLightDecomposition.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/SegTree.hpp
    title: data-structure/SegTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/yosupo/vertex_set_path_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n#line\
    \ 2 \"other/template.hpp\"\n#define _CRT_SECURE_NO_WARNINGS\n#pragma target(\"\
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
    \ StaticModInt {\n\tlint value;\npublic:\n\tStaticModInt() : value(0) {}\n\ttemplate<typename\
    \ T>\n\tStaticModInt(T value = 0) : value(value) {\n\t\tif (value < 0)value =\
    \ -(lint)(-value % modulo) + modulo;\n\t\tthis->value = value % modulo;\n\t}\n\
    \tinline StaticModInt inv()const{return mypow(*this,modulo-2);}\n\tinline operator\
    \ int()const { return value; }\n\tinline StaticModInt& operator+=(const StaticModInt&\
    \ x) {\n\t\tvalue += x.value;\n\t\tif (value >= modulo)value -= modulo;\n\t\t\
    return *this;\n\t}\n\tinline StaticModInt& operator++() {\n\t\tif (value == modulo\
    \ - 1)value = 0;\n\t\telse value++;\n\t\treturn *this;\n\t}\n\tinline StaticModInt\
    \ operator++(int){\n\t\tStaticModInt res=*this;\n\t\t--*this;\n\t\treturn res;\n\
    \t}\n\tinline StaticModInt operator-()const {\n\t\treturn StaticModInt(0) -= *this;\n\
    \t}\n\tinline StaticModInt& operator-=(const StaticModInt& x) {\n\t\tvalue -=\
    \ x.value;\n\t\tif (value < 0)value += modulo;\n\t\treturn *this;\n\t}\n\tinline\
    \ StaticModInt& operator--() {\n\t\tif (value == 0)value = modulo - 1;\n\t\telse\
    \ value--;\n\t\treturn *this;\n\t}\n\tinline StaticModInt operator--(int){\n\t\
    \tStaticModInt res=*this;\n\t\t--*this;\n\t\treturn res;\n\t}\n\tinline StaticModInt&\
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
    \ {\n\tlint a;\n\tist >> a;\n\tx = a;\n\treturn ist;\n}\n#line 3 \"graph/HeavyLightDecomposition.hpp\"\
    \nclass HeavyLightDecomposition{\n\tint n,index=0;\n\tvoid size_dfs(int node){\n\
    \t\tsize[node]=1;\n\t\tfor(int &i:vec[node]){\n\t\t\tif(par[node]==i)continue;\n\
    \t\t\tpar[i]=node;\n\t\t\tsize_dfs(i);\n\t\t\tsize[node]+=size[i];\n\t\t\tif(size[i]>size[vec[node][0]])std::swap(i,vec[node][0]);\n\
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
    \t}\n};\n#line 3 \"data-structure/SegTree.hpp\"\ntemplate<typename T>\nclass SegTree\
    \ {\nprotected:\n\tunsigned int n = 1, rank = 0;\n\tstd::vector<T> node;\n\tT\
    \ nodee;\n\tvirtual T nodef(const T&, const T&)const = 0;\npublic:\n\tSegTree(unsigned\
    \ int m, T init, T nodee):nodee(nodee) {\n\t\twhile (n < m) {\n\t\t\tn *= 2;\n\
    \t\t\trank++;\n\t\t}\n\t\tnode.resize(2 * n, nodee);\n\t\tfor (unsigned int i\
    \ = n; i < 2 * n; i++)node[i] = init;\n\t}\n\tSegTree(const std::vector<T>& initvec,\
    \ T nodee):nodee(nodee) {\n\t\tunsigned int m = initvec.size();\n\t\twhile (n\
    \ < m) {\n\t\t\tn *= 2;\n\t\t\trank++;\n\t\t}\n\t\tnode.resize(2 * n, nodee);\n\
    \t\tfor (unsigned int i = n; i < 2 * n; i++) {\n\t\t\tif (i - n < m)node[i] =\
    \ initvec[i - n];\n\t\t}\n\t}\n\tvirtual void update(int i, T x) {\n\t\ti += n;\n\
    \t\tnode[i] = x;\n\t\twhile (i != 1) {\n\t\t\ti >>= 1;\n\t\t\tnode[i] = nodef(node[2\
    \ * i], node[2 * i + 1]);\n\t\t}\n\t}\n\tvirtual T query(int l, int r) {\n\t\t\
    l += n; r += n;\n\t\tT ls = nodee, rs = nodee;\n\t\twhile (l < r) {\n\t\t\tif\
    \ (l & 1) ls = nodef(ls, node[l++]);\n\t\t\tif (r & 1) rs = nodef(node[--r], rs);\n\
    \t\t\tl >>= 1; r >>= 1;\n\t\t}\n\t\treturn nodef(ls, rs);\n\t}\n\tvirtual T operator[](const\
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
    \ 6 \"test/yosupo/vertex_set_path_composite.test.cpp\"\nusing ModInt=StaticModInt<998244353>;\n\
    class MySeg:public SegTree<std::pair<ModInt,ModInt>>{\n\tusing MP=std::pair<ModInt,ModInt>;\n\
    \tMP nodef(const MP& lhs,const MP& rhs)const{\n\t\treturn {lhs.first*rhs.first,lhs.second*rhs.first+rhs.second};\n\
    \t}\npublic:\n\tMySeg(int n):SegTree<MP>(n,{1,0},{1,0}){}\n};\nint n,q;\nP a[200010];\n\
    int main(){\n\tscanf(\"%d%d\",&n,&q);\n\trep(i,n)scanf(\"%d%d\",&a[i].first,&a[i].second);\n\
    \tHeavyLightDecomposition hld(n);\n\tMySeg st1(n),st2(n);\n\trep(i,n-1){\n\t\t\
    int u,v;\n\t\tscanf(\"%d%d\",&u,&v);\n\t\thld.add_edge(u,v);\n\t}\n\thld.build(0);\n\
    \trep(i,n){\n\t\tst1.update(hld.label[i],a[i]);\n\t\tst2.update(n-1-hld.label[i],a[i]);\n\
    \t}\n\trep(i,q){\n\t\tint t;\n\t\tscanf(\"%d\",&t);\n\t\tif(t==0){\n\t\t\tint\
    \ p,c,d;\n\t\t\tscanf(\"%d%d%d\",&p,&c,&d);\n\t\t\ta[p]={c,d};\n\t\t\tst1.update(hld.label[p],{c,d});\n\
    \t\t\tst2.update(n-1-hld.label[p],{c,d});\n\t\t}\n\t\telse{\n\t\t\tint u,v,x;\n\
    \t\t\tscanf(\"%d%d%d\",&u,&v,&x);\n\t\t\tint t=hld.lca(u,v);\n\t\t\tstd::pair<ModInt,ModInt>\
    \ f1={1,0},f2={1,0};\n\t\t\thld.each_vertex(u,t,[&](int l,int r){\n\t\t\t\tauto\
    \ p=st2.query(n-1-r,n-1-l+1);\n\t\t\t\tf1={f1.first*p.first,f1.second*p.first+p.second};\n\
    \t\t\t});\n\t\t\tf1={f1.first/a[t].first,(f1.second-a[t].second)/a[t].first};\n\
    \t\t\thld.each_vertex(t,v,[&](int l,int r){\n\t\t\t\tauto p=st1.query(l,r+1);\n\
    \t\t\t\tf2={p.first*f2.first,p.second*f2.first+f2.second};\n\t\t\t});\n\t\t\t\
    f1={f1.first*f2.first,f1.second*f2.first+f2.second};\n\t\t\tprintf(\"%d\\n\",ModInt(x)*f1.first+f1.second);\n\
    \t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"../../other/template.hpp\"\n#include \"../../algebraic/StaticModInt.hpp\"\
    \n#include \"../../graph/HeavyLightDecomposition.hpp\"\n#include \"../../data-structure/SegTree.hpp\"\
    \nusing ModInt=StaticModInt<998244353>;\nclass MySeg:public SegTree<std::pair<ModInt,ModInt>>{\n\
    \tusing MP=std::pair<ModInt,ModInt>;\n\tMP nodef(const MP& lhs,const MP& rhs)const{\n\
    \t\treturn {lhs.first*rhs.first,lhs.second*rhs.first+rhs.second};\n\t}\npublic:\n\
    \tMySeg(int n):SegTree<MP>(n,{1,0},{1,0}){}\n};\nint n,q;\nP a[200010];\nint main(){\n\
    \tscanf(\"%d%d\",&n,&q);\n\trep(i,n)scanf(\"%d%d\",&a[i].first,&a[i].second);\n\
    \tHeavyLightDecomposition hld(n);\n\tMySeg st1(n),st2(n);\n\trep(i,n-1){\n\t\t\
    int u,v;\n\t\tscanf(\"%d%d\",&u,&v);\n\t\thld.add_edge(u,v);\n\t}\n\thld.build(0);\n\
    \trep(i,n){\n\t\tst1.update(hld.label[i],a[i]);\n\t\tst2.update(n-1-hld.label[i],a[i]);\n\
    \t}\n\trep(i,q){\n\t\tint t;\n\t\tscanf(\"%d\",&t);\n\t\tif(t==0){\n\t\t\tint\
    \ p,c,d;\n\t\t\tscanf(\"%d%d%d\",&p,&c,&d);\n\t\t\ta[p]={c,d};\n\t\t\tst1.update(hld.label[p],{c,d});\n\
    \t\t\tst2.update(n-1-hld.label[p],{c,d});\n\t\t}\n\t\telse{\n\t\t\tint u,v,x;\n\
    \t\t\tscanf(\"%d%d%d\",&u,&v,&x);\n\t\t\tint t=hld.lca(u,v);\n\t\t\tstd::pair<ModInt,ModInt>\
    \ f1={1,0},f2={1,0};\n\t\t\thld.each_vertex(u,t,[&](int l,int r){\n\t\t\t\tauto\
    \ p=st2.query(n-1-r,n-1-l+1);\n\t\t\t\tf1={f1.first*p.first,f1.second*p.first+p.second};\n\
    \t\t\t});\n\t\t\tf1={f1.first/a[t].first,(f1.second-a[t].second)/a[t].first};\n\
    \t\t\thld.each_vertex(t,v,[&](int l,int r){\n\t\t\t\tauto p=st1.query(l,r+1);\n\
    \t\t\t\tf2={p.first*f2.first,p.second*f2.first+f2.second};\n\t\t\t});\n\t\t\t\
    f1={f1.first*f2.first,f1.second*f2.first+f2.second};\n\t\t\tprintf(\"%d\\n\",ModInt(x)*f1.first+f1.second);\n\
    \t\t}\n\t}\n}"
  dependsOn:
  - other/template.hpp
  - algebraic/StaticModInt.hpp
  - algebraic/DynamicModInt.hpp
  - graph/HeavyLightDecomposition.hpp
  - data-structure/SegTree.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 00:46:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_set_path_composite.test.cpp
- /verify/test/yosupo/vertex_set_path_composite.test.cpp.html
title: test/yosupo/vertex_set_path_composite.test.cpp
---
