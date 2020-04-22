#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, i, j, k;
    cin >> n >> k;
    vector<int> gf(n);
    for(i = 0;i < n; i++)
        cin >> gf[i];
    k--;
    bool visited[n] = {false};
    queue<int> q;
    q.push(k);
    while(!q.empty())
    {
        j = q.front();
        q.pop();
        visited[j] = true;
        for(i = 0;i < n; i++)
        {
            if(i == j)
                continue;
            if(gf[i]&gf[j] != 0 && !visited[i])
                q.push(i);
        }
    }
    int count = 0;
    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0)
            count++;
    }
    cout << count << endl;


    return 0;
}