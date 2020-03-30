#include <bits/stdc++.h>

using namespace std;

// 7 1 5 3 6 4
/* i = 3   k = 5   profit= 1   bought = true
*/
int maxProfit(vector<int>& prices) 
{
    int i, j, k;
    bool bought = false;
    int n = prices.size();
    int profit = 0;
    for(i = 0;i < n; i++)
    {
        k = i+1;
        if(bought == false)
        {
            while(k < n && prices[k-1] > prices[k])
                k++;
            if(k > n-1)
                return profit;
            else
            {
                profit -= prices[k-1];
                bought = true;
            }
        }
        else
        {
            while(k < n && prices[k-1] < prices[k])
                k++;
            if(k >= n-1)
            {
                profit += prices[k-1];
                return profit;
            }
            else
            {
                profit += prices[k-1];
                bought = false;
            }
        }
        i = k-1;
    }
    return profit;
}


int main()
{
    int n, i, k;
    cin >> n;
    vector<int> prices;
    for (i = 0; i < n; i++)
    {
        cin >> k;
        prices.push_back(k);
    }

    int profit = maxProfit(prices);
    cout << profit << endl;
    return 0;
}
