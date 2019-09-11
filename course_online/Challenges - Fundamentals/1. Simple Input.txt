#include<iostream>
using namespace std;
int main() {
    int n,sum=0;         
            while(sum>=0){
                cin>>n;
                if(n>=1000 && n<=-1000 ){
                    break;
                }
                sum += n;
                if(sum>=0) cout<<n<<endl;
            }
}
