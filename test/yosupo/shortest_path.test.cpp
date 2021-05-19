#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../../other/template.hpp"
#include "../../other/FastIO.hpp"
#include "../../graph/Dijkstra.hpp"
FastIO::Scanner cin;
FastIO::Printer cout;
int N, M, s, t, a, b, c;
int main() {
	cin >> N >> M >> s >> t;
	Dijkstra<lint> d(N);
	rep(i, M) {
		cin >> a >> b >> c;
		d.add_edge(a, b, c);
	}
	auto res = d.get_dist_and_path(s, t);
	if (res.first == -1)
		puts("-1");
	else {
		cout << res.first << ' ' << res.second.size() - 1 << '\n';
		rep(i, res.second.size() - 1) cout << res.second[i] << ' '
										   << res.second[i + 1] << '\n';
	}
}