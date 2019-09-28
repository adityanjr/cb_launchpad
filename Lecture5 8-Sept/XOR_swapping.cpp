#include <iostream>
using namespace std;
int main(){
    int a=2, b=3;
    a ^= b;
    b ^= a;
    a ^= b;
    cout<<a<<" "<<b;
}