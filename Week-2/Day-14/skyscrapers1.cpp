#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
    cin>>n;
    long long max[n], i, j, ind, h, maxm = 0, sum = 0;
	for(i = 0;i < n; i++)
        cin >> max[i];
    vector<long long> arr[n];
	for(i = 0;i < n; i++)
	{
		h = max[i];
		sum += h;
		for(j = i - 1;j >= 0; j--)
		{
            if(max[j] < h)
                h = max[j];
            sum += h;
            arr[i].push_back(h);
		}
		reverse(arr[i].begin(), arr[i].end());
		h = max[i];
		arr[i].push_back(h);
		for(j = i + 1;j < n;j++)
		{
            if(max[j] < h)
                h = max[j];
            sum += h;
            arr[i].push_back(h);
		}
		if(sum > maxm)
        {
            maxm = sum;
            ind = i;
        }
		sum = 0;
	}
	for(i = 0;i < arr[ind].size();i++)
        cout << arr[ind][i] <<" "; 
    
    return 0;
}