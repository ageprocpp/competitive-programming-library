#define PROBLEM "https://judge.yosupo.jp/problem/gcd_convolution"
#include "../../basic/template.hpp"
#include "../../basic/FastIO.hpp"
#include "../../math/StaticModInt.hpp"
#include "../../math/GcdConvolution.hpp"
using ModInt = StaticModInt<998244353>;
FastIO::Scanner cin;
FastIO::Printer cout;
int N;
std::vector<ModInt> A, B;
int main() {
	cin >> N >> A >> B;
	A.insert(A.begin(), 0), B.insert(B.begin(), 0);
	auto res = GcdConvolution::convolution(A, B);
	res.erase(res.begin());
	cout << res << '\n';
	return 0;
}