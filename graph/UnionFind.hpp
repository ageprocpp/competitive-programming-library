#pragma once
#include "../other/template.hpp"
class UnionFind {
protected:
	std::vector<int> par, size;
public:
	UnionFind(unsigned int size) {
		par.resize(size); this->size.resize(size, 1);
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
		int a=n,b=m;
		if(size[a]>size[b])std::swap(a,b);
		par[a] = b;
		size[b] += size[a];
	}
	bool same(int n, int m) {
		return find(n) == find(m);
	}
	int getsize(int n) {
		return size[find(n)];
	}
};