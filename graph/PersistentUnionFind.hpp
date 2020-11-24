#pragma once
#include "../other/template.hpp"
#include "UnionFind.hpp"
class PersistentUnionFind : UnionFind {
	std::vector<P> notparent;
	std::vector<std::vector<std::pair<int, int>>> sizevec;
	int opcount = 0;

  public:
	PersistentUnionFind(unsigned int size) : UnionFind(size) {
		notparent.resize(size);
		sizevec.resize(size);
		rep(i, size) {
			par[i] = i;
			sizevec[i].push_back(std::make_pair(-1, 1));
			notparent[i] = std::make_pair(INF, i);
		}
	}
	int find(int n, int t = INF) {
		if (opcount <= t) {
			if (par[n] == n) return n;
			return par[n] = find(par[n]);
		}
		if (notparent[n].first <= t) return find(notparent[n].second, t);
		return n;
	}
	void unite(int n, int m) {
		n = find(n);
		m = find(m);
		if (n == m) {
			opcount++;
			return;
		}
		if (size[n] > size[m]) std::swap(n, m);
		par[n] = m;
		notparent[n] = std::make_pair(opcount, m);
		sizevec[m].emplace_back(
			opcount, sizevec[m].back().second + sizevec[n].back().second);
		opcount++;
	}
	bool same(int n, int m, int t = INF) { return find(n, t) == find(m, t); }
	int getsize(int n, int t = INF) {
		n = find(n, t);
		auto ite = std::lower_bound(all(sizevec[n]), std::make_pair(t, 0));
		if (ite == sizevec[n].end()) ite--;
		if (t < (*ite).first) ite--;
		return (*ite).second;
	}
};