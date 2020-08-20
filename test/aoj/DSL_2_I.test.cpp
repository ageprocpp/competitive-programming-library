#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_I"
#include "../../other/template.hpp"
#include "../../data-structure/IntervalSegTree.hpp"
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	RUQRSQ st(n,0);
	rep(i,q){
		int t;
		scanf("%d",&t);
		if(t==0){
			int s,t,x;
			scanf("%d%d%d",&s,&t,&x);
			st.update(s,t+1,x);
		}
		else{
			int s,t;
			scanf("%d%d",&s,&t);
			printf("%lld\n",st.query(s,t+1));
		}
	}
}