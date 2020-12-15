#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "../../other/template.hpp"
#include "../../graph/Dinic.hpp"
int L, R, M, a[200010], b[200010];
int main() {
	scanf("%d%d%d", &L, &R, &M);
	Dinic flow(L + R + 2);
	REP(i, L) flow.add_edge(0, i, 1);
	for (int i = L + 1; i <= L + R; i++) flow.add_edge(i, L + R + 1, 1);
	rep(i, M) {
		scanf("%d%d", a + i, b + i);
		flow.add_edge(a[i] + 1, b[i] + L + 1, 1);
	}
	std::cout << flow.max_flow(0, L + R + 1) << std::endl;
	auto vec = flow.restore();
	rep(i, M) {
		if (vec[i + L + R]) std::cout << a[i] << " " << b[i] << std::endl;
	}
	return 0;
}