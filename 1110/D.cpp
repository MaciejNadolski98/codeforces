#include"bits/stdc++.h"

using namespace std;
#define ll long long
#define lll __int128

struct res {
    bool pos;
    int a;
    int b;
};

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

void sol(int n, vector<res> arr) {
    vector<int> positives(n);
    vector<int> negatives(n);
    vector<int> idxs;
    vector<int> out(n);
    vector<vector<pair<int, bool>>> graph(n);
    vector<bool> added(n);
    int a = n;
    for (auto x : arr) {
        if (x.pos) {
            positives[x.a]++;
            positives[x.b]++;
        } else {
            negatives[x.a]++;
            negatives[x.b]++;
        }
        graph[x.a].push_back(make_pair(x.b, x.pos));
        graph[x.b].push_back(make_pair(x.a, x.pos));
    }
    // cerr << "graph: " << graph << endl;
    // cerr << "positives: " << positives << endl;
    // cerr << "negatives: " << negatives << endl;

    for (int i = 0; i < n; i++) {
        if (positives[i] == 0 || negatives[i] == 0) {
            idxs.push_back(i);
            added[i] = true;
        }
    }

    // cerr << "idxs: " << idxs << endl;

    while (!idxs.empty()) {
        int curr = idxs.back();
        // cerr << "curr: " << curr << endl;
        idxs.pop_back();
        if (positives[curr] == 0) {
            out[curr] = -a;
        } else {
            out[curr] = a;
        }
        a--;

        for (auto x : graph[curr]) {
            bool pos = x.second;
            int other = x.first;
            if (pos) {
                positives[other]--;
            } else {
                negatives[other]--;
            }
            if ((positives[other] == 0 || negatives[other] == 0) && !added[other]) {
                added[other] = true;
                idxs.push_back(other);
            }
        }
    }
    if (a == 0) {
        cout << "YES" << endl;
        for (auto x : out) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<res> arr;
        for (int j = 0; j < m; j++) {
            int o, a, b;
            cin >> o >> a >> b;
            res x;
            x.pos = o == 1;
            x.a = a-1;
            x.b = b-1;
            arr.push_back(x);
        }
        sol(n, arr);
    }
}
