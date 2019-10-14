#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string str ="abcdefgh";
	string sub = str.substr(1, 4);
	cout<<sub<<endl;
	sub = str.substr(2, 4);
	cout<<sub<<endl;
	sub = str.substr(1);
	cout<<sub<<endl;
	return 0;
}