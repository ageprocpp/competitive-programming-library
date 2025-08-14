#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"
#include "../../basic/template.hpp"
#include "../../math/StaticModInt.hpp"
#include "../../math/Matrix.hpp"
using ModInt = StaticModInt<998244353>;
int N, M;
int main() {
	scanf("%d %d", &N, &M);
	Matrix<ModInt> mat(N, M);
	rep(i, N) rep(j, M) std::cin >> mat[i][j];
	std::cout << mat.rank() << std::endl;
	return 0;
}