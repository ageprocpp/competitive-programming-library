#pragma once
#include "../other/template.hpp"
template <class T, T (*nodef)(const T&, const T&)>
class SegTree {
  protected:
	unsigned int n = 1, m = 1, rank = 0;
	std::vector<T> node;
	T ident;

  public:
	SegTree(T e_) : ident(e_) {}
	SegTree(unsigned int m_, T e_) : m(m_), ident(e_) {
		while (n < m) {
			n *= 2;
			rank++;
		}
		node.resize(2 * n, ident);
	}
	SegTree(unsigned int m_, T init, T e_) : m(m_), ident(e_) {
		while (n < m) {
			n *= 2;
			rank++;
		}
		node.resize(2 * n, ident);
		for (unsigned int i = n; i < 2 * n; i++) node[i] = init;
		for (unsigned int i = n - 1; i > 0; i--) node[i] = nodef(node[i << 1], node[i << 1 | 1]);
	}
	template <class U>
	SegTree(const std::vector<U>& initvec, T e_) : ident(e_) {
		m = initvec.size();
		while (n < m) {
			n *= 2;
			rank++;
		}
		node.resize(2 * n, ident);
		for (unsigned int i = n; i < 2 * n; i++) {
			if (i - n < m) node[i] = initvec[i - n];
		}
		for (unsigned int i = n - 1; i > 0; i--) node[i] = nodef(node[i << 1], node[i << 1 | 1]);
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
	const T& operator[](const int& i) const { return node[n + i]; }
	T query_all() const { return node[1]; }
	void fill(T x) {
		for (unsigned int i = n; i < 2 * n; i++) node[i] = x;
		for (unsigned int i = n - 1; i > 0; i--) node[i] = nodef(node[i << 1], node[i << 1 | 1]);
	}

  private:
	template <class F>
	int max_right(int st, F& check, T& acc, int k, int l, int r) const {
		if (l + 1 == r) {
			acc = nodef(acc, node[k]);
			return check(acc) ? m : k - n;
		}
		int mid = (l + r) >> 1;
		if (mid <= st) return max_right(st, check, acc, (k << 1) | 1, mid, r);
		if (st <= l && check(nodef(acc, node[k]))) {
			acc = nodef(acc, node[k]);
			return m;
		}
		int vl = max_right(st, check, acc, k << 1, l, mid);
		if (vl != m) return vl;
		return max_right(st, check, acc, (k << 1) | 1, mid, r);
	}

	template <class F>
	int min_left(int st, F& check, T& acc, int k, int l, int r) const {
		if (l + 1 == r) {
			acc = nodef(node[k], acc);
			return check(acc) ? 0 : k - n + 1;
		}
		int mid = (l + r) >> 1;
		if (st <= mid) return min_left(st, check, acc, k << 1, l, mid);
		if (r <= st && check(nodef(node[k], acc))) {
			acc = nodef(node[k], acc);
			return 0;
		}
		int vr = min_left(st, check, acc, (k << 1) | 1, mid, r);
		if (vr != 0) return vr;
		return min_left(st, check, acc, k << 1, l, mid);
	}

  public:
	template <class F>
	int max_right(int st, F check) const {
		T acc = ident;
		return max_right(st, check, acc, 1, 0, n);
	}
	template <bool (*check)(const T&)>
	int max_right(int st) const {
		T acc = ident;
		return max_right(st, check, acc, 1, 0, n);
	}

	template <class F>
	int min_left(int st, F check) const {
		T acc = ident;
		return min_left(st, check, acc, 1, 0, n);
	}
	template <bool (*check)(const T&)>
	int min_left(int st) const {
		T acc = ident;
		return min_left(st, check, acc, 1, 0, n);
	}
};
namespace {
	template <typename T>
	T RSQ_nodef(const T& lhs, const T& rhs) {
		return lhs + rhs;
	}
	template <typename T>
	T RMiQ_nodef(const T& lhs, const T& rhs) {
		return std::min(lhs, rhs);
	}
	template <typename T>
	T RMaQ_nodef(const T& lhs, const T& rhs) {
		return std::max(lhs, rhs);
	}
}  // namespace

template <typename T>
class RSQ : public SegTree<T, RSQ_nodef> {
	using Base = SegTree<T, RSQ_nodef>;

  public:
	template <class... Args>
	RSQ(Args&&... args) : Base(std::forward<Args>(args)..., 0) {}
};

template <typename T, typename U = void>
class RMiQ : public SegTree<T, RMiQ_nodef> {
	using Base = SegTree<T, RMiQ_nodef>;

  public:
	template <class... Args>
	RMiQ(Args&&... args) : Base(std::forward<Args>(args)...) {}
};
template <typename T>
class RMiQ<T, std::enable_if_t<std::numeric_limits<T>::is_specialized>>
	: public SegTree<T, RMiQ_nodef> {
	using Base = SegTree<T, RMiQ_nodef>;

  public:
	template <class... Args>
	RMiQ(Args&&... args) : Base(std::forward<Args>(args)..., std::numeric_limits<T>::max()) {}
};

template <typename T, typename U = void>
class RMaQ : public SegTree<T, RMaQ_nodef> {
	using Base = SegTree<T, RMaQ_nodef>;

  public:
	template <class... Args>
	RMaQ(Args&&... args) : Base(std::forward<Args>(args)...) {}
};
template <typename T>
class RMaQ<T, std::enable_if_t<std::numeric_limits<T>::is_specialized>>
	: public SegTree<T, RMaQ_nodef> {
	using Base = SegTree<T, RMaQ_nodef>;

  public:
	template <class... Args>
	RMaQ(Args&&... args) : Base(std::forward<Args>(args)..., std::numeric_limits<T>::min()) {}
};