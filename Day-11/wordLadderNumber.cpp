bool isDiff(string &s1, string &s2)
{
    int i, count=0;
    for(i = 0;i < s1.length(); i++)
    {
        if(s1[i] != s2[i])
            count++;
        if(count > 1)
            return false;
    }
    return true;
}
int bfs(string & s, string &e, vector<string> &dict)
{
    queue<pair<string, int> >q;
    unordered_set<string > a;
    q.push(make_pair(s, 1));
    sety.insert(s);
    while(!q.empty())
    {
        pair<string , int > temp = q.front();
        if(temp.first.compare(e)==0)
            return temp.second;
        q.pop();
        for(string str : dict)
        {
            if(a.find(str) == a.end() && isDiff(str, temp.first))
            {
                a.insert(str);
                q.push(make_pair(str, temp.second+1));
            }
        }
    }
    return 0;
}
int Solution::solve(string A, string B, vector<string> &dict) 
{
    dict.push_back(end);
    int ans = bfs(A, B, dict);
    return ans;
}