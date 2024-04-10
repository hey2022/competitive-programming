#include <bits/stdc++.h>

#include <iostream>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define ff first
#define ss second

#define all(x) begin(x), end(x)
#define sz(x) (int)size(x)

#ifdef DEBUG
#define dbg(x) cerr << #x << " = " << x << "\n";
#else
#define dbg(x)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    pi buckets[3];
    for (auto& x : buckets) {
        cin >> x.ff >> x.ss;
    }
    for (int i = 0; i < 100; i++) {
        int curr = i % 3, next = (i + 1) % 3;
        int pour = min(buckets[curr].ss, buckets[next].ff - buckets[next].ss);
        buckets[next].ss += pour;
        buckets[curr].ss -= pour;
    }
    for (auto& x : buckets) {
        cout << x.ss << "\n";
    }
}
