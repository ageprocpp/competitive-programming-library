#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "../../other/template.hpp"
#include "../../data-structure/BIT.hpp"
int n,q,a;
int main(){
	scanf("%d%d",&n,&q);
	BIT bit(n);
	REP(i,n){
		scanf("%d",&a);
		bit.add(i,a);
	}
	rep(i,q){
		int t;
		scanf("%d",&t);
		if(t==0){
			int p,x;
			scanf("%d%d",&p,&x);
			bit.add(p+1,x);
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			printf("%lld\n",bit.query(r)-(l==0?0:bit.query(l)));
		}
	}
	return 0;
}