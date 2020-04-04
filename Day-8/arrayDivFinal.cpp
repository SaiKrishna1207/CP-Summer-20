#include<bits/stdc++.h>

using namespace std;

int solve(int n, vector<long long> & arr, long long sum)
{
    int i;
    map <long long, long long> m;
    long long total = 0;
    for(i = 0;i < n;i++)
    {
        total += arr[i];
        m[arr[i]] = 1;
        if(m[total - sum/2] == 1)
        {
            cout << "YES" << endl;
            return 1;
        }
    }    
    return 0;
}

// 2 2 3 4 5
//Keeping track of all the distinct numbers in a map and checking for the prefix sums without a double loop

int main()
{
    int i, n, k;
    long long sum = 0;
    cin >> n;
    vector<long long> arr;
    for(i = 0;i < n; i++)
    {
        cin >> k;
        arr.push_back(k);
        sum += k;
    }
    if(sum%2 == 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    k = solve(n, arr, sum);
    if(k == 1)
        return 0;
    reverse(arr.begin(), arr.end());
    k = solve(n, arr, sum);
    if(k == 1)
        return 0;
    cout << "NO" << endl;
    return 0;
}