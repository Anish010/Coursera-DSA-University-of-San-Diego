#include <iostream>
using namespace std;
int get_change(int m)
{
    // write your code here
    int c = 0;
    while (m != 0)
    {
        if (m >= 10)
        {
            m -= 10;
        }
        else if (m >= 5 and m < 10)
        {
            m -= 5;
        }
        else if (m >= 1 and m < 5)
        {
            m -= 1;
        }
        c++;
    }
    return c;
}

int main()
{
    int m;
    cin >> m;
    cout << get_change(m) << '\n';
}
