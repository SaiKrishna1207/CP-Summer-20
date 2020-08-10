#include<bits/stdc++.h>

using namespace std;

int main(){
    int i, j, k, n, t;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> arr(n);
        int mn = INT_MAX, mx = INT_MIN;
        for(i = 0;i < n; i++)
            cin >> arr[i];
        for(i = 0;i < n; i++){
            if(arr[i] != -1 && ((i + 1 < n && arr[i + 1] == -1) || (i - 1 >= 0 && arr[i - 1] == -1))){
                mx = max(mx, arr[i]);
                mn = min(mn, arr[i]);
            }
        }
        k = (mx + mn) / 2;
        for(i = 0;i < n; i++){
            if(arr[i] == -1)
                arr[i] = k;
        }
        int ans = 0;
        for(i = 0;i < n - 1; i++)
            ans = max(ans, abs(arr[i] - arr[i + 1]));
        cout << ans << " " << k << endl;
    }
    return 0;
}