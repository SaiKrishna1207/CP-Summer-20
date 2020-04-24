#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i, k, n, moves = 0, a, max, x, y;
    cin >> n;
    vector <int> arr;
    for(i = 0;i < n; i++)
    {
        cin >> k;
        arr.push_back(k);
    }
    while(arr.size())
    {
        max = 0;
        for(i = 0;i < n;i++)
        {
            a  = arr[i];
            k = 1;
            while(i+k < n && arr[i + k] == a)
                k++;
            if(k > max)
            {
                max = k;
                x = i;
                y = i + k;
            }
            i = i + k - 1;
        }
        arr.erase(arr.begin() + x, arr.begin() + y);
        n -= k;
        moves++;
    }
    cout << moves << endl;
}