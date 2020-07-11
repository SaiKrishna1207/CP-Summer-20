class Solution {
public:
    
    int find(int x1, int y1, int x2, int y2){
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int i, j;
        if(target[0] == 0 && target[1] == 0)
            return true;
        int dist = abs(target[0]) + abs(target[1]);
        vector<int> steps;
        for(i = 0; i < ghosts.size(); i++){
            j = find(ghosts[i][0], ghosts[i][1], target[0], target[1]);
            if(j <= dist)
                return false;
        }
        return true;
    }
};