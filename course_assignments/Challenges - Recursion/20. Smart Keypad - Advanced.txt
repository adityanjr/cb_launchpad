#include <iostream>
#include <cstring>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" ,
  "mno", "pqrs" , "tuv", "wxyz" };
string output[10000000];
int k = 0;

string searchIn [] = { "prateek", "sneha", "deepak", "arnav", 
  "shikha", "palak", "utkarsh", "divyam", "vidhi", "sparsh", "akku" };

void codes(char in[], char out[], int i){
    // base case
    if (in[i]== '\0') {
        out[i] = '\0';
        output[k] = out ;
        k++;
        return;
    }
    
    int k=0;
    while (table[in[i]-'0'][k] != '\0') {
        out[i] = table[in[i]-'0'][k] ;
        codes(in, out, i+1);
        k++;
    }
    
}

int isSubstring(string s1, string s2) { //s1 small, s2 parent
    int M = s1.length();
    int N = s2.length();
    
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;
        
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
        
        if (j == M)
            return i;
    }
    return -1;
}

void printAns(){
    for (int i=0; i<k; i++) {
        for (int j=0; j<11; j++) {
            if(isSubstring(output[i], searchIn[j]) != -1)
                cout << searchIn[j] << endl ;
        }
    }
}

int main() {
    char in[100], out[100]; cin>> in;
    codes(in,out,0);
    printAns();
}