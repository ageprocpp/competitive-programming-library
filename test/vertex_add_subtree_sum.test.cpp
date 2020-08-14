#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "../other/template.hpp"
#include "../graph/HeavyLightDecomposition.hpp"
#include "../data-structure/BIT.hpp"
int n,q,a[500010];
int main(){
	std::cin>>n>>q;
	rep(i,n)std::cin>>a[i];
	HeavyLightDecomposition hld(n);
	BIT bit(n);
	REP(i,n-1){
		int p;
		std::cin>>p;
		hld.add_edge(i,p);
	}
	hld.build(0);
	rep(i,n)bit.add(hld.label[i]+1,a[i]);
	rep(i,q){
		int type;
		std::cin>>type;
		if(type==0){
			int u,x;
			std::cin>>u>>x;
			bit.add(hld.label[u]+1,x);
		}
		else{
			int u;
			std::cin>>u;
			std::cout<<bit.query(hld.last[u])-bit.query(hld.label[u])<<std::endl;
		}
	}
}