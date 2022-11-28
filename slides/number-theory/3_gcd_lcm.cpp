#include <iostream>
#include <numeric>
using namespace std;

int main() {
    int a = 10, b = 15;
    cout << "GCD(" << a << ',' << b << ") = " << gcd(a, b) << endl;
    cout << "LCM(" << a << ',' << b << ") = " << lcm(a, b) << endl;
    /* > GCD(10,15) = 5
     * > LCM(10,15) = 30
     */
}