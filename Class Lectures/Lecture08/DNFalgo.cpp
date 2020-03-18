#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[10]= {1,2,1,0,2,1,0,1,2,0};
  int high=9, low=0, med=0;
  while(med<=high){
    switch (arr[med]){
    case 0:
      swap(arr[med], arr[low]);
      low++;
      med++;
      break;

    case 1:
      med++;
      break;

    case 2:
      swap(arr[med], arr[high]);
      high--;
      break;
    }
  }
// print array
	for(int k=0 ; k<10; k++){
		cout<<arr[k]<<", ";
	}
	return 0;
}
