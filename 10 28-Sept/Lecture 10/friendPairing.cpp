#include <bits/stdc++.h>
using namespace std;

int combinations(int num){
	if(num<=2){
		return num;
	}

	int result = combinations(num-1) + (num-1)*combinations(num-2);
	return result;


}

int main(int argc, char const *argv[])
{
	int num;
	cin>>num;
	int result = combinations(num);
	cout<<result<<endl;

	return 0;
}