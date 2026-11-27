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

bool can_get(vector<pair<ll, ll>> xxx, ll median, ll cost) {
    ll count_smaller = 0;
    ll count_larger = 0;
    for (auto x : xxx) {
        if (x.first < median && x.second == 0) count_smaller++;
        if (x.first >= median) count_larger++;
    }

    if (count_smaller >= (xxx.size() + 1) / 2) return false;
    ll target = (xxx.size() + 2) / 2 - count_larger;
    if (target <= 0) return true;
    for (ll i = xxx.size()-1; i >= 0; i--) {
        auto x = xxx[i];
        if (x.first >= median || x.second == 0) continue;
        target--;
        cost -= (median - x.first);
        if (cost < 0) return false;
        if (target == 0) return true;
    }
    return false;
}

ll sol(vector<ll> arr, vector<ll> brr, ll k) {
    vector<pair<ll, ll>> xxx(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        xxx[i] = make_pair(arr[i], brr[i]);
    }
    sort(xxx.begin(), xxx.end());
    ll median_small = xxx[(xxx.size() - 2) / 2].first;
    ll median_large = xxx[(xxx.size() - 2) / 2 + 1].first;
    ll potential_score = 0;
    for (auto x : xxx) {
        if (x.second == 0) continue;
        ll median = x.first <= median_small ? median_large : median_small;
        potential_score = max(potential_score, x.first + k + median);
    }

    if (xxx.back().second == 1) return potential_score;
    ll maks = xxx.back().first;
    xxx.pop_back();
    ll start = 0;
    ll stop = k + median_large;
    while (start < stop) {
        ll mid = (start + stop + 1) / 2;
        if (can_get(xxx, mid, k)) {
            start = mid;
        } else {
            stop = mid - 1;
        }
    }
    return max(potential_score, start + maks);
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        auto arr = read_line<ll>(n);
        auto brr = read_line<ll>(n);
        cout << sol(arr, brr, k) << endl;
    }
}

