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


ll compute_max_sum(vector<ll> &arr) {
    vector<ll> prefsum;
    prefsum.push_back(0);
    for (auto elem : arr) {
        prefsum.push_back(prefsum.back() + elem);
    }

    ll mini = 0;
    ll max_sum = 0;
    for (int i = 0; i < arr.size() + 1; i++) {
        mini = min(mini, prefsum[i]);
        max_sum = max(max_sum, prefsum[i] - mini);
    }
    return max_sum;
}


void sol(vector<ll> arr, vector<bool> bits, ll target) {
    ll inf = 3e12;
    for (int i = 0; i < arr.size(); i++) {
        if (bits[i]) arr[i] = -inf;
    }
    vector<ll> prefsum;
    prefsum.push_back(0);
    for (auto elem : arr) {
        prefsum.push_back(prefsum.back() + elem);
    }

    ll mini = 0;
    ll max_sum = 0;
    for (int i = 0; i < arr.size() + 1; i++) {
        mini = min(mini, prefsum[i]);
        max_sum = max(max_sum, prefsum[i] - mini);
    }

    if (max_sum > target) {
        cout << "NO" << endl;
        return;
    }

    int index_picked = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (bits[i]) {
            index_picked = i;
            break;
        }
    }

    if (index_picked == -1) {
        if (max_sum == target) {
            cout << "YES" << endl;
            for (auto elem : arr) {
                cout << elem << " ";
            }
            cout << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    ll start = -inf;
    ll stop = target;
    while(start < stop) {
        // cerr << start << "-" << stop << endl;
        ll mid = (start + stop) / 2;
        if (start + stop < 0) mid--;
        arr[index_picked] = mid;

        if (compute_max_sum(arr) >= target) {
            stop = mid;
        } else {
            start = mid + 1;
        }
    }

    arr[index_picked] = start;

    cout << "YES" << endl;
    for (auto elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
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
        int n; ll k;
        cin >> n >> k;
        vector<bool> bits;
        for (int i = 0; i < n; i++) {
            char b;
            cin >> b;
            bits.push_back(b == '0');
        }
        auto arr = read_line<ll>(n);
        sol(arr, bits, k);
    }
}
