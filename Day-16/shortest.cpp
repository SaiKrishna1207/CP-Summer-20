class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        int m = flights.size();
        int adj[n][n];
        priority_queue<pair<int, int>> pq;
        int i, j, k;
        int dist[n], k_value[n];
        for(i = 0;i < n; i++)
        {
            k_value[i] = -1;
            dist[i] = INT_MAX;
        }
        dist[src] = 0;
        for(i = 0;i < n; i++)
        {
            for(j = 0; j < n; j++)
                adj[i][j] = 0;
        }
        for(i = 0;i < flights.size(); i++)
            adj[flights[i][0]][flights[i][1]] = flights[i][2];
        pq.push(make_pair(0, src));
        k_value[src] = K;
        while(!pq.empty())
        {
            if(k_value[pq.top().second] == 0)
            {
                while(!pq.empty())
                {
                    pair<int, int> b = pq.top();
                    pq.pop();
                    int x = b.second;
                    if(x == dst)
                        return dist[x];
                    if(adj[x][dst] != 0)
                    {
                        int d = dist[x] + adj[x][dst];
                        if(d < dist[dst])
                            return d;
                        else
                            return dist[dst];
                    }
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
                    int d = dist[i] + adj[i][j];
                    if(d < dist[j])
                    {
                        dist[j] = d;
                        pq.push(make_pair((-1) * dist[j], j));
                        k_value[j] = k_value[i] - 1;
                    }
                }
            }
            cout << endl;
            for(k = 0;k < n; k++)
                cout << dist[k] << " ";
            cout << endl;
         }
        if(dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }   
};