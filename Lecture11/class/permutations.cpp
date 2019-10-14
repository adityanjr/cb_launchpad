#include <bits/stdc++.h>
using namespace std;

void permutations(string input, string output){

	if(input.size() == 0){
		cout<<output<<endl;
		return;
	}

	for (int i = 0; i < input.size(); ++i)
	{
		char ch = input[i];
		string ros = input.substr(0,i)+input.substr(i+1);

		permutations(ros, output+ch);
	}
}
	
int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	//cout<<str.substr(0,0)<<endl;
	permutations(str, "");
	return 0;
}