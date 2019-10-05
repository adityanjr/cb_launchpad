//find square root of n using binarySearch
#include <iostream>
using namespace std;

int binaryRoot(int n){
  int low =0, high= n;
  int root = 0;
  while (low<=high) {
    int mid=low + (high-low)/2;
    if(mid*mid ==n){
      root=mid;
      return root;
    }
    if(mid*mid >n){
      high = mid-1;
    }
    else{
      root=mid;
      low=mid+1;
    }
  }
  return root;
}
int main(){
  int n;
  cin>>n;
  cout<<binaryRoot(n);
}
