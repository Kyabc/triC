#include <vector>
using namespace std;

vector<bool> eratosthenes(int n) {
    if (n < 2) n = 1;
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (not prime[i]) continue;
        for (int j = i+i; j <= n; j += i) {
            prime[j] = false;
        }
    }
    return prime;
}


#include <iostream>
int main() {
    int n = 10;
    auto prime = eratosthenes(n);
    for (int i = 0; i <= n; i++) {
        cout << i << ' ' << prime[i] << endl;
    }
}