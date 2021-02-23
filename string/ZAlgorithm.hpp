#pragma once
#include "../other/template.hpp"
std::vector<int> ZAlgorithm(const std::string& S) {
	int c = 0, n = S.size();
	std::vector<int> res(n, 0);
	REP(i, S.size() - 1) {
		int l = i - c;
		if (i + res[l] < c + res[c])
			res[i] = res[l];
		else {
			int j = std::max(0, c + res[c] - i);
			while (i + j < n && S[j] == S[i + j]) j++;
			res[i] = j;
			c = i;
		}
	}
	res[0] = n;
	return res;
}