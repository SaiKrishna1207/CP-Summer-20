#include<bits/stdc++.h>

using namespace std;

int count = 0;
vector<long long> route;
unordered_map<long long, vector<long long>> m;
unordered_map<long long, bool> visited;

void solve(long long i)
{
    route.push_back(i);
    visited[i] = true;
    int j; 
    for(j = 0;j < m[i].size(); j++)
    {
        if(!visited[m[i][j]])
            solve(m[i][j]);
    }

}

int main()
{
    int n, i;
    long long a, b, j;
    cin >> n;
    for(i = 0;i < n; i++)
    {
        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    for(auto i : m)
    {
        if(i.second.size() == 1)
        {
            solve(i.first);
            break;
        }
    }
    for(i = 0;i < route.size(); i++)
        cout << route[i] << " ";
    return 0;
}

