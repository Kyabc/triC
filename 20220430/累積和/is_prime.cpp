bool is_prime (int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}