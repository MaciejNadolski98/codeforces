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

void sol(int q, int p) {
    int x = q + 2 * p;
    int last_n = 1e9;
    int m = 1;
    while (m < last_n) {
        int n = (x - m) / (2 * m + 1);
        if (x == 2 * n * m + n + m) {
            if (abs(n - m) <= q) {
                cout << n << " " << m << endl;
                return;
            }
        }
        last_n = n;

        m++;
    }
    cout << -1 << endl;
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


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int q, p;
        cin >> q >> p;
        sol(q, p);
    }
}
