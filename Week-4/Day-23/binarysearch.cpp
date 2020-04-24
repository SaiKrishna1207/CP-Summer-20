class Solution {
public:
    
    int binarySearch(vector<int> & nums, int lo, int hi, int target)
    {
        if(lo > hi)
            return -1;
        int m = lo + (hi - lo) / 2;
        if(nums[m] == target)
            return m;
        else if(nums[m] > target)
            return binarySearch(nums, lo, m - 1, target);
        else
            return binarySearch(nums, m + 1, hi, target);
    }
    
    int pivot(vector<int> & nums, int lo, int hi)
    {
        if(lo > hi)
            return -1;
        if(lo == hi)
            return lo;
        int mid = lo + (hi - lo) / 2;
        if (mid < hi && nums[mid] > nums[mid + 1]) 
            return mid; 
      
        if (mid > lo && nums[mid] < nums[mid - 1]) 
            return (mid-1);
        
        if(nums[lo] >= nums[mid])
            return pivot(nums, lo, mid - 1);
        
        return pivot(nums, mid + 1, hi);
    }
    
    int search(vector<int>& nums, int target) {
        int ind = -1;
        int n = nums.size();
        if(n == 0)
            return -1;
        int p = pivot(nums, 0, n - 1);
        cout << p;
        if(p != -1 && nums[p] == target)
            return p;
        if(p == -1)
            ind = binarySearch(nums, 0, n - 1, target);
        else if(nums[0] > target)
            ind = binarySearch(nums, p + 1, n - 1, target);
        else
            ind = binarySearch(nums, 0, p - 1, target);
        return ind;
    }
};