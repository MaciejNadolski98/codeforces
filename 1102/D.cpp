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

tuple<ll, ll, ll> f(int k) {
    if (k == 0) {
        return make_tuple(1, 1, 0);
    }
    ll a, b, c;
    tie(a, b, c) = f(k-1);
    return make_tuple(a + c, b + c, a + b - 1);
}

ll score(string s) {
    ll x = 0, y = 0;
    for (auto c : s) {
        if (c == '0') x++;
        else y++;
    }
    return x * y;
}

void sol(string a, string b, int k) {
    ll a_count, b_count, c_count;
    tie(a_count, b_count, c_count) = f(k);
    string c;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) c.push_back('0');
        else c.push_back('1');
    }
    ll a_score = score(a);
    ll b_score = score(b);
    ll c_score = score(c);
    cout << a_score * a_count + b_score * b_count + c_score * c_count << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;
        sol(a, b, k);
    }
}
