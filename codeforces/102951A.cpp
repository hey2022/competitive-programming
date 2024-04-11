#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using pb = pair<bool, bool>;
using ps = pair<str, str>;

template <typename T, int Size>
using arr = array<T, Size>;
template <typename T>
using vec = vector<T>;

using vi = vec<int>;
using vl = vec<ll>;
using vd = vec<db>;
using vb = vec<bool>;
using vs = vec<str>;

using vpi = vec<pi>;
using vpl = vec<pl>;
using vpd = vec<pd>;
using vpb = vec<pb>;
using vps = vec<ps>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define F0R(i, b) FOR(i, 0, b)
#define F0RE(i, b) FORE(i, 0, b)
#define LOOP(a) F0R(_, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define ROFE(i, a, b) for (int i = (b); i >= (a); i--)
#define R0F(i, b) ROF(i, 0, b)
#define R0FE(i, b) ROFE(i, 0, b)
#define each(e, c) for (auto& e : c)

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)x.size()

#define pb push_back
#define epb emplace_back
#define ff first
#define ss second

const int MOD = 1e9 + 7;
const db PI = acos((db)-1);

#ifdef LOCAL
#define DBG_MACRO_NO_WARNING
#include "dbg.h"
#else
#define dbg(...) __VA_ARGS__
#endif

#define readln(x) getline(cin >> ws, x);

void read() {}
template <typename Arg, typename... Args>
void read(Arg& arg, Args&... args) {
    cin >> arg;
    read(args...);
}

void readc() {}
template <typename Arg, typename... Args>
void readc(Arg& arg, Args&... args) {
    each(e, arg) cin >> e;
    readc(args...);
}

void print(const str& separator) { (void)separator; }
template <typename Arg, typename... Args>
void print(const str& separator, Arg&& arg, Args&&... args) {
    cout << arg << separator;
    print(separator, args...);
}

void printc(const str& separator) { (void)separator; }
template <typename Arg, typename... Args>
void printc(const str& separator, Arg&& arg, Args&&... args) {
    each(e, arg) cout << e << separator;
    if (separator != "\n") cout << "\n";
    printc(separator, args...);
}

void set_io(str name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// #define int ll

int sq_dist(pi a, pi b) {
    int dx = a.ff - b.ff, dy = a.ss - b.ss;
    return dx * dx + dy * dy;
}

signed main() {
    set_io();
    int n;
    read(n);
    vpi vp(n);
    each(p, vp) read(p.ff);
    each(p, vp) read(p.ss);
    int mx_sq = 0;
    F0R(i, n) FOR(j, i + 1, n) mx_sq = max(mx_sq, sq_dist(vp[i], vp[j]));
    cout << mx_sq;
}
