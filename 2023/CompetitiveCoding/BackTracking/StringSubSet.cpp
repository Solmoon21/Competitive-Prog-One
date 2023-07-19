#include<bits/stdc++.h>
using namespace std;

void Subsets(string s,string origin,vector<string>& ans){

    if(!origin.length()) ans.push_back(s);
    else{
        s.push_back(origin[0]);
        Subsets(s,origin.substr(1),ans);
        s.pop_back();
        Subsets(s,origin.substr(1),ans);
    }
}

vector<string> GetSubs(string origin){
    vector<string> ans;
    Subsets("",origin,ans);
    return ans;
}

bool IsSet(int pos,int mask){
    return (mask>>pos)&1;
}

void Permutate(string curr,int mask,string origin,vector<string>& ans){
    int n = origin.length();
    if( curr.length() == n  ) ans.push_back(curr);
    else{
        for(int j=0; j<n; j++){
            if(IsSet(j,mask)) continue;

            curr.push_back(origin[j]);
            Permutate(curr,mask|(1<<j),origin,ans);
            curr.pop_back();
        }
    }

}

void Permutate2(string s,int l,int r,vector<string>& ans){
   
    if(!s.length()) return;

    if( l == r ) ans.push_back(s);

    for(int i=l; i<=r; i++){
        swap(s[l],s[i]);
        Permutate2(s,l+1,r,ans);
        swap(s[l],s[i]);
    }
}

vector<string> GetPermutations(string origin){
    vector<string> ans;
    Permutate("",0,origin,ans);
    return ans;
}


int main(){
    vector<string> ans;
    Permutate2("abc",0,2,ans);
    cout << "FUNC END\n";
    for(string s : ans)
        cout<< s << endl;

}