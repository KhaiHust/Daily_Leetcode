#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &a)
{
    int ans = INT_MAX;
    int n = a.size();

    int res[n][a[n - 1].size()];

    res[0][0] = a[0][0];
    for (int i = 1; i < n; i++)
    {
        int m = a[i].size();

        res[i][0] = res[i - 1][0] + a[i][0];
        for (int j = 1; j < m; j++)
        {
            res[i][j] = j < m - 1 ? min(res[i - 1][j - 1] + a[i][j], res[i - 1][j] + a[i][j]) : res[i - 1][j - 1] + a[i][j];
        }
    }
    int m = a[n - 1].size();
    for (int i = 0; i < m; i++)
        ans = min(ans, res[n - 1][i]);
    return ans;
}

int main()
{
    vector<vector<int>> triangle = {{2}, {-1, -7}, {6, 7, 9}, {-3, 8, 5, 7}, {5, -3, 2, 5, -7}, {-8, 6, 8, -5, -8, -7}, {1, 5, 2, -5, 5, 8, -3}, {-1, -2, 2, -9, 6, 2, 7, 0}, {1, -9, -5, -7, 7, 9, -4, -3, 2}};
    cout << minimumTotal(triangle);
}