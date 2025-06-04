#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long recurse(long long idx, vector<long long> &apples, long long n, long long sum1, long long sum2){
    if(idx == n){
        return abs(sum1 - sum2);
    }else{
        return min(recurse(idx + 1, apples, n, sum1 + apples[idx], sum2), recurse(idx + 1, apples, n, sum1, sum2 + apples[idx]));
    }

}

void solve() {
    long long n;
    cin >> n;
    vector<long long> apples;
    for(long long i = 0; i < n; i++){
        long long temp;
        cin >> temp;
        apples.push_back(temp);
    }
    
    // find all permutations
    // then calculate the difference
    cout << recurse(0, apples, n, 0, 0);
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