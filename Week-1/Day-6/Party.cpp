#include <bits/stdc++.h>

using namespace std;

int dfs(unordered_map<int,vector<int>>& m, int t)
{
    int j, h, max1 = 0;
    vector<int> a = m[t];
    if(a.size() == 0)
        return 0;
    for(j = 0; j < a.size(); j++)
    {
        h = dfs(m, a[j]);
        if(h > max1)
            max1 = h;
    }
    return max1 + 1;
}

int main()
{
    int n, i, max = 0, x;
    cin >> n;
    int p[n+1];
    unordered_map <int, vector<int>> m;
    for(i = 1;i <= n; i++)
    {
        cin >> p[i];
        m[p[i]].push_back(i);
    }
    vector<int> roots = m[-1];
    for(i = 0;i < roots.size(); i++)
    {
        x = dfs(m, roots[i]);
        if(x > max)
            max = x;
    }
    //We keep getting 1 less because levels start as 0. Hence we increment max.
    max++;
    cout << max << endl;
    return 0;
}