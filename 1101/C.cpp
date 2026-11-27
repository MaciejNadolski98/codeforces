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

ll sol(string friends, ll tables, ll seats) {
    ll count = 0;
    ll ambiverts = 0;
    ll empty = tables;
    ll spots = 0;
    for (auto f : friends) {
        if (empty == 0 && spots == 0) break;
        if (f == 'A') {
            if (spots == 0) {
                empty--;
                spots += seats-1;
            } else {
                ambiverts++;
                spots--;
            }
            count++;
        } else if (f == 'I' && empty != 0) {
            empty--;
            count++;
            spots += seats - 1;
        } else if (f == 'E') {
            if (spots == 0) {
                if (ambiverts == 0) {
                    continue;
                } else {
                    ambiverts--;
                    empty--;
                    spots += seats;
                }
            }
            spots--;
            count++;
        }
        // cerr << "f = " << f << endl;
        // cerr << "spots: " << spots << " count: " << count << " empty: " << empty << endl;
    }
    return min((ll)count, tables * seats);
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, tables, seats;
        cin >> n >> tables >> seats;
        string friends;
        cin >> friends;
        cout << sol(friends, tables, seats) << endl;
    }
}
