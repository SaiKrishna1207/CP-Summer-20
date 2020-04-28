#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, k;
    cin >> n;
    int comb = (n * (n - 1)) / 2;
    unordered_map<int, vector<pair<int, bool>>> games;
    for(i = 0;i < comb - 1; i++)
    {
        cin >> j >> k;
        games[j].push_back(make_pair(k,true));
        games[k].push_back(make_pair(j, false));
    }
    vector<int> miss;
    for(auto i : games)
    {
        if(i.second.size() != n - 1)
            miss.push_back(i.first);
    }
    int a = miss[0], b = miss[1];
    int a_c = 0, b_c = 0;
    for(i = 0;i < games[a].size(); i++)
    {
        if(games[a][i].second == true)
            a_c++;
    }
    for(i = 0;i < games[b].size(); i++)
    {
        if(games[b][i].second == true)
            b_c++;
    }
    if(a_c > b_c)
        cout << a << " " << b << endl;
    else
        cout << b << " " << a << endl;
    return 0;
}
