#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../../basic/template.hpp"
#include "../../basic/FastIO.hpp"
#include "../../graph/Dijkstra.hpp"
FastIO::Scanner cin;
FastIO::Printer cout;
int N, M, s, t, a, b, c;
int main() {
	cin >> N >> M >> s >> t;
	Graph<true, lint> g(N);
	rep(i, M) {
		cin >> a >> b >> c;
		g.add_edge(a, b, c, 1);
	}
	Dijkstra<lint> d(g);
	auto res = d.dist_and_path(s, t);
	if (res.first == LLONG_MAX)
		puts("-1");
	else {
		cout << res.first << ' ' << res.second.size() - 1 << '\n';
		rep(i, res.second.size() - 1) cout << res.second[i] << ' '
										   << res.second[i + 1] << '\n';
	}
}