#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// difficulty: tagged as "easy"

void usaco(){
    freopen("daisy.in", "r", stdin);
    freopen("daisy.out", "w", stdout);

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
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &x : p) cin >> x;

    int photos = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {

            int sum = 0;
            for (int k = i; k <= j; ++k) sum += p[k];
            int len = j - i + 1;

            if (sum % len) continue;
            int avg = sum / len;

            for (int k = i; k <= j; ++k) {
                if (p[k] == avg) {
                    ++photos;
                    break;
                }
            }
        }
    }
    cout << photos << '\n';
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