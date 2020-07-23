#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A"
#include "../other/template.hpp"
#include "../graph/FordFulkerson.hpp"
int v,e;
int main() {
	std::cin>>v>>e;
	FordFulkerson flow(v);
	rep(i,e){
		int a,b,c;
		std::cin>>a>>b>>c;
		flow.add_edge(a,b,c);
	}
	std::cout<<flow.max_flow(0,v-1)<<std::endl;
	return 0;
}