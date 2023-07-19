#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> myP;

int countSetBits(int n){
    int cnt = 0;
    //int check = 1;
    //while(check < n){
    //    cnt += ((n&check)==0?0:1);
    //    check <<= 1;
    //}

    while(n>0){
        if(n&1){
            cnt++;
        }
        n>>=1;
    }
    return cnt;
}

bool myC2(myP a,myP b){
    if(a.first == b.first){
            return a.second < b.second;
        }
    return a.first < b.first;
}

vector<int> sortByBits(vector<int> arr) {

    auto myC = [](myP a,myP b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    };

    priority_queue<myP, vector<myP>, bool(myP,myP)> dict(myC2); // setbitcnt,value
    vector<int> ans;
    ans.reserve(arr.size());
    for(int i : arr){
        dict.push(make_pair(countSetBits(i),i));
    }
    while(!dict.empty()){
        myP curr = dict.top();
        //cout<<curr.second<<' ';
        ans.push_back(curr.second);
        dict.pop();
    }
    return ans;
}

template <class T> bool compare(T a, T b){
    int c = __builtin_popcount(a);
    int d = __builtin_popcount(b);
    if(c == d)
        return a<b;
    return c < d;
}

int longest1Seq(int n){
    int cnt = 0;
    while(n>0){
        n = (n & (n>>1));
        cnt++;
    }
    return cnt;
}

int hammingDistance(int x, int y) {
    int r = x ^ y;
    int ans = 0;
    while(r>0){
        r = r&(r-1);
        ans++;
    }
    return ans;
}


int totalHammingDistance(vector<int> nums) {
    int sum = 0;
    for(int i=0;i<nums.size()-1;i++){
        for(int j=i+1;j<nums.size();j++){
            sum += hammingDistance(nums[i],nums[j]);
        }
    }
    return sum;
}



int main(){
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    /*
        sort function mhr template class thone loh ya tl
        priority queue mhr thone tr class(operator overload), struct, lambda
        lamda thone yin yayy nee 2 myo shi tl. function signature | decltype (shorthand)
    */
    sortByBits(arr);
    //sort(arr.begin(),arr.end(),compare<int>);
    //for(int i : arr){
    //    cout << i << ' ';
    //}
    //cout << longest1Seq(156);
    //cout << hammingdisctance(1,4);
    vector<int> a = {4,14,2};
    //cout << totalHammingDistance(a);
    //cout << hammingDistance(4,2);

    //cout << countSetBits(15);
}