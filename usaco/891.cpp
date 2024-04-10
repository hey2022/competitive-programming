#include <bits/stdc++.h>
using namespace std;

using db = long double;
using ll = long long;
using str = string;

using pb = pair<bool, bool>;
using pd = pair<db, db>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using ps = pair<str, str>;
#define ff first
#define ss second

template <class T>
using vec = vector<T>;
using vb = vec<bool>;
using vd = vec<db>;
using vi = vec<int>;
using vl = vec<ll>;
using vs = vec<str>;
using vpb = vec<pb>;
using vpd = vec<pd>;
using vpi = vec<pi>;
using vpl = vec<pl>;
using vps = vec<ps>;

template <class T, int Size>
using arr = array<T, Size>;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define each(x, v) for (auto& x : v)
#define pb push_back
#define sz(x) int(size(x))

#ifdef DEBUG
#define dbg(x)                                                                 \
    cerr << "[" << __FUNCTION__ << ":" << __LINE__ << "] " << #x << " = " << x \
         << "\n";
template <typename Ostream, typename T>
enable_if_t<!is_pointer_v<T> && is_same_v<Ostream, ostream>, Ostream&>
operator<<(Ostream& os, const T& v) {
    os << "[ ";
    each(x, v) os << x << " ";
    return os << "]";
}
template <typename Ostream, typename T1, typename T2>
Ostream& operator<<(Ostream& os, const pair<T1, T2>& p) {
    return os << "{" << p.ff << ", " << p.ss << "}";
}
#else
#define dbg(x)
#endif

#define readln(x) getline(cin >> ws, x);
void read() {}

template <typename First, typename... Rest>
void read(First& first, Rest&... rest) {
    cin >> first;
    read(rest...);
}

void set_io(str name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

signed main() {
    set_io("shell");
    int n;
    read(n);
    int guesses[4] = {0};
    FOR(i, 0, n) {
        int a, b, g;
        read(a, b, g);
        swap(guesses[a], guesses[b]);
        guesses[g]++;
    }
    cout << *max_element(all(guesses));
}
