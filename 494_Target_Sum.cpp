#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int a;
int x[21];
int n;
vector<int> arr;
void solve(int k, int &sum)
{
    if (k >= n)
        return;
    for (int i = 0; i < 2; i++)
    {
        x[k] = pow(-1, i) * arr[k];
        sum += x[k];
        if (k == (n - 1))
        {
            if (sum == a)
                ans++;
        }

        solve(k + 1, sum);
        sum -= x[k];
    }
}
int findTargetSumWays(vector<int> &nums, int target)
{
    n = nums.size();
    for (int i : nums)
    {
        arr.push_back(i);
    }

    a = target;
    int sum = 0;
    solve(0, sum);
    return ans;
}
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << findTargetSumWays(nums, 3);
}