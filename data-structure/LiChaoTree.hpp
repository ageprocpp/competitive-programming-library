#pragma once
#include "../other/template.hpp"
class LiChaoTree{
    int n=1;
    std::vector<std::tuple<lint,lint,lint>> interval;
    std::vector<LP> node;
    std::vector<lint> cord;
    lint calc(LP l,lint x){
        return l.first*x+l.second;
    }
public:
    LiChaoTree(std::vector<lint> vec){
        vec.emplace_back(vec.back()+1);
        while(n<(int)vec.size())n*=2;
        while((int)vec.size()<n+1)vec.emplace_back(vec.back()+1);
        node.assign(2*n,{0,LINF});
        interval.emplace_back(0,0,0);
        for(int range=n;range;range>>=1){
            for(int i=0;i<n;i+=range){
                if(range==1)interval.emplace_back(vec[i],0,vec[i+range]);
                else interval.emplace_back(vec[i],vec[i+range/2],vec[i+range]);
            }
        }
        cord=std::move(vec);
    }
    void addLine(lint a,lint b){
        int cnt=1;
        while(true){
            lint l=std::get<0>(interval[cnt]),m=std::get<1>(interval[cnt]),r=std::get<2>(interval[cnt]);
            if(n<=cnt){
                if(calc(node[cnt],l)>calc({a,b},l))node[cnt]={a,b};
                break;
            }
            if(calc(node[cnt],l)<calc({a,b},l)&&calc(node[cnt],r)<calc({a,b},r))break;
            if(calc(node[cnt],l)>calc({a,b},l)&&calc(node[cnt],r)>calc({a,b},r)){
                node[cnt]={a,b};
                break;
            }
            if(calc(node[cnt],m)>calc({a,b},m)){
                LP memo=node[cnt];
                node[cnt]={a,b};
                a=memo.first;b=memo.second;
            }
            if(calc(node[cnt],l)>calc({a,b},l))cnt=cnt<<1;
            else cnt=cnt<<1|1;
        }
    }
    lint query(int idx){
        lint x=cord[idx];
        idx+=n;
        lint res=LINF;
        while(idx){
            chmin(res,calc(node[idx],x));
            idx>>=1;
        }
        return res;
    }
};