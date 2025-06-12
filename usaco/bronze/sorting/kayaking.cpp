#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <climits>

using namespace std;

// difficulty tagged as "normal"
// https://codeforces.com/contest/863/problem/B

int helper(vector<int> boats, int size){
    // now sort the weights
    int cost = 0;
    for (int k = 0; k + 1 < boats.size(); k += 2) {
        cost += boats[k+1] - boats[k];
    }
    return cost;
}

void solve() {
    int m;
    cin >> m;
    int n = 2*m;
    vector<int> w(n);
    for (int i = 0; i < n; i++) 
        cin >> w[i];
    sort(w.begin(), w.end());

    int answer = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int cost = 0;
            int idx = 0;
            int prev = 0;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if (idx % 2 == 0) {
                    prev = w[k];
                } else {
                    cost += (w[k] - prev);
                }
                idx++;
            }
            answer = min(answer, cost);
        }
    }

    cout << answer << '\n';
}


int main() {
    solve();
}
