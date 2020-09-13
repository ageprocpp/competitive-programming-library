#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"
#include "../../other/template.hpp"
#include "../../string/SuffixArray.hpp"
int main(){
	std::string s;
	std::cin>>s;
	SuffixArray sa(s);
	std::vector<int> vec=sa;
	vec.erase(vec.begin());
	printArray(vec);
}