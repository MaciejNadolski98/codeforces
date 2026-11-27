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

vector<int> arr;

inline bool check(int a, int b, int c) {
    bool a_ = false;
    bool b_ = false;
    bool c_ = false;
    int prev = -1;
    for (auto x : arr) {
        if (x == prev) continue;
        prev = x;
        if (x == a) {
            if (a_) return false;
            a_ = true;
        }
        if (x == b) {
            if (b_) return false;
            b_ = true;
        }
        if (x == c) {
            if (c_) return false;
            c_ = true;
        }
    }
    return true;
}

void my_swap(int idx1, int idx2) {
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

inline bool try_swap(int idx1, int idx2, int broken) {
    if (idx1 == idx2) return false;
    if (arr[idx1] == arr[idx2]) return false;
    if (idx1 < 0 || idx2 < 0 || idx1 >= arr.size() || idx2 >= arr.size()) return false;
    my_swap(idx1, idx2);
    bool ret = check(arr[idx1], arr[idx2], broken);
    my_swap(idx1, idx2);
    return ret;
}

bool sol() {
    unordered_set<int> tmp;
    int prev = -1;

    vector<int> brokens;
    for (auto x : arr) {
        if (x == prev) {
            continue;
        }
        if (!tmp.contains(x)) {
            tmp.insert(x);
        } else {
            bool con = false;
            for (auto y : brokens) if (y == x) con = true;
            if (!con) {
                brokens.push_back(x);
                if (brokens.size() > 2) return false;
            }
        }
        prev = x;
    }
    if (brokens.size() == 0) return true;
    brokens.push_back(-1);
    int xxx = brokens[0];

    int last = -1;
    int first = -1;
    int second_first = -1;
    int second_last = -1;
    int first_mid = -1;
    int last_mid = -1;
    for (int i = 0; i < arr.size(); i++) {
        int x = arr[i];
        if (x == xxx) {
            second_last = last;
            last = i;
            if (first == -1) first = i;
            else if (second_first == -1) second_first = i;
        } else {
            if (first != -1 && first_mid == -1) first_mid = i;
            if (second_first != -1 && last_mid == -1) last_mid = i;
        }
    }

    if (second_first == last) {
        if (try_swap(first, last-1, brokens[1])) return true;
        if (try_swap(first, last+1, brokens[1])) return true;
        if (try_swap(last, first-1, brokens[1])) return true;
        if (try_swap(last, first+1, brokens[1])) return true;
    } else {
        if (try_swap(first, second_first-1, brokens[1])) return true;
        if (try_swap(first, last+1, brokens[1])) return true;
        if (try_swap(last, second_last+1, brokens[1])) return true;
        if (try_swap(last, first-1, brokens[1])) return true;
        if (try_swap(first, last_mid, brokens[1])) return true;
        if (try_swap(last, first_mid, brokens[1])) return true;
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        arr = read_line<int>(n);
        if (sol()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
