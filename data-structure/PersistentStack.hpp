#pragma once
#include "../other/template.hpp"
template<typename T>
class PersistentStack{
	class Node;
	using ptr=std::shared_ptr<Node>;
	class Node{
	public:
		T value;
		ptr prev;
	};
	ptr last=nullptr;
	PersistentStack(const ptr& p):last(p){}
public:
	explicit PersistentStack()noexcept{}
	T top(){return last->value;}
	PersistentStack push(T x)noexcept{
		ptr p(new Node);
		*p=Node{x,last};
		return PersistentStack(p);
	}
	T top()const noexcept{return last->value;}
	PersistentStack pop()const noexcept{
		return PersistentStack(last->prev);
	}
};