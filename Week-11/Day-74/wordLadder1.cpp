int Solution::solve(string A, string B, vector<string> &C) {
    unordered_set <string> s, visited;

    for(int i=0;i<C.size();i++)
    {
        s.insert(C[i]);
    }
    
    int cnt = 1;
    queue <string> q;
    q.push(A);
    visited.insert(A);
    string str;
    
    while(!q.empty())
    {
        int y=q.size();
        while(y--)
        {
            str = q.front();
            q.pop();
            
            for(int i=0;i<A.size();i++)
            {
                for(int j=0;j<=25;j++)
                {
                    string temp = str;
                    temp[i] = 'a' + j;
                    
                    
                    if(temp == B){
                    return cnt + 1;
                    }
                    
                    // if present in dictionary and word not visited
                    if(s.find(temp)!=s.end() && visited.find(temp)==visited.end())
                    {
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
             }
        }
        cnt++;
    }
    return 0;
}