#pragma once
#include "../other/template.hpp"
template<class T, T (*nodef)(const T&, const T&)>
class SegTree {
protected:
	unsigned int n = 1, rank = 0;
	std::vector<T> node;
	T ident;
public:
	SegTree(unsigned int m, T init, T e_):ident(e_) {
		while (n < m) {
			n *= 2;
			rank++;
		}
		node.resize(2 * n, ident);
		for (unsigned int i = n; i < 2 * n; i++)node[i] = init;
		for (unsigned int i = n - 1; i > 0; i--)node[i] = nodef(node[i << 1], node[i << 1 | 1]);
	}
	SegTree(const std::vector<T>& initvec, T e_):ident(e_) {
		unsigned int m = initvec.size();
		while (n < m) {
			n *= 2;
			rank++;
		}
		node.resize(2 * n, ident);
		for (unsigned int i = n; i < 2 * n; i++) {
			if (i - n < m)node[i] = initvec[i - n];
		}
		for (unsigned int i = n - 1; i > 0; i--)node[i] = nodef(node[i << 1], node[i << 1 | 1]);
	}
	virtual void update(int i, T x) {
		i += n;
		node[i] = x;
		while (i != 1) {
			i >>= 1;
			node[i] = nodef(node[2 * i], node[2 * i + 1]);
		}
	}
	virtual T query(int l, int r) {
		l += n; r += n;
		T ls = ident, rs = ident;
		while (l < r) {
			if (l & 1) ls = nodef(ls, node[l++]);
			if (r & 1) rs = nodef(node[--r], rs);
			l >>= 1; r >>= 1;
		}
		return nodef(ls, rs);
	}
	virtual T operator[](const int& x) {
		return node[n + x];
	}
	void print() {
		rep(i, n)std::cout << operator[](i) << " ";
		std::cout << std::endl;
	}
};
static lint RSQ_nodef(const lint& lhs, const lint& rhs){return lhs + rhs;}
class RSQ :public SegTree<lint, RSQ_nodef> {
	using Base = SegTree<lint, RSQ_nodef>;
public:
	template<class... Args>
	RSQ(Args... args):Base(args..., 0){}
};
static lint RMiQ_nodef(const lint& lhs, const lint& rhs){return std::min(lhs, rhs);}
class RMiQ :public SegTree<lint, RMiQ_nodef> {
	using Base = SegTree<lint, RMiQ_nodef>;
public:
	template<class... Args>
	RMiQ(Args... args):Base(args..., LINF){}
};
static lint RMaQ_nodef(const lint& lhs, const lint& rhs){return std::max(lhs,rhs);}
class RMaQ :public SegTree<lint, RMaQ_nodef> {
	using Base = SegTree<lint, RMaQ_nodef>;
public:
	template<class... Args>
	RMaQ(Args... args):Base(args..., -LINF){}
};