//https://leetcode.com/problems/max-consecutive-ones-iii/?envType=study-plan-v2&envId=leetcode-75
#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int ans = 0;
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]){
            sum++;
            ans = max(sum,ans);
        }
        else if(!nums[i] && !k){
            int j = i-sum;
            sum--;
            if(!nums[j++]) k++;
            i--; continue;
        }
        else{
            k--;
            sum++;
        }
        
    }       
    
    return ans;
}

int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int ans = longestOnes(nums,2);
    cout << ans;
}