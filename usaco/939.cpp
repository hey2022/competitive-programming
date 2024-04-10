#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    int bi, bj, ri, rj, li, lj;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char c;
            cin >> c;
            if (c == 'B') {
                bi = i;
                bj = j;
            }
            if (c == 'L') {
                li = i;
                lj = j;
            }
            if (c == 'R') {
                ri = i;
                rj = j;
            }
        }
    }
    int dist_br = abs(bi - ri) + abs(bj - rj);
    int dist_bl = abs(bi - li) + abs(bj - lj);
    int dist_rl = abs(ri - li) + abs(rj - lj);
    if ((bi == li || bj == lj) && dist_bl == dist_br + dist_rl) {
        cout << dist_bl + 1;
    } else {
        cout << dist_bl - 1;
    }
}
