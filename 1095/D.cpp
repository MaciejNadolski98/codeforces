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

bool check(vector<int> arr, int target) {
    vector<bool> covered(target);
    vector<int> to_use;
    for (auto x : arr) {
        if (x >= target || covered[x]) {
            to_use.push_back(x);
        } else {
            covered[x] = true;
        }
    }
    int idx = to_use.size()-1;
    for (int i = target-1; i >= 0; i--) {
        if (covered[i]) continue;

        if (i * 2 >= to_use[idx]) return false;
        idx--;
    }
    return true;
}

bool sol(vector<int> arr) {
    bool sorted = true;
    for (int i = 0; i < arr.size()-1; i++) {
        if (arr[i] > arr[i+1]) sorted = false;
    }
    if (sorted) return true;

    int global_maks_even = -1;
    int global_mini_even = arr.size();
    int global_maks_odd = -1;
    int global_mini_odd = arr.size();
    for (auto x : arr) {
        if (x % 2 == 1) {
            global_maks_odd = max(global_maks_odd, x);
            global_mini_odd = min(global_mini_odd, x);
        } else {
            global_maks_even = max(global_maks_even, x);
            global_mini_even = min(global_mini_even, x);
        }
    }

    if (global_maks_even == -1 || global_maks_odd == -1) {
        return false;
    }

    int prefix_maks_even = -1;
    int prefix_maks_odd = -1;
    for (auto x : arr) {
        if (x % 2 == 1) {
            if (prefix_maks_odd < x) {
                prefix_maks_odd = x;
                continue;
            }
            if (x < global_maks_even && global_maks_even < prefix_maks_odd
                && x < global_mini_even && global_mini_even < prefix_maks_odd) return false;
        } else {
            if (prefix_maks_even < x) {
                prefix_maks_even = x;
                continue;
            }
            if (x < global_maks_odd && global_maks_odd < prefix_maks_even
                && x < global_mini_odd && global_mini_odd < prefix_maks_even) return false;
        }
    }

    int suffix_mini_even = arr.size();
    int suffix_mini_odd = arr.size();
    reverse(arr.begin(), arr.end());
    for (auto x : arr) {
        if (x % 2 == 1) {
            if (suffix_mini_odd > x) {
                suffix_mini_odd = x;
                continue;
            }
            if (x < global_maks_even && global_maks_even < suffix_mini_odd
                && x < global_mini_even && global_mini_even < suffix_mini_odd) return false;
        } else {
            if (suffix_mini_even > x) {
                suffix_mini_even = x;
                continue;
            }
            if (x < global_maks_odd && global_maks_odd < suffix_mini_even
                && x < global_mini_odd && global_mini_odd < suffix_mini_even) return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        auto arr = read_line<int>(n);
        if (sol(arr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
