#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "../../graph/StronglyConnectedComponents.hpp"
#include "../../basic/template.hpp"
int N, M;
int main() {
	scanf("%d%d", &N, &M);
	StronglyConnectedComponents scc(N);
	rep(i, M) {
		int a, b;
		scanf("%d%d", &a, &b);
		scc.add_edge(a, b);
	}
	scc.build();
	auto vec = scc.get_scc();
	printf("%d\n", vec.size());
	rep(i, vec.size()) {
		printf("%d ", vec[i].size());
		std::cout << vec[i] << std::endl;
	}
	return 0;
}