#Problem:
The problem says you have to pick a and b between x and y such that the XOR of those numbers is maximum.
Let say if x = 2 and y =4 .
The possible values ’ a ’ can have is - 2 and 3
Similarly ’ b ’ can have values 3 and 4
2 XOR 3 = 1
2 XOR 4 = 6
3 XOR 3 = 0
3 XOR 4 = 7
The output should be 7.

#include <iostream>
using namespace std;
int main() {
    int x, y, mx=-100000;
    cin >> x >> y;
    for(int i=x; i<=y; i++) {
        for(int j=x+1; j<=y; j++) {
            if(mx < (i^j)) mx=i^j;
        }
    }
    cout<<mx;
}
