#include <bits/stdc++.h>
#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	//pair
	pair <int, string> p;
	p.first = 1;
	p.second = "apple";
	cout << p.first << endl;
	cout << p.second << endl;
	pair<int, string> p1 = make_pair(2, "mango");
	cout << p1.first << endl;
	cout << p1.second << endl;

	pair<int, string> pArr[10];

	pArr[0] = make_pair(2, "mango");
	pArr[0].first = 9;
	pArr[0].second = "guava";

//vector
	vector<int>v;
	// v.reserve(100);
	for (int i = 0; i < 10; ++i)
	{
		//v[i] = 10-i; // segmentation fault
		v.push_back(10 - i);

	}

	for (auto it : v)
	{
		cout << it << " ";
	}

	return 0;
}