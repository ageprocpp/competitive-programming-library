#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include "../other/template.hpp"
#include "../data-structure/LiChaoTree.hpp"
int n,q;
lint a[200010],b[200010];
std::vector<P> vec;
std::vector<lint> cord;
int main(){
    std::cin>>n>>q;
    rep(i,n)std::cin>>a[i]>>b[i];
    rep(i,q){
        int type;
        std::cin>>type;
        if(type==0){
            lint a,b;
            std::cin>>a>>b;
            vec.emplace_back(a,b);
        }
        else{
            lint p;
            std::cin>>p;
            vec.emplace_back(p,LINF);
            cord.emplace_back(p);
        }
    }
    std::sort(all(cord));
    cord.erase(std::unique(all(cord)),cord.end());
    LiChaoTree lct(cord);
    rep(i,n)lct.addLine(a[i],b[i]);
    for(auto i:vec){
        if(i.second==LINF)std::cout<<lct.query(std::lower_bound(all(cord),i.first)-cord.begin())<<std::endl;
        else lct.addLine(i.first,i.second);
    }
}