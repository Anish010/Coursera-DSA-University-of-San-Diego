#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
#define pi 3.141592653589
#define pb push_back
#define vi vector<int>
#define pii pair<int, int>
#define vpi vector<pi>
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rloop(i, a, n, b) for (int i = n - 1; i >= a; i = i - b)
#define loop(i, a, n, b) for (int i = a; i < n; i = i + b)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

void printvec(vector<int> v)
{
    for (auto &i : v)
    {
        cout << i << ' ';
    }
}

bool compare(ll a, ll b)
{
    return a > b;
}

long long max_dot_product(vector<int> a, vector<int> b)
{
    // write your code here
    long long result = 0;
    int n = a.size();
    sort(a.begin(), a.end(), compare);
    sort(b.begin(), b.end(), compare);
    for (size_t i = 0; i < a.size(); i++)
    {
        result += ((long long)a[i]) * b[i];
    }
    return result;
}

int main()
{
    size_t n;
    cin >> n;
    vector<int> a(n), b(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout << max_dot_product(a, b) << endl;
    return 0;
}
