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

ll sol(vector<pair<ll, ll>> arr) {
    ll buy_sum = 0;
    ll sell_sum = 0;
    for (auto x : arr) {
        buy_sum += x.first;
        sell_sum += x.second;
    }

    ll diff = sell_sum - buy_sum;
    if (diff <= 0) return -1;
    ll maks = 0;
    int idx = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].second <= diff && maks < arr[i].first) {
            maks = arr[i].first;
            idx = i;
        }
    }

    if (idx == -1) return -1;
    arr.erase(arr.begin() + idx);

    sort(arr.begin(), arr.end());
    ll money = 0;
    ll debt = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].first > money) {
            ll investment = arr[i].first - money;
            debt += investment;
            money += investment;
        }
        if (arr[i].second > arr[i].first) money += arr[i].second - arr[i].first;
    }
    
    vector<pair<ll, ll>> remaining;
    for (auto x : arr) {
        if (x.first <= x.second) continue;
        remaining.push_back({x.first - x.second, x.first});
    }

    return buy_sum + debt;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<pair<ll, ll>> arr;
        for (ll j = 0; j < n; j++) {
            ll buy, sell;
            cin >> buy >> sell;
            arr.push_back({buy, sell});
        }
        cout << sol(arr) << endl;
    }
}
