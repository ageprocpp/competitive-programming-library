#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../other/template.hpp"
#include "../../graph/HeavyLightDecomposition.hpp"
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	HeavyLightDecomposition hld(n);
	REP(i,n-1){
		int p;
		scanf("%d",&p);
		hld.add_edge(i,p);
	}
	hld.build(0);
	rep(i,q){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",hld.lca(u,v));
	}
}