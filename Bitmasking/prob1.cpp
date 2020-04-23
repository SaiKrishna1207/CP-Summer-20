#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, k, t, n;
    string x, y;
    long long xn, yn;
    vector<int> ans;
    cin >> t;
    while(t--)
    {
        xn = 0, yn = 0;
        cin >> x >> y;
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        i = 0;
        while(i < y.length() && y[i] == '0')
            i++;
        yn = i;
        while(i < x.length() && x[i] == '0')
            i++;
        xn = i;
        ans.push_back(xn - yn);
    }
    for(i = 0;i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}