#include<bits/stdc++.h>

using namespace std;
vector<int> v[100005];

void dfs(int* visited, int i)
{
    visited[i] = 1;
    for(int j = 0;j < v[i].size(); j++)
    {
        if(visited[v[i][j]] == 0)
            dfs(visited, v[i][j]);
    }
}


int main()
{
    int n, m, i, j, k, x, c = 0, count = 0;
    cin >> n >> m;
    for(i = 0;i < n; i++)
    {
        cin >> k;
        if(k == 0)
            c++;
        for(j = 0;j < k; j++)
        {
            cin >> x;
            v[i].push_back(x + n);
            v[x + n].push_back(i);
        }
    }
    if(c == n)
    {
        cout << n;
        return 0;
    }
    int visited[n + m + 1];
    for(i = 0; i <= n + m; i++)
        visited[i] = 0;
    for(i = 0;i < n; i++)
    {
        if(visited[i] == 0)
        {
            count++;
            dfs(visited, i);
        }
    }

    cout << count - 1 << endl;
    return 0;
}
