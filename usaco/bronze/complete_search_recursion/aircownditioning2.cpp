#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

// https://usaco.org/index.php?page=viewproblem2&cpid=1276


bool compareArrays(vector<int> A, vector<int> B){
    int n = A.size();
    for(int i = 0; i < n; i++){
        if(A[i] < B[i]){
            return false;
        }
    }
    return true;
}

static const int MAX_STALL = 100;

int recurse(int M,
            const vector<vector<int> >& acs,
            const vector<int>& result,
            vector<int>& retA,
            int cost,
            int currMin,
            int acNum)
{
    // if weve considered all M ACs, only accept if retA meets result
    if (acNum == M) {
        if (compareArrays(retA, result))
            return min(currMin, cost);
        else
            return currMin;
    }
    // prune if weve already spent at least currMin
    if (cost >= currMin) return currMin;

    // skip this AC
    int best = recurse(M, acs, result, retA, cost, currMin, acNum + 1);

    // take AC: apply its cooling & cost
    int a = acs[acNum][0];
    int b = acs[acNum][1];
    int p = acs[acNum][2];
    int m = acs[acNum][3];
    for (int s = a; s <= b; s++) {
        retA[s] += p;
    }
    best = recurse(M, acs, result, retA, cost + m, best, acNum + 1);
    // backtrack
    for (int s = a; s <= b; s++) {
        retA[s] -= p;
    }

    return best;
}


void solve() {
    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<vector<int> > cows;
    vector<vector<int> > acs;
    for(int i = 0; i < N; i++){
        vector<int> cow;
        for(int j = 0; j < 3; j++){
            int tmp;
            cin >> tmp;
            cow.push_back(tmp);
        }
        cows.push_back(cow);
    }
    for(int i = 0; i < M; i++){
        vector<int> ac;
        for(int j = 0; j < 4; j++){
            int tmp;
            cin >> tmp;
            ac.push_back(tmp);
        }
        acs.push_back(ac);
    }

    // What final vector should look like
    const int MAX_STALL = 100;
    vector<int> result(MAX_STALL+1, 0);
    vector<int> retA(MAX_STALL+1, 0);

    for(auto cow : cows){
        for(int i = cow[0]; i < cow[1] + 1; i++){
            // p_i value
            result[i] = max(result[i], cow[2]);
        }
    }

    static const int INF = 1000000000;
    cout << recurse(M, acs, result, retA, 0, INF, 0);
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