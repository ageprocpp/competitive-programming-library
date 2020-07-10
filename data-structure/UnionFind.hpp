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
class PersistantUnionFind :UnionFind {
	std::vector<P> notparent;
	std::vector<std::vector<std::pair<int, int>>> sizevec;
	int opcount = 0;
public:
	PersistantUnionFind(unsigned int size) :UnionFind(size) {
		notparent.resize(size); sizevec.resize(size);
		rep(i, size) {
			par[i] = i;
			rank[i] = 0;
			sizevec[i].push_back(std::make_pair(-1, 1));
			notparent[i] = std::make_pair(INF, i);
		}
	}
	int find(int n, int t = INF) {
		if (opcount <= t) {
			if (par[n] == n)return n;
			return par[n] = find(par[n]);
		}
		if (notparent[n].first <= t)return find(notparent[n].second, t);
		return n;
	}
	void unite(int n, int m) {
		n = find(n);
		m = find(m);
		if (n == m) {
			opcount++;
			return;
		}
		if (rank[n] < rank[m]) {
			par[n] = m;
			notparent[n] = std::make_pair(opcount, m);
			sizevec[m].emplace_back(opcount, sizevec[m].back().second + sizevec[n].back().second);
		}
		else {
			par[m] = n;
			notparent[m] = std::make_pair(opcount, n);
			sizevec[n].emplace_back(opcount, sizevec[n].back().second + sizevec[m].back().second);
			if (rank[n] == rank[m])rank[n]++;
		}
		opcount++;
	}
	bool same(int n, int m, int t = INF) {
		return find(n, t) == find(m, t);
	}
	int getsize(int n, int t = INF) {
		n = find(n, t);
		auto ite = std::lower_bound(all(sizevec[n]), std::make_pair(t, 0));
		if (ite == sizevec[n].end())ite--;
		if (t < (*ite).first)ite--;
		return (*ite).second;
	}
};