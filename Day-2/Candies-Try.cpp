#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void solve(vector<int> rating, int n)
{
    int i, j, a, k, k1, count, sum = 0;
    int candies[n];
    //2 4 3 5 2 6 4 5
    //1 2 2 1
    for(i = 0;i < n-1;i++)
    {
        count = 0;
        a = rating[i];
        k = i+1;
        while(rating[k-1] > rating[k])
        {
            k++;
            count++;
        }
        k1 = k;
        if(count != 0)
        {
            k = i;
            while((count + 1) != 0)
            {
                candies[k] = count + 1;
                k++;
                count--;
            }
            i = k1-1;
        }
        count = 0;
        k = i+1;
        while(rating[k-1] < rating[k])
        {
            k++;
            count++;
        }
        k1 = k;//2
        if(count != 0)
        {
            k = i;
            j = count;
            while((j+1) != 0)
            {
                candies[k] = count - j + 1;
                k++;
                j--;
            }
            i = k1-1;
        }
        count = 0;
        k = i;
        while(rating[k-1] == rating[k])
        {
            count++;
            k++;
        }
        k1 = k;
        if(count != 0)
        {
            k = i;
            while(count != 1)
            {
                candies[k] = 1;
                k++;
            }
            if(rating[k] < rating[k+1] && k != n-1)
            {
                candies[k] = 1;
                i = k1-1;
            }
            else if(rating[k] >= rating[k+1] && k != n-1)
            {
                candies[k] = candies[k+1]+1;
                i = k1-1;
            }
            else if(k == n-1)
                candies[k] = 1;
        }   
    }
    if(rating[n-1] > rating[n-2])
        candies[n-1] = candies[n-2] + 1;
    else
        candies[n-1] = 1;
    for(i = 0;i < n;i++)
    {
        sum += candies[i];
    }
    cout<<sum<<endl;
}

int main()
{
    int n, i, k;
    //cout << "Enter n" << endl;
    cin >> n;
    vector<int> rating;
    //cout << "Enter ratings" << endl;
    for(i = 0;i < n;i++)
    {
        cin>>k;
        rating.push_back(k);
    }

    solve(rating, n);

    return 0;
}