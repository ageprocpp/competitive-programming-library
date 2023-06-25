#pragma once
#include "../basic/template.hpp"
template <bool isMin>
class LiChaoTree {
	int n, id;
	std::vector<std::tuple<lint, lint, lint>> interval;
	std::vector<std::pair<LP, int>> node;
	std::vector<lint> cord;
	static lint calc(std::pair<LP, int> l, lint x) { return l.first.first * x + l.first.second; }
	void addSegment(std::pair<LP, int>& newLine, lint cnt) {
		lint l = std::get<0>(interval[cnt]), m = std::get<1>(interval[cnt]),
			 r = std::get<2>(interval[cnt]);
		if (n <= cnt) {
			if (calc(node[cnt], l) > calc(newLine, l)) node[cnt] = newLine;
			return;
		}
		if (calc(node[cnt], l) < calc(newLine, l) && calc(node[cnt], r) < calc(newLine, r)) return;
		if (calc(node[cnt], l) > calc(newLine, l) && calc(node[cnt], r) > calc(newLine, r)) {
			node[cnt] = newLine;
			return;
		}
		if (calc(node[cnt], m) > calc(newLine, m)) std::swap(node[cnt], newLine);
		if (calc(node[cnt], l) > calc(newLine, l))
			addSegment(newLine, cnt << 1);
		else
			addSegment(newLine, cnt << 1 | 1);
	}

  public:
	LiChaoTree(const std::vector<lint>& vec) { init(vec); }
	LiChaoTree(std::vector<lint>&& vec) { init(std::forward<std::vector<lint>>(vec)); }
	void init(const std::vector<lint>& vec) {
		std::vector<lint> tmp = vec;
		init(std::forward<std::vector<lint>>(tmp));
	}
	void init(std::vector<lint>&& vec) {
		interval.clear();
		node.clear();
		cord.clear();
		n = 1;
		id = 0;
		vec.emplace_back(vec.back() + 1);
		while (n < (int)vec.size()) n *= 2;
		while ((int)vec.size() < n + 1) vec.emplace_back(vec.back() + 1);
		node.assign(2 * n, {{0, LINF}, -1});
		interval.emplace_back(0, 0, 0);
		for (int range = n; range; range >>= 1) {
			for (int i = 0; i < n; i += range) {
				if (range == 1)
					interval.emplace_back(vec[i], 0, vec[i + range]);
				else
					interval.emplace_back(vec[i], vec[i + range / 2], vec[i + range]);
			}
		}
		cord = vec;
	}
	void addLine(lint a, lint b) {
		std::pair<LP, int> newLine = {{a, b}, id++};
		if (!isMin) {
			newLine.first.first *= -1;
			newLine.first.second *= -1;
		}
		addSegment(newLine, 1);
	}
	void addSegment(int l, int r, lint a, lint b) {
		l += n;
		r += n;
		std::pair<LP, int> newLine = {{a, b}, id++};
		if (!isMin) {
			newLine.first.first *= -1;
			newLine.first.second *= -1;
		}
		while (l < r) {
			if (l & 1) {
				auto tmp = newLine;
				addSegment(tmp, l++);
			}
			if (r & 1) {
				auto tmp = newLine;
				addSegment(tmp, --r);
			}
			l >>= 1;
			r >>= 1;
		}
	}
	std::pair<lint, int> query(int idx) const {
		lint x = cord[idx];
		idx += n;
		std::pair<lint, int> res = {LINF, -1};
		while (idx) {
			if (chmin(res.first, calc(node[idx], x))) res.second = node[idx].second;
			idx >>= 1;
		}
		if (!isMin) res.first = -res.first;
		return res;
	}
	void clear() {
		id = 0;
		node.assign(2 * n, {{0, LINF}, -1});
	}
};

/**
 * @title Li Chao Tree
 */