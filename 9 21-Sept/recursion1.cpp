#include <iostream>
using namespace std;

void num(int n){
	if (n<0){
		return;
	}
	cout<<n<<endl;
	num(n-1);
	cout<<n<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	num(n);
	return 0;
}