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

bool sol(string s) {
    int count = 0;
    for (int i = 1; i < s.size()-1; i++) {
        if (s[i] == '(') count++;
        else count--;
        if (count < 0) return true;
    }
    return false;
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
        string s;
        cin >> s;
        if (sol(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}


