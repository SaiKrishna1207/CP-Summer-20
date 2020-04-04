#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, p, q, i, k;
    cin >> n;
    cin >> p;
    set <int> s;
    for(i = 0;i < p; i++)
    {
        cin >> k;
        s.insert(k);
    }
    cin >> q;
    for(i = 0;i < q;i++)
    {
        cin >> k;
        s.insert(k);
    }
    if(s.size() == n)
        cout << "I become the guy." << endl;
    else
        cout << "Oh, my keyboard!" << endl;
    return 0;
}