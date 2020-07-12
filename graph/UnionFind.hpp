#pragma once
#include "../other/template.hpp"
class UnionFind {
protected:
	std::vector<int> par, rank, size;
public:
	UnionFind(unsigned int size) {
		par.resize(size); rank.resize(size, 0); this->size.resize(size, 1);
		rep(i, size) {
			par[i] = i;
		}
	}
	int find(int n) {
		if (par[n] == n)return n;
		return par[n] = find(par[n]);
	}
	void unite(int n, int m) {
		n = find(n);
		m = find(m);
		if (n == m)return;
		if (rank[n] < rank[m]) {
			par[n] = m;
			size[m] += size[n];
		}
		else {
			par[m] = n;
			size[n] += size[m];
			if (rank[n] == rank[m])rank[n]++;
		}
	}
	bool same(int n, int m) {
		return find(n) == find(m);
	}
	int getsize(int n) {
		return size[find(n)];
	}
};