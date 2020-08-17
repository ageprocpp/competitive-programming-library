#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "../../other/template.hpp"
#include "../../graph/UnionFind.hpp"
int n,q,t,u,v;
int main(){
	scanf("%d%d",&n,&q);
	UnionFind uf(n);
	rep(i,q){
		scanf("%d%d%d",&t,&u,&v);
		if(t==0)uf.unite(u,v);
		else printf("%d\n",uf.same(u,v));
	}
	return 0;
}