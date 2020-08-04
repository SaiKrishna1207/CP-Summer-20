class Solution {
public:
    int m, n;

    int maxStudents(vector<vector<char>>& seats) {
        int i, j, k;
        m = seats.size();
        n = seats[0].size();
        return max(recurse(seats, 0, 1), recurse(seats, n-1, -1));
    }
    vector<vector<int>> d = {{-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1}};
    int recurse(vector<vector<char>>& seats, int y, int b) {
        int i, j, k;
        if(y >= n || y < 0) 
            return 0;
        int res = 0;
        for(i = 0; i < m; i++) {
            if(seats[i][y] == '#') 
                continue;
            bool f = true;
            for(j = 0; j < 6; j++) {
                int nx = i + d[j][0];
                int ny = y + d[j][1];
                if(nx < 0 || ny < 0 || nx >= m ||ny >= n) 
                    continue;
                if(seats[nx][ny] == 'S') {
                    f = false;
                    break;
                }
            }
            if(f == false) 
                continue;
            res++;
            seats[i][y] = 'S';
        }
        res += recurse(seats, y + b, b);
        for(int i = 0; i < m; i++) 
            if(seats[i][y] == 'S') 
                seats[i][y] = '.';
        return max(res, recurse(seats, y + b, b));
    }
};