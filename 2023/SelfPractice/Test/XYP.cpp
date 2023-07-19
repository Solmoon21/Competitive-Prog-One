#include<bits/stdc++.h>
using namespace std;

int MaxP(int X,int Y,vector<int> arr){
    int P = -1, balance = 0;

    for(int i=0; i<arr.size(); i++){

        if(arr[i] == X) balance++;
        if(arr[i] == Y) balance--;

        if(!balance){
            if(P<0) P = i;
            else P++;
        }
    }

    return P;
}


int main(){

    vector<int> arr = {6,42,11,7,1,42};
    cout << MaxP(42,6,arr);


}