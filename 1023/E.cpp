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

const int LOG = 25;

void init(vector<vector<int>>& tree, int n) {
    for (int i = 0; i < n; i++) {
        tree.push_back(vector<int>(LOG, -1));
    }
}

void set_parent(vector<vector<int>>& tree, int vec, int parent) {
    tree[vec][0] = parent;
    for (int i = 1; i < LOG; i++) {
        if (tree[vec][i-1] == -1) {
            tree[vec][i] = -1;
            continue;
        }
        tree[vec][i] = tree[tree[vec][i-1]][i-1];
    }
}

void sol(int n, int k) {
    vector<vector<int>> tree;
    init(tree, n);

    ll total = 0;
    int last_i = -1;
    for (ll i = 1; i < n; i++) {
        set_parent(tree, i, i-1);
        total += (i * (i - 1)) / 2;
        if (total >= k) {
            last_i = i;
            break;
        }
    }
    if (total < k - 1) {
        cout << "NO" << endl;
        return;
    }
    for (ll i = last_i + 1; i < n; i++) {
        set_parent(tree, i, 0);
    }
    ll last_jump = -1;
    while (total > k + 1) {
        int start, stop;
        start = 1;
        stop = last_i-1;
        while (start < stop) {
            ll jump = (start + stop + 1) / 2;
            ll decrease = (jump * (jump-1)) / 2;
            if (total - decrease < k - 1) {
                stop = jump - 1;
            } else {
                start = jump;
            }
        }

        ll jump = start;
        ll decrease = (jump * (jump-1)) / 2;
        if (last_jump == 2) {
            jump = 2;
            decrease = 2;
        }
        last_jump = jump;
        total -= decrease;
        set_parent(tree, last_i, last_i - jump);
        last_i--;
    }
    cout << "YES" << endl;
    for (int i = 1; i < n; i++) {
        cout << i+1 << " " << tree[i][0]+1 << endl;
    }
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
        int n, k;
        cin >> n >> k;
        sol(n, k);
    }
}
