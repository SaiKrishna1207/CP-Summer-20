#include<bits/stdc++.h>

using namespace std;

int sidesSum(vector<int> & arr, int mid, long long sum)
{
    int i, j, flag = 0;
    long long sumL = 0;
    for(i = 0;i < mid; i++)
        sumL += arr[i];
    for(i = 0;i < mid; i++)
    {
        sumL -= arr[i];
        if(sumL == sum/2)
            return 0;
        else if(sumL > sum/2)
            flag++;
        sumL += arr[i];
    }
    if(flag == mid)
        return -1;
    return 1;
}

int main()
{
    int i, n, k, flag = 0, a, b;
    long long sum = 0;
    int kk;
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
    //1 5 6 8 3 1 7 3
    //3 7 1 3 8 6 5 1 
    int low = 0, high = n;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        kk = sidesSum(arr, mid, sum);
        if(kk == 0)
        {
            flag = 1;
            cout << "YES" << endl;
            break;
        }
        else if(kk == 1)
            low = mid + 1;
        else
            high = mid - 1;           
    }
    reverse(arr.begin(), arr.end());
    low = 0, high = n;
    if(flag == 0)
    {
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            kk = sidesSum(arr, mid, sum);
            if(kk == 0)
            {
                flag = 1;
                cout << "YES" << endl;
                break;
            }       
            else if(kk == 1)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    if(flag == 0)
        cout << "NO" << endl;
    return 0;
}
