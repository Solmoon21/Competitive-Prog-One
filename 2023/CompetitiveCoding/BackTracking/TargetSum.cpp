#include<bits/stdc++.h>
using namespace std;

int ops[] = {1, -1};

int helper(vector<int> nums, int target, int sum, int i){
    
    // if(i == nums.size() && sum == target) return 1;

    if(i == nums.size()){
        return sum == target ? 1 : 0;
    }

    int plus  = helper(nums,target,sum+nums[i],i+1);
    int minus = helper(nums,target,sum-nums[i],i+1);

    return plus+minus;
}


int findTargetSumWays(vector<int> nums, int target) {

    return helper(nums,target,0,0);

}


int main(){

    vector<int> nums = { 1,1,1,1,1 };
    int target = 3;

    cout << findTargetSumWays(nums,target);

}