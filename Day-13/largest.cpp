#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, a = 0;
    cin >> n;
    while(n > 9)
    {
        if(n%10 == 9)
        {
            a += 9;
            n /= 10;
        }
        else
        {
            a += 10 + (n%10);
            n /= 10;
            n--;
        }
    }
    cout << a + n << endl;
    return 0;
}

