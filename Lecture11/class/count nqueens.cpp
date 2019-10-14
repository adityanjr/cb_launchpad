#include <iostream>
using namespace std;
int count=0;
bool isSafe(int maze[][10], int row, int col, int n){
	int i, j;
	//col
	i = row-1;
	while (i >= 0)
	{
		if(maze[i][col] == 1){
			return false;
		}
		i--;
	}
	//left diagonal
	i = row-1;
	j = col-1;
	while(i>=0 && j>=0){
		if(maze[i][j] == 1){
			return false;
		}
		i--;
		j--;
	}

	//right diagonal
	i = row-1;
	j = col+1;
	while(i>=0 && j<= n-1){
		if(maze[i][j] == 1){
			return false;
		}
		i--;
		j++;
	}
	// position is safe
	return true;
}

bool nQueen(int maze[][10], int row, int n){
	//base case
	 if(row == n){
	 	++count;
	 	return false;
	 }
	 for (int col = 0; col < n; col++)
	 {
	 	if(isSafe(maze,row, col, n)){
	 		maze[row][col] = 1;

	 		bool result = nQueen(maze, row+1, n);
	 		if(result){
	 			return true;
	 		}
	 		maze[row][col]= 0;
	 	}
	 }
	 return false;
}

int main(int argc, char const *argv[])
{	int maze[10][10];
	int n;
	cin>>n;
	nQueen(maze, 0, n);
    cout<<count;
	return 0;
}