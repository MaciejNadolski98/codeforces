#include"bits/stdc++.h"

using namespace std;

long long sol(vector<long long> monsters, long long power, long long flips) {
    sort(monsters.begin(), monsters.end());
    for (long long monster : monsters) {
        if (monster > power) {
            return power;
        }
        long long diff = power - monster;
        long long inc = min(diff, flips);
        power = power + monster + inc;
        flips -= inc;
    }
    return power;
}

vector<long long> read_line(long long n) {
    vector<long long> ret;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        ret.push_back(x);
    }
    return ret;
}

int main() {
    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long n, power, flips;
        cin >> n >> power >> flips;
        vector<long long> monsters = read_line(n);
        cout << sol(monsters, power, flips) << endl;
    }
}
