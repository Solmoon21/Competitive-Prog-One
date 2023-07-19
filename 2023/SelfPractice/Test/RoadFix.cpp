#include<bits/stdc++.h>
using namespace std;

int Solve(string s){
    int last = 0;
    int times = 0, currlen = 0;
    for(int i=0; i<s.length(); i++){

        if(s[i] == 'X'){
            currlen++;
        }
        if(!currlen) continue;

        if(s[i] == '.'){
            times += currlen/3 + (currlen%3 ? 1 : 0);
            currlen = 0;
            last = i;
        }
        
        if(i == s.length()-1 && s[i] == 'X')
        {
            times += ( currlen%3? currlen/3 + 1 : currlen/3   );
        }
    }
    return times;
}

int main(){

    cout << Solve(".X..X") << endl;
    cout << Solve("XX.XXX..") << endl;
    cout << Solve("X.XXXXX.X.") << endl;
    cout << Solve("XXXX") << endl;
}