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
    ll count = 0;
    for (auto x : arr) {
        if (x % 2 == 0) {
            count++;
        }
    }
    if (count == arr.size()) return 0;
    sort(arr.begin(), arr.end());
    ll largest_odd;
    for (ll i = arr.size()-1; i >= 0; i--) {
        if (arr[i] % 2 == 1) {
            largest_odd = arr[i];
            break;
        }
    }
    for (ll x : arr) {
        if (x % 2 == 1) continue;
        if (x > largest_odd) return count + 1;
        largest_odd += x;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        auto arr = read_line<ll>(n);
        cout << sol(arr) << endl;
    }
}
