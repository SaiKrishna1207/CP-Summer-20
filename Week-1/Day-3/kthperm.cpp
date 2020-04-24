#include <bits/stdc++.h>

using namespace std;

int fact[13];

string perm(vector<string> remaining, int k) 
{
    int a;
    int n = remaining.size();
    if(n == 0) {
        return "";
    }
    if (n > 12)
        a = k / INT_MAX;
    else
        a = k / fact[n-1];
    string str = remaining[a];
    if(n <= 12)
        k %= fact[n - 1];
    else
        k %= INT_MAX;
    remaining.erase(remaining.begin() + a);
    
    return str.append(perm(remaining, k));
}

string getPermutation(int n, int k) 
{
    fact[0] = 1;
    for(int i = 1; i <= 12; i++) 
    {
        fact[i] = i * fact[i-1];
    }
    vector<string> remaining(n);
    for(int i = 0; i < n; i++) 
    {
        remaining[i] = to_string(i + 1);
    }
    
    return perm(remaining, k - 1);
}

int main()
{
    int n, k;
    cin >> n >> k;
    string s = getPermutation(n, k);
    cout << s << endl;

}