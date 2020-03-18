#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int baised(vector<pair<int, string> > v, int n) {
    sort(v.begin(), v.end());
    int badness = 0;
    for (int i = 0; i < n; i++) {
        badness += abs(v[i].first - (i+1));
    }
    return badness;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, string>> v;
        for(int i=0; i<n; i++){
        string s;
        cin >> s;
        int rank;
        cin >> rank;
        v.push_back(make_pair(rank, s));}
        cout<<baised(v,n)<<endl;
    }
}