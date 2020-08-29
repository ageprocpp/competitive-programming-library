#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"
#include "../../other/template.hpp"
#include "../../string/SuffixArray.hpp"
std::string t,p;
int main(){
	std::cin>>t>>p;
	SuffixArray sa(t);
	std::vector<int> vec=sa.locate(p);
	for(int i:vec)std::cout<<i<<std::endl;
}