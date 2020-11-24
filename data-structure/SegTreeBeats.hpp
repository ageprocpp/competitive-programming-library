#pragma once
#include "../other/template.hpp"
class SegTreeBeats {
	unsigned int n;
	std::vector<lint> width, min[2], minc, max[2], maxc, sum, lazy;
	void eval(int k) {
		if (n - 1 <= k) return;
		if (lazy[k]) {
			update_node_add(2 * k + 1, lazy[k]);
			update_node_add(2 * k + 2, lazy[k]);
			lazy[k] = 0;
		}
		if (max[0][k] < max[0][2 * k + 1]) {
			update_node_max(2 * k + 1, max[0][k]);
		}
		if (min[0][k] > min[0][2 * k + 1]) {
			update_node_min(2 * k + 1, min[0][k]);
		}
		if (max[0][k] < max[0][2 * k + 2]) {
			update_node_max(2 * k + 2, max[0][k]);
		}
		if (min[0][k] > min[0][2 * k + 2]) {
			update_node_min(2 * k + 2, min[0][k]);
		}
	}
	void combine(int k) {
		sum[k] = sum[2 * k + 1] + sum[2 * k + 2];
		if (min[0][2 * k + 1] < min[0][2 * k + 2]) {
			min[0][k] = min[0][2 * k + 1];
			minc[k] = minc[2 * k + 1];
			min[1][k] = std::min(min[1][2 * k + 1], min[0][2 * k + 2]);
		} else if (min[0][2 * k + 1] > min[0][2 * k + 2]) {
			min[0][k] = min[0][2 * k + 2];
			minc[k] = minc[2 * k + 2];
			min[1][k] = std::min(min[0][2 * k + 1], min[1][2 * k + 2]);
		} else {
			min[0][k] = min[0][2 * k + 1];
			minc[k] = minc[2 * k + 1] + minc[2 * k + 2];
			min[1][k] = std::min(min[1][2 * k + 1], min[1][2 * k + 2]);
		}
		if (max[0][2 * k + 1] > max[0][2 * k + 2]) {
			max[0][k] = max[0][2 * k + 1];
			maxc[k] = maxc[2 * k + 1];
			max[1][k] = std::max(max[1][2 * k + 1], max[0][2 * k + 2]);
		} else if (max[0][2 * k + 1] < max[0][2 * k + 2]) {
			max[0][k] = max[0][2 * k + 2];
			maxc[k] = maxc[2 * k + 2];
			max[1][k] = std::max(max[0][2 * k + 1], max[1][2 * k + 2]);
		} else {
			max[0][k] = max[0][2 * k + 1];
			maxc[k] = maxc[2 * k + 1] + maxc[2 * k + 2];
			max[1][k] = std::max(max[1][2 * k + 1], max[1][2 * k + 2]);
		}
	}
	void update_node_max(int k, lint x) {
		sum[k] += (x - max[0][k]) * maxc[k];
		if (max[0][k] == min[0][k])
			min[0][k] = x;
		else if (max[0][k] == min[1][k])
			min[1][k] = x;
		max[0][k] = x;
	}
	void update_node_min(int k, lint x) {
		sum[k] += (x - min[0][k]) * minc[k];
		if (min[0][k] == max[0][k])
			max[0][k] = x;
		else if (min[0][k] == max[1][k])
			max[1][k] = x;
		min[0][k] = x;
	}
	void update_node_add(int k, lint x) {
		min[0][k] += x;
		if (min[1][k] != LINF) min[1][k] += x;
		max[0][k] += x;
		if (max[1][k] != -LINF) max[1][k] += x;
		sum[k] += x * width[k];
		lazy[k] += x;
	}

  public:
	SegTreeBeats(unsigned int size, lint def = 0) {
		*this = SegTreeBeats(std::vector<lint>(size, def));
	}
	SegTreeBeats(std::vector<lint> initvec) {
		n = 1;
		while (n < initvec.size()) n *= 2;
		width.resize(2 * n - 1);
		min[0].resize(2 * n - 1);
		min[1].resize(2 * n - 1, LINF);
		minc.resize(2 * n - 1);
		max[0].resize(2 * n - 1);
		max[1].resize(2 * n - 1, -LINF);
		maxc.resize(2 * n - 1);
		sum.resize(2 * n - 1);
		lazy.resize(2 * n - 1);
		for (int i = n - 1; i < n - 1 + initvec.size(); i++) {
			min[0][i] = max[0][i] = sum[i] = initvec[i - n + 1];
			minc[i] = maxc[i] = 1;
		}
		for (int i = n - 2; i >= 0; i--) { combine(i); }
		width[0] = n;
		REP(i, 2 * n - 2) width[i] = width[(i - 1) / 2] / 2;
	}
	void update_chmin(int a, int b, lint x, int k = 0, int l = 0, int r = -1) {
		if (r == -1) r = n;
		if (b <= l || r <= a || max[0][k] <= x) return;
		if (a <= l && r <= b && max[1][k] < x) {
			update_node_max(k, x);
			return;
		}
		eval(k);
		update_chmin(a, b, x, 2 * k + 1, l, (l + r) / 2);
		update_chmin(a, b, x, 2 * k + 2, (l + r) / 2, r);
		combine(k);
	}
	void update_chmax(int a, int b, lint x, int k = 0, int l = 0, int r = -1) {
		if (r == -1) r = n;
		if (b <= l || r <= a || x <= min[0][k]) return;
		if (a <= l && r <= b && x < min[1][k]) {
			update_node_min(k, x);
			return;
		}
		eval(k);
		update_chmax(a, b, x, 2 * k + 1, l, (l + r) / 2);
		update_chmax(a, b, x, 2 * k + 2, (l + r) / 2, r);
		combine(k);
	}
	void update_add(int a, int b, lint x, int k = 0, int l = 0, int r = -1) {
		if (r == -1) r = n;
		if (b <= l || r <= a) return;
		if (a <= l && r <= b) {
			update_node_add(k, x);
			return;
		}
		eval(k);
		update_add(a, b, x, 2 * k + 1, l, (l + r) / 2);
		update_add(a, b, x, 2 * k + 2, (l + r) / 2, r);
		combine(k);
	}
	void update(int a, int b, lint x) {
		update_chmin(a, b, x);
		update_chmax(a, b, x);
	}
	lint query_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r == -1) r = n;
		if (b <= l || r <= a) return 0;
		if (a <= l && r <= b) return sum[k];
		eval(k);
		lint vl = query_sum(a, b, 2 * k + 1, l, (l + r) / 2);
		lint vr = query_sum(a, b, 2 * k + 2, (l + r) / 2, r);
		return vl + vr;
	}
	lint query_min(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r == -1) r = n;
		if (b <= l || r <= a) return LINF;
		if (a <= l && r <= b) return min[0][k];
		eval(k);
		lint vl = query_min(a, b, 2 * k + 1, l, (l + r) / 2);
		lint vr = query_min(a, b, 2 * k + 2, (l + r) / 2, r);
		return std::min(vl, vr);
	}
	lint query_max(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r == -1) r = n;
		if (b <= l || r <= a) return -LINF;
		if (a <= l && r <= b) return max[0][k];
		eval(k);
		lint vl = query_max(a, b, 2 * k + 1, l, (l + r) / 2);
		lint vr = query_max(a, b, 2 * k + 2, (l + r) / 2, r);
		return std::max(vl, vr);
	}
};