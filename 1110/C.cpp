#include"bits/stdc++.h"

using namespace std;
#define ll long long
#define lll __int128

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

void sol(int n, int k) {
    int target = k ^ n;
    vector<int> powers;
    powers.push_back(0);
    int x = 1;
    while (x <= target) {
        if ((x & target) != 0) {
            powers.push_back(x);
        }
        x *= 2;
    }
    if (powers.back() > n - 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 1; i < n; i++) {
        bool inc = false;
        for (auto x : powers) {
            if (x == i) {
                inc = true;
            }
        }
        if (!inc) {
            cout << i << " ";
        }
    }
    for (auto x : powers) cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        sol(n, k);
    }
}
