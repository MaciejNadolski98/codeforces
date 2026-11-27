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

void sol() {
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cout << j << " ";
        }
        for (int j = 1; j <= n; j++) {
            cout << (j % n) + 1 << " ";
        }
        for (int j = 1; j <= n; j++) {
            cout << (j % n) + 1 << " ";
        }
        for (int j = 1; j <= n; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}

// ))(())))