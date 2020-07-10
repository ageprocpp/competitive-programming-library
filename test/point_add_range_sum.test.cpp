#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../other/template.hpp"
#include "../data-structure/BIT.hpp"
lint n,q,a;
int main(){
	std::cin>>n>>q;
	BIT bit(n);
	REP(i,n){
		std::cin>>a;
		bit.add(i,a);
	}
	rep(i,q){
		int t;
		std::cin>>t;
		if(t==0){
			lint p,x;
			std::cin>>p>>x;
			p++;
			bit.add(p,x);
		}
		else{
			int l,r;
			std::cin>>l>>r;
			l++;r++;
			std::cout<<bit.query(r-1)-(l==1?0:bit.query(l-1))<<std::endl;
		}
	}
	return 0;
}