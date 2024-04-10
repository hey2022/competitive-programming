#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)x.size()

#define pb push_back
#define epb emplace_back
#define ff first
#define ss second

#ifdef DEBUG
#define dbg(x) cerr << #x << " = " << x << "\n";
#else
#define dbg(x)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int N, M;
    cin >> N >> M;
    vi road, cow;
    road.reserve(100), cow.reserve(100);
    while (N--) {
        int len, lim;
        cin >> len >> lim;
        while (len--) road.pb(lim);
    }
    while (M--) {
        int len, lim;
        cin >> len >> lim;
        while (len--) cow.pb(lim);
    }
    int mx = 0;
    for (int i = 0; i < 100; i++) mx = max(cow[i] - road[i], mx);
    cout << mx;
}
