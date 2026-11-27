#include"bits/stdc++.h"

using namespace std;

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

void sol(vector<int> arr) {
    int x = arr[0];
    bool all_same = true;
    int maks = arr[0];
    for (auto elem : arr) if (x != elem) all_same = false;
    if (all_same) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

    for (auto elem : arr) maks = max(maks, elem);
    for (auto elem : arr) {
        if (elem == maks) {
            cout << "1 ";
        } else {
            cout << "2 ";
        }
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
        int n;
        cin >> n;
        auto arr = read_line<int>(n);
        sol(arr);
    }
}


