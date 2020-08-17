#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../other/template.hpp"
int n,q,l,r;
lint a[500010];
int main(){
	scanf("%d%d",&n,&q);
	rep(i,n){
		scanf("%lld",a+i);
		if(i)a[i]+=a[i-1];
	}
	rep(i,q){
		scanf("%d%d",&l,&r);
		printf("%lld\n",a[r-1]-(l==0?0:a[l-1]));
	}
	return 0;
}