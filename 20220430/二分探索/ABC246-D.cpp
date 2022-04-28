#include <iostream>

using namespace std;

constexpr long long INF = (1LL << 60);
constexpr long long MAX = 1000100;

long long f (long long a, long long b) {
    return a * a * a + a * a * b + a * b * b + b * b * b;
}

int main() {
    long long n, ans = INF;
    cin >> n;

    for (long long a = 0; a < MAX; a++) {
        long long ok = MAX, ng = -1;
        while (abs(ok - ng) > 1) {
            long long mid = (ok + ng) / 2LL;
            if (f(a, mid) >= n) ok = mid;
            else ng = mid;
        }
        ans = min(ans, f(a, ok));
    }

    cout << ans << endl;
    return 0;
}