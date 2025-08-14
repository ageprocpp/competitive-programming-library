#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#include "../../basic/template.hpp"
#include "../../basic/FastIO.hpp"
#include "../../math/FastFactorize.hpp"
FastIO::Scanner cin;
FastIO::Printer cout;
int Q;
lint N;
int main() {
	cin >> Q;
	rep(_, Q) {
		cin >> N;
		puts(FastFactorize::is_prime(N) ? "Yes" : "No");
	}
	return 0;
}