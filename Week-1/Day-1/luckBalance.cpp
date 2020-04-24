#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[0] > v2[0]; 
} 

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {
    sort(contests.begin(), contests.end(), sortcol); 
    int i, luckbalance = 0;
    for(i = 0;i < contests.size();i++) {
        if(contests[i][1] == 0){
            luckbalance += contests[i][0];
        }
        else if(contests[i][1] == 1){
            if(k!=0) {
                luckbalance += contests[i][0];
                k--;
            }
            else {
                luckbalance -= contests[i][0];
            }
        }
    }
    return luckbalance;

}

int main()
{
    int n,k,i,a,b;
    cout << "Enter n and k" << endl;
    cin >> n >> k;
    vector<vector<int>> contests(n);
    cout << "Enter losses and importance of each contest" << endl;
    for(i=0;i<n;i++) {
        cin >> a >> b;
        contests[i].push_back(a);
        contests[i].push_back(b);
    }
    int luck = luckBalance(k, contests);
    cout << "Luck balance is : "<< luck << endl;

    return 0;
}