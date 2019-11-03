#include "Stack.h"
using namespace std;

int main(int argc, char const *argv[])
{
	
	stack st;
	st.push(3);
	st.push(4);
	st.push(5);
	//st.v[1] = 10;
	cout<<st.top()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	return 0;
}
