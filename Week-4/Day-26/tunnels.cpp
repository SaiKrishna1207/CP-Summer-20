#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, k;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> exit_time(n);
    unordered_map<int, int> m;
    for(i = 0;i < n; i++)
    {
        cin >> a[i];
        m[a[i]] = i;
    }
    for(i = 0;i < n; i++)
        cin >> b[i];
    for(i = 0;i < n; i++)
    {
        exit_time[m[b[i]]] = i; 
    }
    int mx = exit_time[0];
    int count = 0;
    for(i = 1;i < n; i++)
    {
        if(mx > exit_time[i])
            count++;
        else
            mx = max(mx, exit_time[i]);
    }
    cout << count << endl;
    return 0;
}
