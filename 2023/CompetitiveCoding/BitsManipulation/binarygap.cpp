#include<bits/stdc++.h>

using namespace std;

int solution(int N) {
    // Implement your solution here
    int ans = 0;
    bool flag = false;
    int cnt = 0;
    for(int i=0; i<31; i++){
        if( N & (1<<i) ){
            flag = flag? false : true;
            if(!flag){
                ans = ans < cnt ? cnt : ans;
                cnt = 0;
                printf("\tend : %d\n",i);
                i = i - 1;
            }
            else{
                printf("start : %d",i);
            }
        }
        else{
            if(flag){
                cnt++;
            }
        }

    }
    cout << '\n';
    return ans;
}

int main(){
    cout << solution(1041);
}