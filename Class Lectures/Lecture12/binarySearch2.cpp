#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int key){
  int result = -1;
  while (low<=high) {
    int mid= (low+high)/2;
    if(arr[mid]==key){
      result = mid;  //first occurence for repeated elements
      high = mid-1;  //search in left
    }
    else if (arr[mid]<key){
      low = mid+1;
    }
    else{
      high = mid-1;
    }
  }
  return result;
}

int main() {
  int arr[1000];
  int n;
  cin>>n;
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  int key;
  cin>>key;
  int result = binarySearch(arr, 0, n, key);
  if(result<0){
    cout<<"not found";
  }
  else{
    cout<<"found at index: "<<result;
  }
  return 0;
}
