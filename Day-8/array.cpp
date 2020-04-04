    #include<bits/stdc++.h>
     
    using namespace std;
     
    bool sidesSum(vector<int> & arr, int mid, long long sum)
    {
        int i, j;
        long long sumL = 0;
        for(i = 0;i <= mid;i++)
        {
            sumL += arr[i];
        }
        for(i = 0;i < mid; i++)
        {
            sumL -= arr[i];
            if(sumL == sum/2)
                return true;
            sumL += arr[i];
        }
        return false;
    }
     
    int main()
    {
        int i, n, k, flag = 0, a, b;
        bool kk;
        long long sum = 0;
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
        for(i = 1;i < n;i++)
        {
            kk = sidesSum(arr, i, sum);
            if(kk)
            {
                flag = 1;
                cout << "YES" << endl;
                break;
            }
        }
        reverse(arr.begin(), arr.end());
        if(flag == 0)
        {
            for(i = 1;i < n;i++)
            {
                kk = sidesSum(arr, i, sum);
                if(kk)
                {
                    flag = 1;
                    cout << "YES" << endl;
                    break;
                }
            }
        }
        if(flag == 0)
        {
            cout << "NO" << endl;
        }
        return 0;
    }