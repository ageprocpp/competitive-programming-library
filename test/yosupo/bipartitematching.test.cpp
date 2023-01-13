#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include "../../other/template.hpp"
#include "../../other/FastIO.hpp"
#include "../../graph/Dinic.hpp"
FastIO::Scanner cin;
FastIO::Printer cout;
int L, R, M, a[200010], b[200010];
int main() {
	cin >> L >> R >> M;
	Dinic flow(L + R + 2);
	REP(i, L) flow.add_edge(0, i, 1);
	for (int i = L + 1; i <= L + R; i++) flow.add_edge(i, L + R + 1, 1);
	rep(i, M) {
		cin >> a[i] >> b[i];
		flow.add_edge(a[i] + 1, b[i] + L + 1, 1);
	}
	cout << flow.max_flow(0, L + R + 1) << '\n';
	auto vec = flow.restore();
	rep(i, M) {
		if (vec[i + L + R]) cout << a[i] << ' ' << b[i] << '\n';
	}
	return 0;
}