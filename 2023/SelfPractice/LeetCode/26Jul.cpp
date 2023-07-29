//https://leetcode.com/problems/removing-stars-from-a-string/?envType=study-plan-v2&envId=leetcode-75

#include<bits/stdc++.h>
using namespace std;

string removeStars(string s) {

    stack<char> pile; 
    
    for(int i=s.length()-1; i>=0; i--){
        pile.push(s[i]);
    }

    //while(!pile.empty()){ cout<<pile.top()<<' '; pile.pop(); }
    //cout << endl;

    string ans = "";
    while(!pile.empty()){
        if(pile.top() == '*'){
            ans.pop_back();
        }
        else{
            ans.push_back(pile.top());
        }
        pile.pop();
    }
    
    return ans;
}

vector<int> asteroidCollision(vector<int>& asteroids) {

    stack<int> negs, frees;

    for(int i=asteroids.size()-1; i>=0; i--){
        cout << i<< ' '<< asteroids[i] << ' ';
        if(negs.empty()){

            if(asteroids[i] < 0){
                negs.push(asteroids[i]);
                cout << "1\n";
            } 
            else{
                frees.push(asteroids[i]);
                cout << "2\n"; 
            }

        }
        else{

            if(asteroids[i] < 0){
                negs.push(asteroids[i]); 
                cout << "3\n";
            } 
            else{

                if( asteroids[i] > abs(negs.top()) ){
                    negs.pop();
                    i++;
                    cout << "4\n";
                }
                else if( asteroids[i] + negs.top() == 0){
                    negs.pop();
                    cout << "5\n";
                }
                else{
                    cout << "6\n";
                }
            }
        }
        cout <<endl;
    }

    //printf("N top %d size %d\n",negs.top(),negs.size());
    //printf("F top %d size %d\n",frees.top(),frees.size());

    vector<int> a;
    while(!negs.empty()){ 
        //cout << negs.top() << ' '; 
        a.push_back(negs.top());
        negs.pop(); 
    }

    while(!frees.empty()){ 
        //cout << frees.top() << ' '; 
        a.push_back(frees.top());
        frees.pop(); 
    }
    return a;
}


string decodeString(string s) {

    stack<char> pile;
    

    string ans = ""; 
    for(int i=0; i<s.size(); i++){
        if( s[i] == ']' ){
            // start decode
            string code = "";
            while(pile.top() != '['){
                code = pile.top() + code;
                pile.pop();
            }
            pile.pop();

            string times = "";
            while(!pile.empty() && isdigit(pile.top())){
                times = pile.top() + times;
                pile.pop();
            }
            
            int n = stoi(times);
            

            for(int j=0; j<n; j++){
                for(char c : code){
                    pile.push(c);
                }
            }
        }
        else{
            pile.push(s[i]);
        }
    }       
    
    while(!pile.empty()){
        ans = pile.top() + ans;
        pile.pop();
    }

    return ans;
}

int main(){
    //cout << '#';
    //cout << removeStars("leet**cod*e");
    //cout << '#';

    // vector<int> as = {5 , -6, 2 ,-2 ,3 ,4 ,-6 ,7};
    // as = asteroidCollision(as);

    // for(int a : as){
    //     cout << a << ' ';
    // }


    cout << decodeString("10[a]");
}