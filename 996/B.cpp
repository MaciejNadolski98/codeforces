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



bool sol(vector<int> a, vector<int> b) {
    vector<int> d;
    for (int i = 0; i < a.size(); i++) {
        d.push_back(a[i] - b[i]);
    }

    int negative = 0;
    for (auto x : d) {
        if (x < 0) {
            if (negative < 0) return false;
            negative = x;
        }
    }

    for (auto x : d) {
        if (x == negative) continue;
        if (x + negative < 0) return false;
    }

    return true;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        auto a = read_line<int>(n);
        auto b = read_line<int>(n);
        if (sol(a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
