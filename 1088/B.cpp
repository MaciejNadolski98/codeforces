#include"bits/stdc++.h"

using namespace std;

std::ostream& operator<< (std::ostream& out, const vector<int>& v) {
    out << "[ ";
    for (auto elem : v) {
        out << elem << " ";
    }
    out << "]";
    return out;
}

void sol(int x, int y) {
    int diff = abs(x - y);
    if (diff == 0) {
        cout << 1 << endl;
    } else {
        int count = 0;
        for (int i = 1; i <= diff; i++) {
            if (diff % i == 0) {
                count += 1;
            }
        }
        cout << count << endl;
    }
    for (int i = 0; i < x; i++) {
        cout << 1 << " ";
    }
    for (int j = 0; j < y; j++) {
        cout << -1 << " ";
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
        int x, y;
        cin >> x >> y;
        sol(x, y);
    }
}
