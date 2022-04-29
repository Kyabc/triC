#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<long long> s(n + 1, 0);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    
    long long ans = 0;
    map<long long, long long> counter;
    for (int i = 0; i < n + 1; i++) {
        ans += counter[s[i]];
        counter[s[i]]++;
    }
    
    cout << ans << endl;
    return 0;
}