#include<iostream>           //adjust both rows and column
using namespace std;
int main() {
    int n, row, col;
    cin>>n;
    row=n; col=n;
    if(n>=5){
    for (int i = 0; i < row; i++) { 
    for (int j = 0; j < col; j++) { 
          
    // checking if i < row/2 
    if (i < row / 2) { 
          
        // checking if j<col/2 
        if (j < col / 2) { 
              
        // print '*' if j=0 
        if (j == 0) 
            cout << "*"; 
              
        // else print space 
        else
            cout << " "; 
        } 
          
        // check if j=col/2  
        else if (j == col / 2) 
        cout << "*"; 
        else 
        { 
        // if i=0 then first row will have '*' 
        if (i == 0) 
            cout << "*"; 
        } 
    } 
    else if (i == row / 2) 
        cout << "*"; 
    else { 
          
        // middle column and last column will have '*' 
        // after i > row/2 
        if (j == col / 2 || j == col - 1) 
        cout << "*"; 
          
        // last row 
        else if (i == row - 1) { 
              
        // last row will be have '*' if  
        // j <= col/2 or if it is last column 
        if (j <= col / 2 || j == col - 1) 
            cout << "*"; 
        else
            cout << " "; 
        }  
        else
        cout<< " "; 
    } 
    } 
    cout << endl; 
} 
    }
	return 0;
}




#include<iostream>    //take rows as input
using namespace std;
int main() 
{
	int n;
	cin>>n;
    if(n>=5){
	int hn=(n+1)/2;
	for(int i=1;i<=n;i++)
	{
	    for(int j=1;j<=n;j++)
	    {
	        if(i==hn||j==hn||(i==1 && j>hn)||(i==n && j<hn)||(j==1 && i<hn)||(j==n && i>hn))
	        cout<<"*";
	        else cout<<" ";
	    }
	    cout<<endl;
	}
    }
	return 0;
}
