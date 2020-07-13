#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "../other/template.hpp"
#include "../data-structure/WaveletMatrix.hpp"
int n,q;
std::vector<int> a;
int main(){
    std::cin>>n>>q;
    a.resize(n);
    rep(i,n)std::cin>>a[i];
    WaveletMatrix wm(a);
    rep(i,q){
        int l,r,k;
        std::cin>>l>>r>>k;
        std::cout<<wm.quantile(l,r,k+1)<<std::endl;
    }
}