#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[i + 1][0] = a + max(dp[i][1], dp[i][2]);
        dp[i + 1][1] = b + max(dp[i][0], dp[i][2]);
        dp[i + 1][2] = c + max(dp[i][0], dp[i][1]);
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
    return 0;
}