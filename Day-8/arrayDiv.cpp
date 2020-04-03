#include<bits/stdc++.h>

using namespace std;

bool sidesSum(vector<int> & arr, int mid, long sum)
{
    int i, j, diff;
    long sumL;
    for(i = 0;i < mid;i++)
    {
        sumL = 0;
        for(j = 0;j < mid; j++)
        {
            if(j != i)
                sumL += arr[j];
        }
        if(sumL == sum/2)
            return true;
    }
    return false;
}

int main()
{
    int i, n, k, flag = 0, a, b;
    long sum = 0;
    bool kk;
    cin >> n;
    vector<int> arr;
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
    //2 2 3 4 5 
    int low = 0, high = n;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        kk = sidesSum(arr, mid, sum);
        if(kk)
        {
            flag = 1;
            cout << "YES" << endl;
            break;
        }
        else 
            low = mid + 1;       
    }
    reverse(arr.begin(), arr.end());
    low = 0, high = n;
    if(flag == 0)
    {
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            kk = sidesSum(arr, mid, sum);
            if(kk)
            {
                flag = 1;
                cout << "YES" << endl;
                break;
            }       
            else
                low = mid + 1;
        }
    }
    if(flag == 0)
    {
        cout << "NO" << endl;
    }
    return 0;
}
