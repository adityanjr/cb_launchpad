#include <iostream>
using namespace std;

void print_wave(int array[][10000],int row,int col){
    for(int k=0; k<row; k++){
        if(k%2==0)
            for(int i=0; i<col; i++)
                cout<<array[k][i]<<", ";
        else
            for(int i=col-1; i>=0; i--)
                cout<<array[k][i]<<", ";

    }
    cout<<"END"<<endl;
}

int main(){
    int row,col;
    cin>>row>>col;
    int array[row][10000];
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            cin>>array[i][j];
                print_wave(array,row,col);
}