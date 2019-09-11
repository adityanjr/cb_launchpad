#include <iostream>
using namespace std;

void fibo(int n){

	int a = 0, b=1;
	int c = a+b;
	cout<<a<<" "<<b<<" ";
	while(c<=n){
		cout<<c<<" ";
		a = b;
		b=c;
		c=a+b;
	}


}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	fibo(n);

	return 0;
}







