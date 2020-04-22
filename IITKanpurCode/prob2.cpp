#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, i, j;
    cin >> n;
    vector<int> diff(n, 0);
    for(i = 0;i < n; i++)
        cin >> diff[i];
    sort(diff.begin(), diff.end());
    int sum = 0;
    i = 0;
    while(sum < 10000000 && i < n)
    {
        sum += diff[i];
        i++;
    }
    if(i < n)
        cout << i << endl;
    if(i == n)
    {
        if(sum >= 10000000)
            cout << i << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}