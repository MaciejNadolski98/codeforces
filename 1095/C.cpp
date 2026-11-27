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

void sol(vector<int> arr) {
    sort(arr.begin(), arr.end());

    int start = 1;
    int stop = arr.size();
    while (start < stop) {
        int mid = (start + stop + 1) / 2;
        if (check(arr, mid)) {
            start = mid;
        } else {
            stop = mid - 1;
        }
    }

    cout << start << endl;
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
