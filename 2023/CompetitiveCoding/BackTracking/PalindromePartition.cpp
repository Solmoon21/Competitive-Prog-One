#include<bits/stdc++.h>
using namespace std;

int nCr(int r,int n){
    int sum = 1;
    for(int i = 1; i <= r; i++){
        sum = sum * (n - r + i) / i;
    }
    return sum;
}

bool isPalindrome(string s){
    //string temp = s;
    //reverse(temp.begin(),temp.end());
    //return temp == s;

    int n = s.size();
    int mid = n/2;
    for(int i=0;i<=mid;i++){
        if(s[i] != s[n-i-1]) return false;
    }
    return true;
}

vector<vector<string>> partition(string s) {
    int n = s.size();
    vector<vector<string>> ans;
    for(int sz=1; sz<=n; sz++){
        vector<string> row;
        for(int i=0; i<n-sz+1; i++){
            string sub = s.substr(i,sz);
            if(isPalindrome(sub)){
                row.push_back(sub);
            }
        }
        if(row.size())
            ans.push_back(row);
    }   
    
    return ans;
}


int main(){
    // string s = "aab";
    // for(auto r : partition(s)){
    //     for(auto s : r){
    //         cout << s << "# ";
    //     }
    // }
    int total = 0;
    for(int i=1; i<17; i++){
        total += nCr(i,16);
    }
    cout << "Total " << total;
}