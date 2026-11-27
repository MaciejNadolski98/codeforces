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

struct node {
    int v;
    int mini;
};

const int N = 1e6;
node tree[N];

void add(int idx, int start, int stop, int interval_start, int interval_stop, int delta) {
    // cerr << "idx " << idx << " start, stop " << start << " " << stop << " interval " << interval_start << " " << interval_stop << endl;
    if (idx == 0) exit(0);
    if (start > interval_stop || stop < interval_start) {
        return;
    }
    if (interval_start <= start && stop <= interval_stop) {
        tree[idx].v += delta;
        tree[idx].mini += delta;
        return;
    }

    add(idx * 2, start, (start + stop) / 2, interval_start, interval_stop, delta);
    add(idx * 2 + 1, (start + stop) / 2 + 1, stop, interval_start, interval_stop, delta);
    tree[idx].mini = min(tree[idx * 2].mini, tree[idx * 2 + 1].mini) + tree[idx].v;
}

int query(int idx, int start, int stop, int interval_start, int interval_stop) {
    if (start > interval_stop || stop < interval_start) {
        return 1e9;
    }
    if (interval_start <= start && stop <= interval_stop) {
        return tree[idx].mini;
    }

    int left = query(idx * 2, start, (start + stop) / 2, interval_start, interval_stop);
    int right = query(idx * 2 + 1, (start + stop) / 2 + 1, stop, interval_start, interval_stop);
    return tree[idx].v + min(left, right);
}

void sol(vector<int> arr) {
    vector<bool> present(arr.size()+1);
    int n = 1;
    while (n <= arr.size()) n <<= 1;
    for (int i = 0; i <= 2 * n; i++) {
        tree[i].v = 0;
        tree[i].mini = 0;
    }

    int ans = 0;
    unordered_map<int, int> elems;
    for (auto x : arr) {
        if (x < ans && !present[x]) {
            present[x] = true;
            add(1, 0, n-1, 0, x, 1);
        } else {
            elems[x] += 1;
            x = (x - 1) / 2;
            if (x >= n) x = n-1;
            add(1, 0, n-1, 0, x, 1);
        }
        while (true) {
            if (elems[ans] != 0) {
                present[ans] = true;
                if (query(1, 0, n-1, 0, (ans - 1) / 2) > 0) {
                    add(1, 0, n-1, 0, (ans - 1) / 2, -1);
                    ans++;
                } else {
                    break;
                }
            } else {
                if (query(1, 0, n-1, 0, ans) > 0) {
                    add(1, 0, n-1, 0, ans, -1);
                    ans++;
                } else {
                    break;
                }
            }
        }
        cout << ans << " ";
    }
    cout << endl;
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
