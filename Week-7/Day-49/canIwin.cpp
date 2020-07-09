class Solution {
public:
    unordered_map<int, int> dp;
    bool dfs(int mx, int tot, int k){
        if(dp[k] == 1)
            return true;
        if(dp[k] == -1 || tot <= 0)
            return false;

        int i, j;
        for(i = 0;i < mx; i++){
            if(!(k&(1<<i)) && !dfs(mx, tot - (i + 1), k|(1<<i))){
                dp[k] = 1;
                return true;
            }
        }
        dp[k] = -1;
        return false;
    }
    
    bool canIWin(int mx, int tot) {
        int i, j;
        if(mx >= tot)
            return true;       
        int sum = (mx * (mx + 1)) / 2;
        if(sum < tot)
            return false;
        if(sum == mx){
            if(mx%2)
                return true;
            return false;
        }            
        return dfs(mx, tot, 0);
    }
};