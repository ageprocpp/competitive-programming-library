#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../other/template.hpp"
#include "../graph/HeavyLightDecomposition.hpp"
int n,q;
int main(){
	std::cin>>n>>q;
	HeavyLightDecomposition hld(n);
	REP(i,n-1){
		int p;
		std::cin>>p;
		hld.add_edge(i,p);
	}
	hld.build(0);
	rep(i,q){
		int u,v;
		std::cin>>u>>v;
		std::cout<<hld.lca(u,v)<<std::endl;
	}
}