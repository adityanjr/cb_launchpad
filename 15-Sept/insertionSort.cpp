#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[6]= {5,4,9,6,8,2};

  //check the element on the left
	for(int i=1; i<6; i++){
    int j=i-1;
    while(j>=0 && arr[j]>arr[j+1]){
      swap(arr[j], arr[j+1]);
      j--;
    }
  }
// print array
	for(int k=0 ; k<6; k++){
		cout<<arr[k]<<", ";
	}
	return 0;
}
