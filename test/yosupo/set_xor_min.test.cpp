#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include "../../other/template.hpp"
#include "../../string/Trie.hpp"
int Q,t,x;
int main(){
	scanf("%d",&Q);
	BinaryTrie<30> trie;
	rep(i,Q){
		scanf("%d%d",&t,&x);
		if(t==0&&!trie.search(x))trie.insert(x);
		if(t==1)trie.erase(x);
		if(t==2)std::cout<<trie.xor_min(x)<<std::endl;
	}
}