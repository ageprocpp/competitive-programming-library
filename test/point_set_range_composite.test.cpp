#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include "../other/template.hpp"
#include "../algebraic/ModInt.hpp"
#include "../data-structure/SegTree.hpp"
class MySeg:public SegTree<std::pair<ModInt,ModInt>>{
	using mp=std::pair<ModInt,ModInt>;
	mp nodef(const mp& lhs,const mp& rhs)const{return {lhs.first*rhs.first,lhs.second*rhs.first+rhs.second};}
public:
	MySeg(int size):SegTree<mp>(size,{0,0},{1,0}){}
};
lint n,q;
int main(){
	ModInt::setMod(998244353);
	std::cin>>n>>q;
	MySeg st(n);
	rep(i,n){
		lint a,b;
		std::cin>>a>>b;
		st.update(i,{a,b});
	}
	rep(i,q){
		int t;
		std::cin>>t;
		if(t==0){
			int p,c,d;
			std::cin>>p>>c>>d;
			st.update(p,{c,d});
		}
		else{
			int l,r,x;
			std::cin>>l>>r>>x;
			auto p=st.query(l,r);
			std::cout<<p.first*x+p.second<<std::endl;
		}
	}
	return 0;
}