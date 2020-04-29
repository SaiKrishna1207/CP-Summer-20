class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int i, j, k, n= points.size();
        vector<vector<int>> ans(K, vector<int>(2));
        if(K == 0)
            return ans;
        if(K == n)
            return points;
        priority_queue<pair<float, int>> pq;
        for(i = 0; i < n; i++)
        {
            float a = sqrt((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
            pq.push(make_pair(-(a), i));
        }
        for(i = 0;i < K; i++)
        {
            pair<float, int> b = pq.top();
            pq.pop();
            // cout << -(b.first) << " " << b.second << endl;
            ans[i][0] = points[b.second][0];
            ans[i][1] = points[b.second][1];
        }
        return ans;
    }
};