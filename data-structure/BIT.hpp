#pragma once
#include "../basic/template.hpp"
template <class T>
class BIT {
	int n;
	std::vector<T> bit;

  private:
	T query(int a) const {
		T cnt = 0;
		while (a > 0) {
			cnt += bit[a];
			a -= a & -a;
		}
		return cnt;
	}

  public:
	BIT(int n) : n(n) { bit.resize(n + 1); }
	void add(int a, T x) {
		a++;
		while (a <= n) {
			bit[a] += x;
			a += a & -a;
		}
	}
	T query(int l, int r) const { return query(r) - query(l); }
	void clear() { bit.assign(n + 1, 0); }
	int lower_bound(T x) const {
		int p = 0, k = 1;
		while (k * 2 <= n) k *= 2;
		while (k > 0) {
			if (p + k <= n && bit[p + k] < x) {
				x -= bit[p + k];
				p += k;
			}
			k /= 2;
		}
		return p;
	}
	int upper_bound(T x) const {
		int p = 0, k = 1;
		while (k * 2 <= n) k *= 2;
		while (k > 0) {
			if (p + k <= n && bit[p + k] <= x) {
				x -= bit[p + k];
				p += k;
			}
			k /= 2;
		}
		return p;
	}
};