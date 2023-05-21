#include <bits/stdc++.h>
using namespace std;
int countGoodStrings(int low, int high, int zero, int one)
{

    int mod = 1e9 + 1;
    vector<long long> a;
    for (int i = 0; i <= high; i++)
    {
        a.push_back(0);
    }
    if (zero == one)
    {
        a[zero] = 2;
        for (int i = zero + 1; i <= high; i++)
        {
            a[i] = (a[i - zero] % mod * 2) % mod;
        }
    }
    else
    {
        a[zero] = 1;
        a[one] = 1;
        int x = min(one, zero), y = max(zero, one);
        for (int i = x; i <= high; i++)
        {
            int tmp1 = ((i - zero) >= 0) ? (a[i - zero]) : 0;
            int tmp2 = ((i - one) >= 0) ? (a[i - one]) : 0;
            if (i != y && i != x)
                a[i] = tmp1 + tmp2;
            else
                a[i] += tmp1 + tmp2;
        }
    }

    int sum = 0;
    for (int i = low; i <= high; i++)
    {
        sum += a[i];
    }
    return sum;
}
int main()
{
    // cout << (2 << 0);
    cout << countGoodStrings(10, 10, 1, 1);
}
