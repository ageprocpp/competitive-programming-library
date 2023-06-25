#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../../basic/template.hpp"
int main() {
	int q, type;
	lint k, v;
	std::map<lint, lint> mp;
	scanf("%d", &q);
	rep(i, q) {
		scanf("%d", &type);
		if (type == 0) {
			scanf("%lld%lld", &k, &v);
			mp[k] = v;
		} else {
			scanf("%lld", &k);
			printf("%lld\n", mp[k]);
		}
	}
	return 0;
}