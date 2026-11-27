#include"bits/stdc++.h"

using namespace std;

void sol(vector<long long> arr) {
    for (int i=0; i < arr.size(); i++) {
        int large = 0;
        int small = 0;
        for (int j=i+1; j < arr.size(); j++) {
            if (arr[j] > arr[i]) large++;
            if (arr[j] < arr[i]) small++;
        }
        cout << max(large, small) << " ";
    }
    cout << endl;
}

vector<long long> read_line(long long n) {
    vector<long long> ret;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        ret.push_back(x);
    }
    return ret;
}

int main() {
    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long n;
        cin >> n;
        vector<long long> arr = read_line(n);
        sol(arr);
    }
}
