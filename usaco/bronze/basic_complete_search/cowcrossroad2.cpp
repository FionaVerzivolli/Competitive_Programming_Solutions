#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// difficulty: tagged as "normal"
void usaco(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

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
    std::string in;
    cin >> in;
    int ret = 0;
    vector<bool> seen(26, false);
    vector<char> st;

    for(char ch: in){
        int idx = ch - 'A';
        if(!seen[idx]){
            seen[idx] = true;
            st.push_back(ch);
            continue;
        }

        vector<char> buf;
        while(!st.empty() && st.back() != ch){
            ++ret;
            buf.push_back(st.back());
            st.pop_back();
        }
        st.pop_back();

        for (auto it = buf.rbegin(); it != buf.rend(); ++it){
            st.push_back(*it);
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