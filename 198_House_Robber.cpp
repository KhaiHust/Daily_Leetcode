#include <bits/stdc++.h>
using namespace std;
int rob(vector<int> &nums)
{
    int ans = INT_MIN;
    int n = nums.size();
    int res[n];
    for (int i = 0; i < n; i++)
    {
        res[i] = nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            res[i] = max(res[i], res[j] + nums[i]);
        }
    }
    for (int x : res)
        ans = max(ans, x);
    return ans;
}