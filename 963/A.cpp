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

void sol(string s) {
    int count = 0;
    int a, b, c, d;
    int n = s.size() / 4;
    a = 0; b = 0; c = 0; d = 0;
    for (auto c_ : s) {
        if (c_ == 'A') {
            a++;
        } else if (c_ == 'B') {
            b++;
        } else if (c_ == 'C') {
            c++;
        } else if (c_ == 'D') {
            d++;
        }
    }
    cout << min(a, n) + min(b, n) + min(c, n) + min(d, n) << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        sol(s);
    }
}
