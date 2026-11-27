#include"bits/stdc++.h"

using namespace std;

#define ll long long

ll mod = 1e9+7;

ll add(ll a, ll b) {
    ll x = a + b;
    return x % mod;
}

ll mul(ll a, ll b) {
    ll x = a * b;
    return x % mod;
}

ll pow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0) return pow(mul(a, a), b / 2);
    return mul(a, pow(mul(a, a), b / 2));
}

ll div(ll a, ll b) {
    return mul(a, pow(b, mod-2));
}

std::ostream& operator<< (std::ostream& out, const vector<int>& v) {
    out << "[ ";
    for (auto elem : v) {
        out << elem << " ";
    }
    out << "]";
    return out;
}

bool sol(vector<int> a, vector<int> b, int k) {
    bool as_prev[a.size()];
    for (int i = 0; i < k; i++) {
        as_prev[i] = false;
    }
    for (int i = k; i < a.size(); i++) {
        as_prev[i] = false;
        if (a[i] != a[i-k]) {
            if (b[i] != a[i] && b[i] != -1) return false;
            b[i] = a[i];
            if (b[i-k] != a[i-k] && b[i-k] != -1) return false;
            b[i-k] = a[i-k];
        } else {
            as_prev[i] = true;
        }
    }
    for (int i = 0; i < a.size()-k; i++) {
        if (b[i] == -1) continue;
        if (as_prev[i+k]) {
            if (b[i+k] != -1 && b[i] != b[i+k]) return false;
            b[i+k] = b[i];
        }
    }
    for (int i = a.size()-1; i >= k; i--) {
        if (b[i] == -1) continue;
        if (as_prev[i]) {
            if (b[i-k] != -1 && b[i] != b[i-k]) return false;
            b[i-k] = b[i];
        }
    }

    unordered_map<int, int> map_a;
    unordered_map<int, int> map_b;
    for (int i = 0; i < k; i++) {
        map_a[a[i]]++;
        map_b[b[i]]++;
    }
 
    for (const auto & [key, value] : map_a) {
        int diff = value - map_b[key];
        if (diff < 0 || diff > map_b[-1]) {
            return false;
        }
        map_b[-1] -= diff;
    }
 
    return true;
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
        auto a = read_line<int>(n);
        auto b = read_line<int>(n);
        if (sol(a, b, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
