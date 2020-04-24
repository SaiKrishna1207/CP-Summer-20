#include<bits/stdc++.h>

using namespace std;

int nim[301] = {0};

int mex(vector<int> arr)
{
	int mex = 0;
	while(find(arr.begin(), arr.end(), mex) == arr.end());
		mex++;
	return mex;
}

int grundy(int n)
{
    int i, j, k, x, y;
	if(nim[n] != 0)
		return nim[n];
	if(n == 0)
	{
		nim[0] = 0;
		return 0;
	}
	if (n == 1)
	{
		nim[1] = 1;
	    return 1;
	}
	if (n == 2)
    {
	    nim[2] = 2;
	    return 2;
    }
    vector<int> arr;
	for(i = 1, j = 0, k = 0; i <= n; i++)
	{
		if(i <= n / 2)
		{
			x = grundy(j);
			y = grundy(n - j - 2);
			j++;
		} 
        else 
        {
			x = grundy(k);
			y = grundy(n - k - 1);
			k++;
		}
		arr.push_back(x^y);
	}
	nim[n] = mex(arr);
    return nim[n];
}

int solve(string order, int n)
{
    int i, j = 0, k = 0;
    vector<int> sizes;
    for(i = 0;i < n;i++)
    {
        if(order[i] == 'X')
        {   
            if(j)
                sizes.push_back(j);
            j = 0;
        }
        else if(order[i] == 'I')
            j++;
    }
    if(j)
        sizes.push_back(j);
    for(i = 0;i < sizes.size(); i++)
        k = k ^grundy(sizes[i]);
    if(k <= 0)
        return 0;
    else
        return 1;
}

int main()
{
    int i, j, t, n;
    cin >> t;
    string order;
    vector<int> answers;
    while(t--)
    {
        cin >> n >> order;
        answers.push_back(solve(order, n));
    }
    for(i = 0;i < answers.size(); i++)
    {
        if(answers[i] == 1)
            cout << "WIN" << endl;
        else
            cout << "LOSE" << endl;
    }
    return 0;
}