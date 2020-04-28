#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n, i, j, k, sum, xsum;
    cin >> t;
    vector<int> nums;
    while(t--)
    {
        cin >> n;
        sum = 0;
        xsum = 0;
        for(i = 0;i < n; i++)
        {
            cin >> k;
            sum += k;
            xsum = (xsum ^ k);
            nums.push_back(k);
        }
        if((xsum * 2) == sum)
        {
            cout << 0 << endl << endl;
            continue;
        }
        else
            cout << 2 << endl << xsum << " " << sum + xsum << endl;
        nums.erase(nums.begin(), nums.end());
    }

    return 0;
}