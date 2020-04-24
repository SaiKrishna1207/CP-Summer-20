#include<bits/stdc++.h>

using namespace std;

long long gcd(int n, int m)
{
    if(n == m)
        return m;
    if(n > m)
        return gcd(n-m, m);
    return (n, m-n);
}

int mini(int n, int m)
{
    if(n < m)
        return n;
    return m;
}

int main()
{
    int q, sx, ex, i;
    long long n, m, sy, ey, g1, g2;
    vector<int> answers;
    cin >> n >> m >> q;
    while(q--)
    {
        cin >> sx >> sy >> ex >> ey;
        if(n == m)
        {
            if(sy == ey)
                answers.push_back(1);
            else
                answers.push_back(0);
        }
        else
        {
            long long g = gcd(n, m);
            long long mg = m/g, ng = n/g;
            if(sx == 1)
                g1 = (sy - 1) / ng;
            else
                g1 = (sy - 1) / mg;
            if(ex == 1)
                g2 = (ey - 1) / ng;
            else
                g2 = (ey - 1) / mg;
            if(g1 == g2)
                answers.push_back(1);
            else
                answers.push_back(0);
        }
        
    }
    for(i = 0; i < answers.size(); i++)
    {
        if(answers[i] == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}