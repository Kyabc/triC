#include <vector>
#include <cassert>
using namespace std;

vector<int> divisor(int n) {
    assert(n >= 0);
    std::vector<int> div;
    for (long long x = 1; x * x <= n; x++) {
        if (n % x == 0) {
            div.push_back(x);
            if (x != n / x) {
                div.push_back(n / x);
            }
        }
    }
    return div;
}


#include <iostream>

int main() {
    int n = 12345;
    for (int x: divisor(n)) cout << x << ',';
    //> 1,12345,3,4115,5,2469,15,823
}