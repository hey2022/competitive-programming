#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
#define ff = first;
#define ss = second;

template <class T, int SZ>
using arr = array<T, SZ>;

template <class T>
using vec = vector<T>;
using vb = vec<bool>;
using vi = vec<int>;
using vl = vec<ll>;
using vd = vec<db>;
using vp = vec<pi>;

#define dbg(x) \
    cerr << "Line(" << __LINE__ << "): " << #x << " = " << (x) << "\n";
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)

void set_io(str name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// #define int long long

int N = 5000000;
signed main() {
    set_io();
    vb is_prime(N + 1, true);
    vi prime_divisior(N + 1, 1), prime_factors(N + 1, 0);
    is_prime[0] = is_prime[1] = false;
    FOR(i, 2, N + 1) {
        if (is_prime[i] && (ll)i * i <= N) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
                prime_divisior[j] = i;
            }
        }
    }
    FOR(i, 2, N + 1) {
        prime_factors[i] = prime_factors[i / prime_divisior[i]] + 1;
    }
    FOR(i, 0, N + 1) { prime_factors[i] += prime_factors[i - 1]; }
    int t;
    cin >> t;
    FOR(i, 0, t) {
        int a, b;
        cin >> a >> b;
        cout << prime_factors[a] - prime_factors[b] << "\n";
    }
}
