#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long q, n, i, k;
    cin >> q;
    long long arr[4];
    vector<int> answers;
    while(q--)
    {
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
        arr[0] -= (arr[1]*arr[2]);
        if(arr[0] > 0)
        {
            answers.push_back(arr[1]);
        }
        else
        {
            k = arr[2] - arr[3];
            long long t = (arr[0] * (-1)) / k;
            ++t;
            if(t > arr[1])
                answers.push_back(-1);
            else
                answers.push_back(arr[1] - t);
        }
    }
    for(i = 0;i < answers.size();i++)
        cout << answers[i] << endl;
    return 0;
}