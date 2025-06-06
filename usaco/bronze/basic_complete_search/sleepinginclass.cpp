#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

// difficulty: tagged as "hard"

void solve() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        long long total = 0;
        for (int &x : a) { cin >> x; total += x; }

        if (total == 0) {
            cout << 0 <<'\n';
            continue;
        }

        int best_segments = 1;

        for (long long s = 1; s * s <= total; ++s) {
            if (total % s != 0) continue;

            auto can = [&](long long segSum) {
                long long cur = 0;
                int segments = 0;
                for (int x : a) {
                    cur += x;
                    if (cur > segSum) return 0;
                    if (cur == segSum) {
                        ++segments;
                        cur = 0;
                    }
                }
                return cur == 0 ? segments : 0;
            };

            int keep1 = can(s);
            int keep2 = can(total / s);
            best_segments = max({best_segments, keep1, keep2});
        }

        cout << (N - best_segments) << '\n';
    }
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