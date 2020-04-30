#include<bits/stdc++.h>

using namespace std;

vector<long long> ans;
vector<bool> visited;
int c = 0;

bool dfs(vector<long long> & nums, int i)
{
    visited[i] = true;
    ans.push_back(nums[i]);
    c++;
    for(int j = 0;j < nums.size(); j++)
    {
        if(!visited[j] && ((nums[j] * 3 == nums[i]) || (nums[j] == nums[i] * 2)))
        {
            if(dfs(nums, j))
                return true;
            visited[j] = false;
            ans.pop_back();
            c--;
        }
    }
    if(c == nums.size())
        return true;
    return false;
}

int main()
{
    long long n, j;
    int i;
    cin >> n;
    vector<long long> nums;
    for(i = 0;i < n; i++)
    {
        visited.push_back(false);
        cin >> j;
        nums.push_back(j);
    }
    for(i = 0;i < n; i++)
    {
        if(dfs(nums, i))
            break;
        visited[i] = false;
        ans.pop_back();
        c--;
    }
    for(i = 0;i < n; i++)
        cout << ans[i] << " ";

    return 0;
}
