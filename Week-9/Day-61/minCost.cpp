struct node 
{ 
    int x, y; 
    int distance; 
    node(int x, int y, int distance) : 
        x(x), y(y), distance(distance) {} 
}; 

int Solution::solve(int A, int B, vector<string> &C) {
    int i, j;
    if(!A || !B)
        return 0;
    deque<node> q;
    q.push_front(node(0, 0, 0));
    vector<vector<bool>> visited(A, vector<bool>(B, false));
    while(!q.empty())
    {
        node a = q.front();
        q.pop_front();
        int r = a.x;
        int c = a.y;
        int cur = a.distance;
        visited[r][c] = true;
        if(r == A - 1 && c == B - 1)
            return cur;
            
        if(r + 1 < A && !visited[r + 1][c]){
            if(C[r][c] == 'D')
                q.push_front(node(r + 1, c, cur));
            else
                q.push_back(node(r + 1, c, cur + 1));
        }
        if(c + 1 < B && !visited[r][c + 1]){
            if(C[r][c] == 'R')
                q.push_front(node(r, c + 1, cur));
            else
                q.push_back(node(r, c + 1, cur + 1));
        }
        if(r - 1 >= 0 && !visited[r - 1][c]){
            if(C[r][c] == 'U')
                q.push_front(node(r - 1, c, cur));
            else
                q.push_back(node(r - 1, c, cur + 1));
        }
        if(c - 1 >= 0 && !visited[r][c - 1]){
            if(C[r][c] == 'L')
                q.push_front(node(r, c - 1, cur));
            else
                q.push_back(node(r, c - 1, cur + 1));
        }
    }
    return -1;
}
