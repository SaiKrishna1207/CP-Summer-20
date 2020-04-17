class Solution {
public:
                
    unordered_map<string, bool> sets;

    bool checkString(int a, int b, int c)
    {
        string s = "";
        s = to_string(a) + to_string(b) + to_string(c);
        if(sets[s])
            return false;
        s = "";
        s = to_string(a) + to_string(c) + to_string(b);
        if(sets[s])
            return false;
        s = "";
        s = to_string(b) + to_string(a) + to_string(c);
        if(sets[s])
            return false;
        s = "";
        s = to_string(b) + to_string(c) + to_string(a);
        if(sets[s])
            return false;
        s = "";
        s = to_string(c) + to_string(a) + to_string(b);
        if(sets[s])
            return false;
        s = "";
        s = to_string(c) + to_string(b) + to_string(a);
        if(sets[s])
            return false;
        sets[s] = true;
        return true;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int i, j, k, a, b, c;
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        unordered_map<int, int> m;
        for(i = 0;i < n; i++)
            m[nums[i]]++;
        for(i = 0;i < n; i++)
        {
            a = nums[i];
            m[nums[i]]--;
            for(j = 0; j < n; j++)
            {
                if(j == i)
                    continue;
                b = nums[j];
                m[nums[j]]--;
                if(m[(-a-b)] > 0)
                {
                    if(checkString(a, b, -a-b))
                    {
                        v.push_back(a);
                        v.push_back(b);
                        v.push_back(-a-b);
                        ans.push_back(v);
                        v.erase(v.begin(), v.end());
                        m[nums[j]]++;
                        continue;
                    }
                }
                m[nums[j]]++;
            }
            m[nums[i]]++;
        }
        return ans;
    }
};