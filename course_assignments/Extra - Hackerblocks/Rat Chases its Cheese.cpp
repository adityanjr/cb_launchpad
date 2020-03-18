#include <iostream>
using namespace std;
bool isSafe(int r, int c, int row, int col, int matrix[5][4], int sol[5][4]){
    if(r>=0 && r<=row && c>=0 && c<=col && matrix[r][c]==0 && sol[r][c] ==0){
        return true;
    }
    return false;
}
void printMatrix(int mat[5][4], int row, int col){
    for(int i=0; i<=row; i++){
        for(int j=0; j<=col; j++){
            cout<<mat[row][col]<<" ";
        }
        cout<<endl;
    }
}
bool solveMatrix(int r, int c, int row, int col, int matrix[5][4] , int sol[5][4] ){
    if(r == row && c == col){
        if(isSafe(r,c,row,col,matrix,sol)){
            sol[r][c] = 1;
            printMatrix(sol,row,col);
            return true;
        }
        else{
            return false;   
        }
       
    }

    if(isSafe(r,c,row,col,matrix,sol)){
        sol[r][c] = 1;
    // down
        if(solveMatrix(r+1, c, row, col, matrix, sol) == true){
            return true;
        }
    //right
        if(solveMatrix(r, c+1, row, col, matrix, sol) == true){
            return true;
        }
    //up
        if(solveMatrix(r-1, c, row, col, matrix, sol) == true){
            return true;
        }
    //left
        if(solveMatrix(r, c-1, row, col, matrix, sol) == true){
            return true;
        }
    //backtrack 
        sol[r][c] = 0;
        return false;
    }
         return false;
}

int main() {
    int mat[5][4] = {{0,0,1,0},
                {0,0,0,1},
                {1,0,1,0},
                {1,0,0,1},
                {1,1,0,0}};
    int sol[5][4] = {0};
    if(!solveMatrix(0,0,4, 3, mat,sol)){
        cout<<"NO PATH FOUND"<<endl;
    }
}
