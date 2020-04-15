
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, k;
    vector<int> seq;
    vector<int>::iterator it;
    cin >> n;
    for(i = 0;i < n; i++)
    {
        cin >> k;
        seq.push_back(k);
    }
    vector<int> maxes_lr;
    vector<int> maxes_rl(n, 0);
    maxes_lr.push_back(1);
    for(i = 1;i < n; i++)
    {   
        if(seq[i] > seq[i - 1])
            maxes_lr.push_back(maxes_lr[i - 1] + 1);
        else
            maxes_lr.push_back(1);
    }
    maxes_rl[n-1] = 1;
    for(i = n - 2; i >= 0; i--)
    {
        if(seq[i] < seq[i + 1])
            maxes_rl[i] = maxes_rl[i + 1] + 1;
        else
            maxes_rl[i] = 1;
    }
    int max = maxes_lr[0];
    for(i = 1;i < n; i++)
    {
        if(maxes_lr[i] > max)
            max = maxes_lr[i];
    }
    for(i = 1; i < n - 1; i++)
    {
        if(seq[i - 1] < seq[i + 1])
        {
            if(maxes_lr[i - 1] + maxes_rl[i + 1] > max)
                max = maxes_lr[i - 1] + maxes_rl[i + 1];
        }
    }
    cout << max << endl;

    return 0;
}