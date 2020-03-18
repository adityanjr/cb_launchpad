#include<iostream>
using namespace std;
int localMinima(int* arr, int n){
  int low=0, high=n;
  int mid= low + (high-low)/2;
    if(arr[mid]>arr[mid-1]){
      high=mid-1;
    }
    else if(arr[mid]<arr[mid-1]){
      low=mid+1;
    }
    return mid;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int arr[1000];
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  cout<<"Minima at "<<localMinima(arr, n);
  return 0;
}
