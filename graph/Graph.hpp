#pragma once
#include "../basic/template.hpp"
template <typename>
class Dijkstra;

template <bool weighted, typename W = std::conditional_t<weighted, int, void>>
class Graph {
	size_t N;
	std::vector<
		std::vector<std::conditional_t<weighted, std::pair<int, W>, int>>>
		vec;
	using weight_type = W;

  public:
	Graph(int N_) : N(N_), vec(N_) {}
	Graph(decltype(vec) v_) : N(v_.size()), vec(v_) {}

	size_t size() const { return N; }
	void add_edge(int s, int t, bool directed) {
		if (directed)
			vec[s].emplace_back(t);
		else
			vec[s].emplace_back(t), vec[t].emplace_back(s);
	}
	void add_edge(int s, int t, W w, bool directed) {
		if (directed)
			vec[s].emplace_back(t, w);
		else
			vec[s].emplace_back(t, w), vec[t].emplace_back(s, w);
	}

	Graph<weighted, W> rev() const {
		Graph<weighted, W> res(N);
		rep(i, N) {
			for (const auto& j : vec[i]) {
#if __cplusplus >= 201703L
				if constexpr (weighted)
#else
				if (weighted)
#endif
					res.vec[j.first].emplace_back(i, j.second);
				else
					res.vec[j].emplace_back(i);
			}
		}
		return res;
	}

	friend Dijkstra<W>;
};