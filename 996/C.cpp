#include"bits/stdc++.h"

using namespace std;
#define ll long long

template <typename T1, typename T2>
std::ostream& operator<< (std::ostream& out, const pair<T1, T2> p) {
    out << "(" << p.first << "," << p.second << ")";
    return out;
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const vector<T>& v) {
    out << "[ ";
    for (auto elem : v) {
        out << elem << " ";
    }
    out << "]";
    return out;
}

template <typename T>
vector<T> read_line(int n) {
    vector<T> ret;
    for (int i = 0; i < n; i++) {
        T x;
        cin >> x;
        ret.push_back(x);
    }
    return ret;
}



void sol(string path, vector<vector<ll>> vals) {
    int n = vals.size();
    int m = vals[0].size();
    vector<ll> rows(n);
    vector<ll> cols(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rows[i] += vals[i][j];
            cols[j] += vals[i][j];
        }
    }

    int row = 0, col = 0;
    for (auto c : path) {
        if (c == 'D') {
            vals[row][col] = -rows[row];
            cols[col] -= rows[row];
            row += 1;
        } else {
            vals[row][col] = -cols[col];
            rows[row] -= cols[col];
            col += 1;
        }
    }
    vals[row][col] -= rows[row];

    for (auto v : vals) {
        for (auto x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        string path;
        cin >> path;
        vector<vector<ll>> vals;
        for (int j = 0; j < n; j++) {
            vals.push_back(read_line<ll>(m));
        }
        sol(path, vals);
    }
}
