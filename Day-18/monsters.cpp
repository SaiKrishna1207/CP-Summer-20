#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, k, i, j, max_points = 0;
    bool turn = true;
    cin >> n >> a >> b >> k;
    vector<int> health;
    vector<int> req_k;
    for(i = 0;i < n; i++)
    {
        cin >> j;
        health.push_back(j);
    }
    for(i = 0;i < n; i++)
    {
        int rem = health[i]%(a + b);
        if(rem == 0)
            rem = a + b;
        rem = (rem - 1) / a;
        req_k.push_back(rem);
    }
    sort(req_k.begin(), req_k.end());
    for(i = 0;i < n;i++)
    {
        if(k - req_k[i] < 0)
            break;
        max_points++;
        k -= req_k[i];
    }

    cout << max_points << endl;;
    return 0;
}