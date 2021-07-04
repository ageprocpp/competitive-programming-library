#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include "../../other/template.hpp"
#include "../../math/StaticModInt.hpp"
#include "../../math/Matrix.hpp"
using ModInt = StaticModInt<998244353>;
int N, M, K;
int main() {
	scanf("%d%d%d", &N, &M, &K);
	Matrix<ModInt> mat1(N, M), mat2(M, K);
	rep(i, N) rep(j, M) std::cin >> mat1[i][j];
	rep(i, M) rep(j, K) std::cin >> mat2[i][j];
	auto res = mat1 * mat2;
	rep(i, N) printArray(res[i]);
	return 0;
}