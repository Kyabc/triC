#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr long long INF = (1LL << 60);

int main() {
    int n, q;
    cin >> n;
    std::vector<long long> a(n);
    for (auto &x : a) cin >> x;

    a.push_back(INF);
    a.push_back(-INF);
    sort(a.begin(), a.end());

    cin >> q;
    for (int i = 0; i < q; i++) {
        long long b;
        cin >> b;
        auto iter = lower_bound(a.begin(), a.end(), b);
        long long val1 = b - *prev(iter);
        long long val2 = *iter - b;
        cout << min(val1, val2) << endl;
    }
    return 0;
}
