#include <iostream>
using namespace std;

int uniqueBinary(int arr[], int n){
  int low=0, high=n-1;
  while(low<=high){
    int mid=low + (high-low)/2;
    if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
       return arr[mid];
    }
    if(mid%2==0){
      if(arr[mid]==arr[mid+1])
        low=mid+2;
      else
        high=mid-1;
    }
    else{
      if(arr[mid]!=arr[mid-1])
        high=mid-1;
      else
        low=mid+1;
    }
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  int arr[]= {1,1,2,2,3,3,4,4,5,5,6,7,7,8,8};
  int n=15;
  cout<<uniqueBinary(arr,n);
  return 0;
}
