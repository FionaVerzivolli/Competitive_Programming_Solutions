#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

// difficulty: tagged as "normal"
// https://usaco.org/index.php?page=viewproblem2&cpid=713

void usaco(){
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

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

void solve() {
    // usaco();
    int n;
    cin >> n;
    vector<vector<int> > timings;
    for(int i = 0; i < n; i++){
        vector<int> tmp;
        for(int j = 0; j < 2; j++){
            int foo;
            cin >> foo;
            tmp.push_back(foo);
        }
        timings.push_back(tmp);
    }

    sort(timings.begin(), timings.end());
    int curr = 0;

    for(int i = 0; i < n; i++){
        int arrival = timings[i][0];
        int duration = timings[i][1];
        curr = max(arrival, curr) +  duration;
    }
    cout << curr;
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