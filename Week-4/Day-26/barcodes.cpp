class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int i, n = barcodes.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> m;
        for(i = 0; i < n; i++)
            m[barcodes[i]]++;
        priority_queue<pair<int, int>> pq;
        for(auto i : m)
            pq.push(make_pair(i.second, i.first));
        int index = 0;
        while(!pq.empty())
        {
            pair<int, int> a = pq.top();
            pq.pop();
            while(a.first--)
            {
                ans[index] = a.second;
                index += 2;
                if(index >= n)
                    index = 1;
            }
        }
        return ans;
    }
};