#include<bits/stdc++.h>
using namespace std;

int TSP(vector<vector<int>> dist,int curr,int visited,int n){

    if(visited == (1<<n)-1){
        //cout << dist[curr][0] << endl;
        return dist[curr][0];
    }

    int ans = 1000;
    for(int i=0;i<n;i++){
        if( (visited & (1<<i)) == 0){
            int temp = visited|(1<<i);
            int sub = dist[curr][i] + TSP(dist,i,temp,n);
            ans = min(ans,sub);
            //cout << curr << " to " << i << " is " << ans << endl;
        }
    }
    return ans;
}

int TSP_DP(vector<vector<int>> dist,int curr,int visited,int n,vector<vector<int>> &dp){

    if(visited == (1<<n)-1){
        //cout << dist[curr][0] << endl;
        return dist[curr][0];
    }

    if(dp[visited][curr] != -1){
        return dp[visited][curr];
    }

    int ans = 1000;
    for(int i=0;i<n;i++){
        if( (visited & (1<<i)) == 0){
            int temp = visited|(1<<i);
            int sub = dist[curr][i] + TSP(dist,i,temp,n);
            ans = min(ans,sub);
            //cout << curr << " to " << i << " is " << ans << endl;
        }
    }
    dp[visited][curr] = ans;
    return ans;
}

string Ito4BS(int n){
    stringstream ss;
    int i = 4;
    while(i--){
        int digit = n%2;
        ss<<digit;
        n/=2;
    }
    string temp = ss.str();
    //string ans(temp.rbegin(),temp.rend());
    //return ans;
    reverse(temp.begin(),temp.end());
    return temp;
}

int main(){
    vector<vector<int>> dist = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
    };

    vector< vector<int> > dp (16, vector<int>(4,-1) );

    //cout << TSP(dist,0,1,4);
    cout << TSP_DP(dist,0,0,4,dp) << endl;
    for(int i=0;i<16;i++){
        for(int j=0;j<4;j++){
            cout<< Ito4BS(i) << '-' << j << "\t" << dp[i][j] << endl;
        }
    }
}