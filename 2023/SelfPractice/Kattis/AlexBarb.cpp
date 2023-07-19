#include<bits/stdc++.h>
using namespace std;

int solve(int k,int m,int n){
    
    int player = 0;
    // k - x - n > m , x < k-(m+n)
    while(true){
        if(k-n < m){
            cout << 'W' << (player==0?"Alex ":"Barb ") << k << ' ' << n << endl;   
            k-=n;
        }
        else{
            int opt = k-(m+n);
            opt = max(opt,m);
            opt = min(opt,n);
            cout << 'S' << (player==0?"Alex ":"Barb ") << k << ' ' << opt << endl;
            k-=opt;
        }
        if(k < 0) return player;
        player = (player+1)%2;
    }
}

bool calc(int k,int m,int n){
    int d = n+1;
    cout << k%d << endl;
    return k%d < m;
}


int main(){
    int k,m,n;
    cin>>k>>m>>n;
    //cout << (solve(k,m,n) == 0 ? "Barb":"Alex");

    if(calc(k,m,n)){
        cout << "Alex";
    }
    else{
        cout << "Barb";
    }
}