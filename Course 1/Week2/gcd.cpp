#include <iostream>
using namespace std;

int gcd_naive(int a, int b)
{
    return b == 0 ? a : gcd_naive(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    int gcd = gcd_naive(a, b);
    cout << gcd << endl;
    return 0;
}
