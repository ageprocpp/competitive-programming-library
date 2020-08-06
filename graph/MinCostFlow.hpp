#pragma once
#include "../other/template.hpp"
class MinCostFlow{
    class edge{
    public:
        int to,cap;
        lint cost;
        int rev;
    };
    int n;
    std::vector<std::vector<edge>> vec;
    std::vector<int> prevv,preve;
    std::vector<lint> h,dist;
    bool negative=false;
    lint BellmanFord(int s,int t){
        dist.assign(n,LINF);
        dist[s]=0;
        rep(i,n-1){
            rep(j,n){
                rep(k,vec[j].size()){
                    const edge &e=vec[j][k];
                    if(e.cap>0&&chmin(dist[e.to],dist[j]+e.cost+h[j]-h[e.to])){
                        prevv[e.to]=j;
                        preve[e.to]=k;
                    }
                }
            }
        }
        if(dist[t]==LINF){
            std::cerr<<"The demand is over maximum flow."<<std::endl;
            return -1;
        }
        rep(i,n)h[i]+=dist[i];
        for(int i=t;i!=s;i=prevv[i]){
            vec[prevv[i]][preve[i]].cap--;
            vec[i][vec[prevv[i]][preve[i]].rev].cap++;
        }
        return h[t];
    }
public:
    MinCostFlow(int n):n(n){
        vec.resize(n);
        h.resize(n);
        dist.resize(n);
        prevv.resize(n);
        preve.resize(n);
    }
    void add_edge(int from,int to,int cap,lint cost){
        if(cost<0)negative=true;
        vec[from].push_back({to,cap,cost,(int)vec[to].size()});
        vec[to].push_back({from,0,-cost,(int)vec[from].size()-1});
    }
    lint min_cost_flow(int s,int t,int f){
        lint res=0;
        h.assign(n,0);
        if(negative){
            res+=BellmanFord(s,t);
            f--;
        }
        while(f>0){
            dist.assign(n,LINF);
            dist[s]=0;
            prique<LP> que;
            que.push({0,s});
            while(!que.empty()){
                LP p=que.top();
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
            if(dist[t]==LINF){
                std::cerr<<"The demand is over maximum flow."<<std::endl;
                return -1;
            }
            rep(i,n)h[i]+=dist[i];
            int d=f;
            for(int i=t;i!=s;i=prevv[i]){
                chmin(d,vec[prevv[i]][preve[i]].cap);
            }
            f-=d;
            res+=(lint)d*h[t];
            for(int i=t;i!=s;i=prevv[i]){
                vec[prevv[i]][preve[i]].cap-=d;
                vec[i][vec[prevv[i]][preve[i]].rev].cap+=d;
            }
        }
        return res;
    }
};