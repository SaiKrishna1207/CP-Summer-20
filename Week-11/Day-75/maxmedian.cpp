#include<bits/stdc++.h>

using namespace std;

int main(){
    int i, j, k, n;
    cin >> n >> k;

    vector<int> nums(n);
    for(i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end());
    while(k--){
        nums[n / 2]++;
        int i = n / 2;
        while(i < n - 1 && nums[i] > nums[i + 1]){
            swap(nums[i], nums[i + 1]);
            i++;
        }
    }
    cout << nums[n / 2];
    return 0;
}