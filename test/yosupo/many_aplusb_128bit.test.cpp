#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"
#include "../../basic/template.hpp"
#include "../../basic/FastIO.hpp"
FastIO::Scanner cin;
FastIO::Printer cout;
int main() {
	int T;
	cin >> T;
	rep(_, T) {
		std::string a_, b_;
		cin >> a_ >> b_;
		i128 a = 0, b = 0;
		bool nfa = a_[0] == '-', nfb = b_[0] == '-';
		for (int i = int(nfa); i < a_.size(); i++) a *= 10, a += a_[i] - '0';
		for (int i = int(nfb); i < b_.size(); i++) b *= 10, b += b_[i] - '0';
		if (nfa) a = -a;
		if (nfb) b = -b;
		a += b;
		std::string ans;
		bool nfans = a < 0;
		if (a == 0)
			cout << 0 << '\n';
		else {
			if (nfans) a = -a;
			while (a) ans.push_back('0' + a % 10), a /= 10;
			if (nfans) ans.push_back('-');
			std::reverse(all(ans));
			cout << ans << '\n';
		}
	}
	return 0;
}
