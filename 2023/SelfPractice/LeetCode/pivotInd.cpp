//https://leetcode.com/problems/find-pivot-index/?envType=study-plan-v2&envId=leetcode-75

#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int total = 0;
    for(int n : nums){
        total += n;
    }
    int leftsum = 0;
    if(total - nums[0] == leftsum){
        return 0;
    }
    leftsum = nums[0];
    for(int i=1; i<nums.size(); i++){
        if( total - nums[i] - leftsum == leftsum ){
            return i;
        }
        leftsum += nums[i];
    }
    return -1;
}