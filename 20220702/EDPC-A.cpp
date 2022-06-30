#include <iostream>
#include <vector>

using namespace std;

const int INF = (1 << 30);

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto &x : h) cin >> x;

    vector<int> dp(n, INF);
    dp[0] = 0;
    dp[1] = dp[0] + abs(h[0] - h[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i-1] + abs(h[i-1] - h[i]), dp[i-2] + abs(h[i-2] - h[i]));
    }

    cout << dp[n-1] << endl;
    return 0;
}