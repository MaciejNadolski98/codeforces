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

int sol(vector<int> arr) {
    vector<int> left(arr.size());
    vector<int> right(arr.size());
    int tmp = arr[0] + 1;
    int start, stop;
    for (int i = 0; i < arr.size(); i++) {
        tmp--;
        tmp = min(tmp, arr[i]);
        left[i] = tmp;
        if (tmp == 1) stop = i;
    }
    tmp = arr.back() + 1;
    for (int i = arr.size()-1; i >= 0; i--) {
        tmp--;
        tmp = min(tmp, arr[i]);
        right[i] = tmp;
        if (tmp == 1) start = i;
    }
    if (start > stop) return 0;

    int l = start;
    int r = start;
    for (int time = 1; time <= arr.size(); time++) {
        if (l == 0 || left[l-1] > time + 1) {
            r++;
        } else if (r == arr.size()-1 || right[r+1] > time + 1) {
            l--;
        } else {
            return 0;
        }
    }
    return stop - start + 1;
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
