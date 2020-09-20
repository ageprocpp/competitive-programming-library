#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B"
#include "../../other/template.hpp"
#include "../../graph/MinCostFlow.hpp"
int n,m,f;
int main(){
    scanf("%d%d%d",&n,&m,&f);
    MinCostFlow mcf(n,0,n-1);
    rep(i,m){
        int u,v,c,d;
        scanf("%d%d%d%d",&u,&v,&c,&d);
        mcf.add_edge(u,v,c,d);
    }
    printf("%d\n",mcf.add_flow(f));
}