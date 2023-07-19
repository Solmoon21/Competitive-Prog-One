#include<bits/stdc++.h>
using namespace std;

void GenerateBrackets(int n,int open,int close,string s,int balanced){

    if( balanced == n ) cout << s << endl;

    if( open < n ) {
        GenerateBrackets(n,open+1,close,s+"(",balanced);
    }

    if( close < open ) {
        GenerateBrackets(n,open,close+1,s+")",balanced+1);
    }

}


int main(){

    GenerateBrackets(3,0,0,"",0);

}