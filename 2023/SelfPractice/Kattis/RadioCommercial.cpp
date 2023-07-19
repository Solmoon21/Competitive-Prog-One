#include<bits/stdc++.h>
using namespace std;

//failure to improve
int solve(vector<int> A,int cost,int i,int lastbit,int profit){
    if(i == A.size()) return profit;
    cout << "At " << i << " " << lastbit  << " " << profit << endl;
    int set = 0, unset = 0;

    // must take
    if(lastbit & 1){
        profit = profit + A[i] - cost;
        set = solve(A,cost,i+1,1,profit);
    }
    else{
        int zero = solve(A,cost,i+1,0,profit);
        int one  = solve(A,cost,i+1,1,profit);
        unset =  max(zero,one);
    }   
    int r = max(set,unset);
    cout << "Max " << r << endl;

    return r;
}


int maxSubArraySum(vector<int> a,int p)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < a.size(); i++) {
        max_ending_here = max_ending_here + a[i] - p;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
 





int main(){
    vector<int> A;
    int n,p;
    cin >> n >>p;
    A.resize(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    cout << maxSubArraySum(A,p);
    //int zero = solve(A,20,0,0,0);
    //int one = solve(A,20,0,1,0);
    //cout << max(zero,one) << "#" << endl;

}