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



ll sol(vector<ll> arr, ll jump, ll target) {
    for (int i = 0; i < arr.size(); i++) arr[i] *= 2;
    jump *= 2;
    target *= 2;
    ll time = arr[0];
    ll pos = jump;
    int idx = 1;
    while (pos < target && idx < arr.size()) {
        // cerr << "idx " << idx << " pos " << pos << " time " << time << " arr " << arr[idx] << endl;
        if (abs(pos - arr[idx]) <= time) {
            pos += jump;
            idx++;
            continue;
        }
        if (arr[idx] < pos) {
            arr[idx] += time;
            pos = arr[idx] + jump;
            idx++;
            continue;
        }
        arr[idx] -= time;
        ll dist = arr[idx] - pos;
        pos += dist / 2 + jump;
        time += dist / 2;
        idx++;
    }
    if (pos < target) time += target - pos;
    return time;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n, jump, target;
        cin >> n >> jump >> target;
        auto arr = read_line<ll>(n);
        cout << sol(arr, jump, target) << endl;
    }
}
