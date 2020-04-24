#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

int main() 
{
    long long n;
    int i, j, k;
    string s;
    cin >> n >> s;
    if(s.length() == n)
    {
        cout << 1;
        return 0;
    }
    else if(s.length() > n)
    {
        cout << 0;
        return 0;
    }
    int m = s.length();
    dfa = new int[26][m]; 
    dfa[s.charAt(0) - 'A'][0] = 1; 
    for (i = 0, j = 1; j < m; j++)
    {
        for (int c = 0; c < 26; c++) 
            dfa[c][j] = dfa[c][i];         
        
        dfa[s.charAt(j) - 'a'][j] = j+1;  
        i = dfa[s.charAt(j) - 'a'][i];   
    } 
    return 0;
}