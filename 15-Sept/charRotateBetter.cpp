#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int n, k;
  cout<<"input length of char: "<<endl;
  cin>>n;
  cout<<"times to rotate: "<<endl;
  cin>>k;
  char* arr = new char[n+1];
  cout<<"input chars: "<<endl;
  cin>>arr;
  arr[n]='\0';
  cout<<arr<<endl;

  char* tempArr = new char[k];
	for (int i = 0; i < k; ++i){
		tempArr[i] = arr[n-k+i];
	}
	for (int i = n-1-k; i >=0; i--){
		arr[i+k]=arr[i];
	}
	for (int i = 0; i < k; ++i){
		arr[i] = tempArr[i];
	}
	cout<<arr<<endl;

  return 0;
}
