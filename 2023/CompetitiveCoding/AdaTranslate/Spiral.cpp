#include<bits/stdc++.h>
using namespace std;


// Square Mat
void PrintSnail(vector<vector<int>> arr){
    int start = 0, end = arr.size();
    bool isRow = true;

    int i = start;
    while( i < end ){
        cout << arr[i][end-i] << ' ';
        i++;
    }


}

int main(){


    
}