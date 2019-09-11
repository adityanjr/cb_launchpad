#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	
// 	int i =10;
// 	int a = 5;
// 	cout<<i<<endl;


// //	++i;//preincrement
// 	int b = ++i;
// 	int sum = b + a;
// 	cout<<sum<<endl;

// //	i++;//postincrement
// 	b= i++;
// 	sum = b + a;
// 	cout<<sum<<endl;

// 	b= ++i;
// 	sum = b + a;
// 	cout<<sum<<endl;

// 	i = 1;
// 	cout<< ++i + i++<<endl;



	int n;
	cin>>n;
	int sum =0;
	for (int i = 1; i <= n; i++)
	{
		
		sum+=i;  //sum = sum+i;

	}
	cout<<sum<<endl;



	return 0;
}