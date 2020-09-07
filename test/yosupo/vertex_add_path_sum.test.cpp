#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "../../other/template.hpp"
#include "../../graph/HeavyLightDecomposition.hpp"
#include "../../data-structure/BIT.hpp"
int n,q,a[500010];
int main(){
	scanf("%d%d",&n,&q);
	rep(i,n)scanf("%d",a+i);
	HeavyLightDecomposition hld(n);
	BIT bit(n);
	rep(i,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		hld.add_edge(u,v);
	}
	hld.build(0);
	rep(i,n)bit.add(hld.label[i],a[i]);
	rep(i,q){
		int t;
		scanf("%d",&t);
		if(t==0){
			int p,x;
			scanf("%d%d",&p,&x);
			bit.add(hld.label[p],x);
		}
		else{
			int u,v;
			scanf("%d%d",&u,&v);
			lint ans=0;
			hld.each_vertex(u,v,[&](int l,int r){
				ans+=bit.query(l,r+1);
			});
			printf("%lld\n",ans);
		}
	}
}