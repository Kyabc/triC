#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

    /* 条件を満たす i が存在しない場合 */
    if (a[n - 1] < k) {
        cout << -1 << endl;
        return 0;
    }

    /* 二分探索 */
    int left = -1, right = n - 1;       // 半開区間 (-1, n - 1]
    while (abs(right - left) > 1) {
        int mid = (left + right) / 2;
        if (a[mid] < k) left = mid;
        else right = mid;
    }

    cout << right << endl;
	return 0;
}