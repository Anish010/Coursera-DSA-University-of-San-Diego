#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int compute_min_refills(int dist, int n, int tank, vector<int> &stops)
{
    int c = 0, i = 0, a = 0, j = 0, k = 0;
    vector<int> stops2(n + 1);
    for (i = 0; i < n; i++)
    {
        stops2[i] = stops[i];
    }
    i = 0;
    stops2[n] = dist;
    stops = stops2;
    while (i <= n)
    {
        if (stops[i] - a > tank)
        {
            return -1;
        }
        k = i;
        for (j = 1; j < n - k + 1; j++)
        {
            if (stops[j + k] - a <= tank)
            {
                i++;
            }
            else
            {
                c++;
                break;
            }
        }
        a = stops[i];
        i++;
    }
    return c;
}
int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
    vector<int> stops(n);
    for (auto i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, n, m, stops) << "\n";

    return 0;
}
