#include"bits/stdc++.h"

using namespace std;

template <long long MOD> struct ModInt {
public:
    ModInt() : value(0) {}

    ModInt(long long value) : value(value) {
        assert(0 <= value && value < MOD);
    }

    long long get() {
        return this->value;
    }

    ModInt<MOD> operator+(ModInt<MOD> other) {
        return ModInt<MOD>((this->value + other.value) % MOD);
    }

    ModInt<MOD> operator-() {
        if (this->value == 0) return ModInt<MOD>(0);
        return ModInt<MOD>(MOD - this->value);
    }

    ModInt<MOD> operator-(ModInt<MOD> other) {
        return *this + (-other);
    }

    ModInt<MOD> operator*(ModInt<MOD> other) {
        return ModInt<MOD>((this->value * other.value) % MOD);
    }

    ModInt<MOD> operator^(long long other) {
        if (other == 0) return ModInt<MOD>(1);
        if (other == 1) return ModInt<MOD>(this->value);
        auto ret = (*this * *this) ^ (other / 2);
        if (other % 2 == 0) return ret;
        return ret * *this;
    }

    ModInt<MOD> operator/(ModInt<MOD> other) {
        return *this * (other ^ (MOD - 2));
    }

    friend ostream& operator<<(ostream& out, ModInt<MOD> x) {
        return out << x.value;
    }

    friend istream& operator>>(istream& in, ModInt<MOD>& x) {
        return in >> x.value;
    }
private:
    long long value;
};

template <int N, long long MOD>
struct Combi {
public:
    Combi() {
        fact_[0] = ModInt<MOD>(1);
        for (int i = 1; i <= N; i++) {
            fact_[i] = fact_[i-1] * ModInt<MOD>(i);
        }
    }

    ModInt<MOD> fact(int n) {
        return this->fact_[n];
    }

    ModInt<MOD> over(int n, int k) {
        if (k > n) return ModInt<MOD>(0);
        return this->fact(n) / (this->fact(k) * this->fact(n-k));
    }
private:
    ModInt<MOD> fact_[N+1];
};

const long long MOD = 676767677;
const int N = 2e6;
#define modint ModInt<MOD>

Combi<N, MOD> combi;

std::ostream& operator<< (std::ostream& out, const vector<int>& v) {
    out << "[ ";
    for (auto elem : v) {
        out << elem << " ";
    }
    out << "]";
    return out;
}

struct Data {
public:
    int depth;
    int leq;
    int geq;

    Data() {}
};

Data arr[N];

void fill_data(int depth, int left, int right, int n) {
    int mid = (left + right) / 2;
    arr[mid - 1].depth = depth;
    arr[mid - 1].leq = mid-left;
    arr[mid - 1].geq = right-mid;

    if (left == 1) arr[mid-1].leq = -1;
    if (right == n) arr[mid-1].geq = -1;

    if (left < mid) fill_data(depth+1, left, mid-1, n);
    if (right > mid) fill_data(depth+1, mid+1, right, n);
}

modint sol(int n, int m) {
    fill_data(1, 1, n, n);
    modint total = modint(0);
    for (int i = 0; i < n; i++) {
        auto data = arr[i];
        int spots = n + m - 1;
        int choose = m - 1;
        modint count_all = combi.over(spots, choose);
        modint exclude_left, exclude_right, exclude_both;
        if (data.leq >= 0) exclude_left = combi.over(spots - data.leq - 1, choose);
        if (data.geq >= 0) exclude_right = combi.over(spots - data.geq - 1, choose);
        if (data.leq >= 0 && data.geq >= 0) exclude_both = combi.over(spots - data.leq - data.geq - 2, choose);
        modint count = count_all - exclude_left - exclude_right + exclude_both;
        total = total + count * modint(data.depth);
    }

    return total;
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
        int n, m;
        cin >> n >> m;
        cout << sol(n, m) << endl;
    }
}


