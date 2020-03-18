#include <iostream>
using namespace std;


void hello(){
	cout<<"hello world"<<endl;
}

int factorial(int num){
	int fact=1;
	while(num>0){
		fact = fact*num;
		num--;
	}
	//hello();
	return fact;
}



int main(int argc, char const *argv[])
{

	int testcase;
	cin>>testcase;
	for (int i = 0; i < testcase; ++i)
	{
		int n;
		cin>>n;
		//cout<<factorial(n)<<endl;
		int result = factorial(n);
		cout<<result<<endl;

	}

	hello();


	return 0;
}


