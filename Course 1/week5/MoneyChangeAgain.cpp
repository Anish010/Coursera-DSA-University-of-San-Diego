#include <bits/stdc++.h>
using namespace std;
int get_change(int m, int n, int coins[])
{
    // write your code here

    vector<int> minNumCoins(m + 1, INT_MAX);
    int NumCoins;
    minNumCoins[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= coins[j])
            {
                NumCoins = minNumCoins[i - coins[j]];
                if (NumCoins + 1 < minNumCoins[i])
                {
                    minNumCoins[i] = NumCoins + 1;
                }
            }
        }
    }
    return minNumCoins[m];
}

int main()
{
    int m;
    std::cin >> m;
    int n = 3;
    int coins[n] = {1, 3, 4};
    std::cout << get_change(m, n, coins) << '\n';
}
