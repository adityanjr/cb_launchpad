#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i=0; i<s.length();i++){
        int count =1 ;
        while (s[i]==s[i+1]) {
            count++;
            i++;
        }
        cout<< s[i];
        cout << count;
    }
    return 0;
}