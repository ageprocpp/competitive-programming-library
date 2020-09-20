#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "../../other/template.hpp"
#include "../../graph/TwoSat.hpp"
int N,M;
int main(){
	scanf("p cnf %d%d",&N,&M);
	TwoSat ts(N+1);
	rep(i,M){
		int a,b;
		scanf("%d%d 0",&a,&b);
		ts.add_clause(std::abs(a),a>0,std::abs(b),b>0);
	}
	if(!ts.satisfiable()){
		puts("s UNSATISFIABLE");
		return 0;
	}
	puts("s SATISFIABLE");
	printf("v ");
	auto vec=ts.answer();
	REP(i,N){
		printf("%d ",(vec[i]?1:-1)*i);
	}
	printf("0\n");
}