#include<bits/stdc++.h>
using namespace std;

enum Direction { RIGHT=0, DOWN=1, LEFT=2, UP=3, NONE=4 };

struct Square{
    bool isClean = false;
    Direction dir = NONE;
};



int solution(vector<string> &R) {
    // Implement your solution here
    int cnt = 0;
    int col = R[0].length();
    int row = R.size();
    
    vector<Square> room(row*col,Square());
    Direction robotDirection = RIGHT;
    printf("#%d,%d,%d\n",row,col,room.size());
    int i=0,j=0;
    while(true){
        if(room[i*col+j].isClean && room[i*col+j].dir == robotDirection){
            break;
        }

        if(!room[i*col+j].isClean){
            cnt++;
            room[i*col+j].dir = robotDirection;
        }

        room[i*col+j].isClean = true;
        
        
        // printf("%d,%d,%d\n",i,j,room[i*col+j].dir);
        switch(robotDirection){

            case RIGHT:
                
                if(j+1 == col || R[i][j+1]=='X'){
                    robotDirection = DOWN;
                    // i = i + 1;
                }
                else{
                    j = j + 1;
                }
                // room[i*col+j].dir = robotDirection;
                break;
            case DOWN:
                if(i+1 == row || R[i+1][j]=='X'){
                    robotDirection = LEFT;
                    // j = j - 1;
                }
                else{
                    i = i + 1;
                }
                // room[i*col+j].dir = robotDirection;
                break;
            case LEFT:
                if(j-1 < 0 || R[i][j-1]=='X'){
                    robotDirection = UP;
                    // i = i - 1;
                }
                else{
                    j = j - 1;
                }
                // room[i*col+j].dir = robotDirection;
                break;
            case UP:
                if(i-1 < 0 || R[i-1][j]=='X'){
                    robotDirection = RIGHT;
                    // j = j + 1;
                }
                else{
                    i = i - 1;
                }
                // room[i*col+j].dir = robotDirection;
                break;    
        }
        
    } 


    return cnt;
}


int main(){

    vector<string> R{
        "...X..",
        "....XX",
        "..X..."
    };
    cout << solution(R);
}