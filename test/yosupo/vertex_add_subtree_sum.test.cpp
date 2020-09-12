#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include "../../other/template.hpp"
#include "../../graph/HeavyLightDecomposition.hpp"
#include "../../data-structure/BIT.hpp"
int n,q,a[500010];
int main(){
	scanf("%d%d",&n,&q);
	rep(i,n)scanf("%d",a+i);
	HeavyLightDecomposition hld(n);
	BIT<lint> bit(n);
	REP(i,n-1){
		int p;
		scanf("%d",&p);
		hld.add_edge(i,p);
	}
	hld.build(0);
	rep(i,n)bit.add(hld.label[i],a[i]);
	rep(i,q){
		int t;
		scanf("%d",&t);
		if(t==0){
			int u,x;
			scanf("%d%d",&u,&x);
			bit.add(hld.label[u],x);
		}
		else{
			int u;
			scanf("%d",&u);
			printf("%lld\n",bit.query(hld.label[u],hld.last[u]));
		}
	}
}