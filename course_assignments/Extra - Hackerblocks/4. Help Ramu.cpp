#include<iostream>
using namespace std;
int smaller(int,int);

void input(int A[],int n){

    for(int i=0;i<n;i++)
        cin>>A[i];
}

int minimum_cost_calculator(int A[1000],int n,int c1,int c2,int c3){

    int min1=0,p;
    for(int i=0;i<n;i++){
        p=c1*A[i];
        min1=min1+smaller(c2,p);
    }
    return smaller(min1,c3);
}

int smaller(int m,int n){
    return m>n?n:m;
}

int main()
{
    int m,n,frequency_of_cab[1000],frequency_of_rickshaw[1000];
    int c1,c2,c3,c4;
    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        cin>>c1>>c2>>c3>>c4;
        cin>>m>>n;
        input(frequency_of_cab,m);
        input(frequency_of_rickshaw,n);
    
	    int min1,min2;
        min1=minimum_cost_calculator(frequency_of_cab,m,c1,c2,c3);
        min2=minimum_cost_calculator(frequency_of_rickshaw,n,c1,c2,c3);
		
        int Minimum_journey_cost;
        Minimum_journey_cost=smaller(min1+min2,c4);
            cout<<Minimum_journey_cost<<endl; 
	}
    return 0;
}