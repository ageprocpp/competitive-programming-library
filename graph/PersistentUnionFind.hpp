#pragma once
#include "../other/template.hpp"
#include "UnionFind.hpp"
class PersistentUnionFind {
	std::vector<IP> notparent;
	std::vector<std::vector<std::pair<int, int>>> sizevec;
	int opcount = 0;

  public:
	PersistentUnionFind(unsigned int size) {
		notparent.resize(size);
		sizevec.resize(size);
		rep(i, size) {
			sizevec[i].push_back(std::make_pair(-1, 1));
			notparent[i] = std::make_pair(INF, i);
		}
	}
	int find(int n, int t = INF) {
		if (t < notparent[n].first || notparent[n].second == n) return n;
		return find(notparent[n].second, t);
	}
	void unite(int n, int m) {
		n = find(n);
		m = find(m);
		if (n == m) {
			opcount++;
			return;
		}
		if (sizevec[n].back().second > sizevec[m].back().second)
			std::swap(n, m);
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

/**
 * @title Partially persistent disjoint set
 */