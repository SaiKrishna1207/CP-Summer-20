#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, s, i, j, k;
    cin >> n >> s;
    s--;
    vector<int> a, b;
    for(i = 0;i < n; i++)
    {
        cin >> k;
        a.push_back(k);
    }
    for(i = 0;i < n; i++)
    {
        cin >> k;
        b.push_back(k);
    }

    if(a[0] == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    
    if(a[s] == 1)
    {
        cout << "YES" << endl;
        return 0;
    } 
    else
    {
        for(i = s + 1;i < n; i++)
        {
            if(a[i] == 1 && b[i] == 1)
            {
                if(b[s] == 1)
                {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }   
    }
    cout << "NO" << endl;
    return 0;
}