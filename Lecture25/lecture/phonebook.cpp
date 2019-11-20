#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

class node{
public:
	char data;
	bool isTerminated;
	string name;
	unordered_map<char, node*>h;
	node(char d){
		data = d;
		isTerminated = false;
		name="";
	}
};
class trie
{	node* root;
public:
	trie(){
		root = new node('\0');
	}
	void insert(string str, string username){
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
		temp->name = username;
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
		if(temp->isTerminated){
			cout<<temp->name;
		}
		return temp->isTerminated;
	}
};

int main(int argc, char const *argv[])
{	
	trie t;
	t.insert("12345","apple");
	t.insert("12145","mango");
	t.insert("12125","appe");
	t.insert("12945","man");
	string str = "12146";
	if(t.search(str)){
		cout<<str<<" found"<<endl;
	}
	else{
		cout<<str<<" not found"<<endl;
	}


	
	return 0;
}






