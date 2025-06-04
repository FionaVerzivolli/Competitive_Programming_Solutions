#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// difficulty: tagged as "easy"

void usaco(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

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

void solve(){
    usaco();
    int k;
    int n;
    vector<int> diamonds;
    cin >> n;
    cin >> k;
    
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        diamonds.push_back(tmp);
    }

    int maxnums = 0;

    sort(diamonds.begin(), diamonds.end());
    // [1, 1, 3, 4, 6]
    int left = 0;
    int right = 0;


    while(right < n){
        while(diamonds[right] - diamonds[left] > k){
            left++;
        }
        right++;
        maxnums = max(maxnums, right - left);
    }

    cout << maxnums;
    cout << '\n';

}

//do not submit if usaco(); is open

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