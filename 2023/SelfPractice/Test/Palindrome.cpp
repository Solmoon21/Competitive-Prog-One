#include<bits/stdc++.h>
using namespace std;

string FillPalindrome(string s){

    bool isOdd = s.length()&1;
    int n = s.length();
    string ans = ""; ans.resize(n);
    for(int i=0; i<n/2; i++){
        if( s[i] != '?' && s[i] != s[n-i-1]  ) return "NO";

        char curr = max( (int) s[i], (int) s[n-i-1]);
        if( curr ==  '?' ){
            ans[i] = ans[n-i-1] = 'a';
        }
        else{
            ans[i] = ans[n-i-1] = curr;
        }
    }

    if( isOdd ){
        if(s[n/2] == '?'){
            ans[n/2] = 'm';
        }
        
    }

    return ans;
}

int main(){
    cout << FillPalindrome("ab?a") << endl;
    cout << FillPalindrome("a?ba") << endl;
    cout << FillPalindrome("a?a") << endl;
    cout << FillPalindrome("ab?ba") << endl;
    cout << FillPalindrome("???") << endl;
    cout << FillPalindrome("????") << endl;
    cout << FillPalindrome("a?c") ;
}