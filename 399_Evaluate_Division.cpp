#include <bits/stdc++.h>
using namespace std;

vector<double> calcEquation(vector<vector<string>> &a, vector<double> &values, vector<vector<string>> &queries)
{
    int n = a.size();
    map<string, vector<pair<string, double>>> mp;
    vector<string> b;
    for (int i = 0; i < n; i++)
    {
        mp[a[i][0]].push_back({a[i][1], values[i]});
        mp[a[i][1]].push_back({a[i][0], 1 / values[i]});
    }
    for (auto x : mp)
    {
        b.push_back(x.first);
        int m = x.second.size();
        if (m > 1)
        {
            for (int i = 0; i < m; i++)
                for (int j = i + 1; j < m; j++)
                {
                    mp[x.second.at(i).first].push_back({x.second.at(j).first, x.second.at(j).second / x.second.at(i).second});
                    mp[x.second.at(j).first].push_back({x.second.at(i).first, x.second.at(i).second / x.second.at(j).second});
                }
        }
    }
    vector<double> ans;
    vector<string>::iterator index;
    int m = queries.size();
    for (int i = 0; i < m; i++)
    {
        if (find(b.begin(), b.end(), queries[i][0]) != b.end())
        {

            for (auto x : mp[queries[i][0]])
            {
                if (x.first == queries[i][1])
                    ans.push_back(x.second);
                else
                    ans.push_back(-1.0);
            }
        }
        else
            ans.push_back(-1.0);
    }

    return values;
}