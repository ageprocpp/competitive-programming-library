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
		lazy.resize(2 * n), lazyflag.resize(2 * n), width.resize(2 * n);
		width[1] = n;
		for (unsigned int i = 2; i < 2 * n; i++) width[i] = width[i >> 1] >> 1;
	}
	IntervalSegTree(unsigned int m, T init, T e_) : Base(m, init, e_) {
		lazy.resize(2 * n), lazyflag.resize(2 * n), width.resize(2 * n);
		width[1] = n;
		for (unsigned int i = 2; i < 2 * n; i++) width[i] = width[i >> 1] >> 1;
	}
	IntervalSegTree(const std::vector<T>& initvec, T e_) : Base(initvec, e_) {
		lazy.resize(2 * n), lazyflag.resize(2 * n), width.resize(2 * n),
			width[1] = n;
		for (unsigned int i = 2; i < 2 * n; i++) width[i] = width[i >> 1] >> 1;
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
				else
					lazyflag[l] = true, lazy[l] = x;
				l++;
			}
			if (r & 1) {
				r--;
				updf(node[r], x, width[r]);
				if (lazyflag[r])
					lazyf(lazy[r], x);
				else
					lazyflag[r] = true, lazy[r] = x;
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
	T query_all() {
		eval(1);
		return node[1];
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
	template <class T>
	T RAQRSQ_nodef(const T& a, const T& b) {
		return a + b;
	}
	template <class T>
	void RAQRSQ_lazyf(T& a, const T& b) {
		a += b;
	}
	template <class T>
	void RAQRSQ_updf(T& a, const T& b, const unsigned int& width) {
		a += width * b;
	}

	template <class T>
	T RAQRMiQ_nodef(const T& a, const T& b) {
		return std::min(a, b);
	}
	template <class T>
	void RAQRMiQ_lazyf(T& a, const T& b) {
		a += b;
	}
	template <class T>
	void RAQRMiQ_updf(T& a, const T& b, const unsigned int& width) {
		a += b;
	}

	template <class T>
	T RCHMiQRMiQ_nodef(const T& a, const T& b) {
		return std::min(a, b);
	}
	template <class T>
	void RCHMiQRMiQ_lazyf(T& a, const T& b) {
		chmin(a, b);
	}
	template <class T>
	void RCHMiQRMiQ_updf(T& a, const T& b, const unsigned int& width) {
		chmin(a, b);
	}

	template <class T>
	T RAQRMaQ_nodef(const T& a, const T& b) {
		return std::max(a, b);
	}
	template <class T>
	void RAQRMaQ_lazyf(T& a, const T& b) {
		a += b;
	}
	template <class T>
	void RAQRMaQ_updf(T& a, const T& b, const unsigned int& width) {
		a += b;
	}

	template <class T>
	T RCHMaQRMaQ_nodef(const T& a, const T& b) {
		return std::max(a, b);
	}
	template <class T>
	void RCHMaQRMaQ_lazyf(T& a, const T& b) {
		chmax(a, b);
	}
	template <class T>
	void RCHMaQRMaQ_updf(T& a, const T& b, const unsigned int& width) {
		chmax(a, b);
	}

	template <class T>
	T RUQRSQ_nodef(const T& a, const T& b) {
		return a + b;
	}
	template <class T>
	void RUQRSQ_lazyf(T& a, const T& b) {
		a = b;
	}
	template <class T>
	void RUQRSQ_updf(T& a, const T& b, const unsigned int& width) {
		a = width * b;
	}

	template <class T>
	T RUQRMiQ_nodef(const T& a, const T& b) {
		return std::min(a, b);
	}
	template <class T>
	void RUQRMiQ_lazyf(T& a, const T& b) {
		a = b;
	}
	template <class T>
	void RUQRMiQ_updf(T& a, const T& b, const unsigned int& width) {
		a = b;
	}

	template <class T>
	T RUQRMaQ_nodef(const T& a, const T& b) {
		return std::max(a, b);
	}
	template <class T>
	void RUQRMaQ_lazyf(T& a, const T& b) {
		a = b;
	}
	template <class T>
	void RUQRMaQ_updf(T& a, const T& b, const unsigned int& width) {
		a = b;
	}
}  // namespace

template <class T>
class RAQRSQ
	: public IntervalSegTree<T, T, RAQRSQ_nodef, RAQRSQ_lazyf, RAQRSQ_updf> {
	using Base = IntervalSegTree<T, T, RAQRSQ_nodef, RAQRSQ_lazyf, RAQRSQ_updf>;

  public:
	template <class... Args>
	RAQRSQ(Args&&... args) : Base(std::forward<Args>(args)..., 0) {}
};
template <class T>
class RAQRMiQ
	: public IntervalSegTree<T, T, RAQRMiQ_nodef, RAQRMiQ_lazyf, RAQRMiQ_updf> {
	using Base =
		IntervalSegTree<T, T, RAQRMiQ_nodef, RAQRMiQ_lazyf, RAQRMiQ_updf>;

  public:
	template <class... Args>
	RAQRMiQ(Args&&... args)
		: Base(std::forward<Args>(args)..., std::numeric_limits<T>::max()) {}
};
template <class T>
class RCHMiQRMiQ : public IntervalSegTree<T, T, RCHMiQRMiQ_nodef,
										  RCHMiQRMiQ_lazyf, RCHMiQRMiQ_updf> {
	using Base = IntervalSegTree<T, T, RCHMiQRMiQ_nodef, RCHMiQRMiQ_lazyf,
								 RCHMiQRMiQ_updf>;

  public:
	template <class... Args>
	RCHMiQRMiQ(Args&&... args)
		: Base(std::forward<Args>(args)..., std::numeric_limits<T>::max()) {}
};
template <class T>
class RCHMaQRMaQ : public IntervalSegTree<T, T, RCHMaQRMaQ_nodef,
										  RCHMaQRMaQ_lazyf, RCHMaQRMaQ_updf> {
	using Base = IntervalSegTree<T, T, RCHMaQRMaQ_nodef, RCHMaQRMaQ_lazyf,
								 RCHMaQRMaQ_updf>;

  public:
	template <class... Args>
	RCHMaQRMaQ(Args&&... args)
		: Base(std::forward<Args>(args)..., std::numeric_limits<T>::min()) {}
};
template <class T>
class RAQRMaQ
	: public IntervalSegTree<T, T, RAQRMaQ_nodef, RAQRMaQ_lazyf, RAQRMaQ_updf> {
	using Base =
		IntervalSegTree<T, T, RAQRMaQ_nodef, RAQRMaQ_lazyf, RAQRMaQ_updf>;

  public:
	template <class... Args>
	RAQRMaQ(Args&&... args)
		: Base(std::forward<Args>(args)..., std::numeric_limits<T>::min()) {}
};
template <class T>
class RUQRSQ
	: public IntervalSegTree<T, T, RUQRSQ_nodef, RUQRSQ_lazyf, RUQRSQ_updf> {
	using Base = IntervalSegTree<T, T, RUQRSQ_nodef, RUQRSQ_lazyf, RUQRSQ_updf>;

  public:
	template <class... Args>
	RUQRSQ(Args&&... args) : Base(std::forward<Args>(args)..., 0) {}
};
template <class T>
class RUQRMiQ
	: public IntervalSegTree<T, T, RUQRMiQ_nodef, RUQRMiQ_lazyf, RUQRMiQ_updf> {
	using Base =
		IntervalSegTree<T, T, RUQRMiQ_nodef, RUQRMiQ_lazyf, RUQRMiQ_updf>;

  public:
	template <class... Args>
	RUQRMiQ(Args&&... args)
		: Base(std::forward<Args>(args)..., std::numeric_limits<T>::max()) {}
};
template <class T>
class RUQRMaQ
	: public IntervalSegTree<T, T, RUQRMaQ_nodef, RUQRMaQ_lazyf, RUQRMaQ_updf> {
	using Base =
		IntervalSegTree<T, T, RUQRMaQ_nodef, RUQRMaQ_lazyf, RUQRMaQ_updf>;

  public:
	template <class... Args>
	RUQRMaQ(Args&&... args)
		: Base(std::forward<Args>(args)..., std::numeric_limits<T>::min()) {}
};

/**
 * @title Interval Segment Tree
 */