#include <bits/stdc++.h>
using namespace std;

void toH(int disks, string src, string helper, string dst){

	if(disks==0){
		return;
	}

	toH(disks-1, src, dst, helper);
	cout<< disks<<"th disk move from"<< src<<" to "<<dst<<endl;
	toH(disks-1, helper, src ,dst);

}

int main(int argc, char const *argv[])
{	
	int n;
	cin>>n;
	toH(n, "A", "B", "C");
	return 0;
}






