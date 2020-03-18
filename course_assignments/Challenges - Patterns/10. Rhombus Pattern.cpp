1. Solid Rhombus : Making Solid Rhombus is a bit similar to making solid square rather than the concept that for each ith row we have n-i blank spaces before stars as:
– – – ****
– – ****
– ****
****
2. Hollow Rhombus : Formation of Hollow Rhombus uses the idea behind formation of hollow square and solid rhombus. A hollow square with n-i blank spaces before stars in each ith rows result in formation of hollow rhombus.


1.
#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) 
    { 
        // Print trailing spaces 
        for (int j=1; j<=n - i; j++) 
            cout << " "; 
              
        // Print stars after spaces 
        for (int j=1; j<=n; j++) 
            cout << "*"; 
              
        // Move to the next line/row 
        cout << endl; 
    } 
	return 0;
}


2.
#include<iostream>
using namespace std;
int main() {
    int i, j, n;
    cin>>n;

    for (i=1; i<=n; i++) {
        // Print trailing spaces 
        for (j=1; j<=n - i; j++) 
            cout << " "; 
              
        // Print stars after spaces 
        // Print stars for each solid rows 
        if (i==1 || i==n) 
            for (j=1; j<=n; j++) 
                cout << "*"; 
                  
        // stars for hollow rows 
        else
            for (j=1; j<=n; j++) 
                if (j==1 || j==n) 
                    cout << "*"; 
                else
                    cout << " "; 
        cout << endl; 
    } 
	return 0;
}
