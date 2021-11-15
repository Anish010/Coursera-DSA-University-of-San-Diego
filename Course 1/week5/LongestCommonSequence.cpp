#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int lcs2(vector<int> &a, vector<int> &b)
{
    // write your code here
    int s1 = a.size();
    int s2 = b.size();

    int dp[s1 + 1][s2 + 1];
    for (int i = 0; i <= s1; i++)
    {
        for (int j = 0; j <= s2; j++)
        {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
            else if (i > 0 and j > 0 and a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[s1][s2];
}

int main()
{
    size_t n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    size_t m;
    std::cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> b[i];
    }

    std::cout << lcs2(a, b) << std::endl;
}
