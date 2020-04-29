class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i, j, k, n = rooms.size();
        bool visited[n];
        for(i = 0;i < n; i++)
            visited[i] = false;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            j = q.front();
            q.pop();
            visited[j] = true;
            for(i = 0;i < rooms[j].size(); i++)
            {
                if(!visited[rooms[j][i]])
                    q.push(rooms[j][i]);
            }
        }
        for(i = 0;i < n; i++)
        {
            if(!visited[i])
                return false;
        }
        return true;
    }
};