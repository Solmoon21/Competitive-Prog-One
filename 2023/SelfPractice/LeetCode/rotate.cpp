#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

unsigned int gcd (unsigned int n1, unsigned int n2) {
    unsigned int tmp;
    while (n2 != 0) {
        tmp = n1;
        n1 = n2;
        n2 = tmp % n2;
    }
    return n1;
}

void rotate(vector<int> &A,int k,bool right){

    int n = A.size();
    k = k % n;
    int mult = right ? -1 : 1;
    int fact = gcd(n,k);
    for(int i=0; i<fact; i++){

        int temp = A[i];
        int j = i;

        while(true){

            int to = (j + n + mult * k) % n;
            if(to == i)
                break;
            A[j] = A[to];
            j = to;
        }
        A[j] = temp;
    }

}

int main(){
    vector<int> A = {1,2,3,4,5,6,7};
    vector<int> B = {-1,-100,3,99};


    vector<int> C = {1,2,3};
   
    rotate(A,5,true);

    for(int n : A){
        cout << n << ' ';
    }
    cout << endl;
   
}