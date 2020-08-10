#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"
#include "../other/template.hpp"
#include "../string/RollingHash.hpp"
std::string t,p;
int main(){
	ModInt::setMod(1000000007);
	std::cin>>t>>p;
	if(t.size()<p.size())return 0;
	RollingHash rt1(t,1007),rt2(t,10007),rp1(p,1007),rp2(p,10007);
	rep(i,t.size()-p.size()+1){
		if(rt1.query(i,i+p.size())==rp1&&rt2.query(i,i+p.size())==rp2)std::cout<<i<<std::endl;
	}
}