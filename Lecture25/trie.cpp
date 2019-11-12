#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

class node{
public:
	char data;
    string name;
    bool isTerminated;
	unordered_map<char, node*int>h;
	node(char d, string name){
		data = d;
        name = "";
        isTerminated = false;
	}
};
class trie {
	node* root;
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
			else
				temp = temp->h[ch];
		}
		temp->isTerminated = true;
        temp->name = username;
    } 

	bool search(string str, string username){
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
            cout << temp->username;
        }
		return temp->isTerminated;
	}
};

int main(int argc, char const *argv[])
{	
	trie t;
	t.insert("9891466", "sample");
	t.insert("mango","1");
	t.insert("appe","2");
	t.insert("man","s");
	string str = "9891466";
	if(t.search(str)){
		cout<<str<<" found"<<endl;
	}
	else{
		cout<<str<<" not found"<<endl;
	}
	return 0;
}






