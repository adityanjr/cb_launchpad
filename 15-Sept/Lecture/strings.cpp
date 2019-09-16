#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	char*arr = new char[30];

	cin.getline(arr,30);
	cout<<arr<<endl;
	//strings

	string str = "abcdef";

	cout<<str<<endl;
	str[2] ='N';
	cout<<str<<endl;

	
	cout<<str.size()<<endl;
	string str2;
	cin>>str2;
	string str3 = "jumps over";
	cout<<str+str2+str3<<endl;



	return 0;
}






