#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &nums)
{
    set<int> ans;
    for (int x : nums)
    {
        ans.insert(x);
    }
    nums.clear();
    for (int x : ans)
    {
        nums.push_back(x);
    }

    return ans.size() - 1;
}