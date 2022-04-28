#include <iostream>
#include <vector>
using namespace std;

constexpr int N = 100100;

// 素数判定
bool prime(long long x) {
	if (x < 2) return false;
	if (x == 2) return true;
	for (long long i = 2; i * i <= x; i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main() {
	int q;
	cin >> q;

	std::vector<int> a(N, 0); // a[i]:= i が 2017 に似た数なら 1, そうでないなら 0 
	for (int i = 0; i < N; i++) {
		// 奇数の時のみ判定すればよい
		if (i % 2 == 1) {
			if (prime(i) and prime((i + 1) / 2)) {
				a[i] = 1;
			}
		}
	}

	// 前処理
	std::vector<int> s(N + 1, 0);
	for (int i = 0; i < N; i++) {
		s[i + 1] = s[i] + a[i];
	}

	// クエリ
	// l <= x <= r なので s[r + 1] - s[l]
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << s[r + 1] - s[l] << endl;
	}
	return 0;
}