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

bool check(vector<int> &arr, int k, int median) {
    int target = arr.size() % k;
    if (target == 0) target = k;
    vector<int> dp(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        int elems = i % k;
        int val = 0;
        if (arr[i] >= median) val = 1;
        if (elems == 0) {
            if (val) dp[i] = 1;
            else if (i >= k) dp[i] = dp[i - k];
            else dp[i] = 0;
            continue;
        }
        if (i < k) {
            dp[i] = dp[i-1] + val;
            continue;
        }
        dp[i] = max(dp[i-1] + val, dp[i-k]);
    }
    return dp.back() * 2 > target;
}

int sol(vector<int> arr, int k) {
    int start = 0;
    int stop = 1e9;
    while (start < stop) {
        int mid = (start + stop + 1) / 2;
        if (check(arr, k, mid)) {
            start = mid;
        } else {
            stop = mid - 1;
        }
    }
    return start;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        auto arr = read_line<int>(n);
        cout << sol(arr, k) << endl;
    }
}
