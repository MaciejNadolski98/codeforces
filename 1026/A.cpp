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

int sol(vector<int> arr) {
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++) arr[i] = arr[i] % 2;
    if ((arr[0] + arr.back()) % 2 == 0) return 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] + arr[i+1] == 1) return i+1;
        int r = arr.size() - i - 1;
        if (arr[r] + arr[r-1] == 1) return i+1;
    }
    return -1;
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
        cout << sol(arr) << endl;
    }
}
