//find square root of n using binarySearch
#include <iostream>
using namespace std;

float binaryRoot(int n, int precision){
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
  float prec= 0.1;
  while(precision!=0){
    if(root*root==n){
      return root;
    }
    else if(root*root<n){
      root+=prec;
    }
    else{
      root -= prec;
      prec /= 10;
      precision--;
    }
  }
  return root;
}

int main(){
  int n, k;
  cin>>n>>k;
  cout<<binaryRoot(n, k);
}
