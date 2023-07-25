//https://leetcode.com/problems/find-the-difference-of-two-arrays/?envType=study-plan-v2&envId=leetcode-75

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> answers(2);
    
    unordered_map<int,int> freq;

    for(int n2 : nums2){
        freq.insert( make_pair(n2,1) );
    }

    for(int n1 : nums1){
        if(!freq.count(n1)){
            answers[0].push_back(n1);
            freq.insert(make_pair(n1,-1));
        }
        else{
            if(freq.at(n1) != -1){
                freq.at(n1) = 0;
            }
        }
    }

    for(auto itr : freq){
        if( itr.second == 1 ){
            answers[1].push_back(itr.first);
        }
    }
   
    return answers;
}


bool uniqueOccurrences(vector<int>& arr) {
    unordered_map <int,int> freq;
    unordered_map <int,int> freqFreq;
    for(int i : arr){
        if(freq.count(i)){
            freq.at(i) += 1;
        }
        else{
            freq.insert(make_pair(i,1));
        }
    }


    for(auto itr : freq){
        if(freqFreq.count(itr.second)){
            return false;
            freqFreq.at(itr.second) += 1; 
        }
        else{
            freqFreq.insert(make_pair(itr.second,1));
        }
    }   
    return true;
}

bool closeStrings(string word1, string word2) {

    if( word1.size() - word2.size() ) return false;

    unordered_map<char,int> letters;
    unordered_multiset<int> freq;

    for(char c : word1){
        if(!letters.count(c)){
            letters.insert(make_pair(c,1));
        }
        else{
            letters.at(c) += 1;
        }
    }

    for(auto itr : letters){ freq.insert(itr.second); }

    unordered_map<char,int> letters2;
    for(char c : word2){

        if(!letters.count(c)){ return false; }

        if(letters2.count(c)){
            letters2.at(c) += 1;
        }
        else{
            letters2.insert(make_pair(c,1));
        }
    }
    for(auto i : freq){ cout << i << '@'; } cout << endl;
    for(auto itr : letters2){
        if(!freq.count(itr.second)) return false;
        freq.erase( freq.find(itr.second) );
        cout << "S";
        for(auto i : freq){ cout << i << '#'; }
        cout << "E";
        cout << endl;
    }
    return true;
}

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            //hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            hash |= i;
        }
        return hash;
    }
};

int equalPairs(vector<vector<int>>& grid) {

    //unordered_set<int> iS,jS; //used I's and J's

    unordered_map<vector<int>,int,VectorHasher> chunksR, chunksC;

    for(int i=0; i<grid.size(); i++){
        vector<int> row;
        for(int j=0; j<grid.size(); j++){
            row.push_back(grid[i][j]);
        }

        for(int n : row){ cout << n ; } cout << endl;
       
        if( chunksR.count(row) ){
            chunksR.at(row) += 1;
        }
        else{
            chunksR.insert( make_pair(row,1) );
        }
    }
    cout << "##\n";

    for(int j=0; j<grid.size(); j++){
        vector<int> col;
        for(int i=0; i<grid.size(); i++){
            col.push_back(grid[i][j]);
        }
        for(int n : col){ cout << n ; } cout << endl;

        if(chunksC.count(col)){
            chunksC.at(col) += 1;
        }
        else{
            chunksC.insert( make_pair(col,1) );
        }
    }

    int cnt = 0;
    for(auto itr: chunksC){
        if( chunksR.count(itr.first) ){
            
            if( chunksR.at(itr.first) == chunksC.at(itr.first) ){
                cnt += chunksR.at(itr.first) * chunksR.at(itr.first);
            }
            else{
                cnt += max( chunksR.at(itr.first), chunksC.at(itr.first) );
            }
        }
    }

    return cnt;
}  

int main(){

    // vector<int> nums1 = {1,3,2,3}, nums2 = {1,1,2,2};
    // vector<vector<int>> ans = findDifference(nums1,nums2);

    // for(int n1 : ans[0]){ cout << n1 << ' '; }
    // cout << endl;
    // for(int n2 : ans[1]){ cout << n2 << ' '; }


    //vector<int> arr = {1,2,2,1,1,3};
    //cout << uniqueOccurrences(arr);

    //string w1 = "abc", w2 = "bca";
    //cout << closeStrings(w1,w2);

    vector<vector<int>> grid = {
        {3,2,1},
        {1,7,6},
        {2,7,7}
    };
    cout << equalPairs(grid);
}