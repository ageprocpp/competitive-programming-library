#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../../other/template.hpp"
#include "../../other/FastIO.hpp"
FastIO::Scanner cin;
FastIO::Printer cout;
int main() {
	lint t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << a + b << '\n';
	}
	return 0;
}