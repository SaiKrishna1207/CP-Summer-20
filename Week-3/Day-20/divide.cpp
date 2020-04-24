class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        int i, j, flag1 = 0, flag2 = 0, q = 0;
        if(dividend == divisor)
            return 1;
        if(dividend == INT_MIN && divisor == 1)
            return INT_MIN;
        else if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        if(divisor == INT_MIN)
        {
            if(dividend == INT_MIN)
                return 1;
            else
                return 0;
        }
        
        if(dividend != INT_MIN)
        {
            if(abs(divisor) > abs(dividend))
                return 0;
        }
        if(dividend < 0)
            flag1 = 1;
        if(divisor < 0)
            flag2 = 1;
        if(divisor == 1)
                return dividend;
        if(flag1 == flag2)
        {
            if(flag1 == 0)
            {  
                while(dividend >= divisor)
                {
                    dividend -= divisor;
                    q++;
                }
            }
            else
            {
                while(dividend <= divisor)
                {
                    dividend -= divisor;
                    q++;
                }
            }
        }
        else
        {
            if(flag1 == 1)
            {
                while(dividend <= -(divisor))
                {
                    dividend += divisor;
                    q--;
                }    
            }
            else
            {
                while(dividend >= -(divisor))
                {
                    dividend += divisor;
                    q--;
                }
            }
        }
        return q;
    }
};