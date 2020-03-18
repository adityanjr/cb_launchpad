#include<iostream>
#include<string>
#include<unordered_map>
#include<map>
using namespace std;
#define hashmap map<char,node*>
map<string,int> mp;

class node{
public:
	char c;
	hashmap h;
	bool isTerminal;

    node(char ch){
    	c = ch;
    	isTerminal = false;
    }
};

class Trie{
node* root;

public:

Trie(){
	root = new node('\0');
	root->isTerminal = false;
}

void addWord(string s){
	node* temp = root;
	for(int i=0;i<s.size();i++){
		if(temp->h.count(s[i]))
			temp = temp->h[s[i]];
		else{
			node* newNode = new node(s[i]);
			temp->h[s[i]] = newNode;
			temp = newNode;
		}
	}
	temp->isTerminal = true;
}

bool isPresent(string s){
	node* temp = root;
	for(int i=0;i<s.size();i++){
		if(temp->h.count(s[i]))
			temp = temp->h[s[i]];
		else
			return false;
	}
	return temp->isTerminal;
}

void printWords(string prefix, node* temp, string osf){
	if(temp->isTerminal){
		cout<<prefix+osf<<endl;
	}
	if(temp->h.empty())
		return ;
	for(auto p:temp->h){
		printWords(prefix,p.second,osf+p.first);
	}
}

void printWordWithPrefix(string s){

	node* temp = root;
	for(int i=0;i<s.size();i++){
		if(temp->h.count(s[i])){
		temp = temp->h[s[i]];
		}
		else{
		    addWord(s);
			cout<<"No suggestions\n";
			return ;
		}
	}
	printWords(s,temp,"");
}
};

int main(){

    int n;
    cin>>n;
    Trie t;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        t.addWord(s);
    }

    int preNum;
    cin>>preNum;

    for(int i=0;i<preNum;i++){
        string s;
        cin>>s;
        t.printWordWithPrefix(s);
    }
	return 0;
}
