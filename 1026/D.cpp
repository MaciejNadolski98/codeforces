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

ll sol(vector<ll> batteries, vector<vector<pair<int, ll>>> graph) {
    priority_queue<pair<ll, int>> pq;
    vector<bool> visited = vector<bool>(graph.size());
    ll count = batteries[0];

    for (auto x : graph[0]) {
        pq.push(make_pair(-x.second, x.first));
    }

    ll last_weight = 0;
    while (visited[graph.size()-1] == false) {
        if (pq.empty()) return -1;
        pair<ll, int> edge = pq.top();
        // cerr << "edge " << edge << endl;
        pq.pop();
        last_weight = -edge.first;
        if (last_weight > count) return -1;
        if (visited[edge.second]) continue;
        visited[edge.second] = true;
        count += batteries[edge.second];
        for (auto x : graph[edge.second]) {
            pq.push(make_pair(-x.second, x.first));
        }
    }

    return last_weight;
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
        auto batteries = read_line<ll>(n);
        vector<vector<pair<int, ll>>> graph;
        for (int j = 0; j < n; j++) graph.emplace_back();
        for (int j = 0; j < m; j++) {
            int a, b, w;
            cin >> a >> b >> w;
            graph[a-1].push_back(make_pair(b-1, w));
            graph[b-1].push_back(make_pair(a-1, w));
        }

        cout << sol(batteries, graph) << endl;
    }
}
