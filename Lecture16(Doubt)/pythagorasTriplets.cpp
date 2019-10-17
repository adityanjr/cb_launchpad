
#include <iostream>
using namespace std;
int main(){
    long long int x;

    while( cin >> x){
            if(x < 3){ 
            cout<<"-1"<<endl;
            continue;
        }

        if(x & 1){ // when x is odd
           cout<<(x*x-1)/2<<" "<<(x*x+1)/2<<endl;
        }  
        else{// when x is even
            cout<<((x*x)/4)-1<<" "<<((x*x)/4)+1<<endl;
        }
    }
    return 0;
}