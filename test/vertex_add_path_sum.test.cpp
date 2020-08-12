#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "../other/template.hpp"
#include "../graph/HeavyLightDecomposition.hpp"
#include "../data-structure/BIT.hpp"
int n,q,a[500010];
int main(){
	std::cin>>n>>q;
	rep(i,n)std::cin>>a[i];
	HeavyLightDecomposition hld(n);
	BIT bit(n);
	rep(i,n-1){
		int u,v;
		std::cin>>u>>v;
		hld.add_edge(u,v);
	}
	hld.build(0);
	rep(i,n)bit.add(hld.label[i]+1,a[i]);
	rep(i,q){
		int type;
		std::cin>>type;
		if(type==0){
			int p,x;
			std::cin>>p>>x;
			bit.add(hld.label[p]+1,x);
		}
		else{
			int u,v;
			std::cin>>u>>v;
			lint ans=0;
			hld.each_vertex(u,v,[&](int l,int r){
				ans+=bit.query(r+1)-bit.query(l);
			});
			std::cout<<ans<<std::endl;
		}
	}
}