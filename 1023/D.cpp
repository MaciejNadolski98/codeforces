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

const int N = 1e6;
int parents[N];

tuple<int, int> dfs(vector<vector<int>>& tree, int vec, int parent, vector<bool>& ignore) {
    parents[vec] = parent;
    int best_v = vec, best_depth = 0;
    for (auto other : tree[vec]) {
        if (other == parent || ignore[other]) continue;
        int v, depth;
        tie(v, depth) = dfs(tree, other, vec, ignore);
        if (depth > best_depth || (depth == best_depth && v > best_v)) {
            best_depth = depth;
            best_v = v;
        }
    }

    return tuple(best_v, best_depth+1);
}

vector<tuple<int, int, int>> rec_sol(vector<vector<int>>& tree, int root, vector<bool>& ignore) {
    int one, two, depth;
    tie(one, depth) = dfs(tree, root, -1, ignore);
    tie(two, depth) = dfs(tree, one, -1, ignore);

    auto tup = tuple(depth, max(one, two), min(one, two));
    vector<tuple<int, int, int>> ret;
    ret.push_back(tup);
    int vec = two;
    int prev = -1;
    while(vec != one) {
        ignore[vec] = true;
        for (auto other : tree[vec]) {
            if (other == parents[vec] || other == prev || ignore[other]) continue;
            for (auto tup : rec_sol(tree, other, ignore)) {
                ret.push_back(tup);
            }
        }

        prev = vec;
        vec = parents[vec];
    }

    return ret;
}

void sol(vector<vector<int>> tree) {
    vector<bool> ignore = vector<bool>(tree.size());
    auto ret = rec_sol(tree, 0, ignore);
    sort(ret.begin(), ret.end(), greater<>());
    for (auto elem : ret) {
        int a, b, c;
        tie(a, b, c) = elem;
        cout << a << " " << b + 1 << " " << c + 1 << " "; 
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
        vector<vector<int>> tree = vector<vector<int>>(n);
        for (int j = 0; j < n-1; j++) {
            int a, b;
            cin >> a >> b;
            tree[a-1].push_back(b-1);
            tree[b-1].push_back(a-1);
        }

        sol(tree);
    }
}


