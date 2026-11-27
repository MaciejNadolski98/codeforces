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

void sol(int n, vector<int> teachers, vector<int> queries) {
    sort(teachers.begin(), teachers.end());
    teachers.push_back(n+1);
    cerr << "teachers: " << teachers << endl;
    for (auto q: queries) {
        int start = 0;
        int stop = teachers.size()-1;
        while (start < stop) {
            int mid = (start + stop) / 2;
            if (teachers[mid] > q) {
                stop = mid;
            } else {
                start = mid + 1;
            }
        }
        cerr << "query: " << q << ", start: " << start << endl;
        int ans;
        if (start == 0) {
            ans = teachers[0]-1;
        } else if (start == teachers.size()-1) {
            ans = n - teachers[start-1];
        } else {
            ans = (teachers[start] - teachers[start-1]) / 2;
        }
        cout << ans << endl;
    }
}



int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int t, q;
        cin >> t >> q;
        auto teachers = read_line<int>(t);
        auto queries = read_line<int>(q);
        sol(n, teachers, queries);
    }
}
