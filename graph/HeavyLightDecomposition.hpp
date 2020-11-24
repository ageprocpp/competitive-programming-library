#pragma once
#include "../other/template.hpp"
class HeavyLightDecomposition {
	int n, index = 0;
	void size_dfs(int node) {
		size[node] = 1;
		for (int& i : vec[node]) {
			if (par[node] == i) continue;
			par[i] = node;
			size_dfs(i);
			size[node] += size[i];
			if (size[i] > size[vec[node][0]]) std::swap(i, vec[node][0]);
		}
	}
	void build_dfs(int node) {
		label[node] = index++;
		for (int& i : vec[node]) {
			if (par[node] != i) {
				head[i] = (i == vec[node][0] ? head[node] : i);
				build_dfs(i);
			}
		}
		last[node] = index;
	}

  public:
	std::vector<std::vector<int>> vec;
	std::vector<int> size, par, head, label, last;
	HeavyLightDecomposition() {}
	HeavyLightDecomposition(int m) : n(m) { init(n); }
	void init(int m) {
		n = m;
		vec.resize(n);
		size.resize(n);
		par.resize(n);
		head.resize(n);
		label.resize(n);
		last.resize(n);
	}
	void add_edge(int u, int v) {
		vec[u].emplace_back(v);
		vec[v].emplace_back(u);
	}
	void build(int root) {
		std::fill(all(par), -1);
		size_dfs(root);
		build_dfs(root);
	}
	template <typename F>
	void each_edge(int u, int v, const F& func) const {
		while (true) {
			if (label[u] > label[v]) std::swap(u, v);
			if (head[u] == head[v]) {
				if (label[u] != label[v]) func(label[u] + 1, label[v]);
				return;
			}
			func(label[head[v]], label[v]);
			v = par[head[v]];
		}
	}
	template <typename F>
	void each_vertex(int u, int v, const F& func) const {
		while (true) {
			if (label[u] > label[v]) std::swap(u, v);
			if (head[u] == head[v]) {
				func(label[u], label[v]);
				return;
			}
			func(label[head[v]], label[v]);
			v = par[head[v]];
		}
	}
	int lca(int u, int v) const {
		while (true) {
			if (label[u] > label[v]) std::swap(u, v);
			if (head[u] == head[v]) return u;
			v = par[head[v]];
		}
	}
	void clear() {
		vec.clear();
		size.clear();
		par.clear();
		head.clear();
		label.clear();
		last.clear();
	}
};