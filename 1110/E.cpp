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

ll total = 0;

int dfs(vector<vector<int>> &graph, int idx, int parent) {
    int count = 0;
    bool odd = graph[idx].size() % 2 == 1;
    for (auto other : graph[idx]) {
        if (other == parent) continue;
        if (odd) {
            ll tmp = dfs(graph, other, idx);
            total += (tmp * (tmp + 1)) / (ll) 2;
        } else {
            count += dfs(graph, other, idx);
        }
    }

    if (odd) return 1;
    return count;
}

ll sol(vector<vector<int>> graph) {
    total = 0;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i].size() == 1) {
            dfs(graph, i, -1);
            return total;
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<vector<int>> graph(n);
        for (int j = 0; j < n-1; j++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cout << sol(graph) << endl;
    }
}
