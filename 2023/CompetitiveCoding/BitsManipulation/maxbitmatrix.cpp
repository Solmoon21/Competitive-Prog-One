#include<bits/stdc++.h>
using namespace std;

void Toggle(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        arr[i] = arr[i] ? 0 : 1;
    }
}

void rowcheck(vector<int> &row){
    int n = row.size();
    int left = 0, right = 0;

    for(int i=0;i<n/2;i++){
        if(row[i])
            left++;
    }
    for(int j=(n/2)+1;j<n;j++){
        if(row[j])
            right++;
    }

    // less 1's at significant part of binary number
    if(left<right){
        Toggle(row);
    }
}

void columncheck(vector<vector<int>> &matrix,int j){
    int n = matrix.size();
    int one = 0, zero = 0;
    for(int i=0;i<n;i++){
        if(matrix[i][j])
            one++;
        else
            zero++;
    }
    if(one < zero){
        for(int i=0;i<n;i++){
            matrix[i][j] = matrix[i][j] ? 0 : 1;
        }
    }
}

int arrToint(vector<int> arr){
    int p = pow(2,arr.size()-1);
    int num = 0;
    for(int i : arr){
        num += i * p;
        p /= 2;
    }
    return num;
}

int maxBinaryMatrix(vector<vector<int>> matrix){
    int ans = 0, n = matrix.size(), m = matrix[0].size();
    ans = (1<<m-1)*n;
    for(int j=1;j<m;j++){
        int one = 0;

        for(int i=0;i<n;i++){
            if(matrix[i][j] == matrix[i][0]){
                one++;
            }
        }

        int mult2 = (1<<m-j-1);
        ans += mult2 * max(one,n-one);
    }
    return ans;
}

int rangeBitwiseAnd(int left, int right) {
    int ans = 0;
    for(int i=30;i>=0;i--){
        int mask = (1<<i);
        if( (left&mask) != (right&mask) ){
            break;
        }
        else{
            cout << left << ' ' << mask << ' '<< (left&mask) <<endl;
            if((left&mask)>0)
                ans += mask;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {
        {0,0,1,1},
        {1,0,1,0},
        {1,1,0,0}
    };

    // for(int i=0;i<matrix.size();i++){
    //     rowcheck(matrix[i]);
    // }

    // int m = matrix[0].size();
    // for(int j=0;j<m;j++){
    //     columncheck(matrix,j);
    // }
    

    // for(int i=0;i<matrix.size();i++){
    //     int m = matrix[0].size();
    //     for(int j=0;j<m;j++){
    //         cout << matrix[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // int sum = 0;
    // for(int i=0;i<matrix.size();i++){
    //     int line = arrToint(matrix[i]);
    //     sum += line;
    //     cout << i<< ' ' <<  line  << endl;
    // }
    // cout << sum << endl;
    // cout << arrToint({1,1,0,0});

    cout << rangeBitwiseAnd(5,7);

}