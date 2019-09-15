#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	int i = 0; //initialize
	int sum=0;
	while(i<=n){  //terminate
		sum+=i;
		i++;   //update
	}

	cout<<sum<<endl;


//break statement
	for (int j = 0; j < 10; j++)
	{
		int k =0;
		while(k<10){
			cout<<j <<" "<<k<<", ";
			if(j==5 && k==5){
				break;
			}
			k++;
		}
		cout<<endl;
	}

//continue statement
	for (int j = 0; j < 10; j++)
	{
		int k =0;
		while(k<10){
			cout<<j <<" "<<k<<", ";
			if(j==5 && k==5){
				continue;
			}
			k++;
		}
		cout<<endl;
	}

	return 0;
}