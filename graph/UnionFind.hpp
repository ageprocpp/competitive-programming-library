#pragma once
#include "../other/template.hpp"
class UnionFind {
  protected:
	std::vector<int> par_vec, size_vec;

  public:
	UnionFind() {}
	UnionFind(int size) { init(size); }
	size_t size() const { return par_vec.size(); }
	void init(int size) {
		par_vec.resize(size);
		this->size_vec.resize(size, 1);
		std::iota(all(par_vec), 0);
	}
	int find(int n) {
		if (par_vec[n] == n) return n;
		return par_vec[n] = find(par_vec[n]);
	}
	void unite(int n, int m) {
		n = find(n);
		m = find(m);
		if (n == m) return;
		int a = n, b = m;
		if (size_vec[a] > size_vec[b]) std::swap(a, b);
		par_vec[a] = b;
		size_vec[b] += size_vec[a];
	}
	bool same(int n, int m) { return find(n) == find(m); }
	int get_size(int n) { return size_vec[find(n)]; }
	bool is_root(int n) { return find(n) == n; }
};

/**
 * @title Disjoint set
 */