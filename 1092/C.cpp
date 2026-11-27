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

inline int interval(int a, int b) {
    if (a < b) return interval(b, a);
    return (1 << a) - (1 << b);
}

inline bool interval_xor(int s, int a, int b) {
    return __builtin_popcount(interval(a, b) & s) % 2 == 1;
}

void sol1(int n, int s) {
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (interval_xor(s, a, b)) {
            cout << max(a, b) + 1 << " " << min(a, b) + 1 << endl;
        } else {
            cout << min(a, b) + 1 << " " << max(a, b) + 1 << endl;
        }
    }
}

int dfs(vector<vector<pair<int, bool>>>& graph, int vec, int parent, int target) {
    if (vec == target) return 0;

    for (auto p : graph[vec]) {
        int other; bool xor_;
        tie(other, xor_) = p;
        if (other == parent) continue;
        int ret = dfs(graph, other, vec, target);
        if (ret > -1) {
            return xor_ ? 1 - ret : ret;
        }
    }

    return -1;
}

int sol2(vector<vector<pair<int, bool>>>& graph) {
    int s = 0;
    for (int i = 0; i < graph.size()-1; i++) {
        int ret = dfs(graph, i, -1, i+1);
        s += ret << i;
    }

    return s;
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
    int t, q;
    cin >> t >> q;
    for (int i = 0; i < t; i++) {
        if (q == 1) {
            int n, s;
            cin >> n >> s;
            sol1(n, s-1);
        } else {
            int n;
            cin >> n;
            vector<vector<pair<int, bool>>> graph(n);
            for (int j = 0; j < n-1; j++) {
                int a, b;
                cin >> a >> b;
                bool xor_ = a > b;
                graph[a-1].push_back({b-1, xor_});
                graph[b-1].push_back({a-1, xor_});
            }
            cout << sol2(graph) + 1 << endl;
        }
    }
}

/*
-1
1      -> (2, 1), (3, 01), (4, 001)
01     -> (1, -1), (3, 1), (4, 01)
11     -> (3, 1), (4, 01)
001    -> (1, -01), (2, -1), (4, 1)
011    -> (1, -11), (4, 1)
101    -> (2, -1), (4, 1)
111    -> (4, 1)
0011   -> (1, -011), (2, -11)
0101   -> (1, -101), (3, -1)
0111   -> (1, -111),
1111*
00101  -> (1, -0101), (2, )
*/