#include <iostream>
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

ll get_fibonacci_huge_naive(ll n, ll m)
{

    // Getting the period
    ll pisanoPeriod = pisano(m);

    n = n % pisanoPeriod;

    ll prev = 0;
    ll curr = 1;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    for (int i = 0; i < n - 1; i++)
    {
        ll temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
    }
    return curr % m;
}
int main()
{
    ll n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
