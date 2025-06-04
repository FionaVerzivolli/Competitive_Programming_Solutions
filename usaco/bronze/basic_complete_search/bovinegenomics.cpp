#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// difficulty: tagged as "normal"
void usaco(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    /*
         * How To Use:
         *
         * Call usaco() to take input and output
         * to & from a textfile
         *
         * freopen("File Name", "r" or "w", stdin or stdout);
         *
         * r && stdin == read
         *
         * w && stdout == print
         *
     */
}
bool checkCol(vector<string> grid, int column, int n){
    // check if the genomes in spotty cows don't show up 
    // in the plain cows and vice versa
    set<char> spotty;
    set<char> plain;
    set<char> empty;

    for(int i = 0; i < n; i++){
        spotty.insert(grid[i][column]);
        plain.insert(grid[i+n][column]);
        
    }
    set_difference(spotty.begin(), spotty.end(), plain.begin(), plain.end(), inserter(empty, empty.begin()));
    
    if(empty.size() == spotty.size()){
        return true;
    }
    return false;
}
void solve() {
    usaco();
    int rows;
    int cols;
    cin >> rows;
    cin >> cols;
    vector<string> genomes;
    rows *= 2;
    for(int i = 0; i < rows; i++){
        string tmp;
        cin >> tmp;

        genomes.push_back(tmp);
    }
    int ret = 0;
    for(int i = 0; i < cols; i++){
        if(checkCol(genomes, i, rows/2)){
            ret++;
        }
    }
    cout << ret;
    
}

int main(){
    //Speed up
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int testcases = 1;

    //cin >> testcases; 

    for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){

        //Google
        //cout<<"Case #"<<number_of_total_test_cases<<": ";

        // Normal
        solve();

    }

    //cout << elapsedTime << '\n';
}