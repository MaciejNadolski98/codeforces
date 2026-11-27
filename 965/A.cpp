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

void sol(int x, int y, int k) {
    if (k % 2 == 1) {
        cout << x << " " << y << endl;
        k--;
    }
    for (int i = 0; i < k / 2; i++) {
        cout << x - i - 1 << " " << y << endl;
        cout << x + i + 1 << " " << y << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        sol(x, y, k);
    }
}
