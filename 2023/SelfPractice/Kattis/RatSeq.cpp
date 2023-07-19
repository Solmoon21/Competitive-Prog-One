//https://open.kattis.com/problems/rationalsequence3

#include<bits/stdc++.h>
using namespace std;

void Solve(int n){
    if(n == 1){
        printf("1/1\n");
        return;
    }

    int currLevel = 0;
    int atLevel = floor(log2(n));

    int cores = (1 << atLevel);
    int start = cores;
    int elementsAtLevel = cores;
    
    int p = 1, q = 1;

    while(currLevel < atLevel - 1){
        
        if( n < (start + elementsAtLevel/2) ){
            q = p + q;
            //left
        }
        else{
            p = p + q;
            //right
            start += elementsAtLevel/2;
        }
        currLevel++;
        elementsAtLevel/=2;
        
    }

    if( n & 1 ){
        p = p + q;
    }
    else{
        q = p + q;
    }
    printf("%d/%d\n",p,q);
}



int main(){
    int t,k,n;
    cin>>t;
    while(t--){
        cin>>k>>n;
        cout<<k<<' ';
        Solve(n);
    }

}