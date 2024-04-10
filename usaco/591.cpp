#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    int bb, ba, sb, sa, gb, ga, pb, pa;
    cin >> bb >> ba >> sb >> sa >> gb >> ga >> pb >> pa;
    int gp = pa - pb;
    int sp = ga - gb + gp;
    int bp = sa - sb + sp;
    cout << bp << "\n" << sp << "\n" << gp;
}
