#include <iostream> 
using namespace std; 
  
// Function to find length of longest bitonic subarray 
int bitonic(int *A, int n) 
{ 
    // if A is empty 
    if (n == 0) 
        return 0; 
          
    // initializing max_len as one element can be inc or dec in itself
    int maxLen=1; 
          
    int start=0; 
    int nextStart=0; 
          
    int j =0; 
    while (j < n-1) 
    {  
        // look for end of ascent        
        while (j<n-1 && A[j]<=A[j+1]) 
            j++; 
              
        // look for end of descent        
        while (j<n-1 && A[j]>=A[j+1]){ 
                  
            // adjusting nextStart; this will be necessarily executed at least once, when we detect the start of the descent 
            if (j<n-1 && A[j]>A[j+1]) 
                nextStart=j+1; 
                  
            j++; 
        } 
              
        // updating maxLen, if required 
        maxLen = max(maxLen,j-(start-1)); 
              
        start=nextStart; 
    } 
          
    return maxLen; 
} 
  
int main() 
{ 
    int A[] = {12, 4, 78, 90, 45, 23}; 
    int n = 6; 
    cout<<"Length of max length Bitonic Subarray is "<<bitonic(A, n)<<endl; 
    return 0; 
} 