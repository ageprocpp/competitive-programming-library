#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G"
#include "../../other/template.hpp"
#include "../../data-structure/IntervalSegTree.hpp"
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	RAQRSQ st(n,0);
	rep(i,q){
		int t;
		scanf("%d",&t);
		if(t==0){
			int s,t,x;
			scanf("%d%d%d",&s,&t,&x);
			st.update(s-1,t,x);
		}
		else{
			int s,t;
			scanf("%d%d",&s,&t);
			printf("%lld\n",st.query(s-1,t));
		}
	}
}