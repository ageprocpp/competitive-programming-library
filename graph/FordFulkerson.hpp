#pragma once
#include "../other/template.hpp"
class FordFulkerson{
	class edge{
	public:
		int to,cap,rev;
	};
	int n;
	std::vector<std::vector<edge>> vec;
	std::vector<bool> used;
	int dfs(int v,int t,int f){
		if(v==t)return f;
		used[v]=true;
		for(edge& e:vec[v]){
			if(!used[e.to]&&e.cap>0){
				int d=dfs(e.to,t,std::min(f,e.cap));
				if(d){
					e.cap-=d;
					vec[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
public:
	FordFulkerson(int n):n(n){
		vec.resize(n);
		used.resize(n);
	}
	void add_edge(int from,int to,int cap){
		vec[from].push_back({to,cap,(int)vec[to].size()});
		vec[to].push_back({from,0,(int)vec[from].size()-1});
	}
	int max_flow(int s,int t){
		int res=0;
		while(true){
			used.assign(n,false);
			int f=dfs(s,t,INF);
			if(!f)return res;
			res+=f;
		}
	}
};