#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string a, string b)
{
    int i;
    char x;
    int aAlph[26], bAlph[26];
    for(i = 0;i < 26; i++)
    {
        aAlph[i] = 0;
        bAlph[i] = 0;
    }
    for(i = 0;i < a.length(); i++)
    {   
        x = a[i];
        aAlph[x-97]++;
    }
    for(i = 0;i < b.length(); i++)
    {   
        x = b[i];
        bAlph[x-97]++;
    }

    for(i = 0;i < 26; i++)
    {
        if(aAlph[i] != bAlph[i])
            return false;
    }
    return true;

}

int main() 
{
    int q, i, j, k, sublen, count;
    string str, sub1, sub2;
    vector<int> answers;
    cin >> q;
    while(q--)
    {
        count = 0;
        cin >> str;
        sublen++;
        for(k = 1;k < str.length(); k++)
        {
            for(i = 0;i < str.length() - sublen; i++)
            {
                sub1 = str.substr(i, sublen);
                for(j = i + 1; j < str.length() - sublen + 1; j++)
                {
                    sub2 = str.substr(j, sublen);
                    if(isAnagram(sub1, sub2))
                        count++;
                }
            }
            sublen++;
        }
        answers.push_back(count);
    }
    for(i = 0;i < answers.size(); i++)
        cout << answers[i] << endl;

    return 0;
}