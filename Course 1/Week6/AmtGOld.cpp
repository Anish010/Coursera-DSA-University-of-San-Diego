#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int optimal_weight(int W, vector<int> &w)
{
    int w_size = w.size();
    // vector<vector<int>> dp(w_size + 1, vector<int>(W + 1));
    int dp[w_size + 1][W + 1];
    for (int i = 0; i <= w_size; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (w[i - 1] <= j)
                dp[i][j] = max(w[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int result = dp[w_size][W];

    return result;
}

int main()
{
    int n, W;
    cin >> W >> n;
    vector<int> wt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    cout << optimal_weight(W, wt) << '\n';
}
