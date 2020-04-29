#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i = 0, j;
    int n;
    cin >> n;
    j = 1;
    while(j <= n)
    {
        if(j&n)
            i++;
        j *= 2;
    }
    cout << i << endl;
    return 0;
}