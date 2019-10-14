#include <bits/stdc++.h>
using namespace std;
	
bool isSafe(int maze[5][4], int i, int j, int row, int col){

	if(maze[i][j] == 1 || i> row || j>col){
		return false;
	}

	return true;
}

bool ratinMaze(int maze[5][4], int i, int j, int row, int col){

	if(i == row && j== col){
		return true;
	}

	if(isSafe(maze, i, j, row, col)){
		bool rightResult = ratinMaze(maze, i, j+1, row, col);
		if(rightResult){
			return true;
		}
		bool downResult = ratinMaze(maze, i+1, j, row, col);
		if(downResult){
			return true;
		}
	}
	return false;

}


int main(int argc, char const *argv[])
{	

	int maze[5][4] = {{0,0,0,1},
					  {0,1,0,1},
					  {0,0,0,1},
					  {0,0,1,1},
					  {0,1,0,0}};
	// int sol[5][4] =  {{0,0,0,0},
	// 				  {0,0,0,0},
	// 				  {0,0,0,0},
	// 				  {0,0,0,0},
	// 				  {0,0,0,0}};

	bool pathPossible = ratinMaze(maze, 0, 0, 4,3);
	pathPossible ==1? cout<<"path exist"<<endl : cout<<"path do not exist"<<endl;
	
	return 0;
}











