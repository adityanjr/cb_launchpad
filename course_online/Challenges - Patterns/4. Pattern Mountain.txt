#include<iostream>
using namespace std;

int main() {
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++)
      cout<<j<<" ";

    for(int k=((n-i)*2)-1;k>0;k--)
          cout<<"  ";

    for(int j=i;j>=1;j--){
        if(j!=n)
        cout<<j<<" ";
    }
    cout<<endl;
  }
	return 0;
}
