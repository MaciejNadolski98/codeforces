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

ll interval_sum(vector<ll>& prefsum, ll start, ll stop) {
    ll full_circles = (stop - start) / (prefsum.size() - 1);
    if (stop > prefsum.size() - 2) {
        stop %= prefsum.size() - 1;
    }
    if (start > stop) {
        return interval_sum(prefsum, 0, start) + interval_sum(prefsum, stop, prefsum.size()-2) + full_circles * prefsum.back();
    }

    return prefsum[stop+1] - prefsum[start] + full_circles * prefsum.back();
}

bool can_afford(vector<ll>& prefsum, vector<ll>& a, vector<ll>& b, ll c, ll k) {
    ll cost = 0;
    for (int i = 0; i < a.size(); i++) {
        ll s = interval_sum(prefsum, i, i + c - 1);
        if (s > a[i]) {
            continue;
        }
        cost += a[i] - s;
    }

    return cost <= k;
}

ll sol(vector<ll> a, vector<ll> b, ll k) {
    vector<ll> prefsum(1);
    for (auto elem : b) {
        prefsum.push_back(prefsum.back() + elem);
    }

    ll start = 1;
    ll stop = 1e9;
    while (start < stop) {
        ll mid = (start + stop) / 2;
        if (can_afford(prefsum, a, b, mid, k)) {
            stop = mid;
        } else {
            start = mid + 1;
        }
    }

    return start;
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
        int n;
        ll k;
        cin >> n >> k;
        auto a = read_line<ll>(n);
        auto b = read_line<ll>(n);
        cout << sol(a, b, k) << endl;
    }
}


