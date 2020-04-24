#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void solve(vector<int> money, int n)
{
    int i, j, balance50 = 0, balance25 = 0, balance100 = 0, flag = 0;
    if(money[i] != 25)
    {
        cout << "NO" << endl;
        return;
    }
    for(i = 0;i < n;i++)
    {
        if(flag == 0)
        {
            switch(money[i])
            {
                case 25:balance25++;
                        break;
                case 50:if(balance25 != 0)
                        {
                            balance25--;
                            balance50++;
                        }
                        else
                        {
                            flag = 1;
                        }                     
                        break;
                case 100:if(balance50 >= 1 && balance25 >= 1)
                        {
                            balance50--;
                            balance25--;
                            balance100++;
                        }     
                        else if(balance50 == 0 && balance25 >= 3)
                        {
                            balance25 -= 3;
                            balance100++;
                        }
                        else
                        {
                            flag = 1;
                        }
                        break;
                default : flag = 2;
            }
        }
    }
    if(flag == 0)
        cout << "YES" << endl;
    else if(flag == 1)
        cout << "NO" << endl;
    else if(flag == 2)
        cout << "Invalid note" << endl; 
}

int main()
{
    int n, i, k;
    cout << "Enter n" << endl;
    cin >> n;
    vector<int> money;
    cout << "Enter the values : " << endl;
    for(i = 0;i < n;i++)
    {
        cin>>k;
        money.push_back(k);
    }

    solve(money, n);
    return 0;
}