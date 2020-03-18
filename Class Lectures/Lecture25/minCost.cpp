#include <iostream>
#include <vector>
using namespace std;
int minCost(vector<pair<int,int> >v, int n) {
    int min = v[0].first;
    int totalCost = 0;
    for (int i = 1; i < n; i++){
        minCost = min(minCost, v[i].first);
        totalCost += v[i].first * v[i].second;
    }
    return totalCost;
}
int main() {
    int t;
    while(t--) {
        int n;
        cin >> n;
        vector<pair<int, int> > v;
        for (int i = 0; i < n; i++){
            int x, y;
            v.push_back(make_pair(x, y));
        }
        cout << minCost(v.first, v.second, n);
    }
}