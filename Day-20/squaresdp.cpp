class Solution {
public:
    int numSquares(int n) 
    {
        vector<int> arr(n + 1, INT_MAX);
        if(n < 4)
            return n;
        int i, j;
		for (i = 0; i < 4; i++) {
			arr[i] = i;
		}
		for (i = 4; i <= n; i++) {
			for (j = sqrt(i); j > 0; j--) {
				arr[i] = min(arr[i], arr[i - j * j] + 1);
			}
		}
		return arr[n];
    }
};