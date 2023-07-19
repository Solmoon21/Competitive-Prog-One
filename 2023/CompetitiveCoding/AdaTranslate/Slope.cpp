#include<bits/stdc++.h>
using namespace std;


int main(){
    float m = 0.3;
    double sx = 390;
    double sy = 240;

    double dx = 26*30;
    double dy =  4*30;

    int mx = 1, my = -1;

    int speed = 10;
    double gx = abs(dx-sx)/speed;
    double gy = abs(dy-sy)/gx;

    //cout << (dy-sy) / (dx-sx) << endl;
    

    while(sx <= dx || sy >= dy){
        sx += (speed * mx);
        sy += (gy * my);
        printf("%f,%f\n",sx,sy);
    }

    cout << "From " << sx << "," << sy << endl;
    cout << "To " << dx << "," << dy <<endl;

}