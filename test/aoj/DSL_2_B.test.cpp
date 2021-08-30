#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include "../../data-structure/SegTree.hpp"
#include "../../other/template.hpp"
int n, q;
int main() {
	scanf("%d%d", &n, &q);
	RSQ<int> st(n, 0);
	rep(i, q) {
		int com, x, y;
		scanf("%d%d%d", &com, &x, &y);
		if (com == 0)
			st.update(x - 1, st[x - 1] + y);
		else
			printf("%d\n", st.query(x - 1, y));
	}
}