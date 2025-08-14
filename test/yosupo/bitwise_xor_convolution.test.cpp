#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"
#include "../../basic/template.hpp"
#include "../../basic/FastIO.hpp"
#include "../../math/StaticModInt.hpp"
#include "../../math/XorConvolution.hpp"
using ModInt = StaticModInt<998244353>;
FastIO::Scanner cin;
FastIO::Printer cout;
int N;
std::vector<ModInt> A, B;
int main() {
	cin >> N >> A >> B;
	cout << XorConvolution::convolution(A, B) << '\n';
	return 0;
}