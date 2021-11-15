#include <iostream>
using namespace std;
typedef long long ll;
ll pisano(ll m)
{
    ll prev = 0;
    ll curr = 1;
    ll res = 0;

    for (int i = 0; i < m * m; i++)
    {
        ll temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;

        if (prev == 0 && curr == 1)
            res = i + 1;
    }
    return res;
}

ll getFibonacciLastDigit(ll n)
{
    ll pisanoPeriod = pisano(10);

    n = n % pisanoPeriod;

    ll prev = 0;
    ll curr = 1;
    ll sum = 1;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    for (int i = 0; i < n - 1; i++)
    {
        ll temp = 0;
        temp = curr;
        curr = (prev + curr) % 10;
        prev = temp;
        sum += curr;
    }
    return sum % 10;
}

int main()
{
    ll n;
    cin >> n;
    ll c = getFibonacciLastDigit(n);
    cout << c << '\n';
}
