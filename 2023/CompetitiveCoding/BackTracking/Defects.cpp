#include<bits/stdc++.h>
using namespace std;

int explore(vector<vector<int>> A,int i,int j){
    int sz = 0, n = A.size();
    while(true){
        
        sz++;
        if(j+sz>n || i+sz>n) break;
        for(int x=j+1; x<j+sz; x++){
            for(int y=i+1; y<i+sz; y++){
                if(!A[y][x]){
                    return sz-1;
                }
            }
        }        
    }
    return sz-1;
}

int maxDefect(vector<vector<int>> A,int& myiter){
    int n = A.size();
    int ans = 1, maxans = n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            myiter++;
            if(A[i][j]){
                int localMax = explore(A,i,j); 
                if(localMax == maxans){
                    return maxans;
                }  
                if(ans < localMax){
                    ans = localMax;
                } 
                    
            }
        }
        maxans--;
    }

    return ans;
}

int main(){

    vector<vector<int>> A = {
        {1,1,1,1,1},
        {1,1,1,0,0},
        {1,1,1,0,0},
        {1,1,1,0,0},
        {1,1,1,1,1},
    };

    vector<vector<int>> B = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int myiter = 0;
    cout<<maxDefect(B,myiter);
    cout<< endl << myiter;
    //cout << explore(A,0,0);
}