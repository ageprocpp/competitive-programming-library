#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../other/template.hpp"
#include "../data-structure/UnionFind.hpp"
int n,q,t,u,v;
int main(){
	std::cin>>n>>q;
	UnionFind uf(n);
	rep(i,q){
		std::cin>>t>>u>>v;
		if(t==0)uf.unite(u,v);
		else std::cout<<uf.same(u,v)<<std::endl;
	}
	return 0;
}