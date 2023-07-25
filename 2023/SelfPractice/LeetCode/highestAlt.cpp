// https://leetcode.com/problems/find-the-highest-altitude/?envType=study-plan-v2&envId=leetcode-75

#include<bits/stdc++.h>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int high = 0;
    int sum  = 0;
    for(int g : gain){
        sum = sum + g;
        high = max(sum,high);
    }
    return high;
}

int main(){

    vector<int> gain = {-4,-3,-2,-1,4,3,2};
    cout << largestAltitude(gain);
}