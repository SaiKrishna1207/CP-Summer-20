#include<bits/stdc++.h>

using namespace std;

unordered_map<string, int> m;

int getSum(string a, string b)
{
    if(!m[a] || !m[b])
        return INT_MAX;
    return m[a] + m[b];
}

int main()
{
    int n, i, j, k, vit;
    string s;
    cin >> n;
    for(i = 0;i < n; i++)
    {
        cin >> k >> s;
        sort(s.begin(), s.end());
        if(!m[s])
            m[s] = k;
        else
            m[s] = min(m[s], k);    
    }

    vit = INT_MAX;
    if(m["A"] && m["B"] && m["C"])
        vit = m["A"] + m["B"] + m["C"];
    
    if(m["ABC"])
        vit = min(vit, m["ABC"]);

    vit = min(vit, getSum("A", "BC"));
    vit = min(vit, getSum("AB", "C"));
    vit = min(vit, getSum("AC", "B"));
    vit = min(vit, getSum("AC", "BC"));
    vit = min(vit, getSum("AB", "BC"));
    vit = min(vit, getSum("AB", "AC"));

    if(vit == INT_MAX)
        cout << -1;
    else
        cout << vit << endl;

    return 0;
}