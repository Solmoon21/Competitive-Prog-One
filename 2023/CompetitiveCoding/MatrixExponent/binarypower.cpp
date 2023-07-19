#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long power(long long b,long long p){
    long long res = 1;
    while(p>0){
        
        if(p&1){
            res *= b;
            res %= mod; 
        }
        b *= b;
        b %= mod;
        p>>=1;
    } // 1100100
    //cout<<(p&1)<<' ' << res <<' '<< p << ' ' <<b  << endl;
    return res;
}

int logab(int n,int b){
    return log2(n)/log2(b);
}

string solve(int A,int B, int C){
    int result = power(A,C) - power(B,C);
    return result == 0 ? "=" : result < 0 ? "<" : ">";
}

string solve2(int A,int B,int C){
    int aneg = (A<0 & C%2);
    int bneg = (B<0 & C%2);

    if(aneg != bneg){
        return aneg ? "<":">";
    }
    else{
        if(abs(A) == abs(B))
            return "=";

        if((abs(A) < abs(B)) ^ aneg ){
            return "<";
        }
        else{
            return ">";
        }
    }
}

int locker(int n){
    return 1;
}

int solve(long long A, long long N){
    return 1;
}

long long power9(long long a, long long n){
    long long p;
    if(n==0){
        return 1;
    }
    p=power9(a,n/2);
    p=(p*p)%9;
    if(n%2){
        p=(p*a)%9;
    }
    return p;
}

int main(){
    cout << power9(7,2) << endl;
    cout << power9(7,2) << endl;
    cout << power9(7,2) << endl;
    cout << power9(7,2) << endl;
    cout << power9(7,2) << endl;
}