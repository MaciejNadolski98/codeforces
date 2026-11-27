#include"bits/stdc++.h"

using namespace std;
#define ll long long


template <long long MOD> struct ModInt {
public:
    ModInt() : value(0) {}

    ModInt(long long value) : value(value % MOD) {
        assert(0 <= value);
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
        if (k > n || k < 0) return ModInt<MOD>(0);
        return this->fact(n) / (this->fact(k) * this->fact(n-k));
    }
private:
    ModInt<MOD> fact_[N+1];
};

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

#define fft_int ModInt<998244353>
fft_int base_root = fft_int(3) ^ 119;

fft_int mth_root(int m) {
    assert(__builtin_popcount(m) == 1);
    return base_root ^ ((1 << 23) / m);
}

vector<fft_int> fft(vector<fft_int> arr) {
    if (arr.size() == 1) return arr;

    vector<fft_int> evens(arr.size() / 2);
    vector<fft_int> odds(arr.size() / 2);
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            evens[i/2] = arr[i];
        } else {
            odds[i/2] = arr[i];
        }
    }

    auto evens_fft = fft(evens);
    auto odds_fft = fft(odds);

    auto root = mth_root(arr.size());

    vector<fft_int> out(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        if (i * 2 < arr.size()) {
            out[i] = evens_fft[i] + odds_fft[i] * (root ^ i);
        } else {
            int j = i - arr.size() / 2;
            out[i] = evens_fft[j] - odds_fft[j] * (root ^ j);
        }
    }

    return out;
}

vector<fft_int> expand(vector<fft_int>& arr, int size) {
    while (arr.size() < size) arr.emplace_back();
    return arr;
}

vector<fft_int> conv(vector<fft_int> a, vector<fft_int> b) {
    auto total_size = a.size() + b.size();
    int desired_size = 1;
    while (desired_size < max(a.size(), b.size())) desired_size <<= 1;

    auto a_ = expand(a, desired_size);
    auto b_ = expand(b, desired_size);

    auto a_fft = fft(a_);
    auto b_fft = fft(b_);

    vector<fft_int> c_fft;
    for (int i = 0; i < desired_size; i++) {
        c_fft.push_back(a_fft[i] * b_fft[i]);
    }
    auto c = fft(c_fft);
    for (int i = 0; i < desired_size; i++) {
        c[i] = c[i] / fft_int(desired_size);
    }
    reverse(c.begin()+1, c.end());
    while (c.size() >= total_size) c.pop_back();

    return c;
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

const int N = 2e5;
const int MOD = 998244353;

auto combi = Combi<N, MOD>();

void sol(vector<bool> bits, vector<int> queries) {
    vector<fft_int> a;
    vector<fft_int> b;
    for (ll i = -bits.size(); i <= (ll) bits.size(); i++) {
        if (i >= 0) a.push_back(combi.over(bits.size(), i));
        b.push_back(fft_int(i * i - abs(i) % 2) / fft_int(4));
    }
    reverse(a.begin(), a.end());
    auto c = conv(a, b);

    int cnt0 = 0;
    for (auto elem : bits) {
        if (!elem) cnt0++;
    }
    for (auto q : queries) {
        if (bits[q]) {
            cnt0++;
        } else {
            cnt0--;
        }
        int cnt1 = bits.size() - cnt0;
        int cnt = max(cnt0, cnt1);
        bits[q] = !bits[q];
        cout << c[2 * bits.size() - cnt] << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<bool> bits;
        for (auto c : s) {
            bits.push_back(c == '1');
        }
        auto queries = read_line<int>(q);
        for (int i = 0; i < q; i++) queries[i]--;

        sol(bits, queries);
    }
}
