#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j;
    long long k, n, m;
    cin >> n >> k;
    m = n;
    if(k%2 == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    k--;
    long long size = 1;
    while(m--)
        size *= 2;
    size--;
    long long l = 0, h = size;
    int ans = 1;
    while(l <= h)
    {
        long long m = l + ((h - l) / 2);
        if(m == k)
        {
            ans = n;
            break;
        }
        else if(m > k)
            h = m - 1;
        else if(m < k)
            l = m + 1;
        n--;
    }
    cout << ans;
}