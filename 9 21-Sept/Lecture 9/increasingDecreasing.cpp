#include <bits/stdc++.h>
using namespace std;

void dec(int n){
	//base case
	if(n==0){
		cout<<n<<endl;
		return;
	}

	//self work
	cout<<n<<endl;
	dec(n-1);
	cout<<n<<endl;

}



int main(int argc, char const *argv[])
{
	/* code */
	int n = 5;
	
	dec(n);

	return 0;
}