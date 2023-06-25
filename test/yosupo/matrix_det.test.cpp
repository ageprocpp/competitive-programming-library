#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include "../../basic/template.hpp"
#include "../../math/StaticModInt.hpp"
#include "../../math/Matrix.hpp"
using ModInt = StaticModInt<998244353>;
int N;
int main() {
	scanf("%d", &N);
	SquareMatrix<ModInt> m(N);
	rep(i, N) rep(j, N) std::cin >> m[i][j];
	std::cout << m.determinant() << std::endl;
	return 0;
}