#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A"
#include "../../other/template.hpp"
#include "../../graph/FordFulkerson.hpp"
int v,e;
int main() {
	scanf("%d%d",&v,&e);
	FordFulkerson flow(v);
	rep(i,e){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		flow.add_edge(a,b,c);
	}
	printf("%d\n",flow.max_flow(0,v-1));
	return 0;
}