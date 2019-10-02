#include <iostream>
using namespace std;

bool isSafe(int maze[][], int row, int col, int i, int j){
  if (maze[i][j]==1 || i>row || j>col) {
    return false;
  }
  return true;
}

bool inMaze(int maze[][], int row, int col, int i, int j){
  if (i==row && j==col) {
    return true;
  }
  if (isSafe(maze, i, j, row, col)) {
    bool rightResult = inMaze(maze, i, j+1, row, col);
    if (rightResult) {
      return true;
    }
    bool downResult = inMaze(maze, i+1, j, row, col);
    if (downResult) {
      return true;
    }
  }
  return false;
}

int int main(int argc, char const *argv[]) {
  int maze[5][4] = {{0,0,0,1}, {0,1,0,0}, {0,0,0,1}, {0,0,1,1}, {0,1,0,0}};
  int path =
  return 0;
}
