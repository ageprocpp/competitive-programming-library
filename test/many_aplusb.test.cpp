#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../other/template.hpp"
int main(){
	lint t,a,b;
	std::cin>>t;
	rep(i,t){
		std::cin>>a>>b;
		std::cout<<a+b<<std::endl;
	}
	return 0;
}