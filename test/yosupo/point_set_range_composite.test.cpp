#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../../other/template.hpp"
#include "../../algebraic/StaticModInt.hpp"
#include "../../data-structure/SegTree.hpp"
using ModInt=StaticModInt<998244353>;
class MySeg:public SegTree<std::pair<ModInt,ModInt>>{
	using mp=std::pair<ModInt,ModInt>;
	mp nodef(const mp& lhs,const mp& rhs)const{return {lhs.first*rhs.first,lhs.second*rhs.first+rhs.second};}
public:
	MySeg(int size):SegTree<mp>(size,{0,0},{1,0}){}
};
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	MySeg st(n);
	rep(i,n){
		int a,b;
		scanf("%d%d",&a,&b);
		st.update(i,{a,b});
	}
	rep(i,q){
		int t;
		scanf("%d",&t);
		if(t==0){
			int p,c,d;
			scanf("%d%d%d",&p,&c,&d);
			st.update(p,{c,d});
		}
		else{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			auto p=st.query(l,r);
			printf("%d\n",p.first*x+p.second);
		}
	}
	return 0;
}