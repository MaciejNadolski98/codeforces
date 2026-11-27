#include"bits/stdc++.h"

using namespace std;

bool interactive = false;
bool failed = false;
int ans;

std::ostream& operator<< (std::ostream& out, const vector<int>& v) {
    out << "[ ";
    for (auto elem : v) {
        out << elem << " ";
    }
    out << "]";
    return out;
}

template <typename T>
bool contains(vector<T> v, T elem) {
    for (auto x : v) if (x == elem) return true;
    return false;
}

void sol(int n) {
    int guesses = 1;
    int c = n;
    while (c > 1) {
        guesses++;
        c /= 3;
    }
    cout << guesses << endl;
}

int query(vector<int> a, vector<int> b) {
    assert(a.size() == b.size());
    if (interactive) {
        cout << a.size() + b.size();
        for (int x : a) cout << " " << x;
        for (int x : b) cout << " " << x;
        char res;
        cin >> res;
        if (res == 'L') return 0;
        if (res == 'R') return 1;
        if (res == 'N') return 2;
        return -1;
    }
    if (!failed && rand() % 10 == 0) {
        failed = true;
        return -1;
    }
    if (contains(a, ans)) return 0;
    if (contains(b, ans)) return 1;
    return 2;
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
            cin >> ans;
        }
    }
}


