class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> maxes;
        priority_queue<pair<int, int>> pq;
        int i, j, max, ind;
        for(i = 0;i < k - 1; i++)
            pq.push(make_pair(nums[i], i));
        for(i = 0;i < nums.size() - k + 1; i++)
        {
            j = i + k - 1;
            pq.push(make_pair(nums[j], j));
            pair<int, int> a = pq.top();
            ind = a.second;
            max = a.first;
            
            while(ind < i)
            {
                pq.pop();
                a = pq.top();
                ind = a.second;
                max = a.first;            
            }
            maxes.push_back(max);
        }
        return maxes;
    }
};