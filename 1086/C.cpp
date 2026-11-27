#include"bits/stdc++.h"

using namespace std;

std::ostream& operator<< (std::ostream& out, const vector<int>& v) {
    out << "[ ";
    for (auto elem : v) {
        out << elem << " ";
    }
    out << "]";
    return out;
}

long double sol(vector<int> costs, vector<int> rewards) {
    long double total = 0;
    for (int i = costs.size()-1; i >= 0; i--) {
        auto cost = costs[i];
        auto reward = rewards[i];

        auto multiplier = 1.0L - (long double) cost / 100.0L;

        auto new_total = total * multiplier + (long double) reward;
        if (total < new_total) {
            total = new_total;
        }
    }
    return total;
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
        vector<int> costs;
        vector<int> rewards;
        for (int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            costs.push_back(b);
            rewards.push_back(a);
        }
        cout << setprecision(12) << sol(costs, rewards) << endl;
    }
}
