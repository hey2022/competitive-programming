#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int n, k, length = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        length += word.length();
        if (length <= k) {
            if (i != 0) {
                cout << ' ';
            }
            cout << word;
        } else {
            cout << "\n" << word;
            length = word.length();
        }
    }
}
