#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int no_teleport = abs(b - a);
    int teleport_a = abs(x - a) + abs(y - b);
    int teleport_b = abs(y - a) + abs(x - b);
    cout << min(no_teleport, min(teleport_a, teleport_b));
}
