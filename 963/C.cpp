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

ll sol(vector<ll> arr, ll k) {
    ll maks = -1;
    for (auto x : arr) {
        maks = max(x, maks);
    }
    vector<int> count(k);
    for (auto x : arr) {
        auto v = x - maks % (2 * k);
        if (v < 0) v += 2 * k;
        v %= 2 * k;

        if (v == k) return -1;
        if (v < k) count[v] += 1;
        if (v > k) {
            count[0] += 1;
            count[v-k] -= 1;
        }
    }
    int tmp = 0;
    for (int i = 0; i < k; i++) {
        tmp += count[i];
        if (tmp == arr.size()) return maks + i;
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        auto arr = read_line<ll>(n);
        cout << sol(arr, k) << endl;
    }
}
