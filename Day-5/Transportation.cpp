#include <bits/stdc++.h>

using namespace std;

//1 2 1 2 1 2 1
// visited = 1 1 0 1 0 1 0 0

void recurse(int* arr, int* visited, int currentPos, int n)
{
    int i;
    visited[currentPos] = 1;
    if(currentPos >= n)
        return;
    if(currentPos + arr[currentPos] <= n)
    {
        recurse(arr, visited, currentPos + arr[currentPos], n);
    }
}

void solve(int* arr, int n, int t)
{
    int i;
    int visited[n+1];
    for(i = 0;i <= n; i++)
        visited[i] = 0;
    recurse(arr, visited, 1, n);
    if(visited[t] == 1) 
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    int n, t, i;
    //cout << "Enter n and t : " << endl;
    cin >> n >> t;
    int arr[n+1];
    for(i = 1;i < n; i++)
    {
        cin >> arr[i];
    }
    arr[n] = 0;
    solve(arr, n, t);
    return 0;
}