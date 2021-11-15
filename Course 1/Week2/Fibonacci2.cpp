#include <iostream>
using namespace std;

int getFibonacciLastDigit(int n)
{
    if (n <= 1)
        return n;

    int prv = 0;
    int curr = 1;

    for (int i = 0; i < n - 1; ++i)
    {
        int tmp_prv = prv;
        prv = curr;
        curr = (tmp_prv + curr) % 10;
    }

    return curr % 10;
}

int main()
{
    int n;
    cin >> n;
    int c = getFibonacciLastDigit(n);
    cout << c << '\n';
}
