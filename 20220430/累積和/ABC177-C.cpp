#include <iostream>
#include <vector>
#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint1000000007;

int main() {
	int n;
	cin >> n;
	vector<mint> a(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i] = mint(x);
	}

	vector<mint> s(n + 1, 0);
	for (int i = 0; i < n; i++) {
		s[i + 1] = s[i] + a[i];
	}

	mint ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * (s[n] - s[i + 1]);
	}

	cout << ans.val() << endl;
	return 0;
}