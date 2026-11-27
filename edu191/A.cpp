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
        int n, a_speed, b_speed, setup;
        cin >> n >> a_speed >> b_speed >> setup;
        int cand1 = (n - 1) / (a_speed + b_speed) + 1;
        int cand2 = (n - setup * a_speed - 1) / (a_speed + 10 * b_speed) + 1 + setup;
        cout << min(cand1, cand2) << endl;
    }
}
