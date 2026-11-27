#include"bits/stdc++.h"

using namespace std;


template <typename T1, typename T2>
std::ostream& operator<< (std::ostream& out, pair<T1, T2> p) {
    out << "(" << p.first << ", " << p.second << ")";
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

bool interactive = true;
vector<int> ans;

int query(int l, int r) {
    if (interactive) {
        cout << "? " << l+1 << " " << r+1 << endl;
        int x;
        cin >> x;
        return x;
    } else {
        int count = 0;
        for (int i = l; i <= r; i++) {
            if (ans[i] == 1) {
                count += 1;
            }
        }
        int n = r - l + 1;
        int ret = n / gcd(count, n);
        return ret;
    }
}

void populate(vector<vector<pair<int, bool>>>& graph, int jump) {
    int prev = query(0, jump);
    for (int i = 1 ; i + jump < graph.size(); i++) {
        int curr = query(i, i + jump);
        bool switch_bit = true;
        if (prev == curr) switch_bit = false;
        graph[i-1].push_back(make_pair(i+jump, switch_bit));
        graph[i+jump].push_back(make_pair(i-1, switch_bit));

        prev = curr;
    }
}

void dfs(vector<vector<pair<int, bool>>>& graph, int vertex, vector<bool>& visited, vector<bool>& bits, bool bit) {
    visited[vertex] = true;
    bits[vertex] = bit;
    for (auto edge : graph[vertex]) {
        int other = edge.first;
        bool switch_bit = edge.second;
        if (visited[other]) continue;
        bool next_bit = bit;
        if (switch_bit) next_bit = !next_bit;
        dfs(graph, other, visited, bits, next_bit);
    }
}

void respond(vector<bool> res) {
    cout << "! ";
    for (auto bit : res) {
        if (bit) cout << "1";
        else cout << "0";
    }
    cout << endl;

    int ret;
    cin >> ret;
    if (ret == 1) return;
    cout << "! ";
    for (auto bit : res) {
        if (bit) cout << "0";
        else cout << "1";
    }
    cout << endl;
}

void sol(int n) {
    if (n == 2) {
        vector<bool> res;
        res.push_back(false);
        if (query(0, 1) == 2) {
            res.push_back(true);
        } else {
            res.push_back(false);
        }
        respond(res);
        return;
    }
    if (n == 3) {
        vector<bool> res;
        res.push_back(0);
        if (query(0, 1) == 2) {
            res.push_back(true);
        } else {
            res.push_back(false);
        }
        if (query(1, 2) == 2) {
            res.push_back(!res.back());
        } else {
            res.push_back(res.back());
        }
        respond(res);
        return;
    }
    vector<vector<pair<int, bool>>> graph;
    for (int i = 0; i < n; i++) {
        graph.emplace_back();
    }

    int jump = n / 2;
    if (jump % 2 == 0) jump -= 1;

    populate(graph, jump);
    populate(graph, jump + 2);
    int switch_bit = true;
    if (query(0, 1) == 1) switch_bit = false;
    graph[0].push_back(make_pair(1, switch_bit));
    graph[1].push_back(make_pair(0, switch_bit));
    vector<bool> visited;
    vector<bool> bits;
    for (int i = 0; i < n; i++) {
        visited.push_back(false);
        bits.push_back(false);
    }

    dfs(graph, 0, visited, bits, false);
    respond(bits);
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
        if (!interactive) {
            ans = read_line<int>(n);
        }
        sol(n);
    }
}
