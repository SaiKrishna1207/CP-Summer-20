#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n1, n2, minutes = 0;
    cin >> n1 >> n2;
    while(n1 > 0 && n2 > 0)
    {
        if(n1 == 1 && n2 == 1)
            break;
        if(n1 > n2)
        {
            n1 -= 2;
            n2 += 1;
            minutes++;
        }
        else
        {
            n2 -= 2;
            n1 += 1;
            minutes++;
        }
    }
    cout << minutes << endl;
}