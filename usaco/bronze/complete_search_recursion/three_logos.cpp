#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

// difficulty: tagged as "hard"
// https://codeforces.com/problemset/problem/581/D

void dfsPerm(int pos, array<int,3> &cur, vector<array<int,3> > &out) {
    if (pos == 3) {
        out.push_back(cur);
        return;
    }
    for (int j = pos; j < 3; ++j) {
        swap(cur[pos], cur[j]);
        dfsPerm(pos+1, cur, out);
        swap(cur[pos], cur[j]);
    }
}


vector<array<int,3> > genPerms() {
    array<int,3> start = {0,1,2};
    vector<array<int,3> > perms;
    dfsPerm(0, start, perms);
    return perms;
}

void dfsFlip(int pos, array<bool,3> &cur, vector<array<bool,3> > &out) {
    if (pos == 3) {
        out.push_back(cur);
        return;
    }
    cur[pos] = false;
    dfsFlip(pos+1, cur, out);
    cur[pos] = true;
    dfsFlip(pos+1, cur, out);
}

vector<array<bool,3> > genFlips() {
    array<bool,3> start;
    vector<array<bool,3> > flips;
    dfsFlip(0, start, flips);
    return flips;
}


void printGrid(int s,
               const vector<vector<int> >& pairs,
               const array<bool,3>& flip,
               const array<int,3>& order)
{
    int w[3], h[3];
    for (int slot = 0; slot < 3; ++slot) {
        int idx = order[slot];
        if (flip[idx]) {
            w[slot] = pairs[idx][1];
            h[slot] = pairs[idx][0];
        } else {
            w[slot] = pairs[idx][0];
            h[slot] = pairs[idx][1];
        }
    }

    vector<string> grid(s, string(s, '?'));

    for (int slot = 0; slot < 3; ++slot) {
    }

    // all side-by-side
    if (h[0]==s && h[1]==s && h[2]==s && w[0]+w[1]+w[2]==s) {
        int x = 0;
        for (int slot = 0; slot < 3; ++slot) {
            char ch = char('A' + order[slot]);
            for (int dy = 0; dy < h[slot]; ++dy) {
                for (int dx = 0; dx < w[slot]; ++dx) {
                    grid[dy][x + dx] = ch;
                }
            }
            x += w[slot];
        }
    }
    else {
        // slot 0 at (0,0)
        {
            char ch = char('A' + order[0]);
            for (int dy = 0; dy < h[0]; ++dy)
                for (int dx = 0; dx < w[0]; ++dx)
                    grid[dy][dx] = ch;
        }
        // slot 1 at (w[0],0)
        {
            int x0 = w[0];
            char ch = char('A' + order[1]);
            for (int dy = 0; dy < h[1]; ++dy)
                for (int dx = 0; dx < w[1]; ++dx)
                    grid[dy][x0 + dx] = ch;
        }
        // slot 2 at (w[0], h[1])
        {
            int x0 = w[0], y0 = h[1];
            char ch = char('A' + order[2]);
            for (int dy = 0; dy < h[2]; ++dy)
                for (int dx = 0; dx < w[2]; ++dx)
                    grid[y0 + dy][x0 + dx] = ch;
        }
    }

    // output
    cout << s << "\n";
    for (int i = 0; i < s; ++i) {
        cout << grid[i] << "\n";
    }
}

void solve() {
    vector<vector<int> > pairs(3, vector<int>(2));
    for (int i = 0; i < 3; ++i) {
        cin >> pairs[i][0] >> pairs[i][1];
    }

    int sum = pairs[0][0]*pairs[0][1]
            + pairs[1][0]*pairs[1][1]
            + pairs[2][0]*pairs[2][1];
    int s = int(floor(sqrt(double(sum))));
    if (s*s != sum) {
        cout << -1 << "\n";
        return;
    }

    vector<array<int,3> > perms = genPerms();
    vector<array<bool,3> > flips = genFlips();

    for (size_t pi = 0; pi < perms.size(); ++pi) {
        array<int,3> &order = perms[pi];
        for (size_t fi = 0; fi < flips.size(); ++fi) {
            array<bool,3> &flip = flips[fi];

            int w0 = flip[order[0]] ? pairs[order[0]][1] : pairs[order[0]][0];
            int h0 = flip[order[0]] ? pairs[order[0]][0] : pairs[order[0]][1];
            int w1 = flip[order[1]] ? pairs[order[1]][1] : pairs[order[1]][0];
            int h1 = flip[order[1]] ? pairs[order[1]][0] : pairs[order[1]][1];
            int w2 = flip[order[2]] ? pairs[order[2]][1] : pairs[order[2]][0];
            int h2 = flip[order[2]] ? pairs[order[2]][0] : pairs[order[2]][1];

            // Pattern A
            if (h0==s && h1==s && h2==s && w0+w1+w2==s) {
                printGrid(s, pairs, flip, order);
                return;
            }
            // Pattern B
            int remW = s - w0;
            if (h0==s && remW>0
             && w1==remW && w2==remW
             && h1+h2==s)
            {
                printGrid(s, pairs, flip, order);
                return;
            }
        }
    }

    cout << -1 << "\n";
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