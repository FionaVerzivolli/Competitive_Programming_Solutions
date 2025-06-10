#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

// difficulty: tagged as "normal"
// https://usaco.org/index.php?page=viewproblem2&cpid=965

void usaco(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

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

void backtrack(const vector<string>& cows, vector<vector<string> >& permutations, vector<string>& current,
                vector<int>& freq) {
    if (current.size() == cows.size()) {
        permutations.push_back(current);
        return;
    }
    for (int i = 0; i < (int)cows.size(); i++) {
        if (freq[i] == 0) {
            freq[i] = 1;
            current.push_back(cows[i]);
            backtrack(cows, permutations, current, freq);
            current.pop_back();
            freq[i] = 0;
        }
    }
}

vector<vector<string> > permute(vector<string> cows) {
    vector<vector<string> > permutations;
    vector<string> current;
    vector<int> freq(cows.size(), 0);
    backtrack(cows, permutations, current, freq);
    return permutations;
}

bool isValid(const vector<string>& perm, const vector<pair<string,string> >& constraints) {
    for (auto &c : constraints) {
        // find the two cows in the current ordering
        int i = find(perm.begin(), perm.end(), c.first)  - perm.begin();
        int j = find(perm.begin(), perm.end(), c.second) - perm.begin();
        if (abs(i - j) != 1) 
            return false;
    }
    return true;
}

void solve() {
    usaco();
    int n;
    cin >> n;

    vector<string> cows;
    cows.push_back("Beatrice");
    cows.push_back("Belinda");
    cows.push_back("Bella");
    cows.push_back("Bessie");
    cows.push_back("Betsy");
    cows.push_back("Blue");
    cows.push_back("Buttercup");
    cows.push_back("Sue");
    sort(cows.begin(), cows.end());

    vector<pair<string,string> > constraints;
    for (int i = 0; i < n; i++) {
        string a, tmp, b;
        cin >> a >> tmp >> tmp >> tmp >> tmp >> b;
        constraints.emplace_back(a, b);
    }

    do {
        if (isValid(cows, constraints)) {
            for (auto &c : cows)
                cout << c << "\n";
            return;
        }
    } while (next_permutation(cows.begin(), cows.end()));
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