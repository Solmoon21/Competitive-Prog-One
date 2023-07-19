#include<bits/stdc++.h>
using namespace std;

void PrintM(int (&arr)[9][9]);

bool canPlace(int (&M)[9][9],int i,int j,int k){
    int si = (i/3)*3;
    int sj = (j/3)*3;

    for(int n=0; n<9; n++){
       if(M[i][n] == k || M[n][j] == k) return false;
    }

    for(int x=si; x<si+3; x++ ){
        for(int y=sj; y<sj+3; y++){
            if(M[x][y] == k) {
                return false;
            }
        }
    }

    return true;
}

bool Solve(int (&M)[9][9],int i,int j){

    if(i == 9){
        cout << "Solved" << endl;
        PrintM(M);
        return true;
    }

    if(j == 8){
        return Solve(M,i+1,0);
    }

    if(M[i][j] != 0){
        return Solve(M,i,j+1);
    }

    for(int k=1; k<=9; k++){
        if(canPlace(M,i,j,k)){
            M[i][j] = k;
            bool aftermath = Solve(M,i,j+1);
            if(aftermath){
                return true;
            } 
            M[i][j] = 0;
        }
    }
    return false;
}

bool isValid(vector<vector<int>>& matrix, int x, int y, int val) {
    for (int j = 0; j < 9; j++) {
        if (matrix[x][j] == val) return false;
    }

    for (int i = 0; i < 9; i++) {
        if (matrix[i][y] == val) return false;
    }

    int smi = x / 3 * 3;
    int smj = y / 3 * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[smi + i][smj + j] == val) return false;
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>>& matrix, int i, int j) {
    if (i == 9) {
        return true;
    }

    int ni = 0, nj = 0;
    if (j == 8) {
        ni = i + 1;
        nj = 0;
    } else {
        ni = i;
        nj = j + 1;
    }

    if (matrix[i][j] != 0) {
        if (solveSudoku(matrix, ni, nj)) return true;
    } else {
        for (int po = 1; po <= 9; po++) {
            if (isValid(matrix, i, j, po)) {
                matrix[i][j] = po;
                if (solveSudoku(matrix, ni, nj)) return true;
                matrix[i][j] = 0;
            }
        }
    }

    return false;
}

void Dummy(int (&arr)[9][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            arr[i][j] = 10;
        }   
    }
}

void PrintM(int (&arr)[9][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << arr[i][j] << ' ';
        }   
        cout << endl;
    }
}

int main(){
    int M[9][9] = {
    //vector<vector<int>> M = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };


    if(!Solve(M,0,0)){
        cout << " Lee pl ya ml kwa";
    }

    //if(!solveSudoku(M,0,0)) cout << "Copy wrong";
    //else {
    //    for(auto r : M){
    //        for(auto i : r){
    //            cout << i << ' ';
    //        }
    //        cout << endl;
    //    }
    //}
}