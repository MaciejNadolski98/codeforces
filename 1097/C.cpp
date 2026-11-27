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

bool sol(string s1, string s2) {
    int count = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '(') count++;
        else count--;
        if (s2[i] == '(') count++;
        else count--;
        if (i % 2 == 0 && count < 2) return false;
        if (count < 0) return false; 
    }
    if (count == 0) return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        if(sol(s1, s2)) {
            cout <<"YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
