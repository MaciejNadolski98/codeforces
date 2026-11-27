
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