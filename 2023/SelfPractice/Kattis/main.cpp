#include<bits/stdc++.h>
using namespace std;

int main(){
    float a,b;
    cin >> a >> b;
    // a = __gcd(a,b);
    // cout << a <<endl;
    //cout << __gcd(-12,0);
    //cout << '\t' << __gcd(18,51);
    //return 0;
    float ox = 0, oy = 0;
    for(int i=0; i<4; i++){
        ox += a; oy += b;
        printf("(%f,%f)\n",ox,oy);
    }
}