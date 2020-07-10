#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../other/template.hpp"
int main(){
	lint q,type,k,v;
	std::map<lint,lint> mp;
	std::cin>>q;
	rep(i,q){
		std::cin>>type;
		if(type==0){
			std::cin>>k>>v;
			mp[k]=v;
		}
		else{
			std::cin>>k;
			std::cout<<mp[k]<<std::endl;
		}
	}
	return 0;
}