#include <iostream>
using namespace std;

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int a = 0;
    int b = 0;
    cin >> a;
    cin >> b;
    cout << sum(a, b);
    return 0;
}