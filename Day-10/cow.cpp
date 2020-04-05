#include<bits/stdc++.h>

using namespace std;

int count1 = 0, count2 = 0, co = 0;

//1 1 1 1 0 
//1 1 2 2 
//4 4
int dfs(int* eaten, int* completed, vector<pair<int,int>> & flavours, int n)
{
    int i, a, b, j, min = INT_MAX, flag = 0;
    if(count1 == flavours.size())
    {
        for(i = 0;i < flavours.size(); i++)
        {
            if(completed[i] == 2)
                flag++;
        }
        return flag;
    }
    else if(count1 < flavours.size() && count2 == n)
    {
        for(i = 0;i < n; i++)
        {
            if(completed[i] == 0 || completed[i] == 2)
                flag++;
        }
        return flag;
    }
    for(i = 0;i < flavours.size(); i++)
    {
        if(completed[i] == 0)
        {
            co++;
            a = flavours[i].first;
            b = flavours[i].second;
            // cout << a << " --> " << b << endl;
            if(eaten[a - 1] == 0 && eaten[b-1] == 0)
            {
                eaten[a-1] = 1;
                eaten[b-1] = 1;
                completed[i] = 1;
                count1++;
                count2 += 2;
                j = dfs(eaten, completed, flavours, n);
                if(j < min)
                    min = j;
                eaten[a-1] = 0;
                eaten[b-1] = 0;
                completed[i] = 0;
                count1--;
                count2 -= 2;
            }
            else if(eaten[a-1] == 0)
            {
                eaten[a-1] = 1;
                completed[i] = 1;
                count1++;
                count2++;
                j = dfs(eaten, completed, flavours, n);
                if(j < min)
                    min = j;
                eaten[a-1] = 0;
                completed[i] = 0;
                count1--;
                count2--;
            }
            else if(eaten[b-1] == 0)
            {
                eaten[b-1] = 1;
                completed[i] = 1;
                count1++;
                count2++;
                j = dfs(eaten, completed, flavours, n);
                if(j < min)
                    min = j;
                eaten[b-1] = 0;
                completed[i] = 0;
                count1--;
                count2--;
            }
            else
            {
                completed[i] = 2;
                count1++;
                j = dfs(eaten, completed, flavours, n);
                if(j < min)
                    min = j;
                completed[i] = 0;
                count1--;
            }
            if(min == 0)
                break;
        }
    }
    return min;
}
//1-2 4-3 1-4 3-4

void solve(vector<pair<int, int>> & flavours, int n)
{
    int k = flavours.size();
    int eaten[n] = {0};
    int completed[k] = {0};
    int i, j;
    j = dfs(eaten, completed, flavours, n);
    cout << co << endl;
    cout << j << endl;
}

int main()
{
    int n, k, i, in1, in2;
    cin >> n >> k;
    vector<pair<int, int>> flavours; 
    for(i = 0;i < k; i++)
    {
        cin >> in1 >> in2;
        flavours.push_back(make_pair(in1, in2));
    }
    solve(flavours, n);
}   