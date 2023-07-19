//https://open.kattis.com/problems/makingameowth

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,p,x,y;
    cin >> n >> p >> x >>y;
    int m = ceil(p/n);
    int curr = 1;
    int total = 0;
    while(curr <= p){

        int R = min((n-1),p-(curr-1));
        int t1 = R * x;

        int t2 = min(m,(int)floor((p-curr)/n)) * y;
        
        //int t3 = min(y,p-curr+1)*(x+y);
        total += t1 + t2;
        curr+=R;
    }
    cout << curr << endl;
    cout << total;
}