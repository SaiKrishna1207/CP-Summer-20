#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, i, j, k;
    string s;
    cin >> t;
    vector<vector<int>> initial = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    while (t--)
    {
        for(i = 0;i < 9; i++)
        {
            cin >> s;
            for(j = 0;j < 9; j++)
            {
                k = s[j] - 48;
                initial[i][j] = k;
                if(k == 5)
                    initial[i][j] = 4;
            }
            s = "";
        }
        for(i = 0;i < 9; i++)
        {
            for(j = 0;j < 9; j++)
                cout << initial[i][j];
            cout << endl;
        }
    }
    return 0;
}