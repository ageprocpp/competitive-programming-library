#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../other/template.hpp"
lint n,q,a[500010],l,r;
int main(){
	std::cin>>n>>q;
	rep(i,n){
		std::cin>>a[i];
		if(i)a[i]+=a[i-1];
	}
	rep(i,q){
		std::cin>>l>>r;
		std::cout<<a[r-1]-(l==0?0:a[l-1])<<std::endl;
	}
	return 0;
}