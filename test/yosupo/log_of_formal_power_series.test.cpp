#define PROBLEM "https://judge.yosupo.jp/problem/log_of_formal_power_series"
#include "../../other/template.hpp"
#include "../../math/StaticModInt.hpp"
#include "../../math/FormalPowerSeries.hpp"

using ModInt = StaticModInt<998244353>;
using FPS = FormalPowerSeries<ModInt>;
int main() {
	int N;
	FPS vec;
	std::cin >> N >> vec;
	std::cout << vec.log() << std::endl;
}