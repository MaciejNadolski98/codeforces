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

int cost_to_reach_pos(int n, vector<int> arr, int hand_size, int pos, int energy) {
    sort(arr.begin(), arr.begin() + pos - 1);
    int sum = arr[pos-1];
    for (int i = 0; i < pos - hand_size; i++) {
        sum += arr[i];
    }
    return sum;
}

int cost_to_cycle(int n, vector<int> arr, int hand_size, int pos, int energy) {
    int sum = arr[pos-1];
    arr.erase(arr.begin() + pos-1);
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - hand_size; i++) {
        sum += arr[i];
    }
    return sum;
}

int sol(int n, vector<int> arr, int hand_size, int pos, int energy) {
    energy -= cost_to_reach_pos(n, arr, hand_size, pos, energy);
    if (energy < 0) return 0;
    return 1 + energy / cost_to_cycle(n, arr, hand_size, pos, energy);
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
        int n, hand_size, pos, energy;
        cin >> n >> hand_size >> pos >> energy;
        vector<int> costs = read_line<int>(n);
        cout << sol(n, costs, hand_size, pos, energy) << endl;
    }
}
