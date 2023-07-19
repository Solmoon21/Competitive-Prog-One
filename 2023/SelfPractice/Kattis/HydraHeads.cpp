//https://open.kattis.com/problems/hydrasheads
#include<bits/stdc++.h>
using namespace std;
/*
    1 h -> 1 h
    1 t -> 2 t
    2 t -> 1 h
    2 h -> _ _
*/

/*
S   3 3
2   3 4 
2   3 5
2   3 6
3   4 4
3   5 2
3   6 0
4   4 0
4   2 0
4   0 0
*/

int sub2Times(int n){
    int cnt = 0;
    while(n>0){
        n-=2;
        cnt++;
    }
    return n<0?cnt-1:cnt;
}

int solve(int h,int t){
    int move = 0;
    while(h + t != 0){
        //cout << h << '\t' << t <<'\t'<<move <<endl;
        
        
        if(h==0 || h & 1){ // Odd Heads! Make it Even
            if(t==0 || t&1){
                move++;
                t++;
            }
            else{
                int tToh = t/2;    
                t-= 2*tToh;
                h+= tToh;
                move+=tToh;
            }
        }
        else if(h>0){
            move += h/2;
            h=0;
        }

        
    }
    return move;
}

int main(){
    int h,t;
    cin>>h>>t;
    while(h && t){
       cout<<solve(h,t)<<endl;
       cin>>h>>t;
    }
}