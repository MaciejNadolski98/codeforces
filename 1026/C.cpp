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

void sol(vector<int> ds, vector<pair<int, int>> limits) {
    int l = 0;
    int r = 0;
    for (int i = 0; i < ds.size(); i++) {
        if (ds[i] == 1) {
            l++;
            r++;
        } else if (ds[i] == -1) {
            r++;
        }
        l = max(l, limits[i].first);
        r = min(r, limits[i].second);
        if (r < l) {
            cout << -1 << endl;
            return;
        }
        limits[i] = make_pair(l, r);
    }

    vector<int> heights;
    heights.push_back(limits.back().first);
    for (int i = ds.size()-2; i >= 0; i--) {
        int prev = heights.back();
        if (prev <= limits[i].second) {
            heights.push_back(prev);
        } else {
            heights.push_back(prev-1);
        }
    }
    int prev = 0;
    reverse(heights.begin(), heights.end());
    cerr << "heights: " << heights << endl;
    cerr << "limits: " << limits << endl;
    for (auto x : heights) {
        cout << x - prev << " ";
        prev = x;
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
        auto ds = read_line<int>(n);
        vector<pair<int, int>> limits;
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            limits.push_back(make_pair(l, r));
        }

        sol(ds, limits);
    }
}
