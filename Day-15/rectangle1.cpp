class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        stack<int> s;
        int max = 0, t, area, i=0;
        while(i < n)
        {
            if(s.empty() || heights[s.top()] <= heights[i])
                s.push(i++);
            else
            {
                t = s.top();
                s.pop();
                area = heights[t] * (s.empty() ? i : i - s.top() - 1);
                if(area>max)
                    max=area;
            }
        }
    
        while(!s.empty())
        {
            t = s.top();
            s.pop();
            area=heights[t]*(s.empty()?i:i-s.top()-1);
            if(area>max)
                max=area;
        
        }
    return max;
    }
};