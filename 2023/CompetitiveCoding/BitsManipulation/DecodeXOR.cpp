#include<bits/stdc++.h>
using namespace std;

int XOR1toN(int n){
    switch (n&3)
    {
    case 0:
        return n;
    case 1:
        return 1;
    case 2:
        return n+1;
    case 3:
        return 0;
    }
    return 0;
}

vector<int> Decode(vector<int> arr){
    int n = arr.size();
    vector<int> ans; ans.reserve(n+1);
    int XORall = XOR1toN(n+1);
    cout << "All " << XORall << endl;
    int adjXOR = 0;
    for(int i=0;i<n-1;i+=2){
        adjXOR = adjXOR ^ arr[i];
    }

    int last = adjXOR ^ XORall;
    cout << last << endl;

    ans.push_back(last);
    for(int i=n-1;i>=0;i--){
        last ^= arr[i];
        ans.push_back(last);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main(){
    vector<int> res = Decode({3,1});
    for(int i : res){
        cout << i << ' ';
    }
}