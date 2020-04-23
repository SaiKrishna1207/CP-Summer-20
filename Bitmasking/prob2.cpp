#include<bits/stdc++.h>

using namespace std;

bool solve(vector<int> & degrees, int n)
{
    int i, j, sum;
    for(i = 0;i < (1 << n); i++)
    {
        sum = 0;
        for(j = 0;j < n; j++)
        {
            if((1<<j)&i)
                sum += degrees[j];
            else
                sum -= degrees[j];
        }
        if(sum%360 == 0)
            return true;
    }
    return false;
}

int main()
{
    int i, j, k, n;
    cin >> n;
    vector<int> degrees;
    for(i = 0; i < n; i++)
    {
        cin >> k;
        degrees.push_back(k);
    }
    if(solve(degrees, n))
        cout << "YES" << endl;
    else
        cout<< "NO" << endl;

    return 0;
}
