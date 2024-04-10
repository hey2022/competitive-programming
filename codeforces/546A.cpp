#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n, w;
    cin >> k >> n >> w;
    int cost = k * w * (w + 1) / 2;
    cout << max(cost - n, 0);
}
