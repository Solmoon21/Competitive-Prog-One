#include<bits/stdc++.h>
using namespace std;

vector<int> decodeXOR(vector<int> e,int first){
    vector<int> ans;
    ans.reserve(e.size()-1);
    ans.push_back(first);
    for(int c : e){
        int next = first ^ c;
        ans.push_back(next);
        first = next;
    }

    for(int c : ans){
        cout << c << ' ';
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3};
    int first = 1;
    decodeXOR(arr,1);
}