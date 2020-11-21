#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../../other/template.hpp"
#include "../../algebraic/StaticModInt.hpp"
#include "../../data-structure/IntervalSegTree.hpp"
using ModInt=StaticModInt<998244353>;
using MP = std::pair<ModInt, ModInt>;
ModInt nodef(const ModInt& a,const ModInt& b){return a+b;}
void lazyf(MP& a,const MP& b){a={a.first*b.first,a.second*b.first+b.second};}
void updf(ModInt& a,const MP& b,const unsigned int& width){a=b.first*a+b.second*width;}
class MySeg:public IntervalSegTree<ModInt, MP, nodef, lazyf, updf>{
	using Base = IntervalSegTree<ModInt, MP, nodef, lazyf, updf>;
public:
	MySeg(const std::vector<ModInt>& initvec):Base(initvec, 0){}
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