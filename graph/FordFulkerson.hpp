#pragma once
#include "../other/template.hpp"
class FordFulkerson{
	class edge{
	public:
		int to;
		lint cap;
		int rev,id;
		bool isrev;
	};
	int n,idx=0;
	std::vector<std::vector<edge>> vec;
	std::vector<bool> used;
	lint dfs(int v,int t,lint f){
		if(v==t)return f;
		used[v]=true;
		for(edge& e:vec[v]){
			if(!used[e.to]&&e.cap>0){
				lint d=dfs(e.to,t,std::min(f,e.cap));
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
	void add_edge(int from,int to,lint cap){
		vec[from].push_back({to,cap,(int)vec[to].size(),idx,false});
		vec[to].push_back({from,0,(int)vec[from].size()-1,idx++,true});
	}
	lint max_flow(int s,int t){
		lint res=0;
		while(true){
			used.assign(n,false);
			lint f=dfs(s,t,LINF);
			if(!f)return res;
			res+=f;
		}
	}
	std::vector<lint> restore(){
		std::vector<lint> res(idx);
		rep(i,n){
			for(const auto& j:vec[i]){
				if(j.isrev)res[j.id]=j.cap;
			}
		}
		return res;
	}
};