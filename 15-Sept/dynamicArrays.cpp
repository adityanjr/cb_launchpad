#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int row, col;
  cin>>row>>col;

  int** arr = new int*[row];
  for(int i=0; i<row; i++){
    arr[i] = new int[col];
  }
  //input array elements
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      cin>>arr[i][j];
    }
  }
  //print array
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      cout<<arr[i][j]<<", ";
    }
  }
  //delete
  for(int i=0; i<n; i++){
    delete [] arr[i];
  }
  delete [] arr;

  return 0;
}
