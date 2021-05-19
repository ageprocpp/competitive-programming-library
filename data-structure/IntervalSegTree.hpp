#pragma once
#include "../other/template.hpp"
#include "SegTree.hpp"
template <class T, class U, T (*nodef)(const T&, const T&),
		  void (*lazyf)(U&, const U&),
		  void (*updf)(T&, const U&, const unsigned int&)>
class IntervalSegTree : public SegTree<T, nodef> {
	using Base = SegTree<T, nodef>;
	using Base::ident;
	using Base::n;
	using Base::node;
	using Base::rank;
	std::vector<U> lazy;
	std::vector<bool> lazyflag;
	std::vector<int> width;
	void eval(int k) {
		for (int i = rank; i > 0; i--) {
			int nk = k >> i;
			if (lazyflag[nk]) {
				updf(node[2 * nk], lazy[nk], width[2 * nk]);
				updf(node[2 * nk + 1], lazy[nk], width[2 * nk + 1]);
				if (lazyflag[2 * nk])
					lazyf(lazy[2 * nk], lazy[nk]);
				else
					lazy[2 * nk] = lazy[nk];
				if (lazyflag[2 * nk + 1])
					lazyf(lazy[2 * nk + 1], lazy[nk]);
				else
					lazy[2 * nk + 1] = lazy[nk];
				lazyflag[2 * nk] = lazyflag[2 * nk + 1] = true;
				lazyflag[nk] = false;
			}
		}
	}

  public:
	IntervalSegTree(unsigned int m, T e_) : Base(m, T(), e_) {
		lazy.resize(2 * n);
		lazyflag.resize(2 * n);
		width.resize(2 * n);
		width[1] = n;
		for (unsigned int i = 2; i < 2 * n; i++) {
			width[i] = width[i >> 1] >> 1;
		}
	}
	IntervalSegTree(unsigned int m, T init, T e_) : Base(m, init, e_) {
		lazy.resize(2 * n);
		lazyflag.resize(2 * n);
		width.resize(2 * n);
		width[1] = n;
		for (unsigned int i = 2; i < 2 * n; i++) {
			width[i] = width[i >> 1] >> 1;
		}
	}
	IntervalSegTree(const std::vector<T>& initvec, T e_) : Base(initvec, e_) {
		lazy.resize(2 * n);
		lazyflag.resize(2 * n);
		width.resize(2 * n);
		width[1] = n;
		for (unsigned int i = 2; i < 2 * n; i++) {
			width[i] = width[i >> 1] >> 1;
		}
	}
	void update(int i, U x) {
		i += n;
		eval(i);
		updf(node[i], x, width[i]);
		if (lazyflag[i])
			lazyf(lazy[i], x);
		else {
			lazyflag[i] = true;
			lazy[i] = x;
		}
		while (i /= 2) node[i] = nodef(node[2 * i], node[2 * i + 1]);
	}
	void update(int l, int r, U x) {
		l += n, r += n;
		int nl = l, nr = r;
		while (!(nl & 1)) nl >>= 1;
		while (!(nr & 1)) nr >>= 1;
		nr--;
		eval(nl), eval(nr);
		while (l < r) {
			if (l & 1) {
				updf(node[l], x, width[l]);
				if (lazyflag[l])
					lazyf(lazy[l], x);
				else {
					lazyflag[l] = true;
					lazy[l] = x;
				}
				l++;
			}
			if (r & 1) {
				r--;
				updf(node[r], x, width[r]);
				if (lazyflag[r])
					lazyf(lazy[r], x);
				else {
					lazyflag[r] = true;
					lazy[r] = x;
				}
			}
			l >>= 1, r >>= 1;
		}
		while (nl >>= 1) node[nl] = nodef(node[2 * nl], node[2 * nl + 1]);
		while (nr >>= 1) node[nr] = nodef(node[2 * nr], node[2 * nr + 1]);
	}
	T query(int l, int r) {
		l += n, r += n, eval(l);
		eval(r - 1);
		T ls = ident, rs = ident;
		while (l < r) {
			if (l & 1) ls = nodef(ls, node[l++]);
			if (r & 1) rs = nodef(node[--r], rs);
			l >>= 1, r >>= 1;
		}
		return nodef(ls, rs);
	}
	T operator[](const int& x) {
		eval(n + x);
		return node[n + x];
	}

