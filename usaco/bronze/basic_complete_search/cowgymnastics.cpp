#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// difficulty: tagged as "normal"

void usaco(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

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
    usaco();
    int n, k;
    cin >> n >> k;

    vector<vector<int> > pos(n, vector<int>(k + 1));

    for (int s = 0; s < n; ++s) {
        for (int rank = 0; rank < k; ++rank) {
            int cow;
            cin >> cow;
            pos[s][cow] = rank;
        }
    }

    int consistent = 0;

    for (int a = 1; a <= k; ++a) {
        for (int b = 1; b <= k; ++b) {
            if (a == b) continue;

            bool ok = true;
            for (int s = 0; s < n; ++s) {
                if (pos[s][a] > pos[s][b]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ++consistent;
        }
    }

    cout << consistent << '\n';
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