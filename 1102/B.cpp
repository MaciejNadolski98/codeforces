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

void sol(vector<int> arr) {
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    for (int i = 0; i < arr.size()-2; i++) {
        if (arr[i] % arr[i+1] != arr[i+2]) {
            cout << "-1" << endl;
            return;
        }
    }
    cout << arr[0] << " " << arr[1] << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        ll n;
        cin >> n;
        if (n % 12 != 10) {
            cout << n % 12 << " " << n - n % 12 << endl;
        } else if (n == 10) {
            cout << -1 << endl;
        } else {
            cout << 22 << " " << n - 22 << endl;
        }
    }
}
