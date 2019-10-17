#include<iostream>
using namespace std;
bool isSorted(int ar[],int N){
  if(N==1)
    return true;
  if(ar[0]<=ar[1] && isSorted(ar+1,N-1))
    return true;
  return false;
}

int main(){
	int N;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++){
	  cin>>arr[i];
	}
	bool Y = isSorted(arr, N);
	if(Y==1)
	    cout<<"true";
	else
	    cout<<"false";
	return 0;
}
