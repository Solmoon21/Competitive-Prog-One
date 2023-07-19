#include<bits/stdc++.h>
using namespace std;

int subsolve(int i,int sum,int n,int x,int u){
    
    if(sum == x) {
        return 1;
    }

    if(i >= u){
        return  sum == x ? 1 : 0;
    }
    
    int minus = subsolve(i+1,sum,n,x,u);

    int partial = pow(i,n);
    if( sum + partial > x ) return minus;

    int plus = subsolve(i+1,sum+partial,n,x,u);

    return plus + minus;
}

int solve(int x,int n){

    float u = pow(10,log10(x)/(float)n); 
    int upper = (int) ceil(u);
    cout << "Upper : " << upper << endl;
    return subsolve(1,0,n,x,upper+1);
    
}

int power(int a,int n){
    if(n==0){
        return 1;
    }
    return a*power(a,n-1);
}

int subitersolve(){
    return 1;
}

int itersolve(int x,int n){
    return 1;
}

int cal(int x,int n, vector<int>&vec){
    int sum=0,answer=0;
    for(auto itr:vec){
        sum+=power(itr,n);
    }
    if(sum==x){
        return 1;
    }
    else{
        int answer=0;
        int v=vec.empty()?1:vec.back()+1;
        while(sum+ power(v,n)<=x){
            vec.push_back(v);
            answer+=cal(x,n,vec);
            vec.pop_back();
            v++;
        }
        return answer;
    }
}

int solve2(int x,int n){
    vector<int>vec;
    return cal(x,n,vec);
}

int main(){
    //cout << solve(13,2);
    time_t start,end; 
    time(&start);
    ios_base::sync_with_stdio(false);
    int ans = solve2(1000,2);
    cout << "Ways : " << ans << endl;
    time(&end);
    double total = double(end - start);
    cout << "Time : "<< total << setprecision(5) << endl;
    cout << log10(79);
    // b ^ n = x

}