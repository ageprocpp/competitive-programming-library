#pragma once
#include "../other/template.hpp"
class LiChaoTree{
    int n,id;
    std::vector<std::tuple<lint,lint,lint>> interval;
    std::vector<std::pair<LP,int>> node;
    std::vector<lint> cord;
    lint calc(std::pair<LP,int> l,lint x){
        return l.first.first*x+l.first.second;
    }
public:
    LiChaoTree(){}
    template<class T> LiChaoTree(T vec){init(vec);}
    template<class T> void init(T con){
        interval.clear();node.clear();cord.clear();
        n=1;id=0;
        con.emplace_back(con.back()+1);
        while(n<(int)con.size())n*=2;
        while((int)con.size()<n+1)con.emplace_back(con.back()+1);
        node.assign(2*n,{{0,LINF},-1});
        interval.emplace_back(0,0,0);
        for(int range=n;range;range>>=1){
            for(int i=0;i<n;i+=range){
                if(range==1)interval.emplace_back(con[i],0,con[i+range]);
                else interval.emplace_back(con[i],con[i+range/2],con[i+range]);
            }
        }
        cord=std::move(con);
    }
    void addLine(lint a,lint b){
        int cnt=1;
        std::pair<LP,int> newLine={{a,b},id};
        while(true){
            lint l=std::get<0>(interval[cnt]),m=std::get<1>(interval[cnt]),r=std::get<2>(interval[cnt]);
            if(n<=cnt){
                if(calc(node[cnt],l)>calc(newLine,l))node[cnt]=newLine;
                break;
            }
            if(calc(node[cnt],l)<calc(newLine,l)&&calc(node[cnt],r)<calc(newLine,r))break;
            if(calc(node[cnt],l)>calc(newLine,l)&&calc(node[cnt],r)>calc(newLine,r)){
                node[cnt]=newLine;
                break;
            }
            if(calc(node[cnt],m)>calc(newLine,m))std::swap(node[cnt],newLine);
            if(calc(node[cnt],l)>calc(newLine,l))cnt=cnt<<1;
            else cnt=cnt<<1|1;
        }
        id++;
    }
    std::pair<lint,int> query(int idx){
        lint x=cord[idx];
        idx+=n;
        std::pair<lint,int> res={LINF,-1};
        while(idx){
            if(chmin(res.first,calc(node[idx],x)))res.second=node[idx].second;
            idx>>=1;
        }
        return res;
    }
    void clear(){
        id=0;node.assign(2*n,{{0,LINF},-1});
    }
};