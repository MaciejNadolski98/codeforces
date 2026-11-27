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
    ll maks = 0;
    for (auto x : arr) {
        maks = max(maks, x);
    }
    int idx = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == maks) {
            idx = i;
            break;
        }
    }
    int shift = idx;
    vector<ll> shifted;
    for (int i = shift + 1; i < arr.size(); i++) {
        shifted.push_back(arr[i]);
    }
    for (int i = 0; i < shift; i++) {
        shifted.push_back(arr[i]);
    }
    vector<ll> outs(arr.size());
    vector<pair<int, ll>> stack;
    ll acc = 0;
    for (int i = 0; i < shifted.size(); i++) {
        int count = 1;
        while (!stack.empty() && shifted[i] > stack.back().second) {
            count += stack.back().first;
            acc -= ((ll)stack.back().first) * stack.back().second;
            stack.pop_back();
        }
        acc += ((ll) count) * shifted[i];
        stack.push_back(make_pair(count, shifted[i]));
        outs[i + 1] += acc;
    }
    stack.clear();
    acc = 0;
    for (int i = shifted.size()-1; i >= 0; i--) {
        int count = 1;
        while (!stack.empty() && shifted[i] > stack.back().second) {
            count += stack.back().first;
            acc -= ((ll)stack.back().first) * stack.back().second;
            stack.pop_back();
        }
        acc += ((ll) count) * shifted[i];
        stack.push_back(make_pair(count, shifted[i]));
        outs[i] += acc;
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << outs[(i - shift + arr.size() - 1) % arr.size()] << " ";
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
