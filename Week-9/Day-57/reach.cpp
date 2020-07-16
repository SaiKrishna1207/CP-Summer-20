class Solution {
public:
    int reachNumber(int target) {
        if(target < 0)
            target = -target;

        int i, k = 0;
        int sum = 0, ans = 0;
        while(true)
        {   
            k++;
            sum += k;
            if(sum == target){
                ans = k;
                break;
            }
            else if(sum > target){
                if((sum - target)%2 == 0)
                    ans = k;
                else
                    ans = k + 1 + (k%2);      
                break;
            }
        }
        return ans;
    }
};