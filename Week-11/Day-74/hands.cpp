class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int i, j, k;
        int ans = 0;
        int n = row.size();
        if(!row.size())
            return 0;
        unordered_map<int, int> mp;
        for(i = 0;i < n; i++)
            mp[row[i]] = i;
        
        for(i = 0;i < n; i += 2){
            int other;
            if(row[i]%2 == 1)
                other = row[i] - 1;
            else
                other = row[i] + 1;
            
            if(row[i + 1] != other){
                ans++;
                row[mp[other]] = row[i + 1];
                mp[row[i + 1]] = mp[other];
            }
        }
        return ans;
    }
};