#include<bits/stdc++.h>
using namespace std;

string toBinaryString(int n){
    string s = "";
    for(int i=0; i<4; i++){
        s.append(((1<<i)&n) ? "*" : "." );
    }
    reverse(s.begin(),s.end());
    return s;
}


vector<string> solve(string s){
    vector<string> ans;

    for(int i=0; i<s.length(); i++){

        int digit = s[i] - '0';
        string s = toBinaryString(digit);
        ans.push_back(s);
        //cout<<ans[i]<<endl;
    }

    return ans;
}


int main(){


    string r;
    cin >> r;
    vector<string> ans = solve(r);
    int currCol = 0;
    for(int i=0; i<4; i++){
        for(int j=1; j<=9; j++){
            if(j==5 || j==6){
                cout << ' ';
            }
            else if(!(j&1)){
                cout << ' ';
            }
            else{
                currCol = j / 2;
                currCol = j < 5 ? currCol : currCol - 1; 
                cout << ans[currCol][i]; 
            }
        }
        
        cout << endl;
    }

}