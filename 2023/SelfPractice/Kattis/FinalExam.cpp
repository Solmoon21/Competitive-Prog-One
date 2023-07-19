//https://open.kattis.com/problems/finalexam2
#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,mark = 0;
    cin>>n;
    char curr,last;
    cin>>curr;
    last = curr;
    for(int i=1; i<n; i++){
        cin>>curr;
        if(curr == last) mark++;
        last = curr;
    }

    cout << mark;
}