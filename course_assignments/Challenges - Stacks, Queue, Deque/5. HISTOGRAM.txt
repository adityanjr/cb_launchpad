#include<iostream>
#include<stack>
using namespace std;
#define ll long long

ll getMaxArea(ll hist[], ll n) {
    stack<ll> s;
 
    ll max_area = 0; 
    ll tp;  
    ll area_with_top; 

    for(int i=1; i<n; i++) {
        while(!s.empty() && hist[s.top()] > hist[i]){
            int top = s.top();
            s.pop();
            area_with_top = (s.empty()) ? hist[top]*i : hist[top]*(i-s.top()-1);
            if(max_area < area_with_top)
                max_area=area_with_top;
        }
        s.push(i);
    }
    ll size = s.size();
    while (s.empty() == false) {
        ll top = s.top();
        s.pop();
        area_with_top = hist[top]*(size-s.size());
        if(max_area<area_with_top)
            max_area=area_with_top;
    }
    return max_area;
}

int main(){
    ll n;
    cin>>n;
    
    ll hist[n];
    for(int i=0; i<n; i++) {
        cin >> hist[i];
    }
    cout << getMaxArea(hist, n);
}