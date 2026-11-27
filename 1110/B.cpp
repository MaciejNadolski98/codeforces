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

ll sol(vector<ll> arr) {
    sort(arr.begin(), arr.end());
    ll count = 0;
    for (int i = arr.size()-1; i >= 0; i--) {
        if ((i+1)*2 > arr.size() || arr[i] > 0) {
            count += (ll) arr[i];
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, k;
        cin >> n >> k;
        auto arr = read_line<ll>(n);
        for (int j = 0; j < n; j++) {
            arr[j] -= k;
        }
        cout << sol(arr) << endl;
    }
}
