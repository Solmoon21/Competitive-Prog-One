#include<bits/stdc++.h>
using namespace std;

bool CanPlace(int n,int x,int y,int board[][20]){

    for(int i=0; i<x; i++){
        if(board[i][y]){
            return false;
        }
    }

    int i = x; int j = y;

    while(i>0 && j>0){
        i--; j--;
        if(board[i][j]){
            return false;
        }
    }

    i = x; j = y;
    while(i>0 && j<n-1){
        i--; j++;
        if(board[i][j]){
            return false;
        }
    }

    return true;
}

void PrintBoard(int n,int board[][20]){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }

    cout << endl;
}

int Solve(int n,int board[][20],int currI){

    if( currI == n ){
        // Can Print
        PrintBoard(n,board);
        return 1;
    }

    int ways = 0;
    for( int j=0; j<n; j++ ){
        if(CanPlace(n,currI,j,board)){
            board[currI][j] = 1;
            int success = Solve(n,board,currI+1);
            if(success){
                ways += success;
            }
            board[currI][j] = 0;
        }
    }

    return ways;
}


int main(){

    int board[20][20] = {0};
    Solve(4,board,0);


}