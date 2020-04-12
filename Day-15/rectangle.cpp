#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, j, n, max, min, area, omax;
    vector<int> heights;
    cin >> n;
    for(i = 0;i < n; i++)
    {
        cin >> j;
        heights.push_back(j);
    }
    if(n == 0)
        return 0;
    omax = heights[0];
    for(i = 1;i < n; i++)
    {
        min = heights[i];
        max = heights[i];
        for(j = i - 1; j >= 0; j--)
        {
            if(heights[j] < min)
                min = heights[j];
            area = (i - j + 1) * min;
            if(area > max)
                max = area;
        }
        if(max > omax)
            omax = max;
        min = heights[i];
        max = heights[i];
        for(j = i + 1; j < n; j++)
        {
            if(heights[j] < min)
                min = heights[j];
            area = (j - i + 1) * min;
            if(area > max)
                max = area;
        }
        if(max > omax)
            omax = max;
    }
    cout << omax;
    return 0;
}