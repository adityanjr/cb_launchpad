#Recursive

#include<iostream>
using namespace std;
int power(int x, int y) {
    int temp; 
    if( y == 0) 
        return 1; 
    temp = power(x, y/2); 
    if (y%2 == 0) 
        return temp*temp; 
    else
        return x*temp*temp; 
} 
int main() {
	int x,y;
	cin>>x>>y;
	cout<<power(x,y);
	return 0;
}
.............................................

#Iterative (Preferred)

#include<iostream>
using namespace std;
int power(int x, int y){
    int res = 1;
	while(y>0){
		if(y&1){
			res = res*x;
		}
		y=y>>1;
		x=x*x;
	}
	return res;
} 
int main() {
	int x,y;
	cin>>x>>y;
	cout<<power(x,y);
	return 0;
}
