class Solution {
public:
    int dir[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
    int regionsBySlashes(vector<string>& grid) {
        vector<vector<char>> g(grid.size()*3, vector<char>(grid.size()*3, '0'));
        int res=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(grid[i][j]=='/') g[i*3][j*3+2]='1', g[i*3+1][j*3+1]='1', g[i*3+2][j*3]='1';
                else if(grid[i][j]=='\\') g[i*3][j*3]='1', g[i*3+1][j*3+1]='1', g[i*3+2][j*3+2]='1';
            }
        }
        for(int i=0;i<g.size();i++) {
            for(int j=0;j<g.size();j++) {
                if(g[i][j]=='0') {
                    res++;
                    DFS(i, j, g);
                }
            }
        }
        return res;
    }
    
    void DFS(int x, int y, vector<vector<char>>& g) {
        g[x][y]='#';
        for(int i=0;i<4;i++) {
            int nx=x+dir[i][0], ny=y+dir[i][1];
            if(nx<0||nx>=g.size()||ny<0||ny>=g.size()||g[nx][ny]!='0') continue;
            DFS(nx, ny, g);
        }
    }
};