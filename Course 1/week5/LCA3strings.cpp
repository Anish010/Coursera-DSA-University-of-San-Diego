#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c)
{
    // write your code here
    int s1 = a.size();
    int s2 = b.size();
    int s3 = c.size();
    int dp[s1 + 1][s2 + 1][s3 + 1];
    for (int i = 0; i <= s1; i++)
    {
        for (int j = 0; j <= s2; j++)
        {
            for (int k = 0; k <= s3; k++)
            {
                if (i == 0 or j == 0 or k == 0)
                    dp[i][j][k] = 0;
                else if (i > 0 and j > 0 and k > 0 and a[i - 1] == b[j - 1] and b[j - 1] == c[k - 1])
                    dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                else
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j][k - 1], dp[i][j - 1][k]});
            }
        }
    }
    return dp[s1][s2][s3];
}
int main()
{
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++)
    {
        std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++)
    {
        std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++)
    {
        std::cin >> c[i];
    }
    std::cout << lcs3(a, b, c) << std::endl;
}
