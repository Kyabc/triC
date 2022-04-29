#include <iostream>

using namespace std;

int main() {
    long long r, b, x, y;
    cin >> r >> b >> x >> y;

    // k 束の花束を作れるか？
    auto f = [&] (long long k) {
        if (r < k or b < k) return false;
        long long flower1 = (r - k) / (x - 1);
        long long flower2 = (b - k) / (y - 1);
        return flower1 + flower2 >= k;
    };

    long long ok = 0, ng = r + b;
    while (abs(ok - ng) > 1LL) {
        long long mid = (ok + ng) / 2;
        if (f(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    return 0;
}