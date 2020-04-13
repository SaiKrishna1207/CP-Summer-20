class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        int m = flights.size();
        int adj[n][n];
        priority_queue<pair<int, int>> pq;
        int i, j, k, u, v;
        int dist[n];
        for(i = 0;i < n; i++)
            dist[i] = INT_MAX;       
        dist[src] = 0;
        for(i = 0;i < n; i++)
        {
            for(j = 0; j < n; j++)
                adj[i][j] = 0;
        }
        for(i = 0;i < flights.size(); i++)
        {
            adj[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        
        pq.push(make_pair(0, src));
        while(!pq.empty())
        {
            if(K == 0)
            {
                while(!pq.empty())
                {
                    pair<int, int> b = pq.top();
                    pq.pop();
                    int x = b.second;
                    if(x == dst)
                        return dist[x];
                    if(adj[x][dst] != 0)
                        return dist[x] + adj[x][dst];
                }
                if(pq.empty())
                    return -1;
            }
            pair<int, int> a = pq.top();
            pq.pop();
            i = a.second;
            for(j = 0; j < n; j++)
            {
                if(i != j && adj[i][j] != 0)
                {
                    int d = ((-1) * (a.first)) + adj[i][j];
                    if(d < dist[j])
                    {
                        dist[j] = d;
                        pq.push(make_pair((-1) * dist[j], j));
                    }
                }
            }
            if(pq.empty())
                return -1;
            K--;
         }
         return dist[dst];
    }   
};