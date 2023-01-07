#pragma once
#include "../other/template.hpp"
#include "../other/type_traits.hpp"
#include "StaticModInt.hpp"
template <typename T>
class Combinatorics {
  protected:
	static std::vector<T> factorial;
	static void append(int n) noexcept {
		while (factorial.size() <= n) {
			factorial.emplace_back(factorial.back() * factorial.size());
		}
	}

  public:
	static T get_fact(int a) noexcept {
		append(a);
		return factorial[a];
	}
	static T get_comb(int a, int b) noexcept {
		append(a);
		return factorial[a] / factorial[a - b] / factorial[b];
	}
	static T get_dcomb(int a, int b) noexcept { return get_comb(a + b - 1, b); }
};
template <typename T>
std::vector<T> Combinatorics<T>::factorial = std::vector<T>(1, 1);

template <typename T>
class ModCombinatorics : public Combinatorics<T> {
	static_assert(is_ModInt<T>::value, "ModCombinatorics template is not ModInt");

	using Combinatorics<T>::factorial;
	static std::vector<T> inv;
	static void append(int n) noexcept {
		int tmp = factorial.size();
		if (n < tmp) return;
		Combinatorics<T>::append(n);
		inv.resize(n + 1);
		inv[n] = T(1) / factorial.back();
		for (int i = n; i > tmp; i--) inv[i - 1] = inv[i] * i;
	}

  public:
	static T get_fact(int a) noexcept {
		append(a);
		return factorial[a];
	}
	static T get_fact_inv(int a) noexcept {
		append(a);
		return inv[a];
	}
	static T get_comb(int a, int b) noexcept {
		append(a);
		return factorial[a] * inv[a - b] * inv[b];
	}
	static T get_perm(int a, int b) noexcept {
		append(a);
		return factorial[a] * inv[a - b];
	}
};
/**
 * @title Combinatorics/ModCombinatorics
 */
template <typename T>
std::vector<T> ModCombinatorics<T>::inv = std::vector<T>(1, 1);