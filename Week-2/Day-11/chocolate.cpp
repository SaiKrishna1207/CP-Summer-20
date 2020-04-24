#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, i, j, k, a = 0, b = 0;
    cin >> n;
    vector<int> times;
    for(i = 0;i < n;i++)
    {
        cin >> k;
        times.push_back(k);
    }
    i = 0, j = n - 1;
    if(i == j)
        a++;
    while(i < j)
    {
        int c1 = times[i];
        int c2 = times[j];
        if(c1 == c2)
        {
            i++;
            j--;
            a++;
            b++;
            if(i == j)
                a++;
        }
        else if(c1 < c2)
        {
            i++;
            a++;
            times[j] -= c1;
            if(i == j)
                b++;
        }
        else
        {
            j--;
            b++;
            times[i] -= c2;
            if(i == j)
                a++;
        }
    }
    cout << a << " " << b << endl;
}