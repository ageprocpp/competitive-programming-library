#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "../../other/template.hpp"
#include "../../other/FastIO.hpp"
#include "../../data-structure/vanEmdeBoasTree.hpp"
FastIO::Scanner cin;
FastIO::Printer cout;
int N, Q;
std::string T;
vanEmdeBoasTree<24> ebt;
int main() {
	cin >> N >> Q >> T;
	rep(i, N) if (T[i] == '1') ebt.insert(i + 1);
	rep(i, Q) {
		int c, k;
		cin >> c >> k;
		k++;
		if (c == 0) {
			ebt.insert(k);
		} else if (c == 1) {
			ebt.erase(k);
		} else if (c == 2)
			cout << ebt.contains(k) << '\n';
		else if (c == 3) {
			int ans = ebt.successor(k - 1);
			cout << (ans == -1 ? -1 : ans - 1) << '\n';
		} else {
			int ans = ebt.predecessor(k + 1);
			cout << (ans == -1 ? -1 : ans - 1) << '\n';
		}
	}
	return 0;
}