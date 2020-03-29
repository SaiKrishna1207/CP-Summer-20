#include <bits/stdc++.h>

using namespace std;

string rev(string a)
{
    int i, l = a.length();
    char temp;
    for(i = 0;i < l/2; i++)
    {
        temp = a[i];
        a[i] = a[l-i-1];
        a[l-i-1] = temp;
    }
    return a;
}

void solve(vector<string> str, int m, int n)
{
    int i, j, flag;
    string x, y;
    unordered_map<int, int> pairs;
    for(i = 0;i < n;i++)
    {
        flag = 0;
        x = str[i];
        for(j = i+1; j < n; j++)
        {
            y = str[j];
            if(x == rev(y))
            {
                pairs[i] = j;
                flag = 1;
                break;
            }            
        }
        if(flag == 0)
        {
            if(x == rev(x))
                pairs[i] = i;
        }
    }
    // 0-0 1-2 
    x = "";
    for(auto i: pairs)
    {
        if(i.first != i.second)
        {
            x.append(str[i.first]);
        }
    }
    y = rev(x);
    for(auto i: pairs)
    {
        if(i.first == i.second)
        {
            x.append(str[i.first]);
            break;
        }
    }
    x.append(y);
    int l = x.length();
    cout << l << endl;
    cout << x << endl;
}

int main()
{
    int n, m, i;
    cin >> n >> m;
    vector<string> str;
    string s;

    for(i = 0;i < n; i++)
    {
        cin >> s;
        str.push_back(s);
    }

    solve(str, m, n);

}