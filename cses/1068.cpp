#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    while (n != 1) {
        cout << n << " ";
        if (n % 2) {
            n = 3 * n + 1;
        } else {
            n /= 2;
        }
    }
    cout << n;
}
