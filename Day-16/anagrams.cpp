#include<bits/stdc++.h>

using namespace std;

bool isAnagram(string a, string b)
{
    if(a.length() != b.length())
        return false;
    int i;
    int aArr[26] = {0}, bArr[26] = {0};
    for(i = 0;i < a.length(); i++)
    {
        aArr[a[i] - 97]++;
        bArr[b[i] - 97]++;
    }
    for(i = 0; i < 26; i++)
    {
        if(aArr[i] != bArr[i])
        return false;
    }
    return true;
}
int k = 0;
    
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{   
    int n = strs.size();
    vector<vector<string>> ans(n);
    if(n <= 0)
        return ans;
    vector<int> done(n, 0);
    unordered_map<int, vector<int>> groups;
    int i, j, a;
    for(i = 0;i < n; i++)
    {    
        if(done[i] == 1)
            continue;
        groups[k].push_back(i);
        for(j = i + 1; j < n; j++)
        {
            if(done[j] == 1)
                continue;
            if(isAnagram(strs[i], strs[j]))
            {
                groups[k].push_back(j);
                done[j] = 1;
            }
        }
        done[i] = 1;
        k++;
    }
    k = 0;
    for(auto i : groups)
    {
        vector<int> sep = i.second;
        for(j = 0; j < sep.size(); j++)
        {
            a = sep[j];
            ans[k].push_back(strs[a]);
        }
        k++;
    }
    return ans;
}


int main()
{
    int n, i, j;
    string b;
    cin >> n;
    vector<string> ans;
    for(i = 0;i < n; i++)
    {
        cin >> b;
        ans.push_back(b);
    }
    vector<vector<string>> Ans = groupAnagrams(ans);
    for(i = 0; i < k; i++)
    {
        for(j = 0;j < Ans[i].size(); j++)
        {
            cout << Ans[i][j] << " "; 
        }
        cout << endl;
    }
    return 0;
}