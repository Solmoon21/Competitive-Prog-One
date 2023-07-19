#include<bits/stdc++.h>

using namespace std;

int OccurAt(vector<int> A,int x,int l,int r){

    int start = l, end = r;
    int mid,ans = -1;

    while (start <= end){
        mid = (start + end) / 2;
        if( A[mid] == x ){
            ans = mid;
            end = mid - 1;
        }
        else if( A[mid] > x ){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return ans;
}

void fun(int x){
    //+1;
    //int i=1;
    //while( i<=10){
    //    if(i%x==0){
    //        cout << i << endl;
    //    }
    //    i++;
    //}
    int cnt=1;
    for(int i=1;i<=10;i++){
        if(cnt==x){
            cout << i << endl;
        }
        cnt = (cnt % x) + 1;
    }
}

int Occur(vector<int> A, int x){

    int start,end,mid;

    start = 0;
    end = A.size() - 1;

    mid = ( start + end ) / 2 ;

    int left,right;

    left = OccurAt(A,x,start,mid);

    right = OccurAt(A,x,mid+1,end);

    cout << left << '\t' << right << endl;
    return right - left + 1;
}


int main(){

    vector<int> arr = {1,2,5,5,5,5,6,6,6,7};

    //cout << OccurAt(arr,5,4,9);
    //cout << Occur(arr,5);

    int x;
    cin >> x;
    fun(x);
}