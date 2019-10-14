//Given a string str consisting of a sentence,
//the task is to reverse every word of the sentence
//except the first and last character of the words.
#include <iostream>
using namespace std;
void reverse(char arr[]) {
  int i=0;
  for(int i=1;i<n; i++){
    swap(arr[i], arr[n-i])
  }
}
int main(int argc, char const *argv[]) {
  int n;  //input
  cout<<"input length of char: "<<endl;
  cin>>n;
  char* arr = new char[n+1];
  cout<<"input chars: "<<endl;
  cin>>arr;
  arr[n]='\0';
  cout<<arr<<endl;
  //
  return 0;
}
