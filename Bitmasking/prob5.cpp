#include<bits/stdc++.h>
#include<math.h>

using namespace std;

int main()
{
    int i, j = 1, k, n, c1 = 0, a;
    cin >> n >> k;
    vector<int> pows;
    if(k > n)
    {
        cout << "NO" << endl;
        return 0;
    }
    if(k == n)
    {
        cout << "YES" << endl;
        for(i = 0; i < n; i++)
            cout << 1 << " ";
        return 0;
    }
    while(j <= n)
    {
        if((j&n) != 0)
        {
            pows.push_back(j);
            c1++;
        }
        j *= 2;
    }
    if(k < c1)
    {
        cout << "NO" << endl;
        return 0;
    }
    a = k - c1;
    for(i = 0;i < pows.size() && (a > 0); i++)
    {
        if(pows[i] != 1)
        {
            pows[i] /= 2;
            j = pows[i];
            pows.push_back(j);
            i--;
            a--;
        }
    }
    cout << "YES" << endl;
    for(i = 0;i < pows.size(); i++)
        cout << pows[i] << " ";
    return 0;
}
