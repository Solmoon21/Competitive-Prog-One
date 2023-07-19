#include<bits/stdc++.h>
using namespace std;

string isFourPower(int n){
    int temp = n;
    if(temp <= 0)
        return "No";
    if(temp == 1)
        return "Yes";
    while(temp>2){
        temp >>= 2;
        //int nt = (temp >> 2);
        //temp = nt;
    }
    if(temp&1)
        return "Yes";
    return "No";
}

string newPowerofFour(int n){
    if(n&(n-1) != 0)
        return "No";
    while(3&n == 0){
        n>>= 2;
    }
    if(n&3 == 1)
        return "Yes";
    return "No";
}

int main(){
    string ans = isFourPower(256);
    cout << ans << endl;
    //cout << is_power_of_4(8);
    cout << newPowerofFour(8);
}