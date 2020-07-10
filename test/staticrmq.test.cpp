#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../other/template.hpp"
#include "../data-structure/SparseTable.hpp"
lint n,q,l,r;
std::vector<int> vec;
int main(){
	std::cin>>n>>q;
	vec.resize(n);
	rep(i,n){
		std::cin>>vec[i];
	}
	SparseTable<int> st(vec);
	rep(i,q){
		std::cin>>l>>r;
		std::cout<<st.query(l,r)<<std::endl;
	}
	return 0;
}