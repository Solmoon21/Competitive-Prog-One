#include<bits/stdc++.h>
using namespace std;

bool solution(vector<int> &A) {
    // Implement your solution here
    for(int i=0; i<A.size()-1; i++){

        if(abs(A[i]-A[i+1]) == 1){
            return true;
        }

    }
    return false;
}

int main(){
    vector<int> A = {1,4,6};
    if(solution(A)){
        cout << "G\n";
    }
    else{
        cout << "NG\n";
    }
}