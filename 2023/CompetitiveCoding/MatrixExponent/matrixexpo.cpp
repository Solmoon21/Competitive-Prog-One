#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

class Matrix{
    private:
        int len;
    public:
        std::vector<std::vector<int>> matrix;
        Matrix(int n,bool identity=false);
        Matrix operator* (Matrix b);
        friend ostream& operator<<(ostream& os, const Matrix& obj){
            int n = obj.len;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    os << obj.matrix[i][j] << ' ';
                }
                os<<endl;
            }
            return os;
        }
};

Matrix::Matrix(int n,bool identity){
    len = n;
    matrix.resize(n);
    
    for(int i=0;i<n;i++){
        matrix[i].resize(n);
    }
    if(!identity) return;

    for(int i=0;i<n;i++){
        matrix[i][i] = 1;
    }
}

Matrix Matrix::operator*(Matrix b){
    Matrix res = Matrix(len);
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            for(int k=0;k<len;k++){
                //res.matrix[i][j] += matrix[i][k]*b.matrix[k][j];
                int temp = (long long) matrix[i][k] * b.matrix[k][j] % mod;
                res.matrix[i][j] = ( res.matrix[i][j] + temp ) % mod;
            }
        }
    }
    return res;
}


int Fib(int n){
    Matrix T = Matrix(2);    
    T.matrix[0][0] = T.matrix[0][1] = T.matrix[1][0] = 1;
    T.matrix[1][1] = 0;

    Matrix f2 = Matrix(2);
    f2.matrix[0][0] = 1;
    f2.matrix[1][0] = 1;


    Matrix res = Matrix(2,true);
    n-=2;
    while(n){
        if(n&1){
            res = res * T;
        }
        T = T * T;
        n>>=1;
    }
    res = res * f2;
    return res.matrix[0][0];
}

int FibSum(int n){
    Matrix T = Matrix(3);
    T.matrix = { {1,1,1}, {0,1,1}, {0,1,0} };
    if(n<=0) return 0;
    if(n==1) return 1;

    Matrix f2 = Matrix(3);
    f2.matrix = { {2,0,0}, {1,0,0}, {1,0,0} };

    Matrix res = Matrix(3,true);
    n-=2;
    while(n){
        if(n&1) res = res * T;
        T = T * T;
        n>>=1;
    }
    res = res * f2;
    return res.matrix[0][0];
}

int fibSum(int n,int m){
    return ( (FibSum(m)-FibSum(n-1)) % mod + mod ) % mod;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cout << fibSum(n,m) << endl;
    }
    
}