#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    
    sort(arr.begin(), arr.end()); 
    int i, a, b, c, sum = 99999999;
    for(i = 0; i < arr.size() - k + 1; i++)
    {
        a = arr[i];
        b = arr[i+k-1];
        c = b-a;
        if(c < sum)
            sum = c;
    }
    return sum;
}

int main()
{
    int i, j, n, k;
    cout << "Enter n and k" << endl;
    cin >> n >> k;
    vector<int> arr;
    cout << " Enter array elements" << endl;
    for(i = 0; i < n; i++)
    {
        cin >> j;
        arr.push_back(j);
    }

    int sum = maxMin(k, arr);
    cout << sum << endl;
    return 0;
}