#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../other/template.hpp"
#include "../algebraic/ModInt.hpp"
#include "../data-structure/IntervalSegTree.hpp"
const unsigned int ModInt::modulo=998244353;
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
	std::cin>>n>>q;
	vec.resize(n);
	rep(i,n){
		std::cin>>vec[i];
	}
	MySeg st(vec);
	rep(i,q){
		int t;
		std::cin>>t;
		if(t==0){
			int l,r,b,c;
			std::cin>>l>>r>>b>>c;
			st.update(l,r,{b,c});
		}
		else{
			int l,r;
			std::cin>>l>>r;
			std::cout<<st.query(l,r)<<std::endl;
		}
	}
	return 0;
}