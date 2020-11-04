#pragma once
#include "../other/template.hpp"
template<int char_size,int base>
class Trie{
	class Node{
	public:
		std::vector<int> next;
		int c,cnt=0,lastcnt=0;
		Node(int c_):c(c_){next.assign(char_size,-1);}
	};
protected:
	std::vector<Node> nodes;
public:
	Trie():nodes(1,0){}
	void insert(const std::string &word,int word_id){
		int node_id=0;
		for(char i:word){
			int c=i-base;
			int &next_id=nodes[node_id].next[c];
			if(next_id==-1){
				next_id=nodes.size();
				nodes.push_back(Node(c));
			}
			nodes[node_id].cnt++;
			node_id=next_id;
		}
		nodes[node_id].cnt++;
		nodes[node_id].lastcnt++;
	}
	void insert(const std::string &word){insert(word,nodes[0].cnt);}
	void erase(const std::string &word){
		std::vector<int> path;
		path.reserve(word.size());
		int node_id=0;
		for(char i:word){
			int c=i-base;
			if(nodes[node_id].next[c]==-1||nodes[node_id].cnt==0)return;
			path.emplace_back(node_id);
			node_id=nodes[node_id].next[c];
		}
		nodes[node_id].lastcnt--;
		nodes[node_id].cnt--;
		for(int i:path)nodes[i].cnt--;
	}
	bool search(const std::string &word,bool prefix=false)const{
		int node_id=0;
		for(char i:word){
			int c=i-base;
			if(nodes[node_id].next[c]==-1||nodes[node_id].cnt==0)return false;
			node_id=nodes[node_id].next[c];
		}
		return prefix||nodes[node_id].lastcnt;
	}
	bool start_with(const std::string& prefix)const{return search(prefix,true);}
	int size()const{return nodes[0].cnt;}
};
template<unsigned int bit>
class BinaryTrie:public Trie<2,'0'>{
public:
	void insert(int n){Trie<2,'0'>::insert(std::bitset<bit>(n).to_string());}
	void erase(int n){Trie<2,'0'>::erase(std::bitset<bit>(n).to_string());}
	bool search(int n,bool prefix=false)const{return Trie<2,'0'>::search(std::bitset<bit>(n).to_string());}
	bool start_with(int n)const{return Trie<2,'0'>::start_with(std::bitset<bit>(n).to_string());}
	int xor_min(int n)const{
		int node_id=0,res=0;
		std::string binary=std::bitset<bit>(n).to_string();
		rep(i,bit){
			int c=binary[i]-'0';
			if(nodes[node_id].next[c]==-1||nodes[nodes[node_id].next[c]].cnt==0){
				res+=1<<(bit-i-1);
				node_id=nodes[node_id].next[1-c];
			}
			else node_id=nodes[node_id].next[c];
		}
		return res;
	}
};