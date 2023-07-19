//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/?envType=study-plan-v2&envId=leetcode-75

#include<bits/stdc++.h>
using namespace std;

int maxVowels(string s, int k) {
    string vowels = "aeiouAEIOU";
    int maxVowel = 0, cnt = 0;
    for(int i=0; i<k; i++){
        if( vowels.find_first_of(s[i]) != string::npos ){
            cnt++;
        }
    }
    maxVowel = cnt;

    for(int i=1; i<s.length()-k+1; i++){

        if( vowels.find_first_of(s[i-1]) != string::npos ){
            cnt--;
        }

        if( vowels.find_first_of(s[i+k-1]) != string::npos ){
            cnt++;
        }
        maxVowel = max(cnt,maxVowel);
    }
    return maxVowel;
}


int main(){
    vector<int> k{4};
    string vowels = "aeiouAEIOU";
    int ans = maxVowels("abciiidef",3);
    cout << ans;
}