#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
	unordered_map<string, int>map;
	pair<string, int>p = make_pair("mango", 100);
	map.insert(p);
	map.insert( make_pair("kiwi", 500));
	map["apple"] = 200;
	for(auto it:map){
		cout<<it.first<<" "<<map[it.first]<<endl;
	}
	if(map.find("mango")!=map.end()){
		cout<<"found"<<endl;
	}
	else{
		cout<<"not found"<<endl;
	}
	cout<<map.count("mango")<<endl;
	cout<<map.count("guava")<<endl;
	return 0;
}








