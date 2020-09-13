#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "../../other/template.hpp"
#include "../../graph/Tree.hpp"
int N;
int main(){
	scanf("%d",&N);
	std::vector<std::pair<P,int>> vec;
	rep(i,N-1){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a++;b++;
		vec.push_back({{a,b},c});
	}
	Tree tree(N,vec);
	auto res=tree.DiameterPath();
	printf("%lld %d\n",res.second,res.first.size());
	std::for_each(all(res.first),[](int &n){n--;});
	printArray(res.first);
}