// Inclusion Exclusion
#include<bits/stdc++.h>
using namespace std;

int numDivisible(int l,int r, vector<int> arr){
	int n = arr.size(), ans = 0;
    for(int i=1; i<(1<<n); i++){
        long long lcm = 1;
        int cnt = 0;
        for(int j=0; j<n; j++){

            if(i&(1<<j)){
                lcm = (lcm*(long long)arr[j]) / __gcd(lcm,(long long)arr[j]);
                cnt++;
            }

            if(lcm > r) break;
        }

        if(lcm > r) continue;

        if(cnt % 2){
            ans += (r/lcm);
            ans -= (l-1)/lcm;
        }
        else{
            ans -= (r/lcm);
            ans += (l-1)/lcm;
        }
    }
    return ans;
}


int fact(int n)
{
      if(n==0)
      return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

int CF106751(vector<int> listing){
    if(!listing.size()) return 0;
    int n = listing.size();
    //int categories = trunc(log10(listing[0])) + 1
    int categories = 30;
    int ans = 0;
    for(int c=0; c<categories; c++){
        int sets = 0;

        for(int i=0; i<n; i++){
            if((listing[i]%10)&1)
                sets++;
            listing[i]/=10;
        }
        if(sets>=2) ans+= sets/2 + sets%2;
        //cout << c << " " << sets << " " << ans << endl;
    }
    //cout << "======" << endl;
    return nCr(n,2) - ans;
}

int main(){

    int l=1, r=100;
    vector<int> arr = {2,3,5};
    cout << numDivisible(l,r,arr);

    // vector<int> listing = {
    //     101010,
    //      10001,
    //      11010,
    //        100,
    //     110000,
    // };

    //cout << CF106751(listing);
}