  private:
	template <class F>
	int max_right(int st, F& check, T& acc, int k, int l, int r) {
		eval(k);
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

	template <class F>
	int min_left(int st, F& check, T& acc, int k, int l, int r) {
		eval(k);
		if (l + 1 == r) {
			acc = nodef(node[k], acc);
			return check(acc) ? -1 : k - n + 1;
		}
		int m = (l + r) >> 1;
		if (st <= m) return min_left(st, check, acc, k << 1, l, m);
		if (r <= st && check(nodef(node[k], acc))) {
			acc = nodef(node[k], acc);
			return -1;
		}
		int vr = min_left(st, check, acc, (k << 1) | 1, m, r);
		if (vr != -1) return vr;
		return min_left(st, check, acc, k << 1, l, m);
	}

  public:
	template <class F>
	int max_right(int st, F check) {
		T acc = ident;
		return max_right(st, check, acc, 1, 0, n);
	}
	template <bool (*check)(const T&)>
	int max_right(int st) {
		T acc = ident;
		return max_right(st, check, acc, 1, 0, n);
	}

	template <class F>
	int min_left(int st, F check) {
		T acc = ident;
		return min_left(st, check, acc, 1, 0, n);
	}
	template <bool (*check)(const T&)>
	int min_left(int st) {
		T acc = ident;
		return min_left(st, check, acc, 1, 0, n);
	}
};
namespace {
	lint RAQRSQ_nodef(const lint& a, const lint& b) { return a + b; }
	void RAQRSQ_lazyf(lint& a, const lint& b) { a += b; }
	void RAQRSQ_updf(lint& a, const lint& b, const unsigned int& width) {
		a += width * b;
	}
	lint RAQRMiQ_nodef(const lint& a, const lint& b) { return std::min(a, b); }
	void RAQRMiQ_lazyf(lint& a, const lint& b) { a += b; }
	void RAQRMiQ_updf(lint& a, const lint& b, const unsigned int& width) {
		a += b;
	}
	lint RAQRMaQ_nodef(const lint& a, const lint& b) { return std::max(a, b); }
	void RAQRMaQ_lazyf(lint& a, const lint& b) { a += b; }
	void RAQRMaQ_updf(lint& a, const lint& b, const unsigned int& width) {
		a += b;
	}
	lint RUQRSQ_nodef(const lint& a, const lint& b) { return a + b; }
	void RUQRSQ_lazyf(lint& a, const lint& b) { a = b; }
	void RUQRSQ_updf(lint& a, const lint& b, const unsigned int& width) {
		a = width * b;
	}
	lint RUQRMiQ_nodef(const lint& a, const lint& b) { return std::min(a, b); }
	void RUQRMiQ_lazyf(lint& a, const lint& b) { a = b; }
	void RUQRMiQ_updf(lint& a, const lint& b, const unsigned int& width) {
		a = b;
	}
	lint RUQRMaQ_nodef(const lint& a, const lint& b) { return std::max(a, b); }
	void RUQRMaQ_lazyf(lint& a, const lint& b) { a = b; }
	void RUQRMaQ_updf(lint& a, const lint& b, const unsigned int& width) {
		a = b;
	}
}  // namespace

class RAQRSQ : public IntervalSegTree<lint, lint, RAQRSQ_nodef, RAQRSQ_lazyf,
									  RAQRSQ_updf> {
	using Base =
		IntervalSegTree<lint, lint, RAQRSQ_nodef, RAQRSQ_lazyf, RAQRSQ_updf>;

  public:
	template <class... Args>
	RAQRSQ(Args&&... args) : Base(std::forward<Args>(args)..., 0) {}
};
class RAQRMiQ : public IntervalSegTree<lint, lint, RAQRMiQ_nodef, RAQRMiQ_lazyf,
									   RAQRMiQ_updf> {
	using Base =
		IntervalSegTree<lint, lint, RAQRMiQ_nodef, RAQRMiQ_lazyf, RAQRMiQ_updf>;

  public:
	template <class... Args>
	RAQRMiQ(Args&&... args) : Base(std::forward<Args>(args)..., LINF) {}
};
class RAQRMaQ : public IntervalSegTree<lint, lint, RAQRMaQ_nodef, RAQRMaQ_lazyf,
									   RAQRMaQ_updf> {
	using Base =
		IntervalSegTree<lint, lint, RAQRMaQ_nodef, RAQRMaQ_lazyf, RAQRMaQ_updf>;

  public:
	template <class... Args>
	RAQRMaQ(Args&&... args) : Base(std::forward<Args>(args)..., -LINF) {}
};
class RUQRSQ : public IntervalSegTree<lint, lint, RUQRSQ_nodef, RUQRSQ_lazyf,
									  RUQRSQ_updf> {
	using Base =
		IntervalSegTree<lint, lint, RUQRSQ_nodef, RUQRSQ_lazyf, RUQRSQ_updf>;

  public:
	template <class... Args>
	RUQRSQ(Args&&... args) : Base(std::forward<Args>(args)..., 0) {}
};
class RUQRMiQ : public IntervalSegTree<lint, lint, RUQRMiQ_nodef, RUQRMiQ_lazyf,
									   RUQRMiQ_updf> {
	using Base =
		IntervalSegTree<lint, lint, RUQRMiQ_nodef, RUQRMiQ_lazyf, RUQRMiQ_updf>;

  public:
	template <class... Args>
	RUQRMiQ(Args&&... args) : Base(std::forward<Args>(args)..., LINF) {}
};
class RUQRMaQ : public IntervalSegTree<lint, lint, RUQRMaQ_nodef, RUQRMaQ_lazyf,
									   RUQRMaQ_updf> {
	using Base =
		IntervalSegTree<lint, lint, RUQRMaQ_nodef, RUQRMaQ_lazyf, RUQRMaQ_updf>;

  public:
	template <class... Args>
	RUQRMaQ(Args&&... args) : Base(std::forward<Args>(args)..., -LINF) {}
};

/**
 * @title Interval Segment Tree
 */