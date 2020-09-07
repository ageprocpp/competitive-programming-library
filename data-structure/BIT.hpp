#pragma once
#include "../other/template.hpp"
class BIT {
	int n;
	std::vector<lint> bit;
private:
	lint query(int a) {
		lint cnt = 0;
		while (a > 0) {
			cnt += bit[a];
			a -= a & -a;
		}
		return cnt;
	}
public:
	BIT(int n) :n(n) {
		bit.resize(n + 1);
	}
	void add(int a, lint x) {
		a++;
		while (a <= n) {
			bit[a] += x;
			a += a & -a;
		}
	}
	lint query(int l, int r) {return query(r) - query(l);}
	void clear() {
		bit.assign(n + 1, 0);
	}
	int lower_bound(lint x){
		int p=0,k=1;
		while(k*2<=n)k*=2;
		while(k>0){
			if(p+k<=n&&bit[p+k]<x){
				x-=bit[p+k];
				p+=k;
			}
			k/=2;
		}
		return p;
	}
	int upper_bound(lint x){
		int p=0,k=1;
		while(k*2<=n)k*=2;
		while(k>0){
			if(p+k<=n&&bit[p+k]<=x){
				x-=bit[p+k];
				p+=k;
			}
			k/=2;
		}
		return p;
	}
};