#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n, x, i, j, k;
    vector<long long> initial;
    vector<long long> ans;
    cin >> t;
    while(t--)
    {
        long long sum = 0, count = 0, j = -1;
        cin >> n >> x;
        for(i = 0;i < n; i++)
        {
            cin >> k;
            initial.push_back(k);
        }
        sort(initial.begin(), initial.end());
        for(i = 0;i < n; i++)
        {
            if(initial[i] < x)
                j = i;
            if(initial[i] >= x)  
            {
                count++;
                sum += (initial[i] - x);
            }
        }
        if(j != -1)
            i = j;
        else
        {
            ans.push_back(count);
            initial.erase(initial.begin(), initial.end());
            continue;
        }
        if(count == 0)
            ans.push_back(0);
        else
        {
            while(i >= 0)
            {
                k = x - initial[i];
                if(sum >= k)
                {
                    sum -= k;
                    count++;
                    i--;
                }
                else
                    break;
            }
            ans.push_back(count);
        }
        initial.erase(initial.begin(), initial.end());
    }

    for(i = 0;i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}