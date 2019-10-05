#include <bits/stdc++.h>
using namespace std;

void printMatrix(int matrix[5][4], int row, int col){
	for (int i = 0; i <= row; ++i)
	{
		for (int j = 0; j <= col; ++j)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool isSafe(int maze[5][4], int i, int j, int row, int col){

	if(maze[i][j] == 1 || i> row || j>col){
		return false;
	}
	return true;
}

bool ratinMaze(int maze[5][4], int i, int j, int row, int col, int sol[5][4]){

	if(i == row && j== col){
		sol[i][j]=1;
		printMatrix(sol, row, col);
		return true;
	}

	if(isSafe(maze, i, j, row, col)){
		sol[i][j] =1;
		bool rightResult = ratinMaze(maze, i, j+1, row, col, sol);
		if(rightResult){
			return true;
		}
		bool downResult = ratinMaze(maze, i+1, j, row, col, sol);
		if(downResult){
			return true;
		}
		sol[i][j] =0;
	}
	return false;

}


int main(int argc, char const *argv[])
{

	int maze[5][4] = {{0,0,0,1},
					  {0,1,0,1},
					  {0,0,0,1},
					  {0,0,0,1},
					  {0,1,0,0}};
	int sol[5][4] =  {{0,0,0,0},
					  {0,0,0,0},
					  {0,0,0,0},
					  {0,0,0,0},
					  {0,0,0,0}};

	bool pathPossible = ratinMaze(maze, 0, 0, 4,3,sol);
	pathPossible ==1? cout<<"path exist"<<endl : cout<<"path do not exist"<<endl;

	return 0;
}
