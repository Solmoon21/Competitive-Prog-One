#include<bits/stdc++.h>
using namespace std;

vector<int> subsums(vector<int> a){
    int n = a.size();
    vector<int> sums;
    int sz = 1<<n;
    sums.reserve(sz);

    for(int i=0; i<sz; i++){
        long long tempsum = 0;
        for(int j=0; j<n; j++){
            if((i>>j)&1){
                tempsum += a[j];
            }
        }
        sums.push_back(tempsum);
    }

    return sums;
}

long long solve(int n,int x, vector<int> a){
    int partitionSize = n%2? n/2 +1 : n/2;
    vector<int> l = vector<int>(a.begin(),a.begin()+partitionSize);
    vector<int> r = vector<int>(a.begin()+partitionSize,a.end());

    vector<int> left,right;
    left = subsums(l); right = subsums(r);
    sort(right.begin(),right.end());
    long long ans = 0;
    for(int s : left){

        ans += (upper_bound(right.begin(),right.end(),x-s) - lower_bound(right.begin(),right.end(),x-s) );

    }


    return ans;

}

int main(){
    //vector<int> a = {1,2,3,2}; // 0,1,2,3   0,2,3,5
    //cout << solve(4,5,a);
}