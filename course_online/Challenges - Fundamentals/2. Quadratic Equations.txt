#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
int main ()
{
    float a, b, c, d, sqr;
    int x1, x2 ;
    cin >> a >> b >> c;
    d = b*b - 4*a*c;
    sqr = sqrt(d);
    x1 = (-b - sqr)/(2*a);
    x2 = (-b + sqr)/(2*a);
    
    if (d == 0){
        cout << "Real and Equal"<<endl;
        cout << x1 << " " << x2<<endl;
    }
    else if (d > 0){
        cout << "Real and Distinct"<<endl;
        cout << x1 << " " << x2<<endl;
    }
    else if (d < 0)
        cout << "Imaginary";
    return 0;
}