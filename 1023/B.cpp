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

void sol(vector<int> arr, int k) {
    int mini = arr[0];
    for (auto elem : arr) mini = min(elem, mini);

    ll larger = 0;
    for (auto elem : arr) if (elem - mini > k) larger += (ll) (elem - mini - k);

    if (larger > 1) {
        cout << "Jerry" << endl;
        return;
    }

    ll s = 0;
    for (auto elem : arr) s += (ll) elem;

    if (s % 2 == 0) {
        cout << "Jerry" << endl;
    } else {
        cout << "Tom" << endl;
    }
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
        int n, k;
        cin >> n >> k;
        auto arr = read_line<int>(n);
        sol(arr, k);
    }
}


