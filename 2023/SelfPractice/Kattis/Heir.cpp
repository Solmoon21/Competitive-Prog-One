//https://open.kattis.com/problems/heirsdilemma

#include<bits/stdc++.h>
using namespace std;

bool isValid(int n){
    set<int> digits;

    for(int i=1; i<=6; i++){
        int div = pow(10,i), rem = pow(10,i-1);
        int temp = n % div;
        int d = temp / rem;
        //cout << d << '\t';
        if(d==0 || n % d){
            //cout << endl;
            return false;
        }
        digits.insert(d);
    }
    //cout << endl;
    return digits.size()==6;
}



int main(){

    int l,h,c=0;
    cin >> l >> h;
    for(int i=l; i<=h; i++){
        if(isValid(i)) c++;
    }
    cout << c;
}