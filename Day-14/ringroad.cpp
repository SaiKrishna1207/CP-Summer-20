#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin >> n;
    int start[105] = {0}, end[105] = {0};
    int i, a, b, c, cost1 = 0, cost2, sum = 0;
    for(i = 0;i < n; i++)
    {
        cin >> a >> b >> c;
        if(start[a] == 1 || end[b] == 1)
        {
            start[b] = 1;
            end[a] = 1;
            cost1 += c;
        }
        else
        {
            start[a] = 1;
            end[b] = 1;
        }
        sum += c;
    }
    cost2 = sum - cost1;
    if(cost1 < cost2)
        cout << cost1 << endl;
    else
        cout << cost2 << endl;
    return 0;
}
    