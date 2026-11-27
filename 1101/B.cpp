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

void sol(vector<ll> arr) {
    ll height = arr[0];
    ll excess = 0;
    cout << arr[0] << " ";
    for (ll i = 1; i < arr.size(); i++) {
        excess += arr[i] - height;
        if (excess < 0) {
            ll increase = i + 1;
            ll drop = (-excess - 1) / increase + 1;
            height -= drop;
            excess += drop * increase;
        }
        cout << height << " ";
    }
    cout << endl;
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
