#include <bits/stdc++.h>
using namespace std;
string arr[27] = {"", "a", "b","c", "d","e","f","g","h","i",
					"j","k","l","m","n","o","p","q","r","s",
					"t","u","v", "w","x","y","z"};
void codeOfStrings(string input, string output){
	if(input.size()==0){
		cout<<output<<endl;
		return;
	}

	int one = input[0] - '0';
	int two;
	if(input.size()>1){
		two = stoi(input.substr(0,2));

	}else{
		two =0;
	}

	if(input.size()>1 && two<=26){
		char ch1 = char(one + 'a'-1);
		//char ch1  = arr[one];
		codeOfStrings(input.substr(1), output+ch1);
		char ch2 = char(two + 'a'-1);
		//char ch2  = arr[two];
		codeOfStrings(input.substr(2), output+ch2);
	}
	else{
		char ch1 = char(one + 'a'-1);
		//char ch1  = arr[one];
		codeOfStrings(input.substr(1), output+ch1);
	}
}


int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
codeOfStrings(str, "");

	return 0;
}






