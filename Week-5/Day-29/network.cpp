// Dijsktra ez

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        if(N == 0)
            return 0;
        unordered_map<int, vector<pair<int, int>>> mp;
        int i, j;
        for(i = 0; i < times.size(); i++)
            mp[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        priority_queue<pair<int, int>> pq;
        vector<int> t(N + 1, INT_MAX);
        t[K] = 0;
        pq.push(make_pair(0, K));
        while(!pq.empty())
        {
            pair<int, int> a = pq.top();
            pq.pop();
            i = a.second;
            for(j = 0;j < mp[i].size(); j++)
            {
                int d = mp[i][j].second + t[i];
                if(d < t[mp[i][j].first])
                {
                    t[mp[i][j].first] = d;
                    pq.push(make_pair(-d, mp[i][j].first));
                }
            }
        }
        int mx = 0;
        for(i = 1; i <= N; i++)
            mx = max(mx, t[i]);
        if(mx == INT_MAX)
            return -1;
        return mx;
    }
};