#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../other/template.hpp"
#include "../../data-structure/SparseTable.hpp"
int n,q,l,r;
std::vector<int> vec;
int main(){
	scanf("%d%d",&n,&q);
	vec.resize(n);
	rep(i,n)scanf("%d",vec.data()+i);
	SparseTable<int> st(vec);
	rep(i,q){
		scanf("%d%d",&l,&r);
		printf("%d\n",st.query(l,r));
	}
	return 0;
}