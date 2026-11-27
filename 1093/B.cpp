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

bool sol(vector<int>& arr, int m) {
    int current_streak = 1;
    int last_elem = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == last_elem) {
            current_streak++;
            if (current_streak >= m) return false;
        } else {
            last_elem = arr[i];
            current_streak = 1;
        }
    }
    return true;
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
        int n, m;
        cin >> n >> m;
        auto arr = read_line<int>(n);
        if (sol(arr, m)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
