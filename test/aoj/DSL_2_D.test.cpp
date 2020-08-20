#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"
#include "../../other/template.hpp"
#include "../../data-structure/IntervalSegTree.hpp"
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	RUQRSQ st(n,INT_MAX);
	rep(i,q){
		int t;
		scanf("%d",&t);
		if(t==0){
			int s,t,x;
			scanf("%d%d%d",&s,&t,&x);
			st.update(s,t+1,x);
		}
		else{
			int p;
			scanf("%d",&p);
			printf("%d\n",st[p]);
		}
	}
}