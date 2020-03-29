#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void solve(vector<int> a, vector<int> b, vector<int> c, int n)
{
    int i, j, k, u, v, w, value, sum = 99999;
    vector<int> uni;

    vector<int>::iterator it, st; 
  
    sort(a.begin(), a.begin() + n); 
    sort(b.begin(), b.begin() + n); 
    sort(c.begin(), c.begin() + n);
  
    it = set_union(a.begin(), a.begin() + n, b.begin(), b.begin() + n, uni.begin()); 

    for (st = uni.begin(); st != it; ++st) 
        cout << ' ' << *st; 
    cout << '\n'; 
  

    //sum = u + v + w;
    //cout << "Minimum sum is : " << sum << endl;

}


int main()
{
    int n, i, j, k;
    cout<<"Enter n"<<endl;
    cin>>n;
    vector<int> a,b,c;
    cout<<"Enter the arrays"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>k;
        a.push_back(k);
    }
    for(i=0;i<n;i++)
    {
        cin>>k;
        b.push_back(k);
    }
    for(i=0;i<n;i++)
    {
        cin>>k;
        c.push_back(k);
    }

    
    solve(a, b, c, n);


}