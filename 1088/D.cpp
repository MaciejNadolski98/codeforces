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

// modint mod = 1e9+7;

// modint mod_add(modint a, modint b) {
//     modint x = a + b;
//     return x % mod;
// }

// modint mod_sub(modint a, modint b) {
//     return mod_add(a, mod - b);
// }

// modint mod_mul(modint a, modint b) {
//     modint x = a * b;
//     return x % mod;
// }

// modint mod_pow(modint a, modint b) {
//     if (b == 0) return 1;
//     if (b == 1) return a;
//     if (b % 2 == 0) return mod_pow(mod_mul(a, a), b / 2);
//     return mod_mul(a, mod_pow(mod_mul(a, a), b / 2));
// }

// modint mod_div(modint a, modint b) {
//     return mod_mul(a, mod_pow(b, mod-2));
// }

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

const int N = 100001;
const long long MOD = 1e9 + 7;
#define modint ModInt<MOD>

Combi<N, MOD> combi;

template <typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    out << "[ ";
    for (auto elem : v) {
        out << elem << " ";
    }
    out << "]";
    return out;
}

void sol(vector<modint> b) {
    vector<modint> a;
    for (int i = 0; i <= b.size(); i++) a.push_back(0);
    for (int i = b.size()-1; i >= 0; i--) {
        a[i] = a[i+1];
        if (b[i].get() == 0) continue;
        a[i] = a[i] + b[i];
        for (int j = 0; j < i; j++) {
            modint mp = combi.over(i+1, j+1);
            b[j] = b[j] - (b[i] * mp);
        }
    }
    a.pop_back();
    for (auto x : a) {
        cout << x.get() << " ";
    }
    cout << endl;
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
        auto arr = read_line<modint>(n);
        sol(arr);
    }
}
