class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int i, j, k;
        int count = 0, mx = 0;
        for(i = 0;i < arr.size(); i++){
            mx = max(arr[i], mx);
            if(mx == i)
                count++;
        }
        return count;
    }
};