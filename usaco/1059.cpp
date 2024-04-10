#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int nums[7];
    for (auto &n : nums) {
        cin >> n;
    }
    sort(nums, nums + 7);
    int a = nums[0], b = nums[1], c = nums[6] - a - b;
    cout << a << " " << b << " " << c;
}
