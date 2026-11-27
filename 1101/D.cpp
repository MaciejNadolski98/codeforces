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

int remaining(int a, int b) {
    if (a != 1 && b != 1) return 1;
    if (a != 2 && b != 2) return 2;
    if (a != 3 && b != 3) return 3;
    return -1;
}

bool move_all(int icing, int from, int to, vector<tuple<int, int, int>> &out, vector<int> &arr) {
    if (icing == -1) return true;
    if (arr[icing] == 0) {
        if (!move_all(icing-1, from, remaining(from, to), out, arr)) {
            return false;
        }
        out.push_back(make_tuple(icing, from, to));
        return move_all(icing-1, remaining(from, to), to, out, arr);
    }
    int to_move = icing - arr[icing] - 1;
    if (to_move < -1) return false;
    if (to_move == -1) {
        out.push_back(make_tuple(icing, from, to));
        return move_all(icing-1, from, to, out, arr);
    }

    if (!move_all(to_move, from, remaining(from, to), out, arr)) {
        return false;
    }
    out.push_back(make_tuple(icing, from, to));
    move_all(to_move, remaining(from, to), from, out, arr);
    return move_all(icing-1, from, to, out, arr);
}

void sol(vector<int> arr) {
    vector<tuple<int, int, int>> out;
    if (!move_all(arr.size()-1, 1, 3, out, arr)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << out.size() << endl;
        for (auto x : out) {
            int a, b, c;
            tie(a, b, c) = x;
            cout << a+1 << " " << b << " " << c << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        auto arr = read_line<int>(n);
        sol(arr);
    }
}
