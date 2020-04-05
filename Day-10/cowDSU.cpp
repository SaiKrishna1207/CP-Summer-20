#include<bits/stdc++.h>

using namespace std;

unordered_map<int, int> m;
int c = 0;

void find_connected(int n, int i, int* visited)
{
    if(visited[i] == 0)
    {
        visited[i] = 1;
        if(i != m[i])
            find_connected(n, m[i], visited);
        else
            c++;
    }
    
}

int find(int l) 
{ 
    if (m[l] == l) 
        return l;
    return find(m[l]); 
}

void uni(int a, int b) 
{
    int x = find(a);
    int y = find(b);
    m[x] = y;
}

int main()
{
    int n, k, i, in1, in2;
    cin >> n >> k;
    vector<pair<int, int>> flavours; 
    for(i = 0;i < k; i++)
    {
        cin >> in1 >> in2;
        flavours.push_back(make_pair(in1, in2));
    }
    for(i = 1;i <= n; i++)
        m[i] = i;
    for(i = 0;i < k; i++)
    {
        in1 = flavours[i].first;
        in2 = flavours[i].second;
        if(find(in1) != find(in2))
            uni(in1, in2);
    }
    int visited[n+1] = {0};
    for(i = 1;i <= n; i++)
        find_connected(n, i, visited);
    int ans = k - (n - c); 
    cout << ans << endl;
    return 0;
}
    