#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include "../other/template.hpp"
#include "../algebraic/ModInt.hpp"
#include "../graph/HeavyLightDecomposition.hpp"
#include "../data-structure/SegTree.hpp"
class MySeg:public SegTree<std::pair<ModInt,ModInt>>{
	using MP=std::pair<ModInt,ModInt>;
	MP nodef(const MP& lhs,const MP& rhs)const{
		return {lhs.first*rhs.first,lhs.second*rhs.first+rhs.second};
	}
public:
	MySeg(int n):SegTree<MP>(n,{1,0},{1,0}){}
};
int n,q;
P a[200010];
int main(){
	ModInt::setMod(998244353);
	std::cin>>n>>q;
	rep(i,n)std::cin>>a[i].first>>a[i].second;
	HeavyLightDecomposition hld(n);
	MySeg st1(n),st2(n);
	rep(i,n-1){
		int u,v;
		std::cin>>u>>v;
		hld.add_edge(u,v);
	}
	hld.build(0);
	rep(i,n){
		st1.update(hld.label[i],a[i]);
		st2.update(n-1-hld.label[i],a[i]);
	}
	rep(i,q){
		int type;
		std::cin>>type;
		if(type==0){
			int p,c,d;
			std::cin>>p>>c>>d;
			a[p]={c,d};
			st1.update(hld.label[p],{c,d});
			st2.update(n-1-hld.label[p],{c,d});
		}
		else{
			int u,v,x;
			std::cin>>u>>v>>x;
			int t=hld.lca(u,v);
			std::pair<ModInt,ModInt> f1={1,0},f2={1,0};
			hld.each_vertex(u,t,[&](int l,int r){
				auto p=st2.query(n-1-r,n-1-l+1);
				f1={f1.first*p.first,f1.second*p.first+p.second};
			});
			f1={f1.first/a[t].first,(f1.second-a[t].second)/a[t].first};
			hld.each_vertex(t,v,[&](int l,int r){
				auto p=st1.query(l,r+1);
				f2={p.first*f2.first,p.second*f2.first+f2.second};
			});
			f1={f1.first*f2.first,f1.second*f2.first+f2.second};
			std::cout<<ModInt(x)*f1.first+f1.second<<std::endl;
		}
	}
}