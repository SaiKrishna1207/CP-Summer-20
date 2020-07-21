class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int i, j, k, n = A.size();
        int ans = 0;
        unordered_map<int, int> mp;
        for(i = 0;i < n; i++){
            for(j = 0;j < n; j++){
                k = A[i] + B[j];   
                mp[k]++;
            }
        }
        for(i = 0;i < n; i++){
            for(j = 0;j < n; j++){
                k = -C[i] - D[j];
                ans += mp[k];
            }
        }
        return ans;
    }
};