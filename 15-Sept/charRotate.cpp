#include <iostream>
using namespace std;
void rotate(char* arr, int n) {
  char ch= arr[n-1];
  for (int i = n-2; i>=0; i--) {
    arr[i+1]=arr[i];
  }
  arr[0] = ch;
}

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
  for (int i = 0; i < k; ++i)
	{
		rotate(arr,n);
	}
	cout<<arr<<endl;
  return 0;
}
