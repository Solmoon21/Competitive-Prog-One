#include<vector>
#include<iostream>

using namespace std;

class Matrix{
    private:
        int len;
        std::vector<std::vector<int>> matrix;
    public:
        Matrix(int n);
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
