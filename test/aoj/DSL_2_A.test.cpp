#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"
#include "../../other/template.hpp"
#include "../../data-structure/SegTree.hpp"
int n,q;
int main(){
	scanf("%d%d",&n,&q);
	RMiQ st(n,INT_MAX);
	rep(i,q){
		int com,x,y;
		scanf("%d%d%d",&com,&x,&y);
		if(com==0)st.update(x,y);
		else printf("%d\n",st.query(x,y+1));
	}
}