#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../../other/template.hpp"
#include "../../graph/StronglyConnectedComponents.hpp"
int N,M;
int main(){
	scanf("%d%d",&N,&M);
	StronglyConnectedComponents scc(N);
	rep(i,M){
		int a,b;
		scanf("%d%d",&a,&b);
		scc.add_edge(a,b);
	}
	auto vec=scc.get_scc();
	printf("%d\n",vec.size());
	rep(i,vec.size()){
		printf("%d ",vec[i].size());
		printArray(vec[i]);
	}
	return 0;
}