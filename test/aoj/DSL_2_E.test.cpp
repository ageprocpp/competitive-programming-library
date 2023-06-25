#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E"
#include "../../data-structure/IntervalSegTree.hpp"
#include "../../basic/template.hpp"
int n, q;
int main() {
	scanf("%d%d", &n, &q);
	RAQRSQ<int> st(n, 0);
	rep(i, q) {
		int t;
		scanf("%d", &t);
		if (t == 0) {
			int s, t, x;
			scanf("%d%d%d", &s, &t, &x);
			st.update(s - 1, t, x);
		} else {
			int p;
			scanf("%d", &p);
			printf("%d\n", st[p - 1]);
		}
	}
}