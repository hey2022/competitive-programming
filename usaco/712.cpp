#include <bits/stdc++.h>

#include <iterator>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
using pb = pair<bool, bool>;
using pc = pair<char, char>;
using ps = pair<str, str>;

template <typename T, int Size>
using arr = array<T, Size>;
template <typename T>
using vec = vector<T>;

using vi = vec<int>;
using vl = vec<ll>;
using vd = vec<db>;
using vb = vec<bool>;
using vc = vec<char>;
using vs = vec<str>;

using vvi = vec<vec<int>>;
using vvl = vec<vec<ll>>;
using vvd = vec<vec<db>>;
using vvb = vec<vec<bool>>;
using vvc = vec<vec<char>>;
using vvs = vec<vec<str>>;

using vpi = vec<pi>;
using vpl = vec<pl>;
using vpd = vec<pd>;
using vpb = vec<pb>;
using vpc = vec<pc>;
using vps = vec<ps>;

#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORE(i, a, b) for (auto i = (a); i <= (b); i++)
#define F0R(i, b) FOR(i, 0, b)
#define F0RE(i, b) FORE(i, 0, b)
#define LOOP(a) F0R(_, a)
#define ROF(i, a, b) for (auto i = (b)-1; i >= (a); i--)
#define ROFE(i, a, b) for (auto i = (b); i >= (a); i--)
#define R0F(i, b) ROF(i, 0, b)
#define R0FE(i, b) ROFE(i, 0, b)

#define each(e, c) for (auto& e : c)
#define ceach(e, c) for (const auto& e : c)
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)

template <typename T>
int sz(const T& c) {
    return (int)c.size();
}

template <typename T>
int last(const T& c) {
    return sz(c) - 1;
}

template <typename T>
void remove_first(std::vector<T>& vec, const T& value) {
    const auto it = std::find(all(vec), value);
    if (it != vec.end()) vec.erase(it);
}

#define pb push_back
#define epb emplace_back
#define ff first
#define ss second

constexpr int MOD = 1e9 + 7;
const db PI = acos((db)-1);

#ifdef LOCAL
#define DBG_MACRO_NO_WARNING
#include "dbg.h"
#else
#define dbg(...) __VA_ARGS__
#endif

#define readln(x) getline(cin >> ws, x);

template <typename... Args>
void read(Args&... args) {
    ((cin >> args), ...);
}

template <typename... Args>
void readc(Args&... args) {
    ([](auto& c) { each(e, c) cin >> e; }(args), ...);
}

template <typename... Args>
void print(Args&&... args) {
    const char* sep = "";
    (((cout << sep << args), sep = " "), ...);
}

template <typename... Args>
void println(Args&&... args) {
    print(args...);
    cout << "\n";
}

template <typename... Args>
void printc(Args&&... args) {
    ([](const auto& c) { ceach(e, c) cout << e << " "; }(args), ...);
    cout << "\n";
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

void solve() {
    bool inside[26] = {};
    vc cows;
    cows.reserve(26);
    int crosses = 0;
    LOOP(52) {
        char cow;
        read(cow);
        int index = cow - 'A';
        if (!inside[index]) {
            inside[index] = true;
            cows.pb(cow);
            continue;
        }
        const auto it = find(all(cows), cow);
        crosses += distance(it, cows.end() - 1);
        cows.erase(it);
    }
    print(crosses);
}

signed main() {
    set_io("circlecross");
    solve();
    return 0;
}
