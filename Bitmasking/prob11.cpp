#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, k, n;
    cin >> n;
    vector<int> nums(n, 0);
    int orsum;
    for(i = 0;i < n; i++)
        cin >> nums[i];
    unordered_set<int> s;
    for(i = 0;i < n; i++)
    {
        s.insert(nums[i]);
        for (j = i - 1; j >= 0; j--)
        {
            orsum = nums[j] | nums[i];
            if(nums[j] == orsum)
                break;
            s.insert(orsum);
            nums[j] = orsum;
        }
    }
    cout << s.size() << endl;
    return 0;
}