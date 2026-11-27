#include"bits/stdc++.h"

using namespace std;
#define ll long long
#define lll __int128

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

const ll MOD = 998244353;
#define mint ModInt<MOD>

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

struct req {
    lll value;
    lll modulo;
};

struct egcd {
    lll gcd;
    lll a;
    lll b;
};

egcd _egcd(lll x, lll y) {
    if (x == 0) {
        return egcd { .gcd=y, .a=0, .b=1 };
    } else {
        auto r = _egcd(y % x, x);
        lll tmp = r.a;
        r.a = r.b - (y / x) * r.a;
        r.b = tmp;
        return r;
    }
}

const lll inf = (lll) 1e18 * (lll) 10;
const req impossible = req { .value=-1, .modulo=-1 };

req combine(req a, req b) {
    if (a.modulo < b.modulo) return combine(b, a);
    if (b.modulo == -1) {
        if (a.modulo == -1) {
            if (a.value == b.value) {
                return a;
            } else {
                return impossible;
            }
        } else {
            if (b.value % a.modulo == a.value) return b;
            else return impossible;
        }
    }
    auto egcd1 = _egcd(a.modulo, b.modulo);
    auto gcd = egcd1.gcd;
    auto r1 = a.value % gcd;
    auto r2 = b.value % gcd;
    if (r1 != r2) return impossible;
    a.modulo /= gcd;
    a.value %= a.modulo;

    auto egcd = _egcd(a.modulo, b.modulo);
    auto m1 = egcd.a;
    auto m2 = egcd.b;

    auto x = a.value * m2 * b.modulo + b.value * m1 * a.modulo;
    auto new_modulo = a.modulo * b.modulo;
    if (new_modulo > inf) {
        return req { .value = x, .modulo = -1 };
    } else {
        return req { .value = x, .modulo = new_modulo };
    }
}

bool sat(req a, ll x) {
    if (a.value == -1) return false;
    if (a.modulo == -1) {
        if (x == a.value) {
            return true;
        } else {
            return false;
        }
    }
    if (x % a.modulo == a.value) {
        return true;
    }
    return false;
}

struct dupa {
    vector<int> indices;
    vector<req> reqs;
};

const int N = 5e5+1;
req reqs[N];
vector<int> children[N];
int lengths[N];
lll times[N];
dupa* dupas[N];

void dfs(int root, ll time, req r) {
    times[root] = time;
    reqs[root] = r;
    for (int i = 0; i < children[root].size(); i++) {
        int child = children[root][i];
        ll length = lengths[child];
        ll size = children[root].size();
        ll value = i - (time % size);
        if (value < 0) value += size;
        req new_r = req { .value = value, .modulo = size };
        dfs(child, time+lengths[child], combine(r, new_r));
    }
}
int dfs2(int root) {
    int best = -1;
    int id = -1;
    int total = 1;
    for (int i = 0; i < children[root].size(); i++) {
        int child = children[root][i];
        int x = dfs2(child);
        total += x;
        if (x > best) {
            best = x;
            id = child;
        }
    }

    if (best == -1) {
        vector<int> indices = { root };
        vector<req> _reqs = { reqs[root] };
        dupas[root] = new dupa { .indices=indices, .reqs=_reqs };
    } else {
        dupas[root] = dupas[id];
        dupas[root]->indices.push_back(root);
        dupas[root]->reqs.push_back(reqs[root]);
    }
    return total;
}

int dfs3(int root, ll q) {
    if (children[root].size() == 0) return root;
    int start = 0;
    int stop = dupas[root]->indices.size()-1;
    while (start < stop) {
        int mid = (start + stop) / 2;
        if (sat(dupas[root]->reqs[mid], q)) {
            stop = mid;
        } else {
            start = mid + 1;
        }
    }
    int child = dupas[root]->indices[start];
    if (children[child].size() == 0) return child;
    int next = children[child][(q + times[child]) % children[child].size()];
    return dfs3(next, q);
}

void sol(int n, vector<int> &parents, vector<ll> &queries) {
    for (int i = 0; i < n; i++) children[i].clear();
    for (int i = 1; i < n; i++) {
        children[parents[i]].push_back(i);
    }

    dfs(0, 0, req {.value=0, .modulo=1});
    if (n < 30) {
        for (auto q : queries) {
            for (int i = 0; i < n; i++) {
                if (children[i].size() != 0) continue;
                if (sat(reqs[i], q)) {
                    cout << i+1 << " ";
                    break;
                }
            }
        }
        cout << endl;
    } else {
        dfs2(0);

        for (auto q : queries) {
            cout << dfs3(0, q) + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, q;
        cin >> n >> q;

        int tmp;
        vector<int> parents(1);
        for (int j = 0; j < n-1; j++) {
            cin >> tmp;
            parents.push_back(tmp);
        }
        for (int j = 1; j < n; j++) {
            cin >> lengths[j];
        }
        auto queries = read_line<ll>(q);
        for (int i = 0; i < n; i++) {
            parents[i]--;
        }
        sol(n, parents, queries);
    }
}
