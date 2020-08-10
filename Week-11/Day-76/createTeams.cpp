#include<bits/stdc++.h>

using namespace std;

int main(){
    int i, j, k, t, n;
    cin >> t;
    while(t--){
        int x;
        cin >> n >> x;
        vector<int> arr(n);
        for(i = 0;i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        int cur = 0, ans = 0;
        for(i = 0;i < n; i++){
            k = arr[i];
            cur++;
            if(k * cur >= x){
                ans++;
                cur = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}