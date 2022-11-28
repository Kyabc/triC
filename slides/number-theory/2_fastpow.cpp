long long fastpow(long long x, long long n) {
    long long ans = 1;
    while (n > 0) {
        if (n % 2 == 1) ans *= x;
        x *= x;
        n /= 2;
    }
    return ans;
}


#include <iostream>

int main() {
    long long n = 2;
    long long x = 10;
    std::cout << fastpow(n, x) << std::endl;
    return 0;
}