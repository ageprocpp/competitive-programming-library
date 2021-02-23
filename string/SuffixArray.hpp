#pragma once
#include "../other/template.hpp"
class SuffixArray {
	std::string S;
	std::vector<int> SA;
	std::vector<int> InducedSorting(const std::vector<int> &S, int count) {
		std::vector<int> SA(S.size(), -1);
		std::vector<char> type = AssignType(S);
		std::vector<int> bucket = GetBucket(S, count);
		std::vector<int> nextLms(S.size(), -1), orderedLms;
		int lastLms = -1;
		rep(i, S.size()) {
			if (type[i] == 2) {
				SA[--bucket[S[i]]] = i;
				if (lastLms != -1) nextLms[lastLms] = i;
				lastLms = i;
				orderedLms.emplace_back(i);
			}
		}
		nextLms[lastLms] = lastLms;
		SortL(S, SA, type, count);
		SortS(S, SA, type, count);
		std::vector<int> lms;
		for (int i : SA) {
			if (type[i] == 2) lms.emplace_back(i);
		}
		int nowrank = 0;
		std::vector<int> newS = {0};
		REP(i, lms.size() - 1) {
			int pre = lms[i - 1], now = lms[i];
			if (nextLms[pre] - pre != nextLms[now] - now)
				newS.emplace_back(++nowrank);
			else {
				bool flag = false;
				rep(j, nextLms[pre] - pre + 1) {
					if (S[pre + j] != S[now + j]) {
						flag = true;
						break;
					}
				}
				if (flag) nowrank++;
				newS.emplace_back(nowrank);
			}
		}
		if (nowrank + 1 != lms.size()) {
			std::vector<int> V(S.size(), -1);
			rep(i, lms.size()) V[lms[i]] = newS[i];
			newS.clear();
			rep(i, S.size()) {
				if (V[i] != -1) newS.emplace_back(V[i]);
			}
			std::vector<int> SA_ = InducedSorting(newS, nowrank + 1);
			rep(i, SA_.size()) lms[i] = orderedLms[SA_[i]];
		}
		SA.assign(S.size(), -1);
		bucket = GetBucket(S, count);
		for (int i = lms.size() - 1; i >= 0; i--)
			SA[--bucket[S[lms[i]]]] = lms[i];
		SortL(S, SA, type, count);
		SortS(S, SA, type, count);
		return SA;
	}
	std::vector<char> AssignType(const std::vector<int> &S) {
		std::vector<char> type(S.size());
		type.back() = 2;
		for (int i = (int)S.size() - 2; i >= 0; i--) {
			if (S[i] < S[i + 1])
				type[i] = 0;
			else if (S[i] > S[i + 1]) {
				type[i] = 1;
				if (type[i + 1] == 0) type[i + 1] = 2;
			} else
				type[i] = type[i + 1];
		}
		return type;
	}
	std::vector<int> GetBucket(const std::vector<int> &S, int count) {
		std::vector<int> bucket(count);
		for (int i : S) bucket[i]++;
		rep(i, count - 1) bucket[i + 1] += bucket[i];
		return bucket;
	}
	void SortL(const std::vector<int> &S, std::vector<int> &SA,
			   const std::vector<char> &type, int count) {
		std::vector<int> bucket = GetBucket(S, count);
		for (int i : SA) {
			if (i > 0 && type[i - 1] == 1) SA[bucket[S[i - 1] - 1]++] = i - 1;
		}
	}
	void SortS(const std::vector<int> &S, std::vector<int> &SA,
			   const std::vector<char> &type, int count) {
		std::vector<int> bucket = GetBucket(S, count);
		for (int i = S.size() - 1; i >= 0; i--) {
			int j = SA[i];
			if (j > 0 && (type[j - 1] == 0 || type[j - 1] == 2))
				SA[--bucket[S[j - 1]]] = j - 1;
		}
	}
	int match(const std::string &T, int index) const {
		rep(i, T.size()) {
			if (i + index >= S.size()) return 1;
			if (S[i + index] < T[i]) return 1;
			if (S[i + index] > T[i]) return -1;
		}
		return 0;
	}

  public:
	SuffixArray(const std::string &S) : S(S) {
		std::vector<int> conv;
		int min = INF, max = -INF;
		for (char i : S) {
			chmin(min, i);
			chmax(max, i);
		}
		for (char i : S) conv.emplace_back(i - min + 1);
		conv.emplace_back(0);
		SA = InducedSorting(conv, max - min + 2);
	}
	IP occ(const std::string &T) const {
		int minl = 0, maxl = S.size() + 1;
		while (minl + 1 < maxl) {
			int mid = (minl + maxl) / 2;
			if (match(T, SA[mid]) <= 0)
				maxl = mid;
			else
				minl = mid;
		}
		int minr = 0, maxr = S.size() + 1;
		while (minr + 1 < maxr) {
			int mid = (minr + maxr) / 2;
			if (match(T, SA[mid]) < 0)
				maxr = mid;
			else
				minr = mid;
		}
		return {maxl, maxr};
	}
	std::vector<int> locate(const std::string &T) const {
		std::vector<bool> v(S.size() + 1);
		std::vector<int> res;
		IP range = occ(T);
		for (int i = range.first; i < range.second; i++) v[SA[i]] = true;
		rep(i, S.size() + 1) {
			if (v[i]) res.emplace_back(i);
		}
		return res;
	}
	operator std::vector<int>() const { return SA; }
};

/**
 * @title Suffix array
 */