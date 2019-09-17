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
  //print even rows in reverse order
  for(int i=0; i<row; i++){
    if(i%2==0){
      for(int j=0; j<col; j++){
        cout<<arr[i][j]<<", ";
      }
    }
    else{
      for(int j=col-1; j>=0; j--){
         cout<<arr[i][j]<<", ";
      }
    }
    cout<<endl;
  }
  //delete
  for(int i=0; i<row; i++){
    delete [] arr[i];
  }
  delete [] arr;

  return 0;
}
