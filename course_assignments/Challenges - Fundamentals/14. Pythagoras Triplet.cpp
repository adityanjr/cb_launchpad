#Problem:
PYTHAGORAS TRIPLET
Given a number N (denoting one of the legs of the triangle), Print its Pythagoras pair in increasing order if they exist. Otherwise, print "-1".

Input Format:
A single integer N

Constraints:
N <= 10^9

Output Format
Two numbers X and Y denoting the rest of the numbers of the Pythagorean triplet in increasing order.

Sample Input
3
Sample Output
4 5
............................................

Definition: “Pythagorean triplets” are integer solutions to the Pythagorean Theorem, i.e. they satisfy the equation a^2 + b^2 = c^2

Our task is to generate a triplet from an integral value. This can be a confusing task because, the side given to us can be a hypotenuse or a non-hypotenuse side.
Starting to calculate triplets by putting them in a formula, it can be deduced that only for 1 and 2, no triplets are possible.
Further,
if n is even, our triplets are calculated by formula (n^2/4 - 1)^2 + n^2 = (n^2/4 + 1)^2

if n is odd, our triplets are calculated by formula (n^2-1)^2/2  + n^2 = (n^2+1)^2/2

Proof:
Pythagoras Theorem can also be written as c^2 - b^2 = a^2
i.e a*a = (c-b)(c+b)
a*a x 1 = a*a, thus c = (a^2+1)/2 and b = (a^2 - 1)/2, this solution works if n is odd.
For even solution, c+b = n^2/2, c-b=2, thus, we get the above formula when n is even.

..............................................

#include <bits/stdc++.h> 
using namespace std; 
  
void evaluate(long long int n) 
{ 
  
    if (n == 1 || n == 2) 
        cout<<-1; 
  
    else if (n % 2 == 0) { 
  
        long long int var = n * n / 4; 
        cout<< var-1 << " " << var+1;
    } 
  
    else if (n % 2 != 0) { 
  

        long long int var = n * n + 1; 
        cout<<var / 2 - 1<<" "<< var / 2;
    } 
} 
  

int main() 
{ 
    long long int n;
    cin>>n;
    evaluate(n); 
    return 0; 
} 