#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, k, n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> c(n);
    for(i = 0;i < n; i++)
        cin >> c[i];
    int ans = 0;
    for(i = 3; i < (1<<n); i++)
    {
        if(i == 4 || i == 8 || i == 16 || i == 32 || i == 64 || i == 128 || i == 256 || i == 512 || i == 1024 || i == 2048 || i == 4096 || i == 8192 || i == 16384 || i == 32768) // Only 1 bit active.. problemset requires at least 2 problems..so exclude
            continue;
        int curSum = 0, max = INT_MIN, min = INT_MAX;
        for(j = 0;j < n; j++)
        {
            if(i&(1<<j))
            {
                curSum += c[j];
                if(c[j] > max)
                    max = c[j];
                if(c[j] < min)
                    min = c[j];
            }   
        }
        if(curSum >= l && curSum <= r && (max - min) >= x)
            ans++;
    }

    cout << ans << endl;
    return 0;
}