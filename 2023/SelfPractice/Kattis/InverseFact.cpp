#include<bits/stdc++.h>
using namespace std;

int solve(float np){

    float curr = 10;
    float const w = log((float)np) - 0.919;
    int i = 0;
    while(i<10){
        float temp = ( (curr + w) / log(curr) ) - 0.5;
        if(abs(temp-curr) < 0.001)
            break;
        curr = temp;
        i++;
    }
    return (int)floor(curr);
}

int main(){
    //float n;
    //ifstream infile;
    //infile.open("input.txt");
//
    //while(infile >> n){
    //   cout << solve(9.332622e+157) << endl; 
    //}
    double sum = 0;
    for(int i=1; i<=6; i++){
        sum += log10(i);
    }
    cout << sum;
}