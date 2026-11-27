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

void sol(vector<ll> arr) {
    sort(arr.begin(), arr.end());
    int max_mex = 0;
    for (auto x : arr) {
        if (x == max_mex) max_mex++;
    }
    ll out = (ll) arr.back() * (ll) arr.size();
    for (int i = 1; i < arr.size(); i++) {
        out += (ll) min(i, max_mex);
    }
    if (arr.back() == 0) out++;
    else if (arr.back() == max_mex - 1) out++;
    cout << out << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        auto arr = read_line<ll>(n);
        sol(arr);
    }
}
