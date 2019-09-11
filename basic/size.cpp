#include <iostream>
using namespace std;


void fun(int &num){
	num=5;
}

int main(int argc, char const *argv[])
{
	int n = 1;
	// cout<<sizeof(n)<<endl;
	// cout<<sizeof(char)<<endl;
	//cout<<&n<<endl;
	// fun(n);
	// cout<<n<<endl;
	// fun(n);
	// cout<<n<<endl;

	int i = 4;
	cout<<&i<<endl;
	int* add = &i;
	cout<<add<<endl;
	cout<<sizeof(add)<<endl;
	// char ch ='a';
	// char* chadd = &ch;

	// cout<<chadd<<endl;

	bool b = true;
	bool *addb = &b;
	cout<<addb<<endl;
	cout<<"----------------------"<<endl;
	cout<<add+1<<endl;
	cout<<addb+1<<endl;
	cout<<add+2<<endl;
	cout<<addb+2<<endl;

	cout<<sizeof(addb)<<endl;

	cout<<*(add)<<endl;
	cout<<*(addb)<<endl;









	return 0;
}