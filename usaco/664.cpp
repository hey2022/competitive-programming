#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

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
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    int N;
    cin >> N;
    int max_count[26] = {};
    while (N--) {
        str f, b;
        cin >> f >> b;
        int countf[26] = {0}, countb[26] = {0};
        for (auto &c : f) countf[c - 'a']++;
        for (auto &c : b) countb[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            max_count[i] += max({countf[i], countb[i]});
        }
    }
    for (auto &n : max_count) {
        cout << n << "\n";
    }
}
