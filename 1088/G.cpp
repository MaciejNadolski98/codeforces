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

bool sol(vector<long long> arr) {
    long long right_sum = 0;
    long long right_elems = arr.size();
    for (auto x : arr) {
        right_sum += x;
    }

    long long left_sum = 0;
    long long left_elems = 0;
    for (auto x : arr) {

        left_sum += x;
        right_sum -= x;

        right_elems--;
        left_elems++;

        if (right_elems * left_sum < right_sum * left_elems) {
            return true;
        }
    }

    long long avg = (2 * left_sum) / left_elems;
    if (avg * left_elems != left_sum * 2) return false;
    for (int i = 0; i < arr.size(); i++) {
        arr[i] *= 2;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == avg) continue;
        if (arr[i] + arr[i+1] == 2 * avg) i++;
        else return false;
    }

    return true;
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
        auto arr = read_line<long long>(n);
        if (sol(arr)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

// 0 1 1 - 0
// 1 0 1 - 1
// 1 1 0 - 2

// 0 0 1 - 0
// 0 1 0 - 1
// 1 0 0 - 2

// 0 1 1 1 - 0
// 1 0 1 1 - 1
// 1 1 0 1 - 2
// 1 1 1 0 - 3
// f = 4

// 0 0 1 1 - 0
// 1 0 0 1 - 2
// 1 1 0 0 - 0
// 0 1 1 0 - 2
// f = 2

// 0 1 0 1 - 1
// 1 0 1 0 - 3
// f = 2
