#pragma once
#include "../other/template.hpp"
template <typename T, T (*nodef)(const T&, const T&)>
class SegTree {
  protected:
	unsigned int n = 1, rank = 0;
	std::vector<T> node;
	T ident;

  public:
	SegTree(unsigned int m, T init, T e_) : ident(e_) {
		while (n < m) {
			n *= 2;
			rank++;
		}
		node.resize(2 * n, ident);
		for (unsigned int i = n; i < 2 * n; i++) node[i] = init;
		for (unsigned int i = n - 1; i > 0; i--)
			node[i] = nodef(node[i << 1], node[i << 1 | 1]);
	}
	template <typename U>
	SegTree(const std::vector<U>& initvec, T e_) : ident(e_) {
		unsigned int m = initvec.size();
		while (n < m) {
			n *= 2;
			rank++;
		}
		node.resize(2 * n, ident);
		for (unsigned int i = n; i < 2 * n; i++) {
			if (i - n < m) node[i] = initvec[i - n];
		}
		for (unsigned int i = n - 1; i > 0; i--)
			node[i] = nodef(node[i << 1], node[i << 1 | 1]);
	}
	void update(int i, T x) {
		i += n;
		node[i] = x;
		while (i != 1) {
			i >>= 1;
			node[i] = nodef(node[2 * i], node[2 * i + 1]);
		}
	}
	T query(int l, int r) const {
		l += n;
		r += n;
		T ls = ident, rs = ident;
		while (l < r) {
			if (l & 1) ls = nodef(ls, node[l++]);
			if (r & 1) rs = nodef(node[--r], rs);
			l >>= 1;
			r >>= 1;
		}
		return nodef(ls, rs);
	}
	T operator[](const int& x) const {
		return node[n + x];
	}
	T queryForAll() const {
		return node[1];
	}

  private:
	template <typename F>
	int max_right(int st, F& check, T& acc, int k, int l, int r) const {
		if (l + 1 == r) {
			acc = nodef(acc, node[k]);
			return check(acc) ? -1 : k - n;
		}
		int m = (l + r) >> 1;
		if (m <= st) return max_right(st, check, acc, (k << 1) | 1, m, r);
		if (st <= l && check(nodef(acc, node[k]))) {
			acc = nodef(acc, node[k]);
			return -1;
		}
		int vl = max_right(st, check, acc, k << 1, l, m);
		if (vl != -1) return vl;
		return max_right(st, check, acc, (k << 1) | 1, m, r);
	}

  public:
	template <typename F>
	int max_right(int st, F check) const {
		T acc = ident;
		return max_right(st, check, acc, 1, 0, n);
	}
	template <bool (*check)(const T&)>
	int max_right(int st) const {
		T acc = ident;
		return max_right(st, check, acc, 1, 0, n);
	}
};
static lint RSQ_nodef(const lint& lhs, const lint& rhs) {
	return lhs + rhs;
}
class RSQ : public SegTree<lint, RSQ_nodef> {
	using Base = SegTree<lint, RSQ_nodef>;

  public:
	template <class... Args>
	RSQ(Args&&... args) : Base(std::forward<Args>(args)..., 0) {}
};
static lint RMiQ_nodef(const lint& lhs, const lint& rhs) {
	return std::min(lhs, rhs);
}
class RMiQ : public SegTree<lint, RMiQ_nodef> {
	using Base = SegTree<lint, RMiQ_nodef>;

  public:
	template <class... Args>
	RMiQ(Args&&... args) : Base(std::forward<Args>(args)..., LINF) {}
};
static lint RMaQ_nodef(const lint& lhs, const lint& rhs) {
	return std::max(lhs, rhs);
}
class RMaQ : public SegTree<lint, RMaQ_nodef> {
	using Base = SegTree<lint, RMaQ_nodef>;

  public:
	template <class... Args>
	RMaQ(Args&&... args) : Base(std::forward<Args>(args)..., -LINF) {}
};