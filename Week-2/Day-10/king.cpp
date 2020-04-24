#include<bits/stdc++.h>

using namespace std;
int n;
int arr[1000][1000] = {0};
void solve(int kx, int ky)
{
    arr[kx][ky] = 1;
    if(kx < n && ky+1 < n && kx >= 0 && ky+1 >= 0 && arr[kx][ky+1] == 0)
        solve(kx, ky+1);
    if(kx+1< n && ky+1 < n && kx+1 >= 0 && ky+1 >= 0 && arr[kx+1][ky+1] == 0)
        solve(kx+1, ky+1);
    if(kx+1< n && ky < n && kx+1 >= 0 && ky >= 0 && arr[kx+1][ky] == 0)
        solve(kx+1, ky);
    if(kx+1 < n && ky-1 < n && kx+1 >= 0 && ky-1 >= 0 && arr[kx+1][ky-1] == 0)
        solve(kx+1, ky-1);
    if(kx < n && ky-1 < n && kx >= 0 && ky-1 >= 0 && arr[kx][ky-1] == 0)
        solve(kx, ky-1);
    if(kx-1 < n && ky-1 < n && kx-1 >= 0 && ky-1 >= 0 && arr[kx-1][ky-1] == 0)
        solve(kx-1, ky-1);
    if(kx-1 < n && ky < n && kx-1 >= 0 && ky >= 0 && arr[kx-1][ky] == 0)
        solve(kx-1, ky);
    if(kx-1 < n && ky+1 < n && kx-1 >= 0 && ky+1 >= 0 && arr[kx-1][ky+1] == 0)
        solve(kx-1, ky+1);
}

int main()
{
    int i,j;
    cin >> n;
    int kx, ky, qx, qy, dx, dy, q1, q2;
    cin >> qy >> qx >> ky >> kx >> dy >> dx;
    kx--;
    ky--;
    qx--;
    qy--;
    dx--;
    dy--;
    q1 = qx;
    q2 = qy;
    for(i = 0;i < n; i++)
        arr[qx][i] = 2;
    for(i = 0;i < n; i++)
        arr[i][qy] = 2;
    for(i = qx;i < n;i++)
    {
        if(qx >= n || qy >= n)
            break;
        arr[i][qy++] = 2; 
    }
    qx = q1;
    qy = q2;
    for(i = qx;i < n;i++)
    {
        if(qx >= n || qy < 0)
            break;
        arr[i][qy--] = 2; 
    }
    qx = q1;
    qy = q2;
    for(i = qx;i >= 0;i--)
    {
        if(qx < 0 || qy < 0)
            break;
        arr[i][qy--] = 2; 
    }
    qx = q1;
    qy = q2;
    for(i = qx;i >= 0;i--)
    {
        if(qx < 0 || qy >= n)
            break;
        arr[i][qy++] = 2; 
    }
    if(arr[dx][dy] == 2)
    {
        cout << "NO" << endl;
        return 0;
    }
    solve(kx, ky);
    // arr[kx][ky] = 3;
    // for(i = 0;i < n;i++)
    // {
    //     for(j = 0;j < n;j++)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }
    if(arr[dx][dy] == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
    
}