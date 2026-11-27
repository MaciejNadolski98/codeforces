#include"bits/stdc++.h"

using namespace std;
#define ll long long
#define lll __int128

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
        return this->fact(n) / (this->fact(k) * this->fact(n-k));
    }
private:
    ModInt<MOD> fact_[N+1];
};

const ll MOD_ = 1e9 + 7;
const ll MAX_N = 5e5 + 1;

#define mint ModInt<MOD_>

Combi<MAX_N, MOD_> combi;

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

mint sol(vector<ll> arr) {
    vector<int> stack;
    vector<tuple<int, int>> pairs(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        pairs[i] = make_tuple(1, 1);
    }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            stack.push_back(i);
        }
    }

    int count = 0;
    mint out = 1;
    while (!stack.empty()) {
        count++;
        int idx = stack.back();
        // cerr << "idx:" << idx << endl;
        stack.pop_back();
        int left, right;
        tie(left, right) = pairs[idx];
        // cerr << "left = " << left << ", right = " << right << endl;
        out = out * combi.over(left + right - 2, left - 1);
        int lidx = idx - left;
        int ridx = idx + right;
        if (lidx >= 0) {
            int new_right = left + right;
            int new_left = get<0>(pairs[lidx]);
            pairs[lidx] = make_tuple(new_left, new_right);
            if ((ll) new_right * (ll) new_left == arr[lidx]) {
                stack.push_back(lidx);
            } else if ((ll) new_right * (ll) new_left > arr[lidx]) {
                return mint(0);
            }
        }
        if (ridx < arr.size()) {
            int new_left = left + right;
            int new_right = get<1>(pairs[ridx]);
            pairs[ridx] = make_tuple(new_left, new_right);
            if ((ll) new_right * (ll) new_left == arr[ridx]) {
                stack.push_back(ridx);
            } else if ((ll) new_right * (ll) new_left > arr[ridx]) {
                return mint(0);
            }
        }
    }
    if (count != arr.size()) return mint(0);
    return out;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        auto arr = read_line<ll>(n);
        cout << sol(arr) << endl;
    }
}
