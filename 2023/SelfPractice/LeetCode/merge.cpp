#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //vector<int> ans(m+n);
    vector<int> ans;
    int k = 0;

    cout << endl;
    int i=0, j=0;
    while(i<m && j<n){
        if(nums1[i] <= nums2[j]){
            ans.push_back(nums1[i]);
            //ans[k++] = nums1[i];
            i++;
            cout << nums1[i] << ' ';
        }
        else{
            ans.push_back(nums2[j]);
            //ans[k++] = nums2[j];
            j++;
            cout << nums2[j] << ' ';
        }
    }
    if(i==m){
        while(j<n){
            ans.push_back(nums2[j]);
            //ans[k++] = nums2[j];
            j++;
            cout << nums2[j] << ' ';
        }
    }
    else{
        while(i<m){
            ans.push_back(nums1[i]);
            //ans[k++] = nums1[i];
            i++;
            cout << nums1[i] << ' ';
        }
    }
    cout << endl;
    for(int i=0; i<m+n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}

void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i] <= nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        if(i==m){
            while(j<n){
                ans.push_back(nums2[j]);
                j++;
            }
        }
        else{
            while(i<m){
                ans.push_back(nums1[i]);
                i++;
            }
        }
        cout << endl;
        for(int i=0; i<m+n; i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
    }

int main(){

    vector<int> A = {1,2,3,0,0,0};
    vector<int> B = {2,5,6};
    //merge(A,3,B,3);

    merge2(A,3,B,3);
}