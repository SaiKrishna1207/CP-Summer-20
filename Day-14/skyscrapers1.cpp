#include<bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
    cin>>n;
    long long a[n], i, maxm=0, ele, sum=0, j, x;
	for(i = 0;i < n; i++)
        cin >> a[i];
    vector<long long> arr[n];
	for(i = 0;i < n; i++)
	{
		ele = a[i];
		sum += ele;
		for(j = i - 1;j >= 0; j--)
		{
            if(a[j] < ele)
                ele=a[j];
            sum += ele;
            arr[i].push_back(ele);
		}
		reverse(arr[i].begin(),arr[i].end());
		ele = a[i];
		arr[i].push_back(ele);
		for(j = i + 1;j < n;j++)
		{
            if(a[j] < ele)
                ele = a[j];
            sum += ele;
            arr[i].push_back(ele);
		}
		if(sum > maxm)
        {
            maxm = sum;
            x = i;
        }
		sum = 0;
	}
	for(i = 0;i < arr[x].size();i++)
        cout << arr[x][i] <<" "; 
    
    return 0;
}