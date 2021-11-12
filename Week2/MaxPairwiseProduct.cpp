#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;

void maxProduct(vector<ll> v)
{
    ll n = v.size();
    if (n < 2)
    {
        return;
    }
    if (n == 2)
    {
        cout << v[0] << " " << v[1] << endl;
        return;
    }
    ll posa = 0, posb = 0;
    ll nega = 0, negb = 0;

    for (ll i = 0; i < n; i++)
    {
        if (v[i] > posa)
        {
            posb = posa;
            posa = v[i];
        }
        else if (v[i] > posb)
            posb = v[i];

        if (v[i] < 0 && abs(v[i]) > abs(nega))
        {
            negb = nega;
            nega = v[i];
        }
        else if (v[i] < 0 && abs(v[i]) > abs(negb))
            negb = v[i];
    }

    if (nega * negb > posa * posb)
        cout << nega * negb << endl;
    else
        cout << posa * posb << endl;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (ll i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        vec.push_back(x);
    }

    maxProduct(vec);
    return 0;
}
