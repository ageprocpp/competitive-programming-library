#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../../graph/Dijkstra.hpp"
#include "../../other/template.hpp"
int N, M, s, t, a, b, c;
int main() {
	scanf("%d%d%d%d", &N, &M, &s, &t);
	Dijkstra<lint> d(N);
	rep(i, M) {
		scanf("%d%d%d", &a, &b, &c);
		d.add_edge(a, b, c);
	}
	auto res = d.get_dist_and_path(s, t);
	if (res.first == -1)
		puts("-1");
	else {
		printf("%lld %d\n", res.first, res.second.size() - 1);
		rep(i, res.second.size() - 1) {
			printf("%d %d\n", res.second[i], res.second[i + 1]);
		}
	}
}