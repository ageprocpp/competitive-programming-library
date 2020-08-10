#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include "../other/template.hpp"
#include "../algebraic/NumberTheoreticTransform.hpp"
int n,m;
std::vector<int> a,b;
int main(){
	scanf("%d%d",&n,&m);
	a.resize(n);b.resize(m);
	rep(i,n)scanf("%d",a.data()+i);
	rep(i,m)scanf("%d",b.data()+i);
	std::vector<ModInt> c=NumberTheoreticTransform::multiply(a,b,998244353);
	rep(i,n+m-1)std::cout<<c[i]<<(i==n+m?"\n":" ");
}