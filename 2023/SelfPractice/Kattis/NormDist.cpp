//https://open.kattis.com/problems/differentdistances
#include<bits/stdc++.h>
using namespace std;

double calculateNorm(double x1,double y1,double x2,double y2,double p){
    double x = pow(abs(x1-x2),p);
    double y = pow(abs(y1-y2),p);
    double a = pow(x+y,1.0/p);
    return a;
}


int main(){
    double x1,y1,x2,y2,p;
    while(cin>>x1){
        if(!x1) return 1;
        cin>>y1>>x2>>y2>>p;
        cout << setprecision(6) << calculateNorm(x1,y1,x2,y2,p) <<endl;
    }
}

/*
    main function mhr return statement nk exit chin yin 0 ko pl thone ya tl
    non-zero value -> error
    program ka error pow(10,-4) lat khan tl so yin setprecision(n>4) nk answer htoke
*/