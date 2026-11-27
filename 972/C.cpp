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

const int inf = 1e9;

void sol(vector<string> arr) {
    for (int i = 0; i < arr.size(); i++) {
        string s;
        for (auto c : arr[i]) {
            if (c == 'n' || c == 'a' || c == 'r' || c == 'e' || c == 'k') s += c;
        }
        arr[i] = s;
    }
    string narek = "narek";

    int best[5] = {0, -inf, -inf, -inf, -inf};

    for (int i = 0; i < arr.size(); i++) {
        int new_best[5] = {best[0], best[1], best[2], best[3], best[4]};
        for (int idx = 0; idx < 5; idx++) {
            int next_idx = idx;
            int score = best[idx];
            for (int c : arr[i]) {
                if (c == narek[next_idx]) {
                    next_idx++;
                    score++;
                    if (next_idx == 5) {
                        next_idx = 0;
                    }
                } else {
                    score--;
                }
            }
            new_best[next_idx] = max(new_best[next_idx], score);
        }
        for (int j = 0; j < 5; j++) {
            best[j] = new_best[j];
        }
    }

    int maks = best[0];
    for (int i = 0; i < 5; i++) {
        maks = max(maks, best[i] - 2 * i);
    }
    cout << maks << endl;
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
        auto strings = read_line<string>(n);
        sol(strings);
    }
}

// 4 4 12
// 3 6 2