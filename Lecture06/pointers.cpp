#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	// address operator &
	// int a = 2;
	//  cout<<"value of a: "<<a<<endl;
	//  cout<<"address of a: "<<&a<<endl;


	//  bool x = true;
	//  cout<<"value of x: "<<x<<endl;
	//  cout<<"address of x: "<<&x<<endl;

	// // //pointer *

	//  int* add_a = &a;
	//  bool *add_x = &x;

	//  cout<<"add_a : "<<add_a<<endl;
	//  cout<<"add_x : "<<add_x<<endl;

	// // address of pointer variables
	// cout<<"address of add_a : "<<&add_a<<endl;
	// cout<<"address of add_x : "<<&add_x<<endl;


	// long *random_add;
	// random_add = 0;
	// //random_add = &a;
	// //random_add = 0x7ffee62d64d8; //can't do this
	// cout<<"value of random_add : "<<random_add<<endl;


	// //derefernce operator * 

	// cout<<"value at &a : "<<*(&a)<<endl;
	// cout<<"value at add_a : "<<*add_a<<endl;
	// cout<<"value at &x : "<<*(&x)<<endl;
	// cout<<"value at add_x : "<<*add_x<<endl;

	// cout<<"value at &add_a : "<<*(&add_a)<<endl;
	// cout<<"value at &add_x : "<<*(&add_x)<<endl;


	 //size of different variables or need of defining data type

	 // cout<<"size of a : "<<sizeof(a)<<endl;
	 // cout<<"size of add_a : "<<sizeof(add_a)<<endl;
	 // cout<<"value of add_a : "<<add_a<<endl;
	 // cout<<"value of (add_a + 1) : "<<(add_a+1)<<endl;
	 // cout<<"value at add_a : "<<*add_a<<endl;
	 // cout<<"value at (add_a + 1) : "<<*(add_a+1)<<endl;
	 // cout<<"-------------------------------"<<endl;
	 // cout<<"size of x : "<<sizeof(x)<<endl;
	 // cout<<"size of add_x : "<<sizeof(add_x)<<endl;
	 // cout<<"value of (add_x) : "<<(add_x)<<endl;
	 // cout<<"value of (add_x + 1) : "<<(add_x+1)<<endl;
	 // cout<<"value at (add_x) : "<<*(add_x)<<endl;
	 // cout<<"value at (add_x + 1) : "<<*(add_x+1)<<endl;


	 char ch = 'A';
	 char* add_ch = &ch;

	 cout<<"value of ch: "<<ch<<endl;
	 cout<<"address of ch: "<<&ch<<endl;
	 cout<<"value of add_ch: "<<add_ch<<endl;
	 cout<<"value of add_ch: "<<(void*)add_ch<<endl;
	 cout<<"value at address of ch: "<<*(&ch)<<endl;
	 cout<<"address of add_ch: "<<&add_ch<<endl;
	 cout<<"value at address of add_ch: "<<*(&add_ch)<<endl;
	 

	 int arr[10] ={1,2,3,4,5,6,7,8,9,10};

	 cout<<"arr : "<<arr<<endl;
	 cout<<"value at arr : "<<*arr<<endl;
	 cout<<"arr[0] : "<<arr[0]<<endl;
	 cout<<"arr+1 : "<<arr+1<<endl;
	 cout<<"value at (arr+1) : "<<*(arr+1)<<endl;
	 cout<<"arr[1] : "<<arr[1]<<endl;

	 for (int i = 0; i < 10; ++i)
	 {
	 	cout<<*(arr)<<endl;
	 //	arr = arr+1; //can't do this
	 }

	return 0;
}
























