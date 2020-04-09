#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, i;
    float n;
    cin >> t;
    vector<string> answers;
    char bob[105] = {' '}, alice[105] = {' '};
    while(t--)
    {
        int a, b, c, x = 0, y = 0, z = 0, win = 0, n1;
        cin >> n;
        cin >> a >> b >> c;
        n1 = n;
        string al = "";
        cin >> bob;
        for(i = 0;i < n1; i++)
        {
            if(bob[i] == 'R' && y < b)
            { 
                alice[i] = 'P';
                y++;
                win++;
            }
            if(bob[i] == 'P' && z < c)
            { 
                alice[i] = 'S';
                z++;
                win++;
            }
            if(bob[i] == 'S' && x < a)
            { 
                alice[i] = 'R';
                x++;
                win++;
            }
        }
        for(i = 0;i < n1;i++)
        {
            if(alice[i] != 'R' && alice[i] != 'P' && alice[i] != 'S')
            {
                if(x < a)
                {
                    alice[i] = 'R';
                    x++;
                }
                else if(y < b)
                {
                    alice[i] = 'P';
                    y++;
                }
                else if(z < c)
                {
                    alice[i] = 'S';
                    z++;
                }
            }
        }
        float wins = round(n / 2);
        if(win >= wins)
        {
            answers.push_back("YES");
            answers.push_back(alice);
        }
        else
            answers.push_back("NO");  
        for(i = 0; i < n1; i++)
            alice[i] = ' ';
    }
    for(i = 0;i < answers.size(); i++)
    {
        if(answers[i] == "NO")
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << answers[i+1] << endl;
            i++;
        }
    }

    return 0;
}
