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

vector<vector<int>> tree;

struct component {
    int start;
    int stop;
    vector<int> A;
    vector<int> B;
};

component merge(component A, component B) {
    solve(A.A, B.A);
    solve(A.A, B.B);
    solve(A.B, B.A);
    solve(A.B, B.B);
    component out;
    out.start = A.start;
    out.stop = B.stop;
}

vector<int> query(vector<int> A, vector<int> B) {

}

int sol(int n) {
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        sol(n);
    }
}
