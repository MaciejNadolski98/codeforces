#include"bits/stdc++.h"

using namespace std;

bool interactive = false;
vector<int> arr;


bool query(int a, int b) {
    if (interactive) {
        cout << "? " << a+1 << " " << b+1 << endl;
        int x;
        cin >> x;
        if (x == 1) return true;
        return false;
    }
    if (arr[a] == arr[b]) return true;
    return false;
}

int sol(int n, vector<int> arr) {
    if (query(0, 1)) return 0;
    if (query(1, 2)) return 1;
    if (query(0, 2)) return 0;
    for (int i = 3; i < 2 * n - 1; i += 2) {
        if (query(i, i+1)) return i;
    }
    return 2 * n - 1;
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
        if (!interactive) {
            arr = read_line<int>(2*n);
        }
        int k = sol(n, arr);
        cout << "! " << k + 1 << endl;
    }
}
