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
    vector<ll> out;
    for (int i = 0; i < arr.size(); i++) {
        vector<ll> left(arr.size());
        vector<ll> right(arr.size());
        ll max_level = 0;
        for (int j = (i + 1) % arr.size(); j != i; j = (j + 1) % arr.size()) {
            max_level = max(arr[j], max_level);
            right[j] = max_level;
        }
        max_level = 0;
        for (int j = (i - 1 + arr.size()) % arr.size(); j != i; j = (j - 1 + arr.size()) % arr.size()) {
            max_level = max(arr[(j + 1) % arr.size()], max_level);
            left[j] = max_level;
        }
        ll sum = 0;
        for (int j = 0; j < arr.size(); j++) {
            sum += min(left[j], right[j]);
        }
        out.push_back(sum);
    }
    cout << out.back() << " ";
    for (int i = 0; i < out.size() - 1; i++) {
        cout << out[i] << " ";
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
