#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

class node{
public:
	char data;
	bool isTerminated;
	unordered_map<char, node*>h;
	node(char d){
		data = d;
		isTerminated = false;
	}
};
class trie
{	node* root;
public:
	trie(){
		root = new node('\0');
	}
	void insert(string str){
		node* temp =root;
		for (int i = 0; i < str.length(); ++i)
		{	
			char ch = str[i];
			if(temp->h.count(ch) == 0){
				node* child = new node(str[i]);
				temp->h[ch] = child;
				temp = child;
			}
			else{
				temp = temp->h[ch];
			}
			
		}
		temp->isTerminated = true;
	} 

	bool search(string str){
		node* temp =root;
		for (int i = 0; i < str.length(); ++i)
		{	
			char ch = str[i];
			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}
			else{
				return false;
			}
		}
		return temp->isTerminated;
	}
};

int main(int argc, char const *argv[])
{	
	trie t;
	t.insert("apple");
	t.insert("mango");
	t.insert("appe");
	t.insert("man");
	string str = "app";
	if(t.search(str)){
		cout<<str<<" found"<<endl;
	}
	else{
		cout<<str<<" not found"<<endl;
	}


	
	return 0;
}






