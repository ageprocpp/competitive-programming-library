#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"
#include "../../other/template.hpp"
#include "../../algebraic/FloorSum.hpp"
int main(){
	int T,N,M,A,B;
	scanf("%d",&T);
	rep(_,T){
		scanf("%d%d%d%d",&N,&M,&A,&B);
		printf("%lld\n",FloorSum(N,M,A,B));
	}
}