#include "../other/template.hpp"
template<typename T,bool isMin>
class ConvexHullTrick{
	static constexpr double INF=DBL_MAX;
	class Line{
	public:
		T m,b,val;
		int id;
		double x;
		bool isQuery;
		inline Line(int id=-1,T m=0,T b=0):id(id),m(m),b(b),isQuery(false){}
		T eval(T x)const{return m*x+b;}
		bool parallel(const Line& l)const{return m==l.m;}
		double intersect(const Line& l)const{
			return parallel(l)?INF:(l.b-b)/(m-l.m);
		}
		inline bool operator<(const Line &l)const{
			if(l.isQuery)return x<l.val;
			return m<l.m;
		}
	};
	int index=1;
	std::set<Line> st;
	using iter=typename std::set<Line>::iterator;
	inline bool cPrev(iter it)const{return it!=st.begin();}
	inline bool cNext(iter it)const{return it!=st.end()&&std::next(it)!=st.end();}
	bool bad(const Line& l1,const Line& l2,const Line& l3)const{
		return l1.intersect(l3)<=l1.intersect(l2);
	}
	bool bad(iter it)const{
		return cPrev(it)&&cNext(it)&&bad(*std::prev(it),*it,*std::next(it));
	}
	iter update(iter it){
		if(!cPrev(it))return it;
		double x=it->intersect(*std::prev(it));
		Line tmp(*it);
		tmp.x=x;
		it=st.erase(it);
		return st.insert(it,tmp);
	}
public:
	void addLine(T m,T b){
		if(isMin)m=-m,b=-b;
		Line l(index++,m,b);
		if(st.empty())l.x=-INF;
		iter it=st.lower_bound(l);
		if(it!=st.end()&&l.parallel(*it)){
			if(it->b<b)it=st.erase(it);
			else return;
		}
		it=st.insert(it,l);
		if(bad(it)){
			st.erase(it);
			return;
		}
		while(cPrev(it)&&bad(std::prev(it)))st.erase(std::prev(it));
		while(cNext(it)&&bad(std::next(it)))st.erase(std::next(it));
		it=update(it);
		if(cPrev(it))update(std::prev(it));
		if(cNext(it))update(std::next(it));
	}
	std::pair<T,int> query(T x){
		Line q;
		q.val=x;q.isQuery=true;
		iter it=--st.lower_bound(q);
		if(isMin)return {-it->eval(x),it->id};
		return {it->eval(x),it->id};
	}
	void clear(){
		st.clear();index=0;
	}
};