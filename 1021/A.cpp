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

const int N = 1e5 + 3;
bool sieve[N];

void sol(int n) {
    int prime;
    for (int i = n / 2; i > 0; i--) {
        if (sieve[i] == false) {
            prime = i;
            break;
        }
    }
    if (n == 2) prime = 2;
    if (n == 3) prime = 2;

    int last_x;
    for (int i = 0; i < n; i++) {
        last_x = i;
        int diff = (i + 1) / 2;
        int x;
        if (i % 2) {
            x = prime - diff;
        } else {
            x = prime + diff;
        }
        if (x < 1) {
            break;
        }
        last_x = x;
        cout << x << " ";
        if (i == n-1) {
            last_x = -1;
        }
    }
    if (last_x != -1) {
        for (int i = last_x + 1; i <= n; i++) {
            cout << i << " ";
        }
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
    for (int i = 2; i < N; i++) {
        if (!sieve[i]) {
            for (int j = 2*i; j < N; j+=i) {
                sieve[j] = true;
            }
        }
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        sol(n);
    }
}
