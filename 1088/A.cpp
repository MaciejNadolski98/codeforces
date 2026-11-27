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

void sol(vector<int> arr) {
    if (arr.size() == 1) {
        cout << 1 << endl;
        return;
    }

    for (auto _ : arr) {
        cout << 2 << " ";
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
        vector<int> arr = read_line<int>(n);
        sol(arr);
    }
}
