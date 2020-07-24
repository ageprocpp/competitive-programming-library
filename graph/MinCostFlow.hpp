#include "../other/template.hpp"
class MinCostFlow{
    class edge{
    public:
        int to,cap,cost,rev;
    };
    int n;
    std::vector<std::vector<edge>> vec;
    std::vector<int> h,dist,prevv,preve;
public:
    MinCostFlow(int n):n(n){
        vec.resize(n);
        h.resize(n);
        dist.resize(n);
        prevv.resize(n);
        preve.resize(n);
    }
    void add_edge(int from,int to,int cap,int cost){
        vec[from].push_back({to,cap,cost,(int)vec[to].size()});
        vec[to].push_back({from,0,-cost,(int)vec[from].size()-1});
    }
    int min_cost_flow(int s,int t,int f){
        int res=0;
        h.assign(n,0);
        while(f>0){
            dist.assign(n,INF);
            dist[s]=0;
            prique<P> que;
            que.push({0,s});
            while(!que.empty()){
                P p=que.top();
                que.pop();
                if(dist[p.second]<p.first)continue;
                rep(i,vec[p.second].size()){
                    edge &e=vec[p.second][i];
                    if(e.cap>0&&chmin(dist[e.to],dist[p.second]+e.cost+h[p.second]-h[e.to])){
                        prevv[e.to]=p.second;
                        preve[e.to]=i;
                        que.push({dist[e.to],e.to});
                    }
                }
            }
            if(dist[t]==INF){
                std::cerr<<"The demand is over maximum flow."<<std::endl;
                return -1;
            }
            rep(i,n)h[i]+=dist[i];
            int d=f;
            for(int i=t;i!=s;i=prevv[i]){
                chmin(d,vec[prevv[i]][preve[i]].cap);
            }
            f-=d;
            res+=d*h[t];
            for(int i=t;i!=s;i=prevv[i]){
                vec[prevv[i]][preve[i]].cap-=d;
                vec[i][vec[prevv[i]][preve[i]].rev].cap+=d;
            }
        }
        return res;
    }
};