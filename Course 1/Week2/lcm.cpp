#include <iostream>
using namespace std;
typedef long long ll;
ll gcd_naive(ll a, ll b)
{
    return b == 0 ? a : gcd_naive(b, a % b);
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll gcd = gcd_naive(a, b);
    ll lcm = (a * b) / gcd;
    cout << lcm << endl;
    return 0;
}
