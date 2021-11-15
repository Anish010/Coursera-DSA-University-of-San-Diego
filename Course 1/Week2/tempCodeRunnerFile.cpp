ll pisano(ll m)
{
    ll prev = 0;
    ll curr = 1;
    ll res = 0;

    for (int i = 0; i < m * m; i++)
    {
        ll temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;

        if (prev == 0 && curr == 1)
            res = i + 1;
    }
    return res;
}
