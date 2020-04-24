class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());      
        int n = nums.size();
        vector<vector<int>> arr;
        map<pair<int, int>, int> m;
        for(int i = n - 1;i >= 0; i--)
        {
            int j = 0;
            int k = i - 1;
            while(j < k)
            {
                if(nums[j] + nums[k] + nums[i] == 0)
                {
                    pair<int, int> p;
                    p.first = nums[j];
                    p.second = nums[k];
                    if(m.find(p) == m.end())
                    {
                        vector<int> v;
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        v.push_back(nums[i]);
                        arr.push_back(v);
                        m[p] = 1;
                    }
                    j++;
                    k--;
                }
                else if((nums[j]+nums[k]) < -1*nums[i])
                    j++;
                else
                    k--;
            }
            
        }
        return arr;
    }
};