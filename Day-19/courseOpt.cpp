class Solution {
public:
    
    unordered_map<int, vector<int>> m;
    
    bool dfs(int pos, bool* visited, bool* rec)    
    {
        int i;
        if(visited[pos] == false)
        {
            visited[pos] = true;
            rec[pos] = true;
            
            for(i = 1;i < m[pos].size(); i++)
            {
                if ( !visited[m[pos][i]] && dfs(m[pos][i], visited, rec) ) 
                    return true; 
                else if (rec[m[pos][i]]) 
                    return true; 
            }
        }
        rec[pos] = false;
        return false;
    }
    
    bool findCycle(int n, unordered_map<int, vector<int>> & m)
    {
        bool rec[n], visited[n];
        int i, j;
        for(i = 0;i < n; i++)
        {
            rec[i] = false;
            visited[i] = false;
        }
        for(i = 0;i < n; i++)
        {
            if(dfs(i, visited, rec))
                return true;
        }
        return false;
    }        
    
    void topo(int i, bool* visited, stack<int> & s)
    {
        visited[i] = true; 
        int j, k;
        for (j = 1; j < m[i].size(); j++) 
            if (!visited[m[i][j]]) 
                topo(m[i][j], visited, s); 
  
        s.push(i); 
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int i, j, k, a, b;
        vector<pair<int,int>> indegree;
        vector<int> order;
        if(numCourses == 0)
            return order;
        if(numCourses == 1)
        {
            order.push_back(0);
            return order;
        }
        for(i = 0;i < numCourses; i++)
            m[i].push_back(-1);
        for(i = 0; i < prerequisites.size(); i++)
        {
            a = prerequisites[i][0];
            b = prerequisites[i][1];
            m[a].push_back(b);
        }
        bool cycle = findCycle(numCourses, m);
        if(cycle == true)
            return order;
        
        stack<int> s;
        bool visited[numCourses];
        for(i = 0; i < numCourses; i++)
            visited[i] = false;
        for (i = 0; i < numCourses; i++) 
            if (visited[i] == false) 
               topo(i, visited, s); 
        while (s.empty() == false) 
        { 
            order.push_back(s.top());
            s.pop(); 
        } 
        reverse(order.begin(), order.end());
        return order;
    }
};