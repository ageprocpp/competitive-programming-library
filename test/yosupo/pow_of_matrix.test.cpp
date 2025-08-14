#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"
#include "../../basic/template.hpp"
#include "../../math/StaticModInt.hpp"
#include "../../math/Matrix.hpp"
using ModInt = StaticModInt<998244353>;
int N;
lint K;
int main() {
	scanf("%d %lld", &N, &K);
	SquareMatrix<ModInt> m(N);
	rep(i, N) rep(j, N) std::cin >> m[i][j];
	std::cout << m.pow(K) << std::endl;
	return 0;
}