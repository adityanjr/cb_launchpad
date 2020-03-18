#include<bits/stdc++.h> 
using namespace std; 
const int MAX = 100; 
  
// function to find median in the matrix 
int matrixmedian(int m[][MAX], int r ,int c) 
{ 
    int min = INT_MAX, max = INT_MIN; 
    for (int i=0; i<r; i++) 
    { 
        // to find the minimum element by comparing first index of all rows
        if (m[i][0] < min) 
            min = m[i][0]; 
  
        // Finding the maximum element by comparing last index of all rows
        if (m[i][c-1] > max) 
            max = m[i][c-1]; 
    } 
  
    int desired = (r * c + 1) / 2; 
    while (min < max) 
    { 
        int mid = min + (max - min) / 2; 
        int place = 0; 
  
        // to find count of elements smaller than mid in whole matrix
        for (int i = 0; i < r; ++i) 
            place += upper_bound(m[i], m[i]+c, mid) - m[i]; // to find count of elements smaller than mid in ith row
        if (place < desired) 
            min = mid + 1; 
        else
            max = mid; 
    } 
    return min; 
} 
  
int main() 
{ 
    int r = 3, c = 3; 
    int m[][MAX]= {{1,3,5}, 
                   {2,6,9}, 
                   {3,6,9}}; 
    cout << "Median is " << matrixmedian(m, r, c) << endl; 
    return 0; 
} 