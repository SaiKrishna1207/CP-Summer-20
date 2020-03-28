#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void solve(vector<long> rating, int n)
{
    int i, j;
    long sum = 0;
    long candies[n];
    candies[0] = 1;
    //2 4 3 5 2 6 4 5
    //1 2 2 1
    for(i = 1;i < n;i++)
    {
        if(rating[i] > rating[i-1])
            candies[i] = candies[i-1] + 1;
        else
            candies[i] = 1;
    }
    for(i = n-2; i >= 0 ; i--)
    {
        if(rating[i]>rating[i+1] && candies[i] <= candies[i+1])
            candies[i] = candies[i+1] + 1;
    }
       
    for(i = 0;i < n;i++)
    {
        sum += candies[i];
    }
    cout<<sum<<endl;
}

int main()
{
    int n, i, k;
    cout << "Enter n" << endl;
    cin >> n;
    vector<long> rating;
    cout << "Enter ratings" << endl;
    for(i = 0;i < n;i++)
    {
        cin>>k;
        rating.push_back(k);
    }

    solve(rating, n);

    return 0;
}