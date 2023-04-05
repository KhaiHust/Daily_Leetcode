#include <bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string s1, string s2)
{
    int n = s1.length(), m = s2.length(); // get length s1, s2
    int F[n + 1][m + 1];                  // mark max LC
    memset(F[0], 0, sizeof(F[0]));
    for (int i = 0; i <= n; i++)
    {
        F[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                F[i][j] = F[i - 1][j - 1] + 1;
            else
                F[i][j] = max(F[i - 1][j], F[i][j - 1]);
        }
    }
    return F[n][m];
}
int main()
{
    string s1 = "abcde";
    string s2 = "ace";
    cout << longestCommonSubsequence(s1, s2);
}