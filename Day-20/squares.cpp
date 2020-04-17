class Solution {
public:
    int numSquares(int n) 
    {
        float a = sqrt(n);
        if(n < 4)
            return n;
        int i, j, k, n1 = (int)a, count = 0, m = n;
        vector<int> arr;
        arr.push_back(n);
        for(i = 2;i <= n1; i++)
        {
            count = 0;
            j = i;
            n = m;
            while((n >= j * j) && (n > 0))
            {
                n -= (j * j);
                count++;
                while(n < j * j)
                    j--;
            }
            arr.push_back(count);
        }
        int min = arr[0];
        for(i = 0;i < n1; i++)
            cout << arr[i] << endl;
        for(i = 1;i < n1; i++)
        {
            if(arr[i] < min)
                min = arr[i];
        }
        return min;
    }
};