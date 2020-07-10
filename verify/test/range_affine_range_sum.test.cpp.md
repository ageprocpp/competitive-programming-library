---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :x: test/range_affine_range_sum.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#098f6bcd4621d373cade4e832627b4f6">test</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/range_affine_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include "../other/template.hpp"
#include "../data-structure/ModInt.hpp"
#include "../data-structure/IntervalSegTree.hpp"
const unsigned int ModInt::modulo=998244353;
class MySeg:public IntervalSegTree<ModInt,std::pair<ModInt,ModInt>>{
	using mp=std::pair<ModInt,ModInt>;
	ModInt nodef(const ModInt& a,const ModInt& b)const{return a+b;}
	void lazyf(mp& a,const mp& b){a={a.first*b.first,a.second*b.first+b.second};}
	void updf(ModInt& a,const mp& b,const unsigned int& width){a=b.first*a+b.second*width;}
public:
	MySeg(const std::vector<ModInt>& initvec):IntervalSegTree<ModInt,mp>(0,initvec){
		for(int i=n-1;i>0;i--)node[i]=nodef(node[2*i],node[2*i+1]);
	}
};
int n,q;
std::vector<ModInt> vec;
int main(){
	std::cin>>n>>q;
	vec.resize(n);
	rep(i,n){
		std::cin>>vec[i];
	}
	MySeg st(vec);
	rep(i,q){
		int t;
		std::cin>>t;
		if(t==0){
			int l,r,b,c;
			std::cin>>l>>r>>b>>c;
			st.update(l,r,{b,c});
		}
		else{
			int l,r;
			std::cin>>l>>r;
			std::cout<<st.query(l,r)<<std::endl;
		}
	}
	return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 307, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 187, in _resolve
    raise BundleErrorAt(path, -1, "no such header")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../data-structure/IntervalSegTree.hpp: line -1: no such header

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

