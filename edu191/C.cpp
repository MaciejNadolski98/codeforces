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

int check(string s) {
    int count = 0;
    int pot = 0;
    for (auto c : s) {
        if (c == '(') {
            count++;
            pot++;
        } else {
            if (pot > 0) {
                count++;
                pot--;
            }
        }
    }
    return count - pot;
}

string without(string s, int idx) {
    string out = "";
    for (int i = 0; i < s.size(); i++) {
        if (i == idx) continue;
        out += s[i];
    }
    return out;
}

void sol(string s, int k) {
    int cost = check(s);
    string out = "";
    for (int i = 0; i < s.size(); i++) {
        // cerr << "s: " << s << ", i: " << i << " s without i: " << without(s, i) << endl;
        string tmp = without(s, i);
        // cerr << tmp << endl;
        int _cost = check(tmp);
        if (_cost < cost && k > 0) {
            s = tmp;
            i--;
            k--;
            cost = _cost;
            out += "1";
        } else {
            out += "0";
        }
    }
    cout << out << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        sol(s, k);
    }
}
