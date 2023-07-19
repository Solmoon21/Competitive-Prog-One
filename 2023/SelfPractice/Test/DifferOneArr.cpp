#include<bits/stdc++.h>
using namespace std;

bool Solve(vector<int> A){
    unordered_set<int> myset;

    for(int a : A){
        //cout << a << ' ' << myset.count(a-1) << ' ' << myset.count(a+1) << endl;
        if(myset.count(a-1) || myset.count(a+1))
            return true;
        //if(myset.find(a-1) != myset.end() || myset.find(a+1) != myset.end())
        //    return true;
        myset.insert(a);


    }

    return false;
}


int main(){

    vector<int> A = {11,1,8,12,14};
    if(Solve(A)) cout << "Yes";
    else cout << "No";

}