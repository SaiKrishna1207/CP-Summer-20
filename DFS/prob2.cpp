#include<bits/stdc++.h>

using namespace std;

map<int, int> mp[200020];

int main()
{
    int n, i, j, k;
    cin >> n;
    vector<int> sequence(n);
    //vector<int> bfs;
    //int visited[n + 1] = {0};
    for(i = 0;i < n - 1; i++)
    {
        cin >> j >> k;
        mp[j][k] = 1;
        mp[k][j] = 1;
    }
    for(i = 0;i < n; i++)
        cin >> sequence[i];
    if(sequence[0] != 1)
    {
        cout << "No" << endl;
        return 0;
    }
    // queue<int> q;
    // q.push(1);
    // while(!q.empty())
    // {
    //     i = q.front();
    //     q.pop();
    //     visited[i] = true;
    //     bfs.push_back(i); 
    //     for(j = 0; j < mp[i].size(); j++)
    //     {
    //         if(!visited[mp[i][j]])
    //             q.push(mp[i][j]);
    //     }
    // }
    // for(i = 0;i < n; i++)
    // {
    //     if(bfs[i] != sequence[i])
    //     {
    //         cout << "No" << endl;
    //         return 0;
    //     }
    // }
    j = 1;
    for(i = 0;i < n; i++)
    {
        while(mp[sequence[i]][sequence[j]])
            j++;
    }
    if(j == n)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    return 0;
}
