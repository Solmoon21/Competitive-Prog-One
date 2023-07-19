#include<bits/stdc++.h>
using namespace std;

string keys[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void backtrack(string digits,int i,string s,vector<string>& ans){
    if(i == digits.length()){
        ans.push_back(s);
        return;
    }

    int ind = digits[i]-'0' -2;
    string chars = keys[ind];


    for(char c : chars){
        s.push_back(c);
        backtrack(digits,i+1,s,ans);
        s.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(!digits.length()) return ans;

    backtrack(digits,0,"",ans);
    return ans;
}

int main(){
    vector<string> ans = letterCombinations("29");
    cout << ans.size() << endl;
    for(string s : ans) cout << s << endl;
}