class Solution {
public:
    
    int visited[20][20]; 
    int total, max = 0;
    
    void makeZero(int m, int n)
    {
        int i, j;
        for(i = 0;i < m; i++)
        {
            for(j = 0;j < n; j++)
                visited[i][j] = 0;
        }
    }
    
    void traverse(vector<vector<int>>& grid, int posX, int posY)
    {
        int x = grid.size();
        int y = grid[0].size();
        int flag = 0;
        visited[posX][posY] = 1;
        total += grid[posX][posY];
        if(posX + 1 < x && grid[posX + 1][posY] != 0 && visited[posX + 1][posY] == 0)
        {
            flag = 1;
            traverse(grid, posX + 1, posY);
            total -= grid[posX + 1][posY];
            visited[posX + 1][posY] = 0;
        }
        if(posX - 1 >= 0 && grid[posX - 1][posY] != 0 && visited[posX - 1][posY] == 0)
        {
            flag = 1;
            traverse(grid, posX - 1, posY);
            total -= grid[posX - 1][posY];
            visited[posX - 1][posY] = 0;
        }
        if(posY + 1 < y && grid[posX][posY + 1] != 0 && visited[posX][posY + 1] == 0)
        {
            flag = 1;
            traverse(grid, posX, posY + 1);
            total -= grid[posX][posY + 1];
            visited[posX][posY + 1] = 0;
        }
        if(posY - 1 >= 0 && grid[posX][posY - 1] != 0 && visited[posX][posY - 1] == 0)
        {
            flag = 1;
            traverse(grid, posX, posY - 1);
            total -= grid[posX][posY - 1];
            visited[posX][posY - 1] = 0;
        }
        if(flag == 0)
        {
            if(total > max)
                max = total;
        }
    }  
    
    int getMaximumGold(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0)
            return 0;
        int i, j, k;
        for(i = 0;i < m; i++)
        {
            for(j = 0;j < n; j++)
            {
                if(visited[i][j] == 0 && grid[i][j] != 0)
                {
                    total = 0;
                    traverse(grid, i, j);
                    makeZero(m, n);
                }   
            }
        }
        return max;
    }
};