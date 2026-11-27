#include"bits/stdc++.h"

using namespace std;

string sol(int n, vector<int> arr) {
    unordered_map<int, int> counts;
    for (int elem : arr) {
        counts[elem] += 1;
        if (counts[elem] > n * (n - 1)) {
            return "NO";
        }
    }
    return "YES";
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
        cin >> n;
        vector<int> arr = read_line<int>(n*n);
        cout << sol(n, arr) << endl;
    }
}
