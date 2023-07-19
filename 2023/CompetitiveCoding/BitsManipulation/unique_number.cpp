#include<bits/stdc++.h>
using namespace std;

int unique2n1(vector<int> arr){
    int ans = 0;
    for(int i : arr){
        ans = ans^i;
    }
    return ans;
}

int getSetBitPos(int n){
    int pos = 0;
    while(n>0){
        int lastbit = n&1;
        if(lastbit == 1){
            break;
        }
        n>>=1;
        pos++;
    }
    return pos;
}

bool isSetAt(int p,int n){
    int curr = 0;
    while(curr<p){
        curr++;
        n>>=1;
    }
    if(n&1)
        return true;
    return false;
}

pair<int,int> unique2n2(vector<int> arr){
    int res = unique2n1(arr);
    int pos = getSetBitPos(res);
    int res2 = 0;
    for(int i : arr){
        if( isSetAt(pos,i) ){
            res2 = res2 ^ i;
        }
    }
    auto p = make_pair(res^res2,res2);
    return p;
}

int unique3n1(vector<int> arr){
    vector<int> sums;
    int zero_cnt = 1;
    while(true){
        int col_sum = 0;
        zero_cnt = arr.size();
        for(int i=0;i<arr.size();i++){
            if(arr[i]&1)
                col_sum++;
            else
                zero_cnt--;
            arr[i]>>=1;
        }
        if(!zero_cnt)
            break;
        sums.push_back(col_sum);
    }
    int num = 0;
    int p = 1;
    for(int b : sums){
        b = b % sums.size();
        num += b * p;
        p *= 2;
    }
    return num;
}

int main(){

    vector<int> arr = {2,5,5,3,2,2,5};
    cout << unique3n1(arr);
}