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

bool interactive = false;
int ans1, ans2, ans3;

int queries;
int max_q;

bool query(int a, int b, int extra) {
    queries++;
    a++; b++; extra++;
    if (interactive) {
        assert(a <= b);
        int k = b - a + 1;
        cout << "? ";
        if (extra > 0) {
            k += 1;
            cout << k << " " << extra;
        } else {
            cout << k;
        }
        for (int i = a; i <= b; i++) {
            cout << " " << i;
        }
        cout << endl;
        int response;
        cin >> response;
        if (response % 2 == k % 2) {
            return false;
        } {
            return true;
        }
    } else {
        if (a <= ans1 && ans3 <= b) return true;
        if (extra == ans1) return a <= ans2 && ans3 <= b;
        if (extra == ans3) return a <= ans1 && ans2 <= b;
        return false;
    }
}

void sol(int n) {
    queries = 0;
    int start, stop;
    start = 2;
    stop = 2 * n;
    while (start < stop) {
        int mid = (start + stop) / 2;
        if (query(0, mid, -1)) {
            stop = mid;
        } else {
            start = mid+1;
        }
    }

    int last = start;

    start = 0;
    stop = last - 2;
    while (start < stop) {
        int mid = (start + stop + 1) / 2;
        if (query(mid, last, -1)) {
            start = mid;
        } else {
            stop = mid-1;
        }
    }

    int first = start;

    start = first + 1;
    stop = last - 1;
    while (start < stop) {
        int mid = (start + stop) / 2;
        if (query(first, mid, last)) {
            stop = mid;
        } else {
            start = mid + 1;
        }
    }

    int middle = start;
    cout << "! " << first+1 << " " << middle+1 << " " << last+1 << endl;

    cerr << "total queries " << queries << endl; 
    max_q = max(max_q, queries);
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
        if (!interactive) {
            cin >> ans1 >> ans2 >> ans3;
        }
        sol(n);
    }
    cerr << "max " << max_q << endl;
}

// 1 2 3 4 5 6 7
// 1 2 1 3 1 2 3
