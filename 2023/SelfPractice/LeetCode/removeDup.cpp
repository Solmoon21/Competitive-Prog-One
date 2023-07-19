// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=study-plan-v2&envId=top-interview-150
#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int k = nums.size();
    for(int i=0; i<nums.size(); i++){
        if(i == k) break;

        int j = i;
        while(j>0 && nums[j-1] == nums[i]){
            j--;
        }
    
        cout << endl;
        //remove this element
        if(i - (lower_bound(nums.begin(),nums.begin()+i-1,nums[i]) - nums.begin()) == 2){
            printf("Dup %d %d value %d\n",j,i,nums[i]);
            j = i;
            while(j<k-1){
                nums[j] = nums[j+1];
                j++;
            }
            k--;
            i = i - 1;
            
        }
        
        // for(int n : nums){
        //     cout << n << ' ';
        // }
        // cout << endl;
    }
    return k;
}

int main(){

    vector<int> A = {0,1,1,1,1,2,3,3,3};
    vector<int> B = {1,1,1,1,1,1};
    int b = removeDuplicates(A);
    for(int i=0; i<b; i++){
        cout << A[i] << ' ';
    }
    cout << endl;

    //auto c = lower_bound(A.begin(),A.begin()+2,1);
    //cout << c - A.begin() << endl;
}