#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int> &a)
{
    map<int, int> mp;
    set<int> st;
    int n = a.size();
    for (int x : a)
    {
        st.insert(x);
        mp[x]++;
    }
    int index = 0;
    for (auto x : st)
    {
        for (int i = 0; i < mp[x] && i < 2; i++)
        {
            a[index++] = x;
        }
    }
    return index;
}