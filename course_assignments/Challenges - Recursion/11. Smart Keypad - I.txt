#include <bits/stdc++.h>
using namespace std;
string keypad[10] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void printKeyCodes(string input,string output){
	if(input.size() == 0){
		cout<<output<<endl;
		return;
	}
	char ch = input[0];
	string code = keypad[ch-'0'];
	string ros = input.substr(1);
	for (int i = 0; i < code.length(); ++i){
		printKeyCodes(ros, output+code[i]);
	}
}
int main(int argc, char const *argv[]){
	string input;
	cin>>input;
	printKeyCodes(input,"");
	return 0;
}