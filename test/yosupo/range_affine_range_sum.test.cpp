#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../other/template.hpp"
#include "../../algebraic/StaticModInt.hpp"
#include "../../data-structure/IntervalSegTree.hpp"
using ModInt=StaticModInt<998244353>;
class MySeg:public IntervalSegTree<ModInt,std::pair<ModInt,ModInt>>{
	using mp=std::pair<ModInt,ModInt>;
	ModInt nodef(const ModInt& a,const ModInt& b)const{return a+b;}
	void lazyf(mp& a,const mp& b){a={a.first*b.first,a.second*b.first+b.second};}
	void updf(ModInt& a,const mp& b,const unsigned int& width){a=b.first*a+b.second*width;}
public:
	MySeg(const std::vector<ModInt>& initvec):IntervalSegTree<ModInt,mp>(0,initvec){
		for(int i=n-1;i>0;i--)node[i]=nodef(node[2*i],node[2*i+1]);
	}
};
int n,q;
std::vector<ModInt> vec;
int main(){
	scanf("%d%d",&n,&q);
	vec.resize(n);
	rep(i,n){
		int tmp;
		scanf("%d",&tmp);
		vec[i]=tmp;
	}
	MySeg st(vec);
	rep(i,q){
		int t;
		scanf("%d",&t);
		if(t==0){
			int l,r,b,c;
			scanf("%d%d%d%d",&l,&r,&b,&c);
			st.update(l,r,{b,c});
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%d\n",st.query(l,r));
		}
	}
	return 0;
}