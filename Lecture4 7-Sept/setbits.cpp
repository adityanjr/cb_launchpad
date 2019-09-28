#include <iostream>
using namespace std;

int countSetbits(int n){
	int count=0;
	while (n>0){
		n&1 ? count++ : 0;
		n = n>>1;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	cout << countSetbits(n);
	return 0;
}
