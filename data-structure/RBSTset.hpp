#pragma once
#include "../other/template.hpp"
#include "RBST.hpp"
template<typename T>
class RBSTset{
	RBST<int> rbst;
public:
	RBSTset(){}
	const T& quantile(int idx)const{return rbst.find(idx);}
	bool contains(const T& val)const{return rbst.lower_bound(val)!=rbst.upper_bound(val);}
	void insert(const T& val){rbst.insert(rbst.lower_bound(val),val);}
	void erase(const T& val){rbst.erase(rbst.lower_bound(val));}
	void clear(){rbst.clear();}
	int size()const{return rbst.size();}
	bool empty()const{return rbst.empty();}
};