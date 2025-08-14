#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include "../../basic/template.hpp"
#include "../../basic/FastIO.hpp"
#include "../../math/Factorize.hpp"
FastIO::Scanner cin;
FastIO::Printer cout;
int Q;
lint p;
int main() {
	auto mul = [](lint a, lint b, lint n) { return i128(a) * b % n; };
	auto modpow = [&mul](lint a, lint b, lint n) {
		a %= n;
		lint res(1);
		while (b) {
			if (b & 1) res = mul(res, a, n);
			a = mul(a, a, n), a %= n, b >>= 1;
		}
		return res;
	};
	auto primitive_root = [&modpow](lint mod) {
		lint p = 0;
		static std::random_device rd;
		static std::mt19937_64 mt(rd());
		std::uniform_int_distribution<lint> uid(1, mod - 1);

		// use naive factorize due to file size limit
		auto vec = Factorize::factorize(mod - 1);

		vec.erase(std::unique(all(vec)), vec.end());
		while (true) {
			p = uid(mt);
			bool f = true;
			for (const auto& i : vec) {
				if (modpow(p, (mod - 1) / i, mod) == 1) {
					f = false;
					break;
				}
			}
			if (f) return p;
		}
	};
	cin >> Q;
	rep(_, Q) {
		cin >> p;
		std::cout << primitive_root(p) << '\n';
	}
	return 0;
}