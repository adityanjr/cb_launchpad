#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	
	int score = 38;

	if(score < 33){
		cout<<"student failed"<<endl;
	}
	else if(score > 33 && score <= 40 ){
		cout<<"suppli"<<endl;
	}
	else{
		cout<<"student passed"<<endl;
	}

	int n;
	cin>>n;

	if(n%2 == 0){
		cout<<n<<" is even"<<endl;
	}
	else{
		cout<<n<<" is odd"<<endl;
	}
 
	return 0;
}