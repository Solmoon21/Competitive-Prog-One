#include<bits/stdc++.h>
using namespace std;

int maxOperations(vector<int>& nums, int k) {
        
    int right = nums.size()-1;
    if(!right) return 0;
    int left = 0;
    
    sort(nums.begin(),nums.end());
    int cnt = 0;
    while(left < right){
        cout << left << "->" << nums[left] << '\t' << right << "->" << nums[right] << '\n';
        if( nums[left] + nums[right] == k )
        {
            cnt++;
            left++; right--;
            
        }    
        else if( nums[left] + nums[right] > k )
        {
            right--;
        }
        else{
            left++;
        }
        
    }
    return cnt;
}

int main(){
    vector<int> A = {4,4,1,3,1,3,2,2,5,5,1,5,2,1,2,3,5,4};
    vector<int> B = {-3,1,3,4,-6};
    sort(B.begin(),B.end());
    for(int i : B) {cout << i << ' '; } cout << endl;
    cout << maxOperations(B,-2);
}