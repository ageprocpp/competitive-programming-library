#pragma once
#include "../other/template.hpp"
#include "ModInt.hpp"
ModInt arithmetic_lagrange_interpolation(const ModInt& a,const ModInt& d,const std::vector<ModInt>& y,const ModInt& t){
	const int n=y.size()-1;
	ModInt res=0,ft=1;
	rep(i,n+1)ft*=t-(a+d*i);
	ModInt f=1;
	REP(i,n)f*=-d*i;
	res+=y[0]/f*ft/(t-a);
	rep(i,n){
		f*=i+1;
		f/=i-n;
		res+=y[i+1]/f*ft/(t-(a+d*(i+1)));
	}
	return res;
}