#pragma once
#include "../other/template.hpp"
#include "DynamicModInt.hpp"
#include "StaticModInt.hpp"
template <typename T>
class Combinatorics {
  protected:
	std::vector<T> factorial;
	void append(int n) noexcept {
		while (factorial.size() <= n) {
			factorial.emplace_back(factorial.back() * factorial.size());
		}
	}

  public:
	Combinatorics() noexcept : factorial(1, 1) {}
	Combinatorics(int n) noexcept : factorial(1, 1) { append(n); }
	virtual T getComb(int a, int b) noexcept {
		append(a);
		return factorial[a] / factorial[a - b] / factorial[b];
	}
	virtual T getDcomb(int a, int b) noexcept { return getComb(a + b - 1, b); }
};
template <typename T, typename std::enable_if_t<
						  std::disjunction_v<std::is_template_with_non_type_of<StaticModInt, T>,
											 std::is_same<DynamicModInt, T>>,
						  std::nullptr_t> = nullptr>
class ModCombinatorics : Combinatorics<T> {
	using Combinatorics<T>::factorial;
	std::vector<T> inv;
	void append(int n) noexcept {
		int tmp = factorial.size();
		if (n < tmp) return;
		Combinatorics<T>::append(n);
		inv.resize(n + 1);
		inv[n] = T(1) / factorial.back();
		for (int i = n; i > tmp; i--) inv[i - 1] = inv[i] * i;
	}

  public:
	ModCombinatorics() noexcept : Combinatorics<T>(), inv(1, 1) {}
	ModCombinatorics(int n) noexcept : Combinatorics<T>(n), inv(1, 1) {
		append(n);
	}
	T getComb(int a, int b) noexcept override {
		append(a);
		return factorial[a] * inv[a - b] * inv[b];
	}
	T getDcomb(int a, int b) noexcept override { return getComb(a + b - 1, b); }
	T perm(int a, int b) noexcept {
		append(a);
		return factorial[a] * inv[a - b];
	}
};

/*
 * @title Combinatorics/ModCombinatorics
*/