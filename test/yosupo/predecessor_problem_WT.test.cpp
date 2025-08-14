#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include "../../basic/template.hpp"
#include "../../basic/FastIO.hpp"
#include "../../data-structure/WordsizeTree.hpp"
FastIO::Scanner cin;
FastIO::Printer cout;
int N, Q;
std::string T;
int main() {
	cin >> N >> Q >> T;
	WordsizeTree wt(N);
	rep(i, N) if (T[i] == '1') wt.insert(i);
	rep(i, Q) {
		int c, k;
		cin >> c >> k;
		if (c == 0) {
			wt.insert(k);
		} else if (c == 1) {
			wt.erase(k);
		} else if (c == 2)
			cout << wt.contains(k) << '\n';
		else if (c == 3) {
			int ans = wt.successor(k - 1);
			cout << (ans == N ? -1 : ans) << '\n';
		} else {
			int ans = wt.predecessor(k + 1);
			cout << (ans == -1 ? -1 : ans) << '\n';
		}
	}
	return 0;
}