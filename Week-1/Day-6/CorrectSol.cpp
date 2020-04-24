#include <bits/stdc++.h>

using namespace std;

int main()
{
    string n, m;
    cin >> n >> m;
    sort(n.begin(), n.end());
    int i = 0;
    while(i < (n.length() - 1) && n[i] == '0')
        i++;
    char t = n[0];
    n[0] = n[i];
    n[i] = t;
    int x = n.compare(m);
    if(x == 0)
        cout << "OK" << endl;
    else
        cout << "WRONG_ANSWER" << endl;
    return 0;
}