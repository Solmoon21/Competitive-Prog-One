#include<bits/stdc++.h>
using namespace std;

int solution(string &S) {
    int n = S.length();
    int cnt = 0;
    for(int i=0; i<n; i=i+3){
        string temp = S.substr(i,3); 
        //cout << temp << '#';
        if(temp.find("X") != std::string::npos){
            cnt++;
            //cout << "Y";
        }
        else{
            //cout << "N";
        }
        // cout << endl;
    }
    return cnt;
}

int main(){
    string s = "XX.XXX..";
    cout << solution(s);
    
}