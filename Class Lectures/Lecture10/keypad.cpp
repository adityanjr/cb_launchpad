#include <bits/stdc++.h>
using namespace std;

string arr[10] = {"yz", "*", "abc", "def", "ghi", "jkl", "mno", "pqr", "stu", "vwx"};

void keypad(string input, string output){
	if (input.size() == 0)
	{
		cout<<output<<endl;
		return;
	}
	char ch= input[0];
	string code = arr[ch-'0'];
	string rest = input.substr(1);

	for (int i = 0; i < code.length(); ++i)
	{
		keypad(rest, output+code[i]);
	}
}


int main(int argc, char const *argv[])
{  
	string input;
	cin>>input;
	keypad(input,"");
 	return 0;
}
