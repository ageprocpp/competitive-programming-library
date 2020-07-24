#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_B"
#include "../other/template.hpp"
#include "../graph/MinCostFlow.hpp"
int n,m,f;
int main(){
    std::cin>>n>>m>>f;
    MinCostFlow mcf(n);
    rep(i,m){
        int u,v,c,d;
        std::cin>>u>>v>>c>>d;
        mcf.add_edge(u,v,c,d);
    }
    std::cout<<mcf.min_cost_flow(0,n-1,f)<<std::endl;
}