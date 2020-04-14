#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, n, diff;
    cin >> n;
    vector<int> group;
    vector<int> sums;
    sums.push_back(1);
    for(i = 1;i < n; i++)
        sums.push_back(sums[i-1] + (i+1));
    // for(i = 0;i < n; i++)
        // cout << sums[i] << " "; 

    if(sums[n - 1]%2 == 0)
        diff = 0;
    else
        diff = 1;

    j = sums[n-1] / 2;
    i = n;
    while(i)
    {
        if((j - i) >= 0)
        {
            j -= i;
            group.push_back(i);
        }
        i--;
    }
    cout << diff << endl;
    cout << group.size() << endl;
    for(i = 0;i < group.size(); i++)
        cout << group[i] << " ";

    return 0;
}