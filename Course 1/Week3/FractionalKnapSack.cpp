#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using std::vector;

#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pii>
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

bool compare(pii p1, pii p2)
{
    double v1 = (double)p1.ff / p1.ss;
    double v2 = (double)p2.ff / p2.ss;
    return v1 > v2;
}

double get_optimal_value(int K, vpi a, int n)
{
    double value = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (K >= a[i].ss)
        {
            value += a[i].ff;
            K -= a[i].ss;
            continue;
        }
        double vp = (double)a[i].ff / a[i].ss;
        value += K * vp;
        K = 0;
        break;
    }
    return value;
}

int main()
{
    int n;
    int capacity;
    cin >> n >> capacity;
    vpi a(n);
    // vector<int> values(n);
    // vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].ff >> a[i].ss;
    }
    sort(a.begin(), a.end(), compare);

    double optimal_value = get_optimal_value(capacity, a, n);

    cout.precision(10);
    cout << optimal_value << endl;
    return 0;
}