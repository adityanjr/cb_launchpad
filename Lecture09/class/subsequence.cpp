#include <bits/stdc++.h>
using namespace std;

void subsequence(string input,string output ){

	if(input.length()==0){
		cout<<output<<endl;
		return;
	}
	char ch = input[0];

	string ros = input.substr(1);

	subsequence(ros, output);
	subsequence(ros, output+ch);


}

int main(int argc, char const *argv[])
{
	string input = "abc";

	subsequence(input, "");

	return 0;
